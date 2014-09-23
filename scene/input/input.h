/* Gravity newton box project.
 * File purpose: Scene.
 *               Input capture header.
 * Authors: Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */

#pragma once
#ifndef GBOX_INPUT_H
#define GBOX_INPUT_H

#include <qcoreevent.h>
#include <QtGui>
#include <QEvent>
#include <QKeyEvent>

#include "../../def.h"

// Including primitives
namespace gbox
{
  // Rendering scene class
  class Input
  {
  public:
    /*
     * Keyboard data
     */
    static const int KbdKeysCnt = 256;
    bool
      KbdStateNow[KbdKeysCnt],         // Keys data
      KbdStateLast[KbdKeysCnt];
    bool KbdControl, KbdAlt, KbdShift; // Modifiers keys

    // update keyboard function
    void eventKbd(QEvent *Evnt);

    /*
     * Mouse data
     */
    GVec MousePos, MouseDelta;                // Mouse vectors
    bool MouseLButton, MouseRButton;          // Mouse buttons state
    TypeUse MouseWheel;                       // Mouse Wheel state delta

    // update mouse function
    void eventMouse(QEvent *Evnt);

    /*
     * Global functions
     */
    // update input system state by new event
    void updateEvent(QEvent *Evnt);
  public:
    // Default constructor
    explicit Input();
    // update all input Last Data
    void updateKbdStateLast();
  }; // end of 'input' class
} // end of 'gbox' namespace

#endif // GBOX_INPUT_H
