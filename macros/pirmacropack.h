//
// pirmacropack.h
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

#ifndef PIRMACROPACK_H
#define PIRMACROPACK_H

#include <QTreeWidgetItem>
#include <QString>
#include <map>

class QTreeWidget;
class PIRMacro;

typedef std::map<unsigned int, PIRMacro *> ButtonCollection;
typedef std::map<char, PIRMacro *> KeyboardCollection;

class PIRMacroPack: public QTreeWidgetItem
{
public:
  PIRMacroPack(
    QString n);

  bool hasButton(
    unsigned int buttonID);

  void registerButton(
    unsigned int buttonID,
    PIRMacro *macro);

  void eraseButton(
    unsigned int buttonID,
    PIRMacro *macro);

  QString buttonText(
    unsigned int buttonID);

  void executeButton(
    unsigned int buttonID);

  bool hasKey(
    char key);

  void registerKey(
    char key,
    PIRMacro *macro);

  void eraseKey(
    char key,
    PIRMacro *macro);

  void executeKey(
    char key);

  void storeSettings();

private:
  ButtonCollection buttons;
  KeyboardCollection keymaps;
};

#endif // PIRMACROPACK_H
