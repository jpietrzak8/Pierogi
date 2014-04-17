//
// pirmacrocommanditem.cpp
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

#include "pirmacrocommanditem.h"

#include "mainwindow.h"
#include "pirkeynames.h"

#include <QSettings>
#include <QTimer>

#include <iostream>

PIRKeynameMgr keynameMgr;


PIRMacroCommandItem::PIRMacroCommandItem()
  : name("Unnamed")
{
}


PIRMacroCommandItem::PIRMacroCommandItem(
  QString displayName)
  : name(displayName)
{
}


QString PIRMacroCommandItem::getName() const
{
  return name;
}


void PIRMacroCommandItem::setName(
  QString n)
{
  name = n;
}


PIRKeyCommandItem::PIRKeyCommandItem(
  PIRKeyName keyToExecute,
  MainWindow *mw)
  : PIRMacroCommandItem(keynameMgr.getKeynameString(keyToExecute)),
    key(keyToExecute),
    advanceTimer(0),
    mainWindow(mw)
{
}


PIRKeyCommandItem::~PIRKeyCommandItem()
{
  if (advanceTimer) delete advanceTimer;
  advanceTimer = 0;
}


void PIRKeyCommandItem::executeCommand()
{
  // First, make sure no other macro is running:
  if (advanceTimer) delete advanceTimer;

  // Start a new timer:
  advanceTimer = new QTimer();
  connect(advanceTimer, SIGNAL(timeout()), this, SLOT(startRunningCommand()));
  advanceTimer->start(50);
}


void PIRKeyCommandItem::startRunningCommand()
{
  // Try to start running the command:
  if (mainWindow->startRepeating(key))
  {
    // The command has successfully started, now wait for it to stop:
    if (advanceTimer) delete advanceTimer;
    advanceTimer = new QTimer();
    connect(advanceTimer, SIGNAL(timeout()), this, SLOT(stopRunningCommand()));
    advanceTimer->start(50);
  }
}


void PIRKeyCommandItem::stopRunningCommand()
{
  mainWindow->stopRepeating();

  if (advanceTimer) delete advanceTimer;
  advanceTimer = 0;

  emit commandCompleted();
}


void PIRKeyCommandItem::storeSettings(
  QSettings &settings,
  int index)
{
  QString commandName = "commandType";
  commandName.append(QString::number(index));
  settings.setValue(commandName, KeyCommand_Type);

  commandName = "commandKeyID";
  commandName.append(QString::number(index));
  settings.setValue(commandName, key);
}


QString PIRKeyCommandItem::getTypeString() const
{
  return "Execute Keypress: ";
}


////////////////////////////

PIRKeysetCommandItem::PIRKeysetCommandItem(
  QString displayName,
  unsigned int keysetToChoose,
  MainWindow *mw)
  : PIRMacroCommandItem(displayName),
    id(keysetToChoose),
    mainWindow(mw)
{
}


PIRKeysetCommandItem::PIRKeysetCommandItem(
  unsigned int keysetToChoose,
  MainWindow *mw)
  : PIRMacroCommandItem(),
    id(keysetToChoose),
    mainWindow(mw)
{
  setName(mainWindow->getFullKeysetName(keysetToChoose));
}


void PIRKeysetCommandItem::executeCommand()
{
  mainWindow->updateKeysetSelection(id);
  emit commandCompleted();
}


void PIRKeysetCommandItem::storeSettings(
  QSettings &settings,
  int index)
{
  QString commandName = "commandType";
  commandName.append(QString::number(index));
  settings.setValue(commandName, KeysetCommand_Type);

  commandName = "commandKeysetMake";
  commandName.append(QString::number(index));
  settings.setValue(commandName, mainWindow->getKeysetMake(id));

  commandName = "commandKeysetName";
  commandName.append(QString::number(index));
  settings.setValue(commandName, mainWindow->getKeysetName(id));

  commandName = "commandKeysetDisplayName";
  commandName.append(QString::number(index));
  settings.setValue(commandName, mainWindow->getFullKeysetName(id));
}


QString PIRKeysetCommandItem::getTypeString() const
{
  return "Choose Keyset: ";
}


PIRPauseCommandItem::PIRPauseCommandItem(
  unsigned int timeToWait)
  : timeInSeconds(timeToWait),
    advanceTimer(0)
{
  QString pauseName = "Pause for ";
  pauseName.append(QString::number(timeToWait));
  pauseName.append(" seconds");

  setName(pauseName);
}


PIRPauseCommandItem::~PIRPauseCommandItem()
{
  if (advanceTimer) delete advanceTimer;
}


void PIRPauseCommandItem::executeCommand()
{
  if (advanceTimer) delete advanceTimer;

  advanceTimer = new QTimer();
  connect(advanceTimer, SIGNAL(timeout()), this, SLOT(finishedWaiting()));
  advanceTimer->start(timeInSeconds * 1000);
}


void PIRPauseCommandItem::finishedWaiting()
{
  if (advanceTimer)
  {
    delete advanceTimer;
    advanceTimer = 0;
  }

  emit commandCompleted();
}


void PIRPauseCommandItem::storeSettings(
  QSettings &settings,
  int index)
{
  QString commandName = "commandType";
  commandName.append(QString::number(index));
  settings.setValue(commandName, PauseCommand_Type);

  commandName = "commandPause";
  commandName.append(QString::number(index));
  settings.setValue(commandName, timeInSeconds);
}


QString PIRPauseCommandItem::getTypeString() const
{
  return "Pause (in seconds): ";
}
