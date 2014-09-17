/* Gravity newton box project.
 * Authors: kbsx32;
 * File purpose: global scene functions implementation file.
 */

#include "scene.h"

gbox::Scene::Scene(QWidget *QWidgParent) :
  Render(QWidgParent)
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
  for (std::vector<UnitDef *>::iterator It = units.begin(); It != units.end(); ++It)
    (*It)->render(*this);
}

// event keyboard capture
bool gbox::Scene::event(QEvent *Evnt)
{
  Input::updateEvent(Evnt);
  return QWidget::event(Evnt);
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
