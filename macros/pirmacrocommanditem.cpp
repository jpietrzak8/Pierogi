#include "pirmacrocommanditem.h"

#include "mainwindow.h"
#include "pirkeynames.h"

#include <QTimer>

PIRKeynameMgr keynameMgr;


PIRMacroCommandItem::PIRMacroCommandItem(
  QString displayName)
  : QListWidgetItem(displayName)
{
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


PIRKeysetCommandItem::PIRKeysetCommandItem(
  QString displayName,
  unsigned int keysetToChoose,
  MainWindow *mw)
  : PIRMacroCommandItem(displayName),
    id(keysetToChoose),
    mainWindow(mw)
{
}


void PIRKeysetCommandItem::executeCommand()
{
  mainWindow->updateKeysetSelection(id);
  emit commandCompleted();
}


PIRPauseCommandItem::PIRPauseCommandItem(
  QString displayName,
  unsigned int timeToWait)
  : PIRMacroCommandItem(displayName),
    timeInSeconds(timeToWait),
    advanceTimer(0)
{
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
