/* Gravity newton box project.
 * File purpose: Scene.
 *               Input capture functions implementation.
 * Authors: Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */

#include "input.h"

// Default constructor
gbox::Input::Input() :
  KbdControl(false), KbdAlt(false), KbdShift(false),
  MouseLButton(0), MouseRButton(0), MouseWheel(0)
{
  // KbdAlt = 0, KbdControl = 0, KbdShift = 0;
  memset(KbdStateNow, 0, sizeof(KbdStateNow));
  memset(KbdStateLast, 0, sizeof(KbdStateLast));
}


// update keyboard function
void gbox::Input::eventKbd(QEvent *Evnt)
{
  QKeyEvent *KeyEvent = (QKeyEvent *)Evnt;

  // int KeySignalsStart = Key;
  DWORD IsPressed = KeyEvent->type() == QEvent::KeyPress ? 1 : 0;
  int Key = KeyEvent->key();

  switch (Key)
  {
  case Qt::Key_Control:
    KbdControl = IsPressed;
    break;
  case Qt::Key_Shift:
    KbdShift = IsPressed;
    break;
  case Qt::Key_Alt:
    KbdAlt = IsPressed;
    break;
  default:
    if ((Key >= Qt::Key_0 && Key <= Qt::Key_9) ||
        (Key >= Qt::Key_A && Key <= Qt::Key_Z))
      KbdStateNow[Key] = IsPressed;
  }
}

// update keyboard function
void gbox::Input::eventMouse(QEvent *Evnt)
{
  QMouseEvent *EvMs = (QMouseEvent *)Evnt;
  DWORD IsPressed = EvMs->type() == QEvent::MouseButtonPress ? 1 : 0;
  DWORD Button = EvMs->button();

  switch (Button)
  {
  case Qt::LeftButton:
    MouseLButton = IsPressed;
    break;
  case Qt::RightButton:
    MouseRButton = IsPressed;
    break;
  }
  if (EvMs->type() == QEvent::MouseMove)
    MousePos = GVec(EvMs->x(), EvMs->y());
}

// update input system state
void gbox::Input::updateEvent(QEvent *Evnt)
{
  QEvent::Type EvType = Evnt->type();
  if (EvType == QEvent::KeyPress || EvType == QEvent::KeyRelease)
    eventKbd(Evnt);
  if ((EvType >= QEvent::MouseButtonPress && EvType <= QEvent::MouseMove) ||
      EvType == QEvent::MouseTrackingChange)
    eventMouse(Evnt);
}

// update all input Last Data
void gbox::Input::updateKbdStateLast()
{
  for (int i = 0; i < KbdKeysCnt; i++)
    KbdStateLast[i] = KbdStateNow[i];
}
