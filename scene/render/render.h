/* Gravity newton box project.
 * File purpose: Render header.
 * Authors: Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */

#pragma once
#ifndef GBOX_RENDER_H
#define GBOX_RENDER_H

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
    // rendering default text function
    void renderTextDef(const DBL PosX, const DBL PosY, const QString QStr);
  }; // end of 'render' class
} // end of 'gbox' namespace

#endif // GBOX_RENDER_H
