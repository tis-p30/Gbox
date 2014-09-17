/* Gravity newton box project.
 * Authors: tis-p30, kbsx32;
 * File purpose: General math header.
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

  // Vector class
  class Vec
  {
  private:
    TypeUse X, Y, Z;
  public:
    // Default constructor
    Vec(TypeUse NewX = 0, TypeUse NewY = 0, TypeUse NewZ = 0);
    // Copying constructor
    Vec(Vec &SrcVec);
    ~Vec() {;}

    Vec operator+ (Vec& other);
    Vec operator* (TypeUse number);
    Vec operator& (const Vec& other);
    Vec operator% (const Vec& other);


    inline TypeUse getXCoord() {return this->X;}
    inline TypeUse getYCoord() {return this->Y;}
    inline TypeUse getZCoord() {return this->Z;}

   };
  //TypeUse euler(Vec& accel, Vec position, Vec  );
  //TypeUse rk(TypeUse& accel, TypeUse x);

 }

#endif // MTH_H
