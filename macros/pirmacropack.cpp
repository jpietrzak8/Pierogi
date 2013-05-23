//
// pirmacropack.cpp
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

#include "pirmacropack.h"

#include "pirmacro.h"

#include <QSettings>

#include <iostream>

PIRMacroPack::PIRMacroPack(
  QString name)
{
  setText(0, name);
}


bool PIRMacroPack::hasButton(
  unsigned int buttonID)
{
  ButtonCollection::const_iterator i = buttons.find(buttonID);

  if (i != buttons.end())
  {
    return true;
  }
  else
  {
    return false;
  }
}


void PIRMacroPack::registerButton(
  unsigned int buttonID,
  PIRMacro *macro)
{
  buttons[buttonID] = macro;
}


void PIRMacroPack::eraseButton(
  unsigned int buttonID,
  PIRMacro *macro)
{
  ButtonCollection::iterator i = buttons.find(buttonID);

  if (i != buttons.end() && (*i).second == macro)
  {
    buttons.erase(i);
  }
}


QString PIRMacroPack::buttonText(
  unsigned int buttonID)
{
  ButtonCollection::const_iterator i = buttons.find(buttonID);

  if (i != buttons.end())
  {
    return i->second->getName();
  }
  else
  {
    return "Error: Macro not found";
  }
}


void PIRMacroPack::executeButton(
  unsigned int buttonID)
{
  ButtonCollection::const_iterator i = buttons.find(buttonID);

  if (i != buttons.end())
  {
    i->second->executeMacro();
  }
}


bool PIRMacroPack::hasKey(
  char key)
{
  KeyboardCollection::const_iterator i = keymaps.find(key);

  if (i != keymaps.end())
  {
    return true;
  }
  else
  {
    return false;
  }
}


void PIRMacroPack::registerKey(
  char key,
  PIRMacro *macro)
{
  keymaps[key] = macro;
}


void PIRMacroPack::eraseKey(
  char key,
  PIRMacro *macro)
{
  KeyboardCollection::iterator i = keymaps.find(key);

  if (i != keymaps.end() && (*i).second == macro)
  {
    keymaps.erase(i);
  }
}


void PIRMacroPack::executeKey(
  char key)
{
  KeyboardCollection::const_iterator i = keymaps.find(key);

  if (i != keymaps.end())
  {
    i->second->executeMacro();
  }
}


void PIRMacroPack::storeSettings()
{
  QSettings settings("pietrzak.org", "Pierogi");

  // Erase any existing macros:
  settings.remove("userMacros");

  // First, do we even have any macros?  If not, quit.
  int macroCount = childCount();
  if (macroCount == 0) return;

  // (Re-) Construct the macros array:

  int index = 0;
  PIRMacro *macro;

  settings.beginWriteArray("userMacros");

  while (index < macroCount)
  {
    settings.setArrayIndex(index);
    macro = dynamic_cast<PIRMacro *> (child(index));

    macro->storeSettings(settings);

    ++index;
  }

  settings.endArray();
}
