/* Gravity newton box project.
 * File purpose: Math.
 *               Vectors functions implementation file.
 * Authors: Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */

#include "vec.h"

// vector default constructor
mth::Vec3::Vec3(TypeUse NewX, TypeUse NewY, TypeUse NewZ) :
  X(NewX), Y(NewY), Z(NewZ)
{
}

// Default constructor by one number
mth::Vec3::Vec3(TypeUse NewCoord) :
  X(NewCoord), Y(NewCoord), Z(NewCoord)
{
}

// Vector copying constructor
mth::Vec3::Vec3(const Vec3 &SrcVec) :
  X(SrcVec.X), Y(SrcVec.Y), Z(SrcVec.Z)
{
}

// Getting vector coords function
TypeUse mth::Vec3::operator[](int Ind) const
{
  return *(&X + Ind);
}

// Getting vector coords function reference
TypeUse &mth::Vec3::operator[](int Ind)
{
  return *(&X + Ind);
}

// -Vec function
mth::Vec3 mth::Vec3::operator-() const
{
  return Vec3(-X, -Y, -Z);
}

// Vec + Vec function
mth::Vec3 mth::Vec3::operator+(const mth::Vec3 &Vec1) const
{
  return Vec3(X + Vec1[0], Y + Vec1[1], Z + Vec1[2]);
}

// Vec += Vec function
mth::Vec3 & mth::Vec3::operator+=(const mth::Vec3 &Vec1)
{
  X += Vec1[0];
  Y += Vec1[1];
  Z += Vec1[2];
  return *this;
}

// Vec - Vec function
mth::Vec3 mth::Vec3::operator-(const mth::Vec3 &Vec1) const
{
  return Vec3(X - Vec1[0], Y - Vec1[1], Z - Vec1[2]);
}

// Vec * Num function
mth::Vec3 mth::Vec3::operator*(const TypeUse &Num) const
{
  return Vec3(X * Num, Y * Num, Z * Num);
}

// Vector mult of Vecs function
mth::Vec3 mth::Vec3::operator%(const mth::Vec3 &Vec1) const
{
  return Vec3(Y * Vec1[2] - Z * Vec1[1],
              Z * Vec1[0] - X * Vec1[2],
              X * Vec1[1] - Y * Vec1[0]);
}

// Getting vector length
TypeUse mth::Vec3::length() const
{
  TypeUse Len = X * X + Y * Y + Z * Z;
  if (Len != 0 && Len != 1)
    return sqrt(Len);
  return Len;
}

// Normilize current vector
mth::Vec3 & mth::Vec3::setNormalize()
{
  TypeUse LenSqr = X * X + Y * Y + Z * Z;
  if (LenSqr != 0 && LenSqr != 1)
  {
    TypeUse Len = sqrt(LenSqr);
    X = X / Len;
    Y = Y / Len;
    Z = Z / Len;
  }
  return *this;
}

// Get normalized vector
mth::Vec3 mth::Vec3::getNormalized() const
{
  TypeUse LenSqr = X * X + Y * Y + Z * Z;
  if (LenSqr != 0 && LenSqr != 1)
  {
    TypeUse Len = sqrt(LenSqr);
    return mth::Vec3(X / Len, Y / Len, Z / Len);
  }

  return mth::Vec3(X, Y, Z);
}

// Vector rotate By axis-X function
mth::Vec3 mth::Vec3::rotateByX(const TypeUse AngX) const
{
  TypeUse cosa = cos(AngX), sina = sin(AngX);

  return Vec3(X,
             Y * cosa - Z * sina,
             Y * sina + Z * cosa);
}

// Vector rotate By axis-Y function
mth::Vec3 mth::Vec3::rotateByY(const TypeUse AngX) const
{
  TypeUse cosa = cos(AngX), sina = sin(AngX);

  return Vec3(X * cosa + Z * sina,
              Y,
              Z * cosa - X * sina);
}

// Vector rotate By axis-Z function
mth::Vec3 mth::Vec3::rotateByZ(const TypeUse AngX) const
{
  TypeUse cosa = cos(AngX), sina = sin(AngX);

  return Vec3(X * cosa - Y * sina,
              X * sina + Y * cosa,
              Z);
}

// Count length between two points
TypeUse mth::length(const mth::Vec3 &Pnt0, const mth::Vec3 &Pnt1)
{
  return sqrt(pow(Pnt1[0] - Pnt0[0], 2) +
              pow(Pnt1[1] - Pnt0[1], 2) +
              pow(Pnt1[2] - Pnt0[2], 2));
}
