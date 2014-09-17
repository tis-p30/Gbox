/* Gravity newton box project.
 * Authors: kbsx32;
 * File purpose: Simple units:
 *               Triangle implementation.
 */

#include "triangle.h"

// Default triangle constructor
gbox::units::Triangle::Triangle(const GVec &NewPnt0, const GVec &NewPnt1, const GVec &NewPnt2)
{
  unitPrim.addVertex(new Prim::Vertex(NewPnt0));
  unitPrim.addVertex(new Prim::Vertex(NewPnt1));
  unitPrim.addVertex(new Prim::Vertex(NewPnt2));
}

// Default destructor
gbox::units::Triangle::~Triangle()
{
}

// Revirtualizing Unit default function drawing
void gbox::units::Triangle::render()
{
  unitPrim.render();
}

