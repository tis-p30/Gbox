/* Gravity newton box project.
 * File purpose: Render functions implementation.
 * Authors: Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
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

  glEnable(GL_DEPTH_TEST);
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
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();

  render();
  swapBuffers();
}

// rendering default text function
void gbox::Render::renderTextDef(const DBL PosX, const DBL PosY, const QString QStr)
{
  renderText(PosX, PosY, QStr, QFont("Arial", 10));
}
