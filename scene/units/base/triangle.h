/* Gravity newton box project.
 * Authors: kbsx32;
 * File purpose: Simple units:
 *               Triangle header.
 */

#pragma once
#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "../../scene.h"

namespace gbox
{
  namespace units
  {
    class Triangle : public Scene::UnitDef
    {
    private:
      // GVec Pnt0, Pnt1, Pnt2;
      Prim unitPrim;
    public:
      // Default triangle constructor
      Triangle(const GVec &NewPnt0, const GVec &NewPnt1, const GVec &NewPnt2);
      // Default destructor
      ~Triangle();

      // Revirtualizing Unit default functions
      void render();
    };
  }
}
#endif // TRIANGLE_H
