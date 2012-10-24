#include "pirmacromanager.h"

#include "pirmacropack.h"
#include "pirreversemultitap.h"
#include "pirmacro.h"
#include "pirmacrocommanditem.h"
#include "mainwindow.h"

#include <QSettings>
#include <iostream>

PIRMacroManager::PIRMacroManager(
  MainWindow *mw)
  : userPack(0),
    multitapPack(0),
    keyboardController(0),
    buttonsController(0),
    mainWindow(mw)
{
  userPack = new PIRMacroPack("User Defined Macros");
  multitapPack = new PIRReverseMultitap(mw);

  retrieveSettings();

  // For testing, set the multitap pack as the keyboard controller:
//  keyboardController = multitapPack;

  // And more testing, userpack as button controller:
//  buttonsController = userPack;
}


PIRMacroManager::~PIRMacroManager()
{
// The UI currently owns the macro packs...
//  delete userPack;
//  delete multitapPack;
}


PIRMacroPack *PIRMacroManager::getUserPack()
{
  return userPack;
}


PIRMacroPack *PIRMacroManager::getMultitapPack()
{
  return multitapPack;
}


void PIRMacroManager::setKeyboardController(
  PIRMacroPack *pack)
{
  keyboardController = pack;
}


void PIRMacroManager::setButtonsController(
  PIRMacroPack *pack)
{
  buttonsController = pack;
}


void PIRMacroManager::handleKeypress(
  char key)
{
  if (keyboardController)
  {
    keyboardController->executeKey(key);
  }
  else
  {
    executeStandardKey(key);
  }
}


bool PIRMacroManager::hasMacroButton(
  unsigned int buttonID)
{
  if (buttonsController)
    return buttonsController->hasButton(buttonID);

  return false;
}


QString PIRMacroManager::getMacroButtonText(
  unsigned int buttonID)
{
  if (buttonsController)
    return buttonsController->buttonText(buttonID);

  return "No Macro Found";
}


void PIRMacroManager::executeMacroButton(
  unsigned int buttonID)
{
  if (buttonsController)
    buttonsController->executeButton(buttonID);
}


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


// This needs to be done differently!!!
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
