//
// pirkeypadform.h
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

#ifndef PIRKEYPADFORM_H
#define PIRKEYPADFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRKeypadForm;
}

class PIRKeypadForm : public QWidget
{
  Q_OBJECT

public:
//  explicit PIRKeypadForm(QWidget *parent = 0);
  PIRKeypadForm(MainWindow *mw);
  ~PIRKeypadForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void zeroEnabled(bool);
  void oneEnabled(bool);
  void twoEnabled(bool);
  void threeEnabled(bool);
  void fourEnabled(bool);
  void fiveEnabled(bool);
  void sixEnabled(bool);
  void sevenEnabled(bool);
  void eightEnabled(bool);
  void nineEnabled(bool);
  void enterEnabled(bool);
  void clearEnabled(bool);
  void dashEnabled(bool);
  void plusOneHundredEnabled(bool);
  void doubleDigitEnabled(bool);
  void prevChannelEnabled(bool);

private slots:
  void on_oneButton_pressed();
  void on_oneButton_released();
  void on_twoButton_pressed();
  void on_twoButton_released();
  void on_threeButton_pressed();
  void on_threeButton_released();
  void on_fourButton_pressed();
  void on_fourButton_released();
  void on_fiveButton_pressed();
  void on_fiveButton_released();
  void on_sixButton_pressed();
  void on_sixButton_released();
  void on_sevenButton_pressed();
  void on_sevenButton_released();
  void on_eightButton_pressed();
  void on_eightButton_released();
  void on_nineButton_pressed();
  void on_nineButton_released();
  void on_zeroButton_pressed();
  void on_zeroButton_released();
  void on_enterButton_pressed();
  void on_enterButton_released();
  void on_clearButton_pressed();
  void on_clearButton_released();
  void on_prevChannelButton_pressed();
  void on_prevChannelButton_released();
  void on_plusOneHundredButton_pressed();
  void on_plusOneHundredButton_released();
  void on_dashButton_pressed();
  void on_dashButton_released();
  void on_doubleDigitButton_pressed();
  void on_doubleDigitButton_released();

private:
  Ui::PIRKeypadForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRKEYPADFORM_H
