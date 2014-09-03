/* Gravity newton box project.
 * Authors: tis-p30, kbsx32;
 * File purpose: Run file.
 */


#include <QApplication>

#include "scene/render/render.h"

// Main function
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  gbox::render Rnd;
  Rnd.show();

  return a.exec();
}
