/* Gravity newton box project.
 * Authors: tis-p30, kbsx32;
 * File purpose: Math matrix functions implementation file.
 */

#include <cstring>

#include "mth.h"

// Default constructor
mth::Matr4x4::Matr4x4(
    const TypeUse A00, const TypeUse A01, const TypeUse A02, const TypeUse A03,
    const TypeUse A10, const TypeUse A11, const TypeUse A12, const TypeUse A13,
    const TypeUse A20, const TypeUse A21, const TypeUse A22, const TypeUse A23,
    const TypeUse A30, const TypeUse A31, const TypeUse A32, const TypeUse A33)
{
  (*this)[0][0] = A00; (*this)[0][1] = A01; (*this)[0][2] = A02; (*this)[0][3] = A03;
  (*this)[1][0] = A10; (*this)[1][1] = A11; (*this)[1][2] = A12; (*this)[1][3] = A13;
  (*this)[2][0] = A20; (*this)[2][1] = A21; (*this)[2][2] = A22; (*this)[2][3] = A23;
  (*this)[3][0] = A30; (*this)[3][1] = A31; (*this)[3][2] = A32; (*this)[3][3] = A33;
}

// Constructor by array
mth::Matr4x4::Matr4x4(const TypeUse *NewAr)
{
  for (int y = 0; y < 4; y++)
    for (int x = 0; x < 4; x++)
      Ar[y][x] = NewAr[y * 4 + x];
}

// Constructor by vectors
mth::Matr4x4::Matr4x4(const mth::Vec3 &V0, const mth::Vec3 &V1, const mth::Vec3 &V2)
{
  const mth::Vec3 *VAr[3] = {&V0, &V1, &V2};
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      Ar[i][j] = (*VAr[i])[j];

  Ar[0][3] = Ar[1][3] = Ar[2][3] = 0;
  Ar[3][3] = 1;
}

// Copying constructor
mth::Matr4x4::Matr4x4(const Matr4x4 &SrcMatr)
{
  for (int y = 0; y < 4; y++)
    for (int x = 0; x < 4; x++)
      Ar[y][x] = SrcMatr.Ar[y][x];
}

// Getting array member function
TypeUse * mth::Matr4x4::operator[](int Index)
{
  return &Ar[Index][0];
}

// Getting array member function
const TypeUse * mth::Matr4x4::operator[](int Index) const
{
  return Ar[Index];
}

// Matr0(this) * Matr1 function
mth::Matr4x4 mth::Matr4x4::operator*(const mth::Matr4x4 &Matr1) const
{
  Matr4x4 MatrRes(0, 0, 0, 0,
                  0, 0, 0, 0,
                  0, 0, 0, 0,
                  0, 0, 0, 0);
  for (int y = 0; y < 4; y++)
    for (int x = 0; x < 4; x++) // Choose current matrix slot
      for (int k = 0; k < 4; k++) // Count mult for current slot
        MatrRes[y][x] += Ar[y][k] * Matr1[k][x];

  return MatrRes;
}

// rotate matrix by axis-x
mth::Matr4x4 mth::Matr4x4::rotateX(const TypeUse Angle)
{
  TypeUse sina = sin(Angle), cosa = cos(Angle);
  return Matr4x4(    1,     0,     0,     0,
                     0,  cosa, -sina,     0,
                     0,  sina,  cosa,     0,
                     0,     0,     0,     1);
}

// rotate matrix by axis-y
mth::Matr4x4 mth::Matr4x4::rotateY(const TypeUse Angle)
{
  TypeUse sina = sin(Angle), cosa = cos(Angle);
  return Matr4x4( cosa,     0,  sina,     0,
                     0,     1,     0,     0,
                 -sina,     0,  cosa,     0,
                     0,     0,     0,     1);
}

// rotate matrix by axis-z
mth::Matr4x4 mth::Matr4x4::rotateZ(const TypeUse Angle)
{
  TypeUse sina = sin(Angle), cosa = cos(Angle);
  return Matr4x4( cosa, -sina,     0,     0,
                  sina,  cosa,     0,     0,
                     0,     0,     1,     0,
                     0,     0,     0,     1);
}

// Vec3(4) * Matr function
mth::Vec3 mth::Matr4x4::operator*(const mth::Vec3 &SrcVec) const
{
  Vec3 ResVec(0, 0, 0);
  TypeUse Vc[] = {SrcVec[0], SrcVec[1], SrcVec[2], 1};
  for (int y = 0; y < 3; y++)
    for (int i = 0; i < 4; i++)
      ResVec[y] += Ar[y][i] * Vc[i];
  return ResVec;
}

// Matr * Num function
mth::Matr4x4 mth::Matr4x4::operator*(const TypeUse Num) const
{
  Matr4x4 MatrRes;
  for (int y = 0; y < 4; y++)
    for (int x = 0; x < 4; x++)
      MatrRes[y][x] = Ar[y][x] * Num;
  return MatrRes;
}

// Getting matrix 3x3 determinator function
TypeUse mth::Matr4x4::matr3x3Determ(const TypeUse Ar00, const TypeUse Ar01, const TypeUse Ar02,
                                    const TypeUse Ar10, const TypeUse Ar11, const TypeUse Ar12,
                                    const TypeUse Ar20, const TypeUse Ar21, const TypeUse Ar22)
{
  return Ar00 * (Ar11 * Ar22 - Ar12 * Ar21 ) -
         Ar01 * (Ar10 * Ar22 - Ar12 * Ar20 ) +
         Ar02 * (Ar10 * Ar21 - Ar11 * Ar20 );
}

// Getting matrix 4x4 determinator function
TypeUse mth::Matr4x4::determ() const
{
  return Ar[0][0] * matr3x3Determ(Ar[1][1], Ar[1][2], Ar[1][3],    // 1 colomumn
                                  Ar[2][1], Ar[2][2], Ar[2][3],
                                  Ar[3][1], Ar[3][2], Ar[3][3]) -
         Ar[0][0] * matr3x3Determ(Ar[1][0], Ar[1][2], Ar[1][3],    // 2 colomumn
                                  Ar[2][0], Ar[2][2], Ar[2][3],
                                  Ar[3][0], Ar[3][2], Ar[3][3]) +
         Ar[0][0] * matr3x3Determ(Ar[1][0], Ar[1][1], Ar[1][3],    // 3 colomumn
                                  Ar[2][0], Ar[2][1], Ar[2][3],
                                  Ar[3][0], Ar[3][1], Ar[3][3]) +
         Ar[0][0] * matr3x3Determ(Ar[1][0], Ar[1][1], Ar[1][2],    // 4 colomumn
                                  Ar[2][0], Ar[2][1], Ar[2][2],
                                  Ar[3][0], Ar[3][1], Ar[3][2]);
}

// Getting transposed matrix
mth::Matr4x4 mth::Matr4x4::transpose() const
{
  Matr4x4 MatrRes;
  for (int y = 0; y < 4; y++)
    for (int x = 0; x < 4; x++)
      MatrRes[y][x] = Ar[x][y];
  return MatrRes;
}

