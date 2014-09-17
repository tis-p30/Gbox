/* Newton gravity box project
 *
 * Authors: Tikhonenko Iliya <iliya.t@mail.ru>
 *
 * Numerical integration functions implementation
 */

#include "mth.h"
#include "numint.h"

template<class T>
T mth::euler(T& deriv, T arg,
                   T value0, TypeUse step)
{
  return value0 + deriv(arg)*step;
}

template<class T>
T mth::rk(T& deriv, T arg,
                   T value0, TypeUse step)
{
  T k1 = deriv(arg, value0);
  T k2 = deriv(arg + step*0.5, value0 + step*0.5*k1);
  T k3 = deriv(arg + step*0.5, value0 + step*0.5*k2);
  T k4 = deriv(arg + step, value0 + step*k3);
  return value0 + (k1 + k2 + k3 + k4)*step/6;
}
