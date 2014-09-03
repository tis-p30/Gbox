/* Gravity newton box project.
 * Authors: kbsx32;
 * File purpose: Render header.
 */

#pragma once
#ifndef RENDER_H
#define RENDER_H

#include <QGLWidget>
#include <QGLFunctions>

namespace gbox
{
  // Rendering scene class
  class render : public QGLWidget, QGLFunctions
  {
    Q_OBJECT
  private:
    // OpenGL revirtualize functions:
    void initializeGL();
    void paintGL();

  public:
    // Default constructor
    explicit render(QWidget *Parent = 0);
  }; // end of 'render' class
} // end of 'gbox' namespace
#endif // RENDER_H
