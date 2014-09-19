/* Gravity newton box project.
 * File purpose: Scene functions implementation.
 * Authors: Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */

#include "scene.h"

gbox::Scene::Scene(QWidget *QWidgParent) :
  Render(QWidgParent), IsPause(0)
{
  timer = new QTimer(this);

  timer->setInterval(30);
  connect(timer, SIGNAL(timeout()), this, SLOT(update()));
  timer->start();
}

// default scene destructor
gbox::Scene::~Scene()
{
  for (std::vector<UnitDef *>::iterator It = units.begin(); It != units.end(); ++It)
    delete *It;

  timer->stop();
  delete timer;
}

// Scene update function
void gbox::Scene::update()
{
  for (std::vector<UnitDef *>::iterator It = units.begin(); It != units.end(); ++It)
    (*It)->response(*this);

  Input::updateKbdStateLast();
  updateGL();
}

// Adding new unit to scene function
gbox::Scene & gbox::Scene::operator<<(UnitDef *NewUnit)
{
  units.push_back(NewUnit);
  return *this;
}

void gbox::Scene::render()
{
  static TypeUse x = 0;
  // Getting camera 'LookAt' vectors
  GVec Pos = Camera::getvPos(), LookAt = Camera::getLookAtPos(), Up = Camera::getvUp();

  if (!IsPause)
    x += 2;
  for (std::vector<UnitDef *>::iterator It = units.begin(); It != units.end(); ++It)
  {
    glLoadIdentity();
    gluLookAt(Pos[0], Pos[1], Pos[2],
              LookAt[0], LookAt[1], LookAt[2],
              Up[0], Up[1], Up[2]);
    glRotatef(x, 0, 1.0, 0);

    (*It)->render(*this);
  }
}

// event keyboard capture
bool gbox::Scene::event(QEvent *Evnt)
{
  Input::updateEvent(Evnt);
  return QWidget::event(Evnt);
}

// Getting Scene pause flag
bool gbox::Scene::GetPauseFlag()
{
  return IsPause;
}

// Inversing scene pause flag function
bool gbox::Scene::PauseReset()
{
  return (IsPause = !IsPause);
}

/*
 * Unit default functions
 */

// unit default response function
void gbox::Scene::UnitDef::response(gbox::Scene &SrcSc)
{
}
// unit default drawing function
void gbox::Scene::UnitDef::render(gbox::Scene &SrcSc)
{
}

// default unit destructor
gbox::Scene::UnitDef::~UnitDef()
{
}
