#include "pirmacro.h"

#include "macros/pirmacrocommanditem.h"

bool PIRMacro::macroRunning = false;

PIRMacro::PIRMacro(
  QTreeWidgetItem *parent,
  QString n,
  char k)
  : QTreeWidgetItem(parent),
    keyMapping(k)
{
  setText(0, n);
}


QString PIRMacro::getName()
{
  return text(0);
}


char PIRMacro::getKeyMapping()
{
  return keyMapping;
}


void PIRMacro::appendCommand(
  PIRMacroCommandItem *c)
{
  commands.push_back(c);
}


void PIRMacro::populateList(
  QListWidget *lw)
{
  lw->clear();

  CommandSequence::const_iterator i = commands.begin();

  while (i != commands.end())
  {
    lw->addItem(*i);
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

  connect(
    *currentCommand,
    SIGNAL(commandCompleted()),
    this,
    SLOT(startNextCommand()));

  (*currentCommand)->executeCommand();

  ++currentCommand;

  return true;
}


void PIRMacro::startNextCommand()
{
  // Are we done?
  if (currentCommand == commands.end())
  {
    // We are done.
    macroRunning = false;
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

  ++currentCommand;
}
