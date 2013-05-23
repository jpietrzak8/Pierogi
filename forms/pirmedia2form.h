//
// pirmedia2form.h
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

#ifndef PIRMEDIA2FORM_H
#define PIRMEDIA2FORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRMedia2Form;
}

class PIRMedia2Form : public QWidget
{
  Q_OBJECT
  
public:
  PIRMedia2Form(MainWindow *mw);
  ~PIRMedia2Form();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void tunerBandEnabled(bool);
  void programEnabled(bool);
  void memoryEnabled(bool);
  void callEnabled(bool);
  void autoTrackingEnabled(bool);
  void trackingMinusEnabled(bool);
  void trackingPlusEnabled(bool);
  void vhsSpeedEnabled(bool);
  void slowEnabled(bool);
  void slowMinusEnabled(bool);
  void slowPlusEnabled(bool);
  void nextDiscEnabled(bool);
  void repeatEnabled(bool);
  void repeatABEnabled(bool);
  void randomEnabled(bool);
  void discTitleEnabled(bool);

private slots:
  void on_tunerBandButton_pressed();
  void on_tunerBandButton_released();
  void on_programButton_pressed();
  void on_programButton_released();
  void on_memoryButton_pressed();
  void on_memoryButton_released();
  void on_callButton_pressed();
  void on_callButton_released();
  void on_autoTrackingButton_pressed();
  void on_autoTrackingButton_released();
  void on_trackingMinusButton_pressed();
  void on_trackingMinusButton_released();
  void on_trackingPlusButton_pressed();
  void on_trackingPlusButton_released();
  void on_vhsSpeedButton_pressed();
  void on_vhsSpeedButton_released();
  void on_slowButton_pressed();
  void on_slowButton_released();
  void on_slowMinusButton_pressed();
  void on_slowMinusButton_released();
  void on_slowPlusButton_pressed();
  void on_slowPlusButton_released();
  void on_discSelectButton_pressed();
  void on_discSelectButton_released();
  void on_repeatButton_pressed();
  void on_repeatButton_released();
  void on_repeatABButton_pressed();
  void on_repeatABButton_released();
  void on_randomButton_pressed();
  void on_randomButton_released();
  void on_discTitleButton_pressed();
  void on_discTitleButton_released();
  
private:
  Ui::PIRMedia2Form *ui;

  MainWindow *mainWindow;
};

#endif // PIRMEDIA2FORM_H
