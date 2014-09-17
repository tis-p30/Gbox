/* Gravity newton box project.
 * Authors: kbsx32;
 * File purpose: Render camera class functions implementation.
 */

#include "camera.h"

// Default constructor
gbox::Camera::Camera(const GVec &NewPos,
                     const GVec &NewUp,
                     const GVec &LookAtPos) :
  vPos(NewPos), vUp(NewUp.getNormalized()),
  vDir((LookAtPos - vPos).getNormalized()), vRight((vDir % vUp).getNormalized())
{
  // vUp = NewUp.GetNormalized();
}

// Getting camera 'look at' vector function
gbox::GVec gbox::Camera::getLookAtPos() const
{
  return vPos + vDir;
}

// Getting camera position vector function
gbox::GVec gbox::Camera::getvPos() const
{
  return vPos;
}

// Getting camera 'up' vector function
gbox::GVec gbox::Camera::getvUp() const
{
  return vUp;
}

// Move by Direction vector
gbox::Camera & gbox::Camera::moveByDir(const TypeUse Dt)
{
  vPos += vDir * Dt;
  return *this;
}

// Move by Right vector
gbox::Camera & gbox::Camera::moveByRight(const TypeUse Dt)
{
  vPos += vRight * Dt;
  return *this;
}

// Move by Up vector
gbox::Camera & gbox::Camera::moveByUp(const TypeUse Dt)
{
  vPos += vUp * Dt;
  return *this;
}

// Rotate by Direction vector
gbox::Camera & gbox::Camera::rotateByDir(const TypeUse Ang)
{
  GMatr MatrRes = buildCamMatrix() * GMatr::rotateZ(Ang);
  vRight = GVec(MatrRes[0][2], MatrRes[1][2], MatrRes[2][2]).getNormalized();
  vDir = GVec(MatrRes[0][0], MatrRes[1][0], MatrRes[2][0]).getNormalized();
  vUp = GVec(MatrRes[0][1], MatrRes[1][1], MatrRes[2][1]).getNormalized();
  return *this;
}

// Rotate by Right vector
gbox::Camera & gbox::Camera::rotateByRight(const TypeUse Ang)
{
  // GMatr MatrRes = buildCamMatrixInv() * GMatr::rotateZ(Ang) * buildCamMatrix();
  GMatr MatrRes = buildCamMatrix() * GMatr::rotateZ(Ang) * buildCamMatrixInv();
  // GMatr Maaa = buildCamMatrix() * buildCamMatrixInv();
  vRight = (MatrRes * vRight).getNormalized();
  vDir = (MatrRes * vDir).getNormalized();
  vUp = (MatrRes * vUp).getNormalized();
  return *this;
}

// Rotate by Up vector
gbox::Camera & gbox::Camera::rotateByUp(const TypeUse Ang)
{
  GMatr MatrRes = GMatr::rotateY(Ang) * buildCamMatrix();

  vRight = GVec(MatrRes[0][2], MatrRes[1][2], MatrRes[2][2]).getNormalized();
  vDir = GVec(MatrRes[0][0], MatrRes[1][0], MatrRes[2][0]).getNormalized();
  vUp = GVec(MatrRes[0][1], MatrRes[1][1], MatrRes[2][1]).getNormalized();
  return *this;
}

gbox::GMatr gbox::Camera::buildCamMatrix()
{
  return gbox::GMatr(vDir, vUp, vRight);
  // return gbox::GMatr(vRight, vUp, vDir);
}

gbox::GMatr gbox::Camera::buildCamMatrixInv()
{
  return gbox::GMatr(vUp[1] * vRight[2] - vRight[1] * vUp[2], -vDir[1] * vRight[2] + vRight[1] * vDir[2],  vDir[1] * vUp[2] - vUp[1] * vDir[2], 0,
                    -vUp[0] * vRight[2] + vRight[0] * vUp[2],  vDir[0] * vRight[2] - vRight[0] * vDir[2], -vDir[0] * vUp[2] + vUp[0] * vDir[0], 0,
                     vUp[0] * vRight[1] - vRight[0] * vUp[1], -vDir[0] * vRight[1] + vRight[0] * vDir[1],  vDir[0] * vUp[1] - vUp[0] * vDir[1], 0,
                     0, 0, 0, 1).transpose() * (1.0 / buildCamMatrix().determ());
  // return gbox::GMatr(vRight, vUp, vDir);
}

