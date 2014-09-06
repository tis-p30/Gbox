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
gbox::render::render(QWidget *Parent) : QGLWidget(Parent)
{
}

// default render destructor
gbox::render::~render()
{
}

// revirtualized init OpenGL function
void gbox::render::initializeGL()
{
  initializeGLFunctions();
  glClearColor(0.3, 0.5, 0.7, 1);

  glEnable(GL_CULL_FACE);
}

// revirualized resizing GL function
void gbox::render::resizeGL(int w, int h)
{
  glPixelZoom(1, -1);
  glViewport(0, 0, w, h);

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f, GLdouble(this->width() / this->height()), 0.1f, 100.0f);
  glMatrixMode(GL_MODELVIEW);
}

// revirtualized paint OpenGL function
void gbox::render::paintGL()
{
  static double x = 0.3;
  glClear(GL_COLOR_BUFFER_BIT);

  glLoadIdentity();
  gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);

  glRotatef(x += 0.3, 0, 1.0, 0);
  glBegin(GL_LINES);
    glColor3d(1, 0, 0);
    glVertex3d(0, 0, 0);
    glVertex3d(5, 0, 0);

    glColor3d(0, 1, 0);
    glVertex3d(0, 0, 0);
    glVertex3d(0, 5, 0);

    glColor3d(0, 0, 1);
    glVertex3d(0, 0, 0);
    glVertex3d(0, 0, 5);
  glEnd();

  // Drawing some cube lines. Not all because i want to sleep
  glBegin(GL_LINES);
    glVertex3d(-1, -1, -1);
    glVertex3d(-1, -1, 1);
    glVertex3d(1, -1, 1);
    glVertex3d(1, -1, -1);

    glVertex3d(-1, 1, -1);
    glVertex3d(-1, 1, 1);
    glVertex3d(1, 1, 1);
    glVertex3d(1, 1, -1);
  glEnd();

  swapBuffers();
}
