//
// pirmacro.cpp
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

#include "pirmacro.h"

#include "pirmacrocommanditem.h"
#include "pirmacropack.h"
#include "mainwindow.h"
#include "dialogs/pirrunmacrodialog.h"

#include <QSettings>
#include <QXmlStreamReader>
#include <QMaemo5InformationBox>

#include <iostream>

// An ugly global, need to work on this:
extern PIRKeynameMgr keynameMgr;

bool PIRMacro::macroRunning = false;
bool PIRMacro::stopRunningMacro = false;

PIRMacro::PIRMacro(
  PIRMacroPack *parent,
  QString name,
  char k,
  unsigned int b,
  MainWindow *mw)
  : QTreeWidgetItem(parent),
    keyDefined(false),
    key(k),
    buttonDefined(false),
    buttonID(b),
    macroDialog(0),
    mainWindow(mw)
{
  setText(0, name);

  if (key)
  {
    parent->registerKey(key, this);
    keyDefined = true;
  }

  if (buttonID)
  {
    parent->registerButton(buttonID, this);
    buttonDefined = true;
  }
}


PIRMacro::~PIRMacro()
{
  currentCommand = commands.begin();
  while (currentCommand != commands.end())
  {
    delete *currentCommand;
    commands.pop_front();
    currentCommand = commands.begin();
  }
}


QString PIRMacro::getName()
{
  return text(0);
}


void PIRMacro::setName(
  QString name)
{
  setText(0, name);
}


bool PIRMacro::hasKey()
{
  return keyDefined;
}


char PIRMacro::getKey()
{
  return key;
}


void PIRMacro::setKey(
  char k)
{
  key = k;
}


bool PIRMacro::hasButtonID()
{
  return buttonDefined;
}


unsigned int PIRMacro::getButtonID()
{
  return buttonID;
}


void PIRMacro::setButtonID(
  unsigned int id)
{
  buttonID = id;
}

void PIRMacro::appendCommand(
  PIRMacroCommandItem *c)
{
  commands.push_back(c);
}


bool PIRMacro::deleteCommand(
  int index)
{
  CommandSequence::iterator i = commands.begin();
  int count = 0;

  while (i != commands.end())
  {
    if (index == count)
    {
      delete (*i);
      commands.erase(i);
      return true;
    }
    ++count;
    ++i;
  }

  return false;
}


bool PIRMacro::moveUp(
  int index)
{
  CommandSequence::iterator i = commands.begin();
  int count = 0;
  CommandSequence::iterator previ = commands.begin();

  while (i != commands.end())
  {
    if (index == count)
    {
      PIRMacroCommandItem *mci = *i;
      commands.erase(i);
      commands.insert(previ, mci);
      return true;
    }

    previ = i;
    ++count;
    ++i;
  }

  return false;
}


bool PIRMacro::moveDown(
  int index)
{
  CommandSequence::iterator i = commands.begin();
  CommandSequence::iterator nexti = commands.begin();
  int count = 0;

  while (i != commands.end())
  {
    ++nexti;
    if ((index == count) && nexti != commands.end())
    {
      PIRMacroCommandItem *mci = *i;
      commands.erase(i);
      ++nexti;
      commands.insert(nexti, mci);
      return true;
    }

    ++count;
    ++i;
  }

  return false;
}


void PIRMacro::populateList(
  QListWidget *lw)
{
  lw->clear();

  CommandSequence::const_iterator i = commands.begin();

  while (i != commands.end())
  {
    lw->addItem(new QListWidgetItem((*i)->getName()));
    ++i;
  }
}


// executeMacro() returns false if it was unable to start the macro running:
bool PIRMacro::executeMacro(
  PIRRunMacroDialog *rmd)
{
  // Don't start a new macro if one is already running:
  if (macroRunning) return false;

  stopRunningMacro = false;

  currentCommand = commands.begin();

  // If this macro is empty, just return:
  if (currentCommand == commands.end())
  {
    emit macroCompleted();
    macroRunning = false;
    return true;
  }

  // Prepare the macro dialog box:
  macroDialog = rmd;
  macroDialog->setMacroName(text(0));
  macroDialog->setModal(true);

  // Start running the list of commands:
  macroRunning = true;

  // Take note of the current keyset id:
  preMacroKeysetID = mainWindow->getCurrentKeyset();

  connect(
    *currentCommand,
    SIGNAL(commandCompleted()),
    this,
    SLOT(startNextCommand()));

  macroDialog->setCommandName(
    (*currentCommand)->getName());

  macroDialog->show();

  (*currentCommand)->executeCommand();

  return true;
}


void PIRMacro::abortMacro()
{
  stopRunningMacro = true;
}


void PIRMacro::startNextCommand()
{
  disconnect(
    *currentCommand,
    SIGNAL(commandCompleted()),
    0,
    0);

  ++currentCommand;

  // Are we done?
  if (currentCommand == commands.end() || stopRunningMacro)
  {
    // We are done.
    mainWindow->updateKeysetSelection(preMacroKeysetID);
    emit macroCompleted();
    macroDialog->hide();
    macroDialog = 0;
    macroRunning = false;
    return;
  }

  // We are not done; run the next command.
  connect(
    *currentCommand,
    SIGNAL(commandCompleted()),
    this,
    SLOT(startNextCommand()));

  macroDialog->setCommandName(
    (*currentCommand)->getName());

  (*currentCommand)->executeCommand();
}


void PIRMacro::storeSettings(
  QSettings &settings)
{
  settings.setValue("macroName", text(0));
  settings.setValue("macroKey", key);
  settings.setValue("macroButtonID", buttonID);

  CommandSequence::const_iterator i = commands.begin();

  int index = 0;
  while (i != commands.end())
  {
    (*i)->storeSettings(settings, index);
    ++index;
    ++i;
  }
}


QString PIRMacro::getCommandType(
  int index)
{
  CommandSequence::iterator i = commands.begin();

  // Advance 'index' steps into the sequence:
  while (i != commands.end() && index)
  {
    ++i;
    --index;
  }

  if (i != commands.end())
  {
    return (*i)->getTypeString();
  }

  return "";
}


QString PIRMacro::getCommandName(
  int index)
{
  CommandSequence::iterator i = commands.begin();

  while (i != commands.end() && index)
  {
    ++i;
    --index;
  }

  if (i != commands.end())
  {
    return (*i)->getName();
  }

  return "";
}


/////////////////////////

// Parse XML

bool PIRMacro::parseMacro(
  QXmlStreamReader &sr)
{
  while (!sr.atEnd())
  {
    sr.readNext();

    if (sr.isStartElement())
    {
      if (sr.name() == "send")
      {
        if (sr.attributes().hasAttribute("key"))
        {
          PIRKeyName kn = keynameMgr.getKeynameID(
            sr.attributes().value("key"));

          if (kn == Unmapped_Key)
          {
            QString errStr = "Could not find mapping for key: ";
            errStr += sr.attributes().value("key");
            QMaemo5InformationBox::information(0, errStr, 0);
            break;
          }

          PIRKeyCommandItem *kci = new PIRKeyCommandItem(kn, mainWindow);

          commands.push_back(kci);
        }

        // Need error message here!
      }

      else if (sr.name() == "pause")
      {
        // Construct a "pause" command
        if (sr.attributes().hasAttribute("seconds"))
        {
          unsigned int seconds =
            sr.attributes().value("seconds").toString().toInt();

          PIRPauseCommandItem *pci = new PIRPauseCommandItem(seconds);

          commands.push_back(pci);
        }
      }

      else if (sr.name() == "keyset")
      {
        // Construct a "change keyset" command:
        if ( sr.attributes().hasAttribute("make")
          && sr.attributes().hasAttribute("name"))
        {
          QString make(sr.attributes().value("make").toString());
          QString name(sr.attributes().value("name").toString());
          unsigned int keysetID;
          QString displayName = make + " " + name;

          if (!mainWindow->findKeysetID(make, name, keysetID))
          {
            QString errStr = "Could not find keyset: ";
            errStr += displayName;
            QMaemo5InformationBox::information(0, errStr, 0);
            return false;
          }

          PIRKeysetCommandItem *kci = new PIRKeysetCommandItem(
            displayName,
            keysetID,
            mainWindow);

          commands.push_back(kci);
        }
      }
    }

    if (sr.isEndElement())
    {
      if (sr.name() == "macro")
      {
        break;
      }
    }
  }

  if (sr.hasError())
  {
    QString errStr = "QXmlStreamReader returned error: ";
    errStr += sr.errorString();
    QMaemo5InformationBox::information(0, errStr, 0);
    return false;
  }

  return true;
}
