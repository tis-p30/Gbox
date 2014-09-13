/* Gravity newton box project.
 * Authors: kbsx32;
 * File purpose: Render camera class functions implementation.
 */

#include "camera.h"

// Default constructor
gbox::Camera::Camera(const GVec &NewPos,
                     const GVec &NewUp,
                     const GVec &LookAtPos) :
  vPos(NewPos), vUp(NewUp),
  vDir(LookAtPos - vPos), vRight(vDir % vUp)
{
}

// Getting camera 'look at' vector function
gbox::GVec gbox::Camera::GetLookAtPos() const
{
  return vPos + vDir;
}

// Getting camera position vector function
gbox::GVec gbox::Camera::GetvPos() const
{
  return vPos;
}

// Getting camera 'up' vector function
gbox::GVec gbox::Camera::GetvUp() const
{
  return vUp;
}

// Move by Direction vector
gbox::Camera & gbox::Camera::MoveByDir(const TypeUse Dt)
{
  vPos += vDir * Dt;
  return *this;
}

// Move by Right vector
gbox::Camera & gbox::Camera::MoveByRight(const TypeUse Dt)
{
  vPos += vRight * Dt;
  return *this;
}

// Move by Up vector
gbox::Camera & gbox::Camera::MoveByUp(const TypeUse Dt)
{
  vPos += vUp * Dt;
  return *this;
}

// Rotate by Direction vector
gbox::Camera & gbox::Camera::RotateByDir(const TypeUse Ang)
{
  vRight.RotateByZ(Ang);
  vUp.RotateByZ(Ang);

  return *this;
}

// Rotate by Right vector
gbox::Camera & gbox::Camera::RotateByRight(const TypeUse Ang)
{
  vUp.RotateByX(Ang);
  vDir.RotateByX(Ang);

  return *this;
}

// Rotate by Up vector
gbox::Camera & gbox::Camera::RotateByUp(const TypeUse Ang)
{
  vRight.RotateByY(Ang);
  vDir.RotateByY(Ang);

  return *this;
}


