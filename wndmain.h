/* Gravity newton box project.
 * Authors: tis-p30, kbsx32;
 * File purpose: Main window header file.
 */

#pragma once

#ifndef WNDMAIN_H
#define WNDMAIN_H

#include <QMainWindow>


// Predeclaration
namespace Ui
{
  class WndMain;
}

class WndMain : public QMainWindow
{
  Q_OBJECT
  
public:
  explicit WndMain(QWidget *parent = 0);
  ~WndMain();
  
private:
  Ui::WndMain *ui;

public slots:
  void PushButtonStart_OnClick();
};

#endif // WNDMAIN_H
