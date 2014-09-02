/* Gravity newton box project.
 * Authors: tis-p30, kbsx32;
 * File purpose: Main window implementation functions.
 */

#include <cstdio>
#include <string>
#include <QString>

#include "wndmain.h"
#include "ui_wndmain.h" // Auticompile.

// Main window constructor
WndMain::WndMain(QWidget *parent) :
  QMainWindow(parent),
  ui(new Ui::WndMain)
{
  ui->setupUi(this);

  ui->PushButton_Start->setText("test 0");
  QObject::connect(ui->PushButton_Start, SIGNAL(clicked()), this, SLOT(PushButtonStart_OnClick()));
}

// Main window destructor
WndMain::~WndMain()
{
  delete ui;
}

// on PushButton_Start event clicked function
void WndMain::PushButtonStart_OnClick()
{
  static int i = 1;
  char Buf[1000];
  sprintf(Buf, "Test start %d", i++);
  QString Str(Buf);

  ui->PushButton_Start->setText(Str);
}

