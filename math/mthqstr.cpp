/* Gravity newton box project.
 * File purpose: Math QString showing implementation file.
 * Authors: Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */

#include "mthqstr.h"

// overloading QString double number function
QString mth::operator+(const QString &QStr, const DBL Number)
{
  return QStr + QString::number(Number, 'g', 3);
}

// overloading QString int number function
QString mth::operator+(const QString &QStr, const int Number)
{
  return QStr + QString::number(Number);
}

// overloading QString math vector 3 function
QString mth::operator+(const QString &QStr, const mth::Vec3 &SrcVec)
{
  return QStr + "(" + SrcVec[0] + "; " + SrcVec[1] + "; " + SrcVec[2] + ")";
}
