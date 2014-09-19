/* Gravity newton box project.
 * File purpose: Gbox definitions file.
 * Authors: Tikhonenko Iliya (tis-p30) <iliya.t@mail.ru>,
 *          Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */

#pragma once
#ifndef DEF_H
#define DEF_H

typedef double TypeUse;

#include "math/mth.h"
#include "math/mthqstr.h"

// main namespace
namespace gbox
{
  // Redefinition global classes
  typedef mth::Vec3 GVec;
  typedef mth::Matr4x4 GMatr;
}

#endif // DEF_H
