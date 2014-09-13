/* Gravity newton box project.
 * Authors: kbsx32;
 * File purpose: Render primitive class header.
 */

#pragma once
#ifndef PRIM_H
#define PRIM_H

#include <vector>

#include <QGLWidget>
#include <QGLFunctions>

#include "../../def.h"
#include "render.h"

namespace gbox
{
  // primitive header
  class Prim
  {
  public:
    // Vertex class declaration
    class Vertex
    {
    public:
      gbox::GVec
        pos,       // Vertex position
        color;     // Vertex color

      // Default constructor
      Vertex(const GVec &NewPos = GVec(), const GVec &NewColor = GVec());
      // Copying constructor
      Vertex(const Vertex &SrcVert);
    };
  private:
    // Array of vertexes
    std::vector<Vertex *> vertarr;
   public:
    // Primitive destructor
    ~Prim();
    // Adding new vertex to primitive function
    Prim & addVertex(Vertex *NewVert);

    // Drawing primitive function
    void render();
  };
}
#endif // PRIM_H
