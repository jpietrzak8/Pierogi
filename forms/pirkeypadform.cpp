//
// pirkeypadform.cpp
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

#include "pirkeypadform.h"
#include "ui_pirkeypadform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

PIRKeypadForm::PIRKeypadForm(MainWindow *mw) :
  QWidget(0),
  ui(new Ui::PIRKeypadForm),
  mainWindow(mw)
{
  ui->setupUi(this);
}

PIRKeypadForm::~PIRKeypadForm()
{
  delete ui;
}


void PIRKeypadForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  emit zeroEnabled(keyset->hasKey(id, Zero_Key));
  emit oneEnabled(keyset->hasKey(id, One_Key));
  emit twoEnabled(keyset->hasKey(id, Two_Key));
  emit threeEnabled(keyset->hasKey(id, Three_Key));
  emit fourEnabled(keyset->hasKey(id, Four_Key));
  emit fiveEnabled(keyset->hasKey(id, Five_Key));
  emit sixEnabled(keyset->hasKey(id, Six_Key));
  emit sevenEnabled(keyset->hasKey(id, Seven_Key));
  emit eightEnabled(keyset->hasKey(id, Eight_Key));
  emit nineEnabled(keyset->hasKey(id, Nine_Key));
  emit enterEnabled(keyset->hasKey(id, Enter_Key));
  emit clearEnabled(keyset->hasKey(id, Clear_Key));
  emit dashEnabled(keyset->hasKey(id, Dash_Key));
  emit plusOneHundredEnabled(keyset->hasKey(id, PlusOneHundred_Key));
  emit doubleDigitEnabled(keyset->hasKey(id, DoubleDigit_Key));
  emit prevChannelEnabled(keyset->hasKey(id, PrevChannel_Key));
}


void PIRKeypadForm::on_oneButton_pressed()
{
  mainWindow->startRepeating(One_Key);
}

void PIRKeypadForm::on_oneButton_released()
{
  mainWindow->stopRepeating();
}

void PIRKeypadForm::on_twoButton_pressed()
{
  mainWindow->startRepeating(Two_Key);
}

void PIRKeypadForm::on_twoButton_released()
{
  mainWindow->stopRepeating();
}

void PIRKeypadForm::on_threeButton_pressed()
{
  mainWindow->startRepeating(Three_Key);
}

void PIRKeypadForm::on_threeButton_released()
{
  mainWindow->stopRepeating();
}

void PIRKeypadForm::on_fourButton_pressed()
{
  mainWindow->startRepeating(Four_Key);
}

void PIRKeypadForm::on_fourButton_released()
{
  mainWindow->stopRepeating();
}

void PIRKeypadForm::on_fiveButton_pressed()
{
  mainWindow->startRepeating(Five_Key);
}

void PIRKeypadForm::on_fiveButton_released()
{
  mainWindow->stopRepeating();
}

void PIRKeypadForm::on_sixButton_pressed()
{
  mainWindow->startRepeating(Six_Key);
}

void PIRKeypadForm::on_sixButton_released()
{
  mainWindow->stopRepeating();
}

void PIRKeypadForm::on_sevenButton_pressed()
{
  mainWindow->startRepeating(Seven_Key);
}

void PIRKeypadForm::on_sevenButton_released()
{
  mainWindow->stopRepeating();
}

void PIRKeypadForm::on_eightButton_pressed()
{
  mainWindow->startRepeating(Eight_Key);
}

void PIRKeypadForm::on_eightButton_released()
{
  mainWindow->stopRepeating();
}

void PIRKeypadForm::on_nineButton_pressed()
{
  mainWindow->startRepeating(Nine_Key);
}

void PIRKeypadForm::on_nineButton_released()
{
  mainWindow->stopRepeating();
}

void PIRKeypadForm::on_zeroButton_pressed()
{
  mainWindow->startRepeating(Zero_Key);
}

void PIRKeypadForm::on_zeroButton_released()
{
  mainWindow->stopRepeating();
}

void PIRKeypadForm::on_enterButton_pressed()
{
  mainWindow->startRepeating(Enter_Key);
}

void PIRKeypadForm::on_enterButton_released()
{
  mainWindow->stopRepeating();
}

void PIRKeypadForm::on_clearButton_pressed()
{
  mainWindow->startRepeating(Clear_Key);
}

void PIRKeypadForm::on_clearButton_released()
{
  mainWindow->stopRepeating();
}

void PIRKeypadForm::on_prevChannelButton_pressed()
{
  mainWindow->startRepeating(PrevChannel_Key);
}

void PIRKeypadForm::on_prevChannelButton_released()
{
  mainWindow->stopRepeating();
}

void PIRKeypadForm::on_plusOneHundredButton_pressed()
{
  mainWindow->startRepeating(PlusOneHundred_Key);
}

void PIRKeypadForm::on_plusOneHundredButton_released()
{
  mainWindow->stopRepeating();
}

void PIRKeypadForm::on_dashButton_pressed()
{
  mainWindow->startRepeating(Dash_Key);
}

void PIRKeypadForm::on_dashButton_released()
{
  mainWindow->stopRepeating();
}

void PIRKeypadForm::on_doubleDigitButton_pressed()
{
  mainWindow->startRepeating(DoubleDigit_Key);
}

void PIRKeypadForm::on_doubleDigitButton_released()
{
  mainWindow->stopRepeating();
}
