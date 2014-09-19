/* Gravity newton box project.
 * File purpose: Run file.
 * Authors: Tikhonenko Iliya (tis-p30) <iliya.t@mail.ru>,
 *          Kuznetsov Roman (kbsx32) <blacksmithx32@gmail.com>
 */

#include <QApplication>

#include "scene/scene.h"
#include "scene/units/units.h"


// Redefinition types and main variables to simple use
typedef gbox::Prim::Mtl Mtl;
Mtl &DefMtl = Mtl::MtlDef;

// Main function
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  gbox::Scene Scn;
  Scn.show();

  gbox::units::UnitScControl *UnScCont = new gbox::units::UnitScControl();
  UnScCont->SetAxisDrawFlag(true);
  Scn << UnScCont;

  DefMtl = Mtl(gbox::GVec(0.2, 0.3, 0.5));
  for (int i = 0; i < 20; i++)
  {
    DefMtl = Mtl(gbox::GVec((DBL)rand() / RAND_MAX, (DBL)rand() / RAND_MAX, (DBL)rand() / RAND_MAX));
    Scn << new gbox::units::Sphere(gbox::GVec(rand() % 30 - 15, rand() % 30 - 15, rand() % 30 - 15), 1);
  }

  DefMtl = Mtl(gbox::GVec(0.2, 0.3, 0.5));
  Scn << new gbox::units::Sphere(gbox::GVec(0, 0, 0), 1, 32);
  DefMtl = Mtl(gbox::GVec(0.5, 0.3, 0.2));
  Scn << new gbox::units::Sphere(gbox::GVec(0, 2, 2), 0.5, 32);
  DefMtl = Mtl(gbox::GVec(0.5, 0.8, 0.8));
  Scn << new gbox::units::Sphere(gbox::GVec(-2, -1, 2), 0.4, 32);

  return a.exec();
}
