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
  Scn << new gbox::units::Sphere(gbox::GVec(0, 0, 0), 1, 32,
                                 gbox::GVec(0.7, 0.7, 0.0));

  Scn << new gbox::units::Sphere(gbox::GVec(0, 2, 2), 0.5, 32,
                                 gbox::GVec(0.3, 0.3, 0.3));

  Scn << new gbox::units::Sphere(gbox::GVec(-2, -1, 2), 0.4, 32,
                                 gbox::GVec(0.1, 0.6, 0.7));

  return a.exec();
}
