/* Gravity newton box project.
 * Authors: kbsx32;
 * File purpose: Render functions implementation file.
 */

#include <QTime>
#include <cmath>
#include <cstdlib>
#include <GL/glu.h>

#include "render.h"

// render class constructor
gbox::Render::Render(QWidget *WidgParent) : QGLWidget(WidgParent)
{
}

// default render destructor
gbox::Render::~Render()
{
}

// revirtualized init OpenGL function
void gbox::Render::initializeGL()
{
  initializeGLFunctions();
  glClearColor(0.3, 0.5, 0.7, 1);

  // glEnable(GL_CULL_FACE);
}

// revirualized resizing GL function
void gbox::Render::resizeGL(int w, int h)
{
  glPixelZoom(1, -1);
  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, GLdouble(this->width() / this->height()), 0.1f, 100.0f);
  glMatrixMode(GL_MODELVIEW);
}

// revirtualized paint OpenGL function
void gbox::Render::paintGL()
{
  static double x = 0.3;
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);
  glRotatef(x += 2, 0, 1.0, 0);

  render();
  swapBuffers();
}
