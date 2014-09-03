/* Gravity newton box project.
 * Authors: kbsx32;
 * File purpose: Render functions implementation file.
 */

#include "render.h"

// render class constructor
gbox::render::render(QWidget *Parent) : QGLWidget(Parent)
{
}

// revirtualized init OpenGL function
void gbox::render::initializeGL()
{
  initializeGLFunctions();
  glClearColor(0.3, 0.5, 0.7, 1);

  glEnable(GL_CULL_FACE);
  // updateGL();
  paintGL();
}

// revirtualized paint OpenGL function
void gbox::render::paintGL()
{
  glClear(GL_COLOR_BUFFER_BIT);

  glBegin(GL_TRIANGLES);
    glVertex2d(0.3, 0.3);
    glVertex2d(0.5, 0.3);
    glVertex2d(0.3, 0.5);
  glEnd();
  swapBuffers();
}

