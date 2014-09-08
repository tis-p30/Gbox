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
mth::Vec::Vec(Vec &SrcVec) :
  X(SrcVec.X), Y(SrcVec.Y), Z(SrcVec.Z)
{
  ;
}

