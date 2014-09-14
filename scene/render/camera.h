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

    GVec getLookAtPos() const;
    GVec getvPos() const;
    GVec getvUp() const;
    // Move camera actions

    // Move by Direction vector
    Camera & moveByDir(const TypeUse Dt);
    // Move by Right vector
    Camera & moveByRight(const TypeUse Dt);
    // Move by Up vector
    Camera & moveByUp(const TypeUse Dt);

    // Rotate camera actions

    // Rotate by Direction vector
    Camera & rotateByDir(const TypeUse Ang);
    // Rotate by Right vector
    Camera & rotateByRight(const TypeUse Ang);
    // Rotate by Up vector
    Camera & rotateByUp(const TypeUse Ang);

    // Building camera matrix function
    GMatr buildCamMatrix();
  }; // end of 'Camera' class
}

#endif // CAMERA_H
