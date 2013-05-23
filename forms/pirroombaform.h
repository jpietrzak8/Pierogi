//
// pirroombaform.h
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

#ifndef PIRROOMBAFORM_H
#define PIRROOMBAFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRRoombaForm;
}

class PIRRoombaForm : public QWidget
{
  Q_OBJECT
  
public:
//  explicit PIRRoombaForm(QWidget *parent = 0);
  PIRRoombaForm(
    MainWindow *mw);

  ~PIRRoombaForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void spotEnabled(bool);
  void forwardEnabled(bool);
  void cleanEnabled(bool);
  void ccwEnabled(bool);
  void pauseEnabled(bool);
  void cwEnabled(bool);
  void maxEnabled(bool);
  void powerEnabled(bool);
  
private slots:
  void on_spotButton_pressed();
  void on_spotButton_released();
  void on_forwardButton_pressed();
  void on_forwardButton_released();
  void on_cleanButton_pressed();
  void on_cleanButton_released();
  void on_ccwButton_pressed();
  void on_ccwButton_released();
  void on_pauseButton_pressed();
  void on_pauseButton_released();
  void on_cwButton_pressed();
  void on_cwButton_released();
  void on_maxButton_pressed();
  void on_maxButton_released();
  void on_powerButton_pressed();
  void on_powerButton_released();

private:
  Ui::PIRRoombaForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRROOMBAFORM_H
