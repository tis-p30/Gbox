/* Gravity newton box project.
 * Authors: kbsx32;
 * File purpose: Simple units:
 *               Sphere header.
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
      Sphere(const GVec &NewPos, const TypeUse NewRad, const int NewPntCnt,
             const GVec &NewCol = GVec(1.0, 1.0, 1.0));
      // Default destructor
      ~Sphere();

      // Revirtualizing Unit default functions
      void render();
    };
  }
}
#endif // SPHERE_H
