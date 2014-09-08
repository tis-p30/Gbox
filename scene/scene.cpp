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
  timer->stop();
  delete timer;
}

// Scene update function
void gbox::Scene::update()
{
  updateGL();
}

