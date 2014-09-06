/* Gravity newton box project.
 * Authors: kbsx32;
 * File purpose: global scene functions implementation file.
 */

#include "scene.h"

gbox::scene::scene(QWidget *parent) :
  render(parent)
{
  Timer = new QTimer(this);

  Timer->setInterval(30);
  connect(Timer, SIGNAL(timeout()), this, SLOT(Update()));
  // connect(Timer, SIGNAL(timeout()), this, SLOT(updateGL()));
  Timer->start();
}

// default scene destructor
gbox::scene::~scene()
{
  Timer->stop();
  delete Timer;
}

// Scene update function
void gbox::scene::Update()
{
  updateGL();
}

