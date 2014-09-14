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
    TypeUse & operator[](int Ind);

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
    Vec rotateByX(const TypeUse AngX) const;
    // Vector rotate By axis-Y function
    Vec rotateByY(const TypeUse AngX) const;
    // Vector rotate By axis-Z function
    Vec rotateByZ(const TypeUse AngX) const;

    // Getting vector length
    TypeUse length() const;

    // Normilize current vector
    Vec &setNormalize();
    // Get normalized vector
    Vec getNormalized() const;
  }; // End of 'Vec' class

  class Matr4x4
  {
  private:
    TypeUse Ar[4][4];
  public:
    // Default constructor
    Matr4x4(const TypeUse A00 = 1, const TypeUse A01 = 0, const TypeUse A02 = 0, const TypeUse A03 = 0,
            const TypeUse A10 = 0, const TypeUse A11 = 1, const TypeUse A12 = 0, const TypeUse A13 = 0,
            const TypeUse A20 = 0, const TypeUse A21 = 0, const TypeUse A22 = 1, const TypeUse A23 = 0,
            const TypeUse A30 = 0, const TypeUse A31 = 0, const TypeUse A32 = 0, const TypeUse A33 = 1);
    // Constructor by array
    Matr4x4(const TypeUse *Ar);
    // Constructor by vectors
    Matr4x4(const Vec &V0, const Vec &V1, const Vec &V2);
    // Copying constructor
    Matr4x4(const Matr4x4 &SrcMatr);

    // Getting array member function
    TypeUse * operator[](int Index);
    // Matr0(this) * Matr1 function
    Matr4x4 operator*(const Matr4x4 &Matr1);
  }; // End of 'matr4x4' class
}

#endif // MTH_H
