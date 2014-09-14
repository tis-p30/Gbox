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
  vDir((LookAtPos - vPos).getNormalized()), vRight(vDir % vUp)
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
  vRight = vRight.rotateByZ(Ang);
  vUp = vUp.rotateByZ(Ang);
  // vDir = vDir.RotateByZ(Ang);
  return *this;
}

// Rotate by Right vector
gbox::Camera & gbox::Camera::rotateByRight(const TypeUse Ang)
{
  vUp = vUp.rotateByX(Ang);
  vDir = vDir.rotateByX(Ang);
  // vRight =vRight.RotateByX(Ang);
  return *this;
}

// Rotate by Up vector
gbox::Camera & gbox::Camera::rotateByUp(const TypeUse Ang)
{
  vRight = vRight.rotateByY(Ang);
  vDir = vDir.rotateByY(Ang);
  return *this;
}

gbox::GMatr gbox::Camera::buildCamMatrix()
{
  return gbox::GMatr(vDir, vUp, vRight);
}
