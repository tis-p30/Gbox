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

  // Predeclaration class matrix
  class Matr;

  // Vector class
  class Vec3
  {
  private:
    TypeUse X, Y, Z;
  public:
    // Default constructor by one number
    Vec3(TypeUse NewCoord = 0);
    // constructor by 3-coords
    Vec3(TypeUse NewX, TypeUse NewY, TypeUse NewZ);

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

  class Matr4x4
  {
  private:
    TypeUse
      Ar[4][4];    // Matrix array
  public:
    // Default constructor
    Matr4x4(const TypeUse A00 = 1, const TypeUse A01 = 0, const TypeUse A02 = 0, const TypeUse A03 = 0,
            const TypeUse A10 = 0, const TypeUse A11 = 1, const TypeUse A12 = 0, const TypeUse A13 = 0,
            const TypeUse A20 = 0, const TypeUse A21 = 0, const TypeUse A22 = 1, const TypeUse A23 = 0,
            const TypeUse A30 = 0, const TypeUse A31 = 0, const TypeUse A32 = 0, const TypeUse A33 = 1);
    // Constructor by array
    Matr4x4(const TypeUse *NewAr);
    // Constructor by vectors
    Matr4x4(const Vec3 &V0, const Vec3 &V1, const Vec3 &V2);
    // Copying constructor
    Matr4x4(const Matr4x4 &SrcMatr);

    // Getting array member function
    TypeUse * operator[](int Index);
    // Getting array member const function
    const TypeUse * operator[](int Index) const;

    // Matr0(this) * Matr1 function
    Matr4x4 operator*(const Matr4x4 &Matr1) const;
    // Matr * Num function
    Matr4x4 operator*(const TypeUse Num) const;
    // Vec3(4) * Matr function
    Vec3 operator*(const Vec3 &SrcVec) const;

    // rotate matrix by axis-x
    static Matr4x4 rotateX(const TypeUse Angle);
    // rotate matrix by axis-y
    static Matr4x4 rotateY(const TypeUse Angle);
    // rotate matrix by axis-z
    static Matr4x4 rotateZ(const TypeUse Angle);

    // Getting matrix 3x3 determinator function
    static TypeUse matr3x3Determ(const TypeUse Ar00, const TypeUse Ar01, const TypeUse Ar02,
                                 const TypeUse Ar10, const TypeUse Ar11, const TypeUse Ar12,
                                 const TypeUse Ar20, const TypeUse Ar21, const TypeUse Ar22);
    // Getting matrix 4x4 determinator function
    TypeUse determ() const;

    // Getting transposed matrix
    Matr4x4 transpose() const;
  }; // End of 'matr4x4' class
}

#endif // MTH_H
