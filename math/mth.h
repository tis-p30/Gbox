/* Gravity newton box project.
 * Authors: tis-p30, kbsx32;
 * File purpose: Math functions header.
 */

#pragma once

#ifndef MTH_H
#define MTH_H

#include <cmath>

// Redifinition main types
typedef float FLT;
typedef double DBL;

// Setting default type
typedef double TypeUse;

namespace mth
{
  // math pi constant
  const TypeUse pi = 3.1415;

  // Vector class
  class Vec
  {
  private:
    TypeUse X, Y, Z;
  public:
    // Default constructor by one number
    Vec(TypeUse NewCoord = 0);
    // constructor by 3-coords
    Vec(TypeUse NewX, TypeUse NewY, TypeUse NewZ);

    // Copying constructor
    Vec(const Vec &SrcVec);
    // Getting vector coords
    TypeUse operator[](int Ind) const;
    // Getting vector coords reference
    TypeUse &operator[](int Ind);

    // Vec + Vec function
    Vec operator+(const Vec &Vec1) const;
    // Vec - Vec function
    Vec operator-(const Vec &Vec1) const;

    // Vec += Vec function
    Vec &operator+=(const Vec &Vec1);

    // Vec * Num function
    Vec operator*(const TypeUse &Num) const;

    // Vector mult of Vecs function
    Vec operator%(const Vec &SrcVec) const;

    // Vector rotate By axis-X function
    Vec RotateByX(const TypeUse AngX);
    // Vector rotate By axis-Y function
    Vec RotateByY(const TypeUse AngX);
    // Vector rotate By axis-Z function
    Vec RotateByZ(const TypeUse AngX);

    // Getting vector length
    TypeUse Length();

    // Normilize current vector
    Vec &SetNormalize();
    // Get normalized vector
    Vec GetNormalized() const;
  }; // End of 'Vec' class
}

#endif // MTH_H
