/* Gravity newton box project.
 * File purpose: Math.
 *               Vectors header.
 * Authors: Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */

#pragma once
#ifndef GBOX_VEC_H
#define GBOX_VEC_H

#include "mthdef.h"

namespace mth
{
  // Vector class
  class Vec3
  {
  private:
    TypeUse X, Y, Z;
  public:
    // Default constructor by one number
    Vec3(TypeUse NewCoord = 0);
    // constructor by 3-coords
    Vec3(TypeUse NewX, TypeUse NewY, TypeUse NewZ = 0);

    // Copying constructor
    Vec3(const Vec3 &SrcVec);
    // Getting vector coords
    TypeUse operator[](int Ind) const;
    // Getting vector coords reference
    TypeUse & operator[](int Ind);


    // -Vec3 function
    Vec3 operator-() const;

    // Vec3 + Vec3 function
    Vec3 operator+(const Vec3 &Vec1) const;
    // Vec3 - Vec3 function
    Vec3 operator-(const Vec3 &Vec1) const;

    // Vec3 += Vec3 function
    Vec3 &operator+=(const Vec3 &Vec1);

    // Vec3 * Num function
    Vec3 operator*(const TypeUse &Num) const;

    // Vector mult of Vecs function
    Vec3 operator%(const Vec3 &SrcVec) const;

    // Vector rotate By axis-X function
    Vec3 rotateByX(const TypeUse AngX) const;
    // Vector rotate By axis-Y function
    Vec3 rotateByY(const TypeUse AngX) const;
    // Vector rotate By axis-Z function
    Vec3 rotateByZ(const TypeUse AngX) const;

    // Getting vector length
    TypeUse length() const;

    // Normilize current vector
    Vec3 &setNormalize();
    // Get normalized vector
    Vec3 getNormalized() const;
  }; // End of 'Vec3' class

  // Count length between two points
  TypeUse length(const Vec3 &Pnt0, const Vec3 &Pnt1);
} // End of 'mth' namespace

#endif // GBOX_VEC_H
