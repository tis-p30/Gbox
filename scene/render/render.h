/* Gravity newton box project.
 * Authors: kbsx32;
 * File purpose: Render header.
 */

#pragma once
#ifndef RENDER_H
#define RENDER_H

#include <QGLWidget>
#include <QGLFunctions>
#include <GL/glu.h>

namespace gbox
{
  // Rendering scene class
  class render : public QGLWidget, QGLFunctions
  {
  private:
    // OpenGL revirtualize functions:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

  public:
    // Default constructor
    explicit render(QWidget *Parent = 0);
    // class destructor
    ~render();
  }; // end of 'render' class
} // end of 'gbox' namespace
#endif // RENDER_H
