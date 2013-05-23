//
// pirrecordform.h
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

#ifndef PIRRECORDFORM_H
#define PIRRECORDFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRRecordForm;
}

class PIRRecordForm : public QWidget
{
  Q_OBJECT

public:
  PIRRecordForm(
    MainWindow *mw);

  ~PIRRecordForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void timerEnabled(bool);
  void programEnabled(bool);
  void memoryEnabled(bool);
  void callEnabled(bool);
  void favoritesEnabled(bool);
  void scanEnabled(bool);
  void prevPresetEnabled(bool);
  void nextPresetEnabled(bool);
  void recordEnabled(bool);
  void recordPauseEnabled(bool);
  void recordStopEnabled(bool);
  void recordMuteEnabled(bool);

private slots:
  void on_timerButton_pressed();
  void on_timerButton_released();
  void on_programButton_pressed();
  void on_programButton_released();
  void on_memoryButton_pressed();
  void on_memoryButton_released();
  void on_callButton_pressed();
  void on_callButton_released();
  void on_favoritesButton_pressed();
  void on_favoritesButton_released();
  void on_scanButton_pressed();
  void on_scanButton_released();
  void on_prevPresetButton_pressed();
  void on_prevPresetButton_released();
  void on_nextPresetButton_pressed();
  void on_nextPresetButton_released();
  void on_recordButton_pressed();
  void on_recordButton_released();
  void on_recordPauseButton_pressed();
  void on_recordPauseButton_released();
  void on_recordStopButton_pressed();
  void on_recordStopButton_released();
  void on_recordMuteButton_pressed();
  void on_recordMuteButton_released();

private:
  Ui::PIRRecordForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRRECORDFORM_H
