/* Gravity newton box project.
 * File purpose: Units control.
 *               Scene controller unit functions implementation.
 * Authors: Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */

#include "sccontrol.h"

// default constructor
gbox::units::UnitScControl::UnitScControl() :
  IsDrawAxis(false)
{
}

// unit response function
void gbox::units::UnitScControl::response(gbox::Scene &SrcSc)
{
  static DBL DShift = 0.2, ShiftRot = 0.1;
  if (SrcSc.Input::KbdAlt && SrcSc.Input::KbdStateNow['X'])
    exit(0);

  if (SrcSc.Input::KbdAlt)
    if (SrcSc.Input::KbdStateNow['X'])
      exit(0);

  if (SrcSc.Input::KbdStateNow['M'] && !SrcSc.Input::KbdStateLast['M'])
    IsDrawAxis = !IsDrawAxis;
  if (SrcSc.Input::KbdStateNow['P'] && !SrcSc.Input::KbdStateLast['P'])
    SrcSc.PauseReset();

  /*
   * Camera
   */

  // Move by Direction vector
  if (SrcSc.Input::KbdStateNow['W'])
    SrcSc.Camera::moveByDir(DShift);
  if (SrcSc.Input::KbdStateNow['S'])
    SrcSc.Camera::moveByDir(-DShift);

  // Move by Right vector
  if (SrcSc.Input::KbdStateNow['A'])
    SrcSc.Camera::moveByRight(-DShift);
  if (SrcSc.Input::KbdStateNow['D'])
    SrcSc.Camera::moveByRight(DShift);

  // Move by Up vector
  if (SrcSc.Input::KbdStateNow['O'])
    SrcSc.Camera::moveByUp(DShift);
  if (SrcSc.Input::KbdStateNow['L'])
    SrcSc.Camera::moveByUp(-DShift);

  // Rotate by Right vector
  if (SrcSc.Input::KbdStateNow['I'])
    SrcSc.Camera::rotateByRight(ShiftRot);
  if (SrcSc.Input::KbdStateNow['K'])
    SrcSc.Camera::rotateByRight(-ShiftRot);

  // Rotate by Up vector
  if (SrcSc.Input::KbdStateNow['Q'])
    SrcSc.Camera::rotateByUp(ShiftRot);
  if (SrcSc.Input::KbdStateNow['E'])
    SrcSc.Camera::rotateByUp(-ShiftRot);

  // Rotate by Dir vector
  if (SrcSc.Input::KbdStateNow['G'])
    SrcSc.Camera::rotateByDir(-ShiftRot);
  if (SrcSc.Input::KbdStateNow['H'])
    SrcSc.Camera::rotateByDir(ShiftRot);

}

// unit drawing function
void gbox::units::UnitScControl::render(gbox::Scene &SrcSc)
{
  if (IsDrawAxis)
  {
    glBegin(GL_LINES);
      glColor3d(1, 0, 0);
      glVertex3d(0, 0, 0);
      glVertex4d(1, 0, 0, 0);

      glColor3d(0, 1, 0);
      glVertex3d(0, 0, 0);
      glVertex4d(0, 1, 0, 0);

      glColor3d(0, 0, 1);
      glVertex3d(0, 0, 0);
      glVertex4d(0, 0, 1, 0);
    glEnd();
  }

  glDisable(GL_DEPTH_TEST);
  GVec V;
  QString QStr;
  SrcSc.qglColor(Qt::white);
  V = SrcSc.Render::Camera::getvPos();
  QStr = QString("vPos") + V;
  SrcSc.renderTextDef(10, 10, QStr);

  V = SrcSc.Render::Camera::getvUp();
  QStr = QString("vUp = ") + V;
  SrcSc.renderTextDef(10, 25, QStr);

  V = SrcSc.Render::Camera::getLookAtPos();
  QStr = QString("LookAtPos = ") + V;
  SrcSc.renderTextDef(10, 40, QStr);

  glEnable(GL_DEPTH_TEST);
  // glRotatef(90, 0, 0)
}

// Changing axis draw flag function
void gbox::units::UnitScControl::SetAxisDrawFlag(const bool NewFlag)
{
  IsDrawAxis = NewFlag;
}
