//
// pirtvmenuform.h
//
// Copyright 2015 by John Pietrzak (jpietrzak8@gmail.com)
//
// This file is part of Pierogi.
//
// Pierogi is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// Pierogi is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#ifndef PIRTVMENUFORM_H
#define PIRTVMENUFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRTVMenuForm;
}

class PIRTVMenuForm : public QWidget
{
  Q_OBJECT
  
public:
  PIRTVMenuForm(
    MainWindow *mw);

  ~PIRTVMenuForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void menuEnabled(bool);
  void cecEnabled(bool);
  void appsEnabled(bool);
  void quickEnabled(bool);
  void leftEnabled(bool);
  void toolsEnabled(bool);
  void upEnabled(bool);
  void selectEnabled(bool);
  void downEnabled(bool);
  void backEnabled(bool);
  void rightEnabled(bool);
  void exitEnabled(bool);
  
private slots:
  void on_menuButton_pressed();
  void on_menuButton_released();
  void on_cecButton_pressed();
  void on_cecButton_released();
  void on_appsButton_pressed();
  void on_appsButton_released();
  void on_quickMenuButton_pressed();
  void on_quickMenuButton_released();
  void on_leftButton_pressed();
  void on_leftButton_released();
  void on_toolsButton_pressed();
  void on_toolsButton_released();
  void on_upButton_pressed();
  void on_upButton_released();
  void on_selectButton_pressed();
  void on_selectButton_released();
  void on_downButton_pressed();
  void on_downButton_released();
  void on_backButton_pressed();
  void on_backButton_released();
  void on_rightButton_pressed();
  void on_rightButton_released();
  void on_exitButton_pressed();
  void on_exitButton_released();

private:
  Ui::PIRTVMenuForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRTVMENUFORM_H
