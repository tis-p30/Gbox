/* Gravity newton box project.
 * Authors: kbsx32;
 * File purpose: Render header.
 */

#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <QTimer>
#include "render/render.h"

namespace gbox
{
  class scene : public render
  {
    Q_OBJECT
  private:
    QTimer *Timer; // Main updater timer

  public:
    // default constructor
    explicit scene(QWidget *parent = 0);
    // default destructor
    ~scene();

  public Q_SLOTS:
    // Update scene function
    void Update();
  }; // end of 'scene' class
} // end of 'gbox' namespace

#endif // SCENE_H
