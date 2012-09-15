#ifndef PIRMACROCOMMANDITEM_H
#define PIRMACROCOMMANDITEM_H

#include <QListWidgetItem>
#include <QObject>
#include <QString>

#include "pirkeynames.h"

class QTimer;
class QSettings;
class MainWindow;

// For convenience:
enum CommandItemType{
  NoCommand_Type,
  KeysetCommand_Type,
  KeyCommand_Type,
  PauseCommand_Type
};

class PIRMacroCommandItem: public QObject
{
  Q_OBJECT

public:
  PIRMacroCommandItem();

  PIRMacroCommandItem(
    QString displayName);

  virtual void executeCommand() = 0;

  virtual void storeSettings(
    QSettings &settings,
    int index) = 0;

  virtual QString getTypeString() const = 0;

  QString getName() const;

  void setName(
    QString name);

signals:
  void commandCompleted();

private:
  QString name;
};


class PIRKeyCommandItem: public PIRMacroCommandItem
{
  Q_OBJECT

public:
  PIRKeyCommandItem(
    PIRKeyName keyToExecute,
    MainWindow *mw);

  ~PIRKeyCommandItem();

  virtual void executeCommand();

  virtual void storeSettings(
    QSettings &settings,
    int index);

  virtual QString getTypeString() const;

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

  PIRKeysetCommandItem(
    unsigned int keysetToChoose,
    MainWindow *mw);

  virtual void executeCommand();

  virtual void storeSettings(
    QSettings &settings,
    int index);

  virtual QString getTypeString() const;

private:
  unsigned int id;
  MainWindow *mainWindow;
};


class PIRPauseCommandItem: public PIRMacroCommandItem
{
  Q_OBJECT

public:
  PIRPauseCommandItem(
    unsigned int timeToWait);

  ~PIRPauseCommandItem();

  virtual void executeCommand();

  virtual void storeSettings(
    QSettings &settings,
    int index);

  virtual QString getTypeString() const;

private slots:
  void finishedWaiting();

private:
  unsigned int timeInSeconds;
  QTimer *advanceTimer;
};


#endif // PIRMACROCOMMANDITEM_H
