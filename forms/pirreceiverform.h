//
// pirreceiverform.h
//
// Copyright 2014 by John Pietrzak (jpietrzak8@gmail.com)
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

#ifndef PIRRECEIVERFORM_H
#define PIRRECEIVERFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRReceiverForm;
}

class PIRReceiverForm : public QWidget
{
  Q_OBJECT
  
public:
//  explicit PIRReceiverForm(QWidget *parent = 0);
  PIRReceiverForm(MainWindow *mw);
  ~PIRReceiverForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void prevPresetEnabled(bool);
  void nextPresetEnabled(bool);
  void tuneUpEnabled(bool);
  void tuneDownEnabled(bool);
  void powerEnabled(bool);
  void muteEnabled(bool);
  void volumeUpEnabled(bool);
  void volumeDownEnabled(bool);
  void toggleBandEnabled(bool);
  void fmEnabled(bool);
  void amEnabled(bool);
  void lwEnabled(bool);

  void keysetNameChanged(QString);

private slots:
  void on_prevPresetButton_pressed();
  void on_prevPresetButton_released();
  void on_nextPresetButton_pressed();
  void on_nextPresetButton_released();
  void on_powerButton_pressed();
  void on_powerButton_released();
  void on_muteButton_pressed();
  void on_muteButton_released();
  void on_volumeUpButton_pressed();
  void on_volumeUpButton_released();
  void on_volumeDownButton_pressed();
  void on_volumeDownButton_released();
  void on_tuneUpButton_pressed();
  void on_tuneUpButton_released();
  void on_tuneDownButton_pressed();
  void on_tuneDownButton_released();
  void on_toggleBandButton_pressed();
  void on_toggleBandButton_released();
  void on_lwButton_pressed();
  void on_lwButton_released();
  void on_amButton_pressed();
  void on_amButton_released();
  void on_fmButton_pressed();
  void on_fmButton_released();

private:
  Ui::PIRReceiverForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRRECEIVERFORM_H
