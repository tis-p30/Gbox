/* Gravity newton box project.
 * File purpose: Units Simple.
 *               Sphere header.
 * Authors: Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */

#pragma once
#ifndef SPHERE_H
#define SPHERE_H

#include "../../scene.h"

namespace gbox
{
  namespace units
  {
    class Sphere : public Scene::UnitDef
    {
    private:
      Prim unitPrim;
    public:
      // Default triangle constructor
      Sphere(const GVec &NewPos, const TypeUse NewRad = 1, const int NewPntCnt = 16);
      // Default destructor
      ~Sphere();

      // Revirtualizing Unit default functions
      void render(Scene &SrcSc);
    };
  }
}

#endif // SPHERE_H
