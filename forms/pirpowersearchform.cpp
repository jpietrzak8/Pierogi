//
// pirpowersearchform.cpp
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

#include "pirpowersearchform.h"
#include "ui_pirpowersearchform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

#include <QTimer>
#include <QMutex>

// Debugging includes:
#include <iostream>

// Check if a command is running:
extern bool commandInFlight;
extern QMutex commandIFMutex;

/*
PIRPowerSearchForm::PIRPowerSearchForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRPowerSearchForm)
{
  ui->setupUi(this);
}
*/


PIRPowerSearchForm::PIRPowerSearchForm(
  MainWindow *mw)
  : QWidget(mw),
    ui(new Ui::PIRPowerSearchForm),
    mainWindow(mw),
    advanceTimer(0)
{
  ui->setupUi(this);

  // Make this a stacked window:
  setAttribute(Qt::WA_Maemo5StackedWindow);
  setWindowFlags(windowFlags() | Qt::Window);
}


PIRPowerSearchForm::~PIRPowerSearchForm()
{
  if (advanceTimer) delete advanceTimer;

  delete ui;
}

void PIRPowerSearchForm::setKeysetName(
  QString name)
{
  ui->keysetNameLabel->setText(name);
}

void PIRPowerSearchForm::on_stepBackwardButton_pressed()
{
  if (advanceTimer)
  {
    delete advanceTimer;
    advanceTimer = 0;
    mainWindow->stopRepeating();
  }
  else if (mainWindow->selectPrevKeyset())
  {
    mainWindow->startRepeating(Power_Key);
  }
}

void PIRPowerSearchForm::on_stepBackwardButton_released()
{
  mainWindow->stopRepeating();
}

void PIRPowerSearchForm::on_stepForwardKey_pressed()
{
  if (advanceTimer)
  {
    delete advanceTimer;
    advanceTimer = 0;
    mainWindow->stopRepeating();
  }
  else if (mainWindow->selectNextKeyset())
  {
    mainWindow->startRepeating(Power_Key);
  }
}

void PIRPowerSearchForm::on_stepForwardKey_released()
{
  mainWindow->stopRepeating();
}

void PIRPowerSearchForm::on_fastBackwardButton_pressed()
{
  if (advanceTimer)
  {
    delete advanceTimer;
    advanceTimer = 0;
    mainWindow->stopRepeating();
    return;
  }

  if (!mainWindow->selectPrevKeyset())
  {
    return;
  }

  mainWindow->startRepeating(Power_Key);

  advanceTimer = new QTimer();
  connect(advanceTimer, SIGNAL(timeout()), this, SLOT(gotoPrevKeyset()));
  advanceTimer->start(50);
}

void PIRPowerSearchForm::on_fastBackwardButton_released()
{
  delete advanceTimer;
  advanceTimer = 0;
  mainWindow->stopRepeating();
}

void PIRPowerSearchForm::on_fastForwardButton_pressed()
{
  if (advanceTimer)
  {
    delete advanceTimer;
    advanceTimer = 0;
    mainWindow->stopRepeating();
    return;
  }

  if (!mainWindow->selectNextKeyset())
  {
    return;
  }

  mainWindow->startRepeating(Power_Key);

  advanceTimer = new QTimer();
  connect(advanceTimer, SIGNAL(timeout()), this, SLOT(gotoNextKeyset()));
  advanceTimer->start(50);
}


void PIRPowerSearchForm::on_fastForwardButton_released()
{
  delete advanceTimer;
  advanceTimer = 0;
  mainWindow->stopRepeating();
}


void PIRPowerSearchForm::gotoPrevKeyset()
{
  if (checkMutex())
  {
    mainWindow->stopRepeating();
    return;
  }

  if (mainWindow->selectPrevKeyset())
  {
    mainWindow->startRepeating(Power_Key);
  }
  else
  {
    if (advanceTimer) delete advanceTimer;
    advanceTimer = 0;
  }
}


void PIRPowerSearchForm::gotoNextKeyset()
{
  if (checkMutex())
  {
    mainWindow->stopRepeating();
    return;
  }

  if (mainWindow->selectNextKeyset())
  {
    mainWindow->startRepeating(Power_Key);
  }
  else
  {
    if (advanceTimer) delete advanceTimer;
    advanceTimer = 0;
  }
}


bool PIRPowerSearchForm::checkMutex()
{
  QMutexLocker locker(&commandIFMutex);
  return commandInFlight;
}


void PIRPowerSearchForm::on_autoSearchButton_pressed()
{
  if (advanceTimer)
  {
    delete advanceTimer;
    advanceTimer = 0;
    mainWindow->stopRepeating();
    return;
  }

  if (mainWindow->selectFirstKeyset())
  {
    advanceTimer = new QTimer();
    connect(advanceTimer, SIGNAL(timeout()), this, SLOT(gotoNextKeyset()));
    advanceTimer->start(50);
  }
}


void PIRPowerSearchForm::on_pauseSearchButton_pressed()
{
  if (advanceTimer)
  {
    delete advanceTimer;
    advanceTimer = 0;
    mainWindow->stopRepeating();
    return;
  }

  advanceTimer = new QTimer();
  connect(advanceTimer, SIGNAL(timeout()), this, SLOT(gotoNextKeyset()));
  advanceTimer->start(50);
}


void PIRPowerSearchForm::on_editKeysetButton_clicked()
{
  if (advanceTimer)
  {
    delete advanceTimer;
    advanceTimer = 0;
    mainWindow->stopRepeating();
  }

  mainWindow->openCurrentKeysetDialog();
}
