//
// piractimerform.h
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

#ifndef PIRACTIMERFORM_H
#define PIRACTIMERFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRACTimerForm;
}

class PIRACTimerForm : public QWidget
{
  Q_OBJECT

public:
//  explicit PIRACTimerForm(QWidget *parent = 0);
  PIRACTimerForm(
    MainWindow *mw);

  ~PIRACTimerForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void setTimerButtonEnabled(bool);
  void timerOptionComboBoxEnabled(bool);
  void timeValueSpinBoxEnabled(bool);

private slots:
  void on_setTimerButton_pressed();
  void on_setTimerButton_released();

private:
  Ui::PIRACTimerForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRACTIMERFORM_H
