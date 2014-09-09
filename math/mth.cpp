/* Gravity newton box project.
 * Authors: tis-p30, kbsx32;
 * File purpose: Math functions implementation file.
 */

#include "mth.h"

/*
 *  Vector functions implementation
 */

// vector default constructor
mth::Vec::Vec(TypeUse NewX, TypeUse NewY, TypeUse NewZ) :
  X(NewX), Y(NewY), Z(NewZ)
{
  ;
}

// Vector copying constructor
mth::Vec::Vec(const Vec &SrcVec) :
  X(SrcVec.X), Y(SrcVec.Y), Z(SrcVec.Z)
{
  ;
}


// Getting vector coords function
TypeUse mth::Vec::operator[](int Ind) const
{
  return *(&X + Ind);
}

// Vec + Vec function
mth::Vec mth::Vec::operator+ (const Vec &Vec1) const
{
  return Vec(X + Vec1[0], Y + Vec1[1], Z + Vec1[2]);
}

// Vec * Num function
mth::Vec mth::Vec::operator* (const TypeUse &Num) const
{
  return Vec(X * Num, Y * Num, Z * Num);
}

