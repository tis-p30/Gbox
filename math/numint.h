#ifndef NUMINT_H
#define NUMINT_H
/* Newton gravity box project
 *
 * Authors: Tikhonenko Iliya <iliya.t@mail.ru>
 *
 * Numerical integration functions implementation
 */


#include "mth.h"

namespace mth
{
//this functions return next value of function,
//using current 'arg'

//simple numerical integration
  template<class T>
  T euler(T& deriv, T arg,
                T value0, TypeUse step);

//advanced numerical integration
  template<class T>
  T rk(T& deriv, T arg,
                T value0, TypeUse step);
/*
expected syntax like:
accel(r) = -1/r^2
euler<Vec,Point>(accel, accel_cur, vel0, 0.001);
*/
}
#endif // NUMINT_H
