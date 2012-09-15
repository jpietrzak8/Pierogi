#include "pirmacro.h"

#include "pirmacrocommanditem.h"
#include "pirmacropack.h"
#include "mainwindow.h"

#include <QSettings>

#include <iostream>

bool PIRMacro::macroRunning = false;

PIRMacro::PIRMacro(
  PIRMacroPack *parent,
  QString name,
  char k,
  unsigned int b,
  MainWindow *mw)
  : QTreeWidgetItem(parent),
    key(k),
    buttonID(b),
    mainWindow(mw)
{
  setText(0, name);

  if (key)
  {
    parent->registerKey(key, this);
  }

  if (buttonID)
  {
    parent->registerButton(buttonID, this);
  }
}


PIRMacro::~PIRMacro()
{
  PIRMacroPack *mp = dynamic_cast<PIRMacroPack*> (QTreeWidgetItem::parent());

  if (key)
  {
    mp->eraseKey(key, this);
  }

  if (buttonID)
  {
    mp->eraseButton(buttonID, this);
  }

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


char PIRMacro::getKey()
{
  return key;
}


void PIRMacro::setKey(
  char k)
{
  key = k;
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
bool PIRMacro::executeMacro()
{
  // Don't start a new macro if one is already running:
  if (macroRunning) return false;

  currentCommand = commands.begin();

  // If this macro is empty, just return:
  if (currentCommand == commands.end())
  {
    emit macroCompleted();
    return true;
  }

  // Start running the list of commands:
  macroRunning = true;

  // Take note of the current keyset id:
  preMacroKeysetID = mainWindow->getCurrentKeyset();

  connect(
    *currentCommand,
    SIGNAL(commandCompleted()),
    this,
    SLOT(startNextCommand()));

  (*currentCommand)->executeCommand();

  return true;
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
  if (currentCommand == commands.end())
  {
    // We are done.
    macroRunning = false;
    mainWindow->updateKeysetSelection(preMacroKeysetID);
    emit macroCompleted();
    return;
  }

  // We are not done; run the next command.
  connect(
    *currentCommand,
    SIGNAL(commandCompleted()),
    this,
    SLOT(startNextCommand()));

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
