/* Gravity newton box project.
 * File purpose: Math header file.
 * Authors: Tikhonenko Iliya (tis-p30) <iliya.t@mail.ru>,
 *          Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */

#pragma once

#ifndef GBOX_MTH_H
#define GBOX_MTH_H

#include <cstdlib>
#include <cmath>
#include <QString>

#include "mthdef.h"

#include "vec.h"
#include "matr.h"

#include "numint.h"

namespace mth
{
  // math pi constant
  const TypeUse pi = 3.1415;

  // Getting random number function
  template<typename Type>
    Type random(Type NumLeft, Type NumRight)
    {
      return (Type)rand() / RAND_MAX * (NumRight - NumLeft) + NumLeft;
    }
}

#endif // GBOX_MTH_H
