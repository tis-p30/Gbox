/* Gravity newton box project.
 * Authors: kbsx32;
 * File purpose: Render primitive class implementation file.
 */

#include "prim.h"


/*
 * Material functions implementation
 */

gbox::Prim::Mtl gbox::Prim::Mtl::MtlDef(gbox::GVec(1.0, 1.0, 1.0)); // Default material

// Default constructor
gbox::Prim::Mtl::Mtl(gbox::GVec NewColor) :
  color(NewColor)
{
}

// Copying contructor
gbox::Prim::Mtl::Mtl(const gbox::Prim::Mtl &SrcMtl) :
  color(SrcMtl.color)
{
}

// Getting material color function
gbox::GVec gbox::Prim::Mtl::GetColor()
{
  return color;
}

/*
 * Vertexes functions
 */

// Vertex default constructor
gbox::Prim::Vertex::Vertex(const gbox::GVec &NewPos) :
  pos(NewPos), mtl(gbox::Prim::Mtl::MtlDef)
{
}

// Copying constructor
gbox::Prim::Vertex::Vertex(const gbox::Prim::Vertex &SrcVert) :
  pos(SrcVert.pos), mtl(SrcVert.mtl)
{
}

// Adding new vertex to primitive function
gbox::Prim & gbox::Prim::addVertex(gbox::Prim::Vertex *NewVert)
{
  vertarr.push_back(NewVert);
  return *this;
}


/*
 * Primitive functions
 */

// Primitive destructor
gbox::Prim::~Prim()
{
  for (std::vector<Vertex *>::iterator It = vertarr.begin(); It != vertarr.end(); ++It)
    delete *It;
}

// Drawing primitive function
void gbox::Prim::render()
{
  // global example
  // glColor3d(color[0],);
  glBegin(GL_TRIANGLE_STRIP);
  for (std::vector<Vertex *>::iterator It = vertarr.begin(); It != vertarr.end(); ++It)
  {
    GVec Col = (*It)->mtl.GetColor();
    glColor3dv(&Col[0]);
    glVertex3dv(&((*It)->pos[0]));
    // glColor3dv(&Col[0]), (*It)->color[1], (*It)->color[2]);
    // glVertex3d((*It)->pos[0], (*It)->pos[1], (*It)->pos[2]);
  }
  glEnd();
}

