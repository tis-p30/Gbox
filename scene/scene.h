/* Gravity newton box project.
 * File purpose: Scene header.
 * Authors: Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */

#pragma once
#ifndef GBOX_SCENE_H
#define GBOX_SCENE_H

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
    bool IsPause;  // Pause flag
    // static
  public:
    // Default unit
    class UnitDef
    {
    public:
      // default unit destructor
      virtual ~UnitDef();
      // unit default response function
      virtual void response(Scene &SrcSc);
      // unit default drawing function
      virtual void render(Scene &SrcSc);
    };
  private:
    // Array of units
    std::vector<UnitDef *> units;
  public:
    // default constructor
    explicit Scene(QWidget *parent = 0);
    // default destructor
    ~Scene();

    // Getting Scene pause flag
    bool GetPauseFlag();
    // Inversing scene pause flag function
    bool PauseReset();

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

#endif // GBOX_SCENE_H
