#ifndef PIRMACROCOMMANDITEM_H
#define PIRMACROCOMMANDITEM_H

#include <QListWidgetItem>
#include <QObject>
#include <QString>

#include "pirkeynames.h"

class QTimer;
class MainWindow;


class PIRMacroCommandItem: public QObject, public QListWidgetItem
{
  Q_OBJECT

public:
  PIRMacroCommandItem(
    QString displayName);

  virtual void executeCommand() = 0;

signals:
  void commandCompleted();
};


class PIRKeyCommandItem: public PIRMacroCommandItem
{
  Q_OBJECT

public:
  PIRKeyCommandItem(
    PIRKeyName keyToExecute,
    MainWindow *mw);

  virtual void executeCommand();

private slots:
  void startRunningCommand();
  void stopRunningCommand();

private:
  PIRKeyName key;
  QTimer *advanceTimer;
  MainWindow *mainWindow;
};


class PIRKeysetCommandItem: public PIRMacroCommandItem
{
  Q_OBJECT

public:
  PIRKeysetCommandItem(
    QString displayName,
    unsigned int keysetToChoose,
    MainWindow *mw);

  virtual void executeCommand();

private:
  unsigned int id;
  MainWindow *mainWindow;
};


class PIRPauseCommandItem: public PIRMacroCommandItem
{
  Q_OBJECT

public:
  PIRPauseCommandItem(
    QString displayName,
    unsigned int timeToWait);

  virtual void executeCommand();

private slots:
  void finishedWaiting();

private:
  unsigned int timeInSeconds;
  QTimer *advanceTimer;
};


#endif // PIRMACROCOMMANDITEM_H
