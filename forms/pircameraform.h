//
// pircameraform.h
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

#ifndef PIRCAMERAFORM_H
#define PIRCAMERAFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;
class PIRFlashLED;

namespace Ui {
class PIRCameraForm;
}

class PIRCameraForm : public QWidget
{
  Q_OBJECT
  
public:
//  explicit PIRCameraForm(QWidget *parent = 0);

  PIRCameraForm(
    MainWindow *mw);

  ~PIRCameraForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void openShutterEnabled(bool);
  void delayedOpenShutterEnabled(bool);
  
private slots:
  void on_openShutterButton_pressed();
  void on_openShutterButton_released();

private:
  Ui::PIRCameraForm *ui;

  MainWindow *mainWindow;

  PIRFlashLED *flash;
};

#endif // PIRCAMERAFORM_H
