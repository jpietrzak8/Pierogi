//
// pirpowersearchform.h
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

#ifndef PIRPOWERSEARCHFORM_H
#define PIRPOWERSEARCHFORM_H

#include <QWidget>
#include <QString>

class MainWindow;
class PIRKeysetManager;
class QTimer;

namespace Ui {
class PIRPowerSearchForm;
}

class PIRPowerSearchForm : public QWidget
{
  Q_OBJECT
  
public:
//  explicit PIRPowerSearchForm(QWidget *parent = 0);

  PIRPowerSearchForm(
    MainWindow *mw);

  ~PIRPowerSearchForm();

  void setKeysetName(
    QString name);
  
private slots:
  void on_stepBackwardButton_pressed();
  void on_stepBackwardButton_released();
  void on_stepForwardKey_pressed();
  void on_stepForwardKey_released();
  void on_fastBackwardButton_pressed();
  void on_fastBackwardButton_released();
  void on_fastForwardButton_pressed();
  void on_fastForwardButton_released();
  void on_autoSearchButton_pressed();
  void on_pauseSearchButton_pressed();
  void on_editKeysetButton_clicked();

  void gotoPrevKeyset();
  void gotoNextKeyset();

private:
  bool checkMutex();

  Ui::PIRPowerSearchForm *ui;

  MainWindow *mainWindow;

  QTimer *advanceTimer;
};

#endif // PIRPOWERSEARCHFORM_H
