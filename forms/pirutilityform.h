//
// pirutilityform.h
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

#ifndef PIRUTILITYFORM_H
#define PIRUTILITYFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRUtilityForm;
}

class PIRUtilityForm : public QWidget
{
  Q_OBJECT

public:
//  explicit PIRUtilityForm(QWidget *parent = 0);
  PIRUtilityForm(MainWindow *mw);
  ~PIRUtilityForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void redEnabled(bool);
  void greenEnabled(bool);
  void yellowEnabled(bool);
  void blueEnabled(bool);
  void pictureModeEnabled(bool);
  void soundModeEnabled(bool);
  void aspectRatioEnabled(bool);
  void audioEnabled(bool);
  void infoEnabled(bool);
  void captionsEnabled(bool);
  void inputEnabled(bool);
  void sleepEnabled(bool);
  void selectInputListEnabled(bool);

private slots:
  void on_redButton_pressed();
  void on_redButton_released();
  void on_greenButton_pressed();
  void on_greenButton_released();
  void on_yellowButton_pressed();
  void on_yellowButton_released();
  void on_blueButton_pressed();
  void on_blueButton_released();
  void on_pictureModeButton_pressed();
  void on_pictureModeButton_released();
  void on_soundModeButton_pressed();
  void on_soundModeButton_released();
  void on_aspectRatioButton_pressed();
  void on_aspectRatioButton_released();
  void on_audioButton_pressed();
  void on_audioButton_released();
  void on_infoButton_pressed();
  void on_infoButton_released();
  void on_captionButton_pressed();
  void on_captionButton_released();
  void on_inputButton_pressed();
  void on_inputButton_released();
  void on_sleepButton_pressed();
  void on_sleepButton_released();
  void on_selectInputPushButton_pressed();
  void on_selectInputPushButton_released();

private:
  Ui::PIRUtilityForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRUTILITYFORM_H
