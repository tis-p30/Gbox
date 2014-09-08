/* Gravity newton box project.
 * Authors: tis-p30, kbsx32;
 * File purpose: Run file.
 */


#include <QApplication>

#include "scene/scene.h"

// Main function
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  gbox::Scene Scn;
  Scn.show();

  return a.exec();
}
