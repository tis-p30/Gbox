/* Gravity newton box project.
 * File purpose: Render.
 *               Camera class functions implementation.
 * Authors: Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */

#include "camera.h"

// Default constructor
gbox::Camera::Camera(const GVec &NewPos,
                     const GVec &NewUp,
                     const GVec &LookAtPos) :
  vPos(NewPos), vUp(NewUp.getNormalized()),
  vDir((LookAtPos - vPos).getNormalized()), vRight((vDir % vUp).getNormalized())
{
  vUp = vRight % vDir;
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
  GMatr MatrRes = GMatr::rotateZ(Ang) * buildCamMatrix();

  vRight = GVec(MatrRes[0][0], MatrRes[0][1], MatrRes[0][2]);
  vUp    = GVec(MatrRes[1][0], MatrRes[1][1], MatrRes[1][2]);
  // vDir   = GVec(MatrRes[2][0], MatrRes[2][1], MatrRes[2][2]);
  return *this;
}

// Rotate by Right vector
gbox::Camera & gbox::Camera::rotateByRight(const TypeUse Ang)
{
  GMatr MatrRes = GMatr::rotateX(Ang) * buildCamMatrix();

  // vRight = GVec(MatrRes[0][0], MatrRes[0][1], MatrRes[0][2]);
  vUp    = GVec(MatrRes[1][0], MatrRes[1][1], MatrRes[1][2]);
  vDir   = GVec(MatrRes[2][0], MatrRes[2][1], MatrRes[2][2]);
  return *this;
}

// Rotate by Up vector
gbox::Camera & gbox::Camera::rotateByUp(const TypeUse Ang)
{
  GMatr MatrRes = GMatr::rotateY(Ang) * buildCamMatrix();

  vRight = GVec(MatrRes[0][0], MatrRes[0][1], MatrRes[0][2]);
  // vUp    = GVec(MatrRes[1][0], MatrRes[1][1], MatrRes[1][2]);
  vDir   = GVec(MatrRes[2][0], MatrRes[2][1], MatrRes[2][2]);
  return *this;
}

gbox::GMatr gbox::Camera::buildCamMatrix()
{
  return gbox::GMatr(vRight, vUp, vDir);
  // return gbox::GMatr(vRight, vUp, vDir);
}
