/* Gravity newton box project.
 * File purpose: Scene.
 *               Input capture functions implementation.
 * Authors: Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */

#include "input.h"

// Default constructor
gbox::Input::Input() :
  KbdControl(false), KbdAlt(false), KbdShift(false)
{
  // KbdAlt = 0, KbdControl = 0, KbdShift = 0;
  memset(KbdStateNow, 0, sizeof(KbdStateNow));
  memset(KbdStateLast, 0, sizeof(KbdStateLast));
}

// update input system state
void gbox::Input::updateEvent(QEvent *Evnt)
{
  typedef enum
  {
    Key_Unpressed,  // False-state
    Key_Pressed,    // True-state
    Key_NoPressed   // No Pressed state
  } KeyState;

  KeyState Kst = Key_NoPressed;
  if (Evnt->type() == QEvent::KeyPress)
    Kst = Key_Pressed;
  else if (Evnt->type() == QEvent::KeyRelease)
    Kst = Key_Unpressed;

  if (Kst != Key_NoPressed)
  {
    QKeyEvent *KeyEvent = (QKeyEvent *)Evnt;

    int Key = KeyEvent->key();
    switch(Key)
    {
    case Qt::Key_Control:
      KbdControl = Kst;
      break;
    case Qt::Key_Shift:
      KbdShift = Kst;
      break;
    case Qt::Key_Alt:
      KbdAlt = Kst;
      break;
    default:
      if ((Key >= Qt::Key_0 && Key <= Qt::Key_9) ||
          (Key >= Qt::Key_A && Key <= Qt::Key_Z))
      {
        if (Kst == Key_Pressed)
          KbdStateNow[Key] = true;

        else if (Kst == Key_Unpressed)
          KbdStateNow[Key] = false;
      }
    }
  }
}

// update all input Last Data
void gbox::Input::updateKbdStateLast()
{
  for (int i = 0; i < KbdKeysCnt; i++)
    KbdStateLast[i] = KbdStateNow[i];
}
