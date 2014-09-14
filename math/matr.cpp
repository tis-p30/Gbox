/* Gravity newton box project.
 * Authors: tis-p30, kbsx32;
 * File purpose: Math matrix functions implementation file.
 */

#include "mth.h"

// Default constructor
mth::Matr4x4::Matr4x4(
    const TypeUse A00, const TypeUse A01, const TypeUse A02, const TypeUse A03,
    const TypeUse A10, const TypeUse A11, const TypeUse A12, const TypeUse A13,
    const TypeUse A20, const TypeUse A21, const TypeUse A22, const TypeUse A23,
    const TypeUse A30, const TypeUse A31, const TypeUse A32, const TypeUse A33)
{
}

// Constructor by array
mth::Matr4x4::Matr4x4(const TypeUse *Ar)
{
}

// Constructor by vectors
mth::Matr4x4::Matr4x4(const mth::Vec &V0, const mth::Vec &V1, const mth::Vec &V2)
{
  const mth::Vec *VAr[3] = {&V0, &V1, &V2};
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      Ar[i][j] = (*VAr[i])[j];

  Ar[0][3] = Ar[1][3] =
  Ar[2][3] = Ar[3][3] = 0;
}

// Copying constructor
mth::Matr4x4::Matr4x4(const mth::Matr4x4 &SrcMatr)
{
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++)
      Ar[i][j] = SrcMatr.Ar[i][j];
}

// Getting array member function
TypeUse *mth::Matr4x4::operator[](int Index)
{
  return &Ar[Index][0];
}

// Matr0(this) * Matr1 function
// Not released as you can see now
mth::Matr4x4 mth::Matr4x4::operator*(const mth::Matr4x4 &Matr1)
{
  return Matr4x4();
}



