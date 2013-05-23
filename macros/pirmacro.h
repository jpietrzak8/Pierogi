//
// pirmacro.h
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

#ifndef PIRMACRO_H
#define PIRMACRO_H

#include <QObject>
#include <QTreeWidgetItem>
#include <QString>

class PIRMacroCommandItem;
class PIRMacroPack;
class QListWidget;
class QSettings;
class MainWindow;

#include <list>
typedef std::list<PIRMacroCommandItem *> CommandSequence;

class PIRMacro: public QObject, public QTreeWidgetItem
{
  Q_OBJECT

public:
  PIRMacro(
    PIRMacroPack *parent,
    QString name,
    char key,
    unsigned int buttonID,
    MainWindow *mw);

  ~PIRMacro();

  QString getName();

  void setName(
    QString name);

  char getKey();

  void setKey(
    char key);

  unsigned int getButtonID();

  void setButtonID(
    unsigned int id);

  void appendCommand(
    PIRMacroCommandItem *c);

  bool deleteCommand(
    int index);

  bool moveUp(
    int index);

  bool moveDown(
    int index);

  void populateList(
    QListWidget *lw);

  bool executeMacro();

  void storeSettings(
    QSettings &settings);

  QString getCommandType(
    int index);

  QString getCommandName(
    int index);

signals:
  void macroCompleted();

private slots:
  void startNextCommand();

private:
  char key;
  unsigned int buttonID;
  CommandSequence commands;
  CommandSequence::iterator currentCommand;
  unsigned int preMacroKeysetID;

  static bool macroRunning; // only one macro can run at a time!

  MainWindow *mainWindow;
};

#endif // PIRMACRO_H
