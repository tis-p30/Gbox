/* Gravity newton box project.
 * Authors: kbsx32;
 * File purpose: Render header.
 */

#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <QTimer>

#include "../def.h"
#include "render/render.h"

namespace gbox
{
  class Scene : public Render
  {
    Q_OBJECT
  private:
    QTimer *timer; // Main updater timer

  public:
    // default constructor
    explicit Scene(QWidget *parent = 0);
    // default destructor
    ~Scene();

  public Q_SLOTS:
    // Update scene function
    void update();
  }; // end of 'scene' class
} // end of 'gbox' namespace

#endif // SCENE_H
