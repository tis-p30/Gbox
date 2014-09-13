/* Gravity newton box project.
 *
 * Authors: kbsx32;
 * File purpose: Input capture functions implementation file.
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
  if (Evnt->type() == QEvent::KeyPress)
  {
    QKeyEvent *KeyEvent = (QKeyEvent *)Evnt;
    int Key = KeyEvent->key();
    switch(Key)
    {
    case Qt::Key_Control:
      KbdControl = true;
      break;
    case Qt::Key_Shift:
      KbdShift = true;
      break;
    case Qt::Key_Alt:
      KbdAlt = true;
      break;
    default:
      if ((Key >= Qt::Key_0 && Key <= Qt::Key_9) ||
          (Key >= Qt::Key_A && Key <= Qt::Key_Z))
      {
        KbdStateLast[Key] = KbdStateNow[Key];
        KbdStateNow[Key] = true;
      }
    }
  }
  else if (Evnt->type() == QEvent::KeyRelease)
  {
    QKeyEvent *KeyEvent = (QKeyEvent *)Evnt;
    int Key = KeyEvent->key();
    switch(Key)
    {
    case Qt::Key_Control:
      KbdControl = true;
      break;
    case Qt::Key_Shift:
      KbdShift = true;
      break;
    case Qt::Key_Alt:
      KbdAlt = true;
      break;
    default:
      if ((Key >= Qt::Key_0 && Key <= Qt::Key_9) ||
          (Key >= Qt::Key_A && Key <= Qt::Key_Z))
        KbdStateNow[Key] = KbdStateLast[Key] = false;
    }
  }
}
