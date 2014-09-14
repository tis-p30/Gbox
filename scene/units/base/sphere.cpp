/* Gravity newton box project.
 * Authors: kbsx32;
 * File purpose: Simple units:
 *               Triangle implementation.
 */

#include <vector>
#include <cstdlib>
#include <cmath>
#include "sphere.h"

// Default triangle constructor
gbox::units::Sphere::Sphere(const GVec &NewPos, const TypeUse NewRad, const int NewPntCnt)
{
  int x, y;

  std::vector<Prim::Vertex> ArrVert= std::vector<Prim::Vertex>(NewPntCnt * NewPntCnt);

  for (x = 0; x < NewPntCnt; x++)
    for (y = 0; y < NewPntCnt; y++)
      {
        TypeUse
          alpha = x / (NewPntCnt - 1.0) * mth::pi,
          beta = y / (NewPntCnt - 1.0) * 2 * mth::pi;
        gbox::GVec Norm = gbox::GVec(sin(alpha) * sin(beta),
                                     cos(alpha),
                                     sin(alpha) * cos(beta));
        ArrVert[y * NewPntCnt + x] = Prim::Vertex(NewPos + Norm * NewRad);
      }

  for (x = 0; x < NewPntCnt - 1; x++)
    for (y = 0; y < NewPntCnt - 1; y++)
    {
      unitPrim.addVertex(new Prim::Vertex(ArrVert[(y * NewPntCnt + x)]));
      unitPrim.addVertex(new Prim::Vertex(ArrVert[(y * NewPntCnt + x + 1)]));
      unitPrim.addVertex(new Prim::Vertex(ArrVert[((y + 1) * NewPntCnt + x)]));

      unitPrim.addVertex(new Prim::Vertex(ArrVert[(y * NewPntCnt + x + 1)]));
      unitPrim.addVertex(new Prim::Vertex(ArrVert[((y + 1) * NewPntCnt + x + 1)]));
      unitPrim.addVertex(new Prim::Vertex(ArrVert[((y + 1) * NewPntCnt + x)]));
    }
}

// Default destructor
gbox::units::Sphere::~Sphere()
{
}

// Revirtualizing Unit default functions
void gbox::units::Sphere::render(Scene &SrcSc)
{
  unitPrim.render();
}

