//
// piractimerform.cpp
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

#include "piractimerform.h"
#include "ui_piractimerform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"
#include "pirackeyset.h"

/*
PIRACTimerForm::PIRACTimerForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRACTimerForm)
{
  ui->setupUi(this);
}
*/

PIRACTimerForm::PIRACTimerForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRACTimerForm),
    mainWindow(mw)
{
  ui->setupUi(this);
}

PIRACTimerForm::~PIRACTimerForm()
{
  delete ui;
}

void PIRACTimerForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  const PIRACKeyset *ackeys = keyset->getACKeyset(id);

  if (ackeys && keyset->hasKey(id, ACSetTimer_Key))
  {
    emit setTimerButtonEnabled(true);
    emit timeValueSpinBoxEnabled(true);

    PIRStatePairs pairs;
    PIRStatePairs::const_iterator i;

    ackeys->getTimerOptionPairs(pairs);
    i = pairs.begin();
    if (i == pairs.end())
    {
      // No options defined
      emit timerOptionComboBoxEnabled(false);
    }
    else
    {
      while (i != pairs.end())
      {
        ui->timerOptionComboBox->addItem(
          (*i)->getName(),
          QVariant((*i)->getCode()));

        ++i;
      }

      emit timerOptionComboBoxEnabled(true);
    }
  }
  else
  {
    emit setTimerButtonEnabled(false);
    emit timeValueSpinBoxEnabled(false);
    emit timerOptionComboBoxEnabled(false);
  }
}


void PIRACTimerForm::on_setTimerButton_pressed()
{
  PIRACStateInfo state;

  if (ui->timerOptionComboBox->isEnabled())
  {
    state.timerOption = ui->timerOptionComboBox->itemData(
      ui->timerOptionComboBox->currentIndex()).toInt();
  }

  if (ui->timeValueSpinBox->isEnabled())
  {
    state.timerHours = ui->timeValueSpinBox->value();
  }

  mainWindow->startRepeating(state, ACSetTimer_Key);
}

void PIRACTimerForm::on_setTimerButton_released()
{

}
