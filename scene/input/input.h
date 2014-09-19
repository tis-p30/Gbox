/* Gravity newton box project.
 * File purpose: Scene.
 *               Input capture header.
 * Authors: Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */

#pragma once
#ifndef INPUT_H
#define INPUT_H

#include <qcoreevent.h>
#include <QtGui>
#include <QEvent>
#include <QKeyEvent>

// Including primitives
namespace gbox
{
  // Rendering scene class
  class Input
  {
  public:
    static const int KbdKeysCnt = 256;
    bool
      KbdStateNow[KbdKeysCnt],         // Keys data
      KbdStateLast[KbdKeysCnt];
    bool KbdControl, KbdAlt, KbdShift; // Modifiers keys
  public:
    // Default constructor
    explicit Input();
    // update input system state by new event
    void updateEvent(QEvent *Evnt);
    // update all input Last Data
    void updateKbdStateLast();
  }; // end of 'input' class
} // end of 'gbox' namespace

#endif // INPUT_H
