//
// pirmacrocommanditem.h
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
