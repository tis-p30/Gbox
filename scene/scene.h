/* Gravity newton box project.
 * Authors: kbsx32;
 * File purpose: Render header.
 */

#pragma once
#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include <QTimer>

#include "../def.h"

#include "render/render.h"
#include "render/prim.h"

#include "input/input.h"

namespace gbox
{
  class Scene : public Render, public Input
  {
    Q_OBJECT
  private:
    QTimer *timer; // Main updater timer
    // static
  public:
    // Default unit
    class UnitDef
    {
    public:
      // default unit destructor
      virtual ~UnitDef();
      // unit default response function
      virtual void response();
      // unit default drawing function
      virtual void render();
    };
  private:
    // Array of units
    std::vector<UnitDef *> units;
  public:
    // default constructor
    explicit Scene(QWidget *parent = 0);
    // default destructor
    ~Scene();

  public slots:
    // Update scene function
    void update();
    // drawing all units function
    void render();
    // event keyboard capture by event
    bool event(QEvent *Evnt);

  public:
    // Adding new unit to scene
    Scene & operator<<(UnitDef *NewUnit);
  }; // end of 'scene' class
} // end of 'gbox' namespace

#endif // SCENE_H
