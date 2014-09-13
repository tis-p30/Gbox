/* Gravity newton box project.
 * Authors: kbsx32;
 * File purpose: Render camera class header.
 */

#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include "../../def.h"

namespace gbox
{
  // render camera class
  class Camera
  {
  private:
    GVec vPos, vUp, vDir, vRight; // Camera vectors
  public:
    // Default constructor
    Camera(const GVec &NewPos = GVec(5.0, 5.0, 5.0),
           const GVec &NewUp = GVec(0.0, 1.0, 0.0),
           const GVec &LookAtPos = GVec(0.0, 0.0, 0.0));

    GVec GetLookAtPos() const;
    GVec GetvPos() const;
    GVec GetvUp() const;
    // Move camera actions

    // Move by Direction vector
    Camera & MoveByDir(const TypeUse Dt);
    // Move by Right vector
    Camera & MoveByRight(const TypeUse Dt);
    // Move by Up vector
    Camera & MoveByUp(const TypeUse Dt);

    // Rotate camera actions

    // Rotate by Direction vector
    Camera & RotateByDir(const TypeUse Ang);
    // Rotate by Right vector
    Camera & RotateByRight(const TypeUse Ang);
    // Rotate by Up vector
    Camera & RotateByUp(const TypeUse Ang);
  }; // end of 'Camera' class
}

#endif // CAMERA_H
