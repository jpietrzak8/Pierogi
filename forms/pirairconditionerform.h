//
// pirairconditionerform.h
//
// Copyright 2012, 2013 by John Pietrzak (jpietrzak8@gmail.com)
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

#ifndef PIRAIRCONDITIONERFORM_H
#define PIRAIRCONDITIONERFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRAirConditionerForm;
}

class PIRAirConditionerForm : public QWidget
{
  Q_OBJECT
  
public:
  PIRAirConditionerForm(MainWindow *mw);
  ~PIRAirConditionerForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void oscillateEnabled(bool);
  void powerEnabled(bool);
  void timerEnabled(bool);
  void modeEnabled(bool);
  void fanFasterEnabled(bool);
  void heatEnabled(bool);
  void fanEnabled(bool);
  void tempUpEnabled(bool);
  void fanSlowerEnabled(bool);
  void energySaveEnabled(bool);
  void coolEnabled(bool);
  void tempDownEnabled(bool);
  
private slots:
  void on_oscillateButton_pressed();
  void on_oscillateButton_released();
  void on_powerButton_pressed();
  void on_powerButton_released();
  void on_timerButton_pressed();
  void on_timerButton_released();
  void on_modeButton_pressed();
  void on_modeButton_released();
  void on_fanFasterButton_pressed();
  void on_fanFasterButton_released();
  void on_heatButton_pressed();
  void on_heatButton_released();
  void on_fanButton_pressed();
  void on_fanButton_released();
  void on_tempUpButton_pressed();
  void on_tempUpButton_released();
  void on_fanSlowerButton_pressed();
  void on_fanSlowerButton_released();
  void on_energySaveButton_pressed();
  void on_energySaveButton_released();
  void on_coolButton_pressed();
  void on_coolButton_released();
  void on_tempDownButton_pressed();
  void on_tempDownButton_released();

private:
  Ui::PIRAirConditionerForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRAIRCONDITIONERFORM_H
