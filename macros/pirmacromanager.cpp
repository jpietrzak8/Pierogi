//
// pirmacromanager.cpp
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

#include "pirmacromanager.h"

#include "pirmacropack.h"
//#include "pirreversemultitap.h"
#include "pirmacro.h"
#include "pirmacrocommanditem.h"
#include "mainwindow.h"
#include "dialogs/pirrunmacrodialog.h"

//#include <QSettings>
#include <QXmlStreamReader>
#include <QFile>
#include <QMaemo5InformationBox>

#include <iostream>

PIRMacroManager::PIRMacroManager(
  MainWindow *mw)
  : macroPack(0),
    macroDialog(0),
    mainWindow(mw)
{
//  userPack = new PIRMacroPack("User Defined Macros");
//  multitapPack = new PIRReverseMultitap(mw);

//  retrieveSettings();

  // For testing, set the multitap pack as the keyboard controller:
//  keyboardController = multitapPack;

  // And more testing, userpack as button controller:
//  buttonsController = userPack;

  macroDialog = new PIRRunMacroDialog(mainWindow);
}


PIRMacroManager::~PIRMacroManager()
{
// The UI currently owns the macro packs...
//  delete userPack;
//  delete multitapPack;

  if (macroDialog) delete macroDialog;
}


/*
PIRMacroPack *PIRMacroManager::getUserPack()
{
  return userPack;
}


PIRMacroPack *PIRMacroManager::getMultitapPack()
{
  return multitapPack;
}
*/


/*
void PIRMacroManager::setKeyboardMacros(
  PIRMacroPack *pack)
{
  keyboardMacros = pack;
}


void PIRMacroManager::setButtonMacros(
  PIRMacroPack *pack)
{
  buttonMacros = pack;
}
*/


void PIRMacroManager::runMacro(
  QString macroName)
{
  if (macroPack)
  {
    macroPack->runMacro(macroDialog, macroName);
  }
}


void PIRMacroManager::abortMacro()
{
  if (macroPack)
  {
    macroPack->abortMacro();
  }
}


void PIRMacroManager::handleKeypress(
  char key)
{
  if (macroPack)
  {
    macroPack->executeKey(macroDialog, key);
  }
  else
  {
    executeStandardKey(key);
  }
}


bool PIRMacroManager::hasMacroButton(
  unsigned int buttonID)
{
  if (macroPack)
    return macroPack->hasButton(buttonID);

  return false;
}


QString PIRMacroManager::getMacroButtonText(
  unsigned int buttonID)
{
  if (macroPack)
    return macroPack->buttonText(buttonID);

  return "No Macro Found";
}


void PIRMacroManager::executeMacroButton(
  unsigned int buttonID)
{
  if (macroPack) macroPack->executeButton(macroDialog, buttonID);
}


/*
void PIRMacroManager::storeSettings()
{
  if (userPack) userPack->storeSettings();
}


void PIRMacroManager::retrieveSettings()
{
  // Pull in any user-defined macros:
  QSettings settings("pietrzak.org", "Pierogi");
  int size = settings.beginReadArray("userMacros");
  int index = 0;
  QString macroName;
  char macroKey;
  unsigned int macroButtonID;
  PIRMacro *macro;
  PIRMacroCommandItem *macroCommand;
  int commandIndex;
  QString commandName;
  int commandType;
  unsigned int keysetID;
  QString commandKeysetName;
  QString commandKeysetMakeStr;
  QString commandKeysetDisplayName;
  PIRKeyName commandKeyID;
  unsigned int commandPause;

  while (index < size)
  {
    settings.setArrayIndex(index);
    macroName = settings.value("macroName").toString();
    macroKey = settings.value("macroKey").toInt();
    macroButtonID = settings.value("macroButtonID").toInt();

    macro = new PIRMacro(
      userPack, macroName, macroKey, macroButtonID, mainWindow);

    commandIndex = 0;
    commandName = "commandType";
    commandName.append(QString::number(commandIndex));
    while (settings.contains(commandName))
    {
      commandType = settings.value(commandName).toInt();
      switch(CommandItemType(commandType))
      {
      case KeysetCommand_Type:
        commandName = "commandKeysetName";
        commandName.append(QString::number(commandIndex));
        commandKeysetName = settings.value(commandName).toString();

        commandName = "commandKeysetMake";
        commandName.append(QString::number(commandIndex));
        commandKeysetMakeStr = settings.value(commandName).toString();

        commandName = "commandKeysetDisplayName";
        commandName.append(QString::number(commandIndex));
        commandKeysetDisplayName = settings.value(commandName).toString();

        if (mainWindow->findKeysetID(
            commandKeysetMakeStr,
            commandKeysetName,
            keysetID))
        {
          macroCommand = new PIRKeysetCommandItem(
            commandKeysetDisplayName,
            keysetID,
            mainWindow);

          macro->appendCommand(macroCommand);
        }

        break;

      case KeyCommand_Type:
        commandName = "commandKeyID";
        commandName.append(QString::number(commandIndex));
        commandKeyID = PIRKeyName(settings.value(commandName).toInt());

        macroCommand = new PIRKeyCommandItem(commandKeyID, mainWindow);

        macro->appendCommand(macroCommand);

        break;

      case PauseCommand_Type:
        commandName = "commandPause";
        commandName.append(QString::number(commandIndex));
        commandPause = settings.value(commandName).toInt();

        macroCommand = new PIRPauseCommandItem(commandPause);

        macro->appendCommand(macroCommand);

        break;

      default:
        break;
      }

      ++commandIndex;
      commandName = "commandType";
      commandName.append(QString::number(commandIndex));
    }

    ++index;
  }

  settings.endArray();
}
*/


// This needs to be done differently!!!
/*
void PIRMacroManager::setKbdFocus(
  int index)
{
  if (index == 0)
  {
    keyboardController = userPack;
  }
  else
  {
    keyboardController = multitapPack;
  }
}


void PIRMacroManager::setBtnFocus(
  int index)
{
  if (index == 0)
  {
    buttonsController = userPack;
  }
  else
  {
    buttonsController = multitapPack;
  }
}
*/


void PIRMacroManager::executeStandardKey(
  char key)
{
  switch (key)
  {
  case 'Q':
    mainWindow->switchToTab(0);
    break;

  case 'W':
    mainWindow->switchToTab(1);
    break;

  case 'E':
    mainWindow->switchToTab(2);
    break;

  case 'R':
    mainWindow->switchToTab(3);
    break;

  case 'T':
    mainWindow->switchToTab(4);
    break;

  case 'Y':
    mainWindow->switchToTab(5);
    break;

  case 'U':
    mainWindow->switchToTab(6);
    break;

  case 'I':
    mainWindow->switchToTab(7);
    break;

  case 'O':
    mainWindow->switchToTab(8);
    break;

  case 'P':
    mainWindow->switchToTab(9);

  default:
    break;
  }
}


bool PIRMacroManager::parseMacroFile(
  QString filename)
{
  QFile f(filename);

  if (!f.exists())
  {
    QString errStr = "File ";
    errStr += filename;
    errStr += " does not exist.";
    QMaemo5InformationBox::information(0, errStr, 0);
    return false;
  }

  if (!f.open(QIODevice::ReadOnly | QIODevice::Text))
  {
    QString errStr = "File ";
    errStr += filename;
    errStr += " could not be opened.";
    QMaemo5InformationBox::information(0, errStr, 0);
    return false;
  }

  QXmlStreamReader sr(&f);
  PIRMacroPack *pack = 0;

  while (!sr.atEnd())
  {
    sr.readNext();

    if (sr.isStartElement())
    {
      if (sr.name() == "macropack")
      {
        QString name = "unnamed";

        if (sr.attributes().hasAttribute("name"))
        {
          name = sr.attributes().value("name").toString();
        }

        pack = new PIRMacroPack(name, mainWindow);

        if (!pack->parseMacroPack(sr))
        {
          // parsing failed.
          QString errStr = "Failed to parse ";
          errStr += name;
          errStr += " macro pack.";
          QMaemo5InformationBox::information(0, errStr, 0);
          return false;
        }
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

  // If we reach this point, we should have a valid pack:
  if (macroPack)
  {
    // Remove the existing macro pack:
    delete macroPack;
  }

  macroPack = pack;

  return true;
}


void PIRMacroManager::populateMacroComboBox(
  QComboBox *cb)
{
  if (macroPack)
  {
    macroPack->populateMacroComboBox(cb);
  }
}
