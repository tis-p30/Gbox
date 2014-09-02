/* Gravity newton box project.
 * Authors: tis-p30, kbsx32;
 * File purpose: Run file.
 */


#include <QApplication>
#include "wndmain.h"

// Main function
int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  WndMain w;
  w.show();
  
  return a.exec();
}
