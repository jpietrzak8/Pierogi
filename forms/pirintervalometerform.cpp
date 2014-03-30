//
// pirintervalometerform.cpp
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

#include "pirintervalometerform.h"
#include "ui_pirintervalometerform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"
#include <QTimer>
#include <time.h>

/*
PIRIntervalometerForm::PIRIntervalometerForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRIntervalometerForm)
{
  ui->setupUi(this);
}
*/

PIRIntervalometerForm::PIRIntervalometerForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRIntervalometerForm),
    intervalTimer(0),
    mainWindow(mw)
{
  ui->setupUi(this);

  connect(
    mainWindow,
    SIGNAL(contextChanged()),
    this,
    SLOT(on_quitPushButton_clicked()));
}


PIRIntervalometerForm::~PIRIntervalometerForm()
{
  if (intervalTimer) delete intervalTimer;

  delete ui;
}


void PIRIntervalometerForm::enableButtons(
  const PIRKeysetManager *km,
  unsigned int id)
{
  emit openShutterEnabled(km->hasKey(id, OpenShutter_Key));
}


void PIRIntervalometerForm::on_startPushButton_clicked()
{
  if (intervalTimer)
  {
    delete intervalTimer;
    intervalTimer = 0;
  }

  QTime zeroTime(0,0,0,0);
  intervalValue = zeroTime.msecsTo(ui->intervalTimeEdit->time());
  if (intervalValue < 1000)
  {
    ui->numberLeftLabel->setText("0");
    return;
  }

  int pauseBeforeStart = zeroTime.msecsTo(ui->pauseTimeEdit->time());
  exposureCount = ui->quantitySpinBox->value();

  QString tempString;
  ui->numberLeftLabel->setText(tempString.setNum(exposureCount));

  if (pauseBeforeStart > 0)
  {
    QTimer::singleShot(
      pauseBeforeStart,
      this,
      SLOT(startIntervalometer()));
  }
  else
  {
    startIntervalometer();
  }
}


void PIRIntervalometerForm::on_quitPushButton_clicked()
{
  // Don't need to do anything if timer is not running:
  if (!intervalTimer) return;

  exposureCount = 0;
  ui->numberLeftLabel->setText("0");
  delete intervalTimer;
  intervalTimer = 0;
}


void PIRIntervalometerForm::startIntervalometer()
{
  executeInterval();

  if (exposureCount > 0)
  {
    intervalTimer = new QTimer(this);
    connect (intervalTimer, SIGNAL(timeout()), this, SLOT(executeInterval()));
    intervalTimer->start(intervalValue);
  }
}


void PIRIntervalometerForm::executeInterval()
{
  // execute the "open shutter" command for a short period:
  mainWindow->startRepeating(OpenShutter_Key);

  // Wait for a moment:
  timespec sleeptime;
  sleeptime.tv_sec = 0;
  sleeptime.tv_nsec = 20000;
  timespec remainingtime;

  nanosleep(&sleeptime, &remainingtime);

  // Stop repeating the command:
  mainWindow->stopRepeating();

  --exposureCount;

  if (exposureCount <= 0)
  {
    if (intervalTimer)
    {
      delete intervalTimer;
      intervalTimer = 0;
    }
  }

  QString tempString;
  ui->numberLeftLabel->setText(tempString.setNum(exposureCount));
}
