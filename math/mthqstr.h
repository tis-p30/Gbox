/* Gravity newton box project.
 * File purpose: Math QString showing implementation file.
 * Authors: Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */

#ifndef MTHQSTR_H
#define MTHQSTR_H

#include <QString>
#include "mth.h"

namespace mth
{
  // overloading QString double number function
  QString operator+(const QString &QStr, const DBL Number);
  // overloading QString int number function
  QString operator+(const QString &QStr, const int Number);

  // overloading QString math vector 3 function
  QString operator+(const QString &QStr, const mth::Vec3 &SrcVec);
}

#endif // MTHQSTR_H
