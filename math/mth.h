/* Gravity newton box project.
 * Authors: tis-p30, kbsx32;
 * File purpose: Math functions header.
 */

#pragma once

#ifndef MTH_H
#define MTH_H

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
    // Default constructor
    Vec(TypeUse NewX = 0, TypeUse NewY = 0, TypeUse NewZ = 0);
    // Copying constructor
    Vec(const Vec &SrcVec);
    // Getting vector coords
    TypeUse operator[](int Ind) const;
    // Vec + Vec function
    Vec operator+ (const Vec &SrcVec) const;
    // Vec * Num function
    Vec operator* (const TypeUse &Num) const;
  };
}

#endif // MTH_H
