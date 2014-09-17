/* Gravity newton box project.
 * Authors: tis-p30, kbsx32;
 * File purpose: Math functions implementation file.
 */

#include "mth.h"

/*
 *  Vector functions implementation
 */
using namespace mth;
// vector default constructor
Vec::Vec(TypeUse NewX, TypeUse NewY, TypeUse NewZ) :
  X(NewX), Y(NewY), Z(NewZ)
{
  ;
}

// Vector copying constructor
Vec::Vec(Vec &SrcVec) :
  X(SrcVec.X), Y(SrcVec.Y), Z(SrcVec.Z)
{
  ;
}

Vec Vec::operator+ (Vec& other)
{
  Vec v(X + other.X, Y + other.Y, Z + other.Z);
  return v;
}

void test()
{
  Vec v(1,1,1);
}
