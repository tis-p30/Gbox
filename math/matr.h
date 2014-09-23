/* Gravity newton box project.
 * File purpose: Math.
 *               Matrix header.
 * Authors: Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */

#pragma once
#ifndef GBOX_MATR_H
#define GBOX_MATR_H

#include "mthdef.h"
#include "vec.h"

namespace mth
{
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
} // End of 'mth' namespace

#endif // GBOX_MATR_H
