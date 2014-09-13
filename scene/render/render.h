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

#include "camera.h"

// Including primitives
namespace gbox
{
  // Rendering scene class
  class Render : public QGLWidget, QGLFunctions,
                 public Camera
  {
  private:
    // OpenGL revirtualize functions:
    void initializeGL();
    virtual void paintGL();
    void resizeGL(int w, int h);

  public:
    // Default constructor
    explicit Render(QWidget *WidgParent = 0);
    // class destructor
    ~Render();

    // rendering function for higher level
    virtual void render() = 0;
  }; // end of 'render' class
} // end of 'gbox' namespace
#endif // RENDER_H
