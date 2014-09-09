/* Gravity newton box project.
 * Authors: tis-p30, kbsx32;
 * File purpose: Run file.
 */


#include <QApplication>

#include "scene/scene.h"
#include "scene/units/units.h"


// Main function
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  gbox::Scene Scn;
  Scn.show();

  /*
  Scn << new gbox::units::Triangle(gbox::GVec(0, 0, 0),
                                   gbox::GVec(0, 1, 1),
                                   gbox::GVec(0, 2, 1),
                                   gbox::GVec(0.6, 0.6, 0.6));
  Scn << new gbox::units::Triangle(gbox::GVec(0, 0, 0),
                                   gbox::GVec(0, -1,-1),
                                   gbox::GVec(0, 2, -1),
                                   gbox::GVec(0.5, 0.6, 0.8));
  Scn << new gbox::units::Triangle(gbox::GVec(0, 0, 0),
                                   gbox::GVec(0, -1, 1),
                                   gbox::GVec(0, -2, 1));
  */
  Scn << new gbox::units::Sphere(gbox::GVec(0, 0, 0), 2, 8);

  return a.exec();
}
