/* Gravity newton box project.
 * File purpose: Units Simple.
 *               Triangle header.
 * Authors: Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
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
      Prim unitPrim;
    public:
      // Default triangle constructor
      Triangle(const GVec &NewPnt0, const GVec &NewPnt1, const GVec &NewPnt2);
      // Default destructor
      ~Triangle();

      // Revirtualizing Unit default functions
      void render(Scene &SrcSc);
    };
  }
}

#endif // TRIANGLE_H
