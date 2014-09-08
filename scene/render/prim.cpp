/* Gravity newton box project.
 * Authors: kbsx32;
 * File purpose: Render primitive class implementation file.
 */

#include "prim.h"

// Primitive destructor
gbox::Prim::~Prim()
{
  for (std::vector<Vertex *>::iterator It = vertarr.begin(); It != vertarr.end(); ++It)
    delete *It;
}

// Vertex default constructor
gbox::Prim::Vertex::Vertex(const gbox::GVec &NewPos, const gbox::GVec &NewColor) :
  pos(NewPos), color(NewColor)
{
}

// Copying constructor
gbox::Prim::Vertex::Vertex(const gbox::Prim::Vertex &SrcVert) :
  pos(SrcVert.pos), color(SrcVert.color)
{
}

// Adding new vertex to primitive function
gbox::Prim & gbox::Prim::addVertex(gbox::Prim::Vertex *NewVert)
{
  vertarr.push_back(NewVert);
  return *this;
}

// Drawing primitive function
void gbox::Prim::render()
{
  // global example
  // glColor3d(color[0],);
  glBegin(GL_TRIANGLE_STRIP);
  for (std::vector<Vertex *>::iterator It = vertarr.begin(); It != vertarr.end(); ++It)
  {
    glColor3d((*It)->color[0], (*It)->color[1], (*It)->color[2]);
    glVertex3d((*It)->pos[0], (*It)->pos[1], (*It)->pos[2]);
  }
  glEnd();
}

