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
#include <QXmlStreamReader>
#include <QMaemo5InformationBox>
#include <QComboBox>

#include <iostream>

PIRMacroPack::PIRMacroPack(
  QString name,
  MainWindow *mw)
  : mainWindow(mw)
{
  setText(0, name);
}


PIRMacroPack::~PIRMacroPack()
{
  MacroCollection::iterator i = macros.begin();

  while (i != macros.end())
  {
    if (i->second)
    {
      delete i->second;
      i->second = 0;
    }

    ++i;
  }
}


void PIRMacroPack::runMacro(
  PIRRunMacroDialog *rmd,
  QString macroName)
{
  MacroCollection::const_iterator i = macros.find(macroName);

  if (i != macros.end())
  {
    i->second->executeMacro(rmd);
  }
}


void PIRMacroPack::abortMacro()
{
  PIRMacro::abortMacro();
}


bool PIRMacroPack::hasButton(
  unsigned int buttonID)
{
  ButtonCollection::const_iterator i = buttons.find(buttonID);

  return (i != buttons.end());
}


void PIRMacroPack::registerButton(
  unsigned int buttonID,
  PIRMacro *macro)
{
  buttons[buttonID] = macro;
}


/*
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
*/


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
  PIRRunMacroDialog *rmd,
  unsigned int buttonID)
{
  ButtonCollection::const_iterator i = buttons.find(buttonID);

  if (i != buttons.end())
  {
    i->second->executeMacro(rmd);
  }
}


bool PIRMacroPack::hasKey(
  char key)
{
  KeyboardCollection::const_iterator i = keymaps.find(key);

  return (i != keymaps.end());
}


void PIRMacroPack::registerKey(
  char key,
  PIRMacro *macro)
{
  keymaps[key] = macro;
}


/*
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
*/


void PIRMacroPack::executeKey(
  PIRRunMacroDialog *rmd,
  char key)
{
  KeyboardCollection::const_iterator i = keymaps.find(key);

  if (i != keymaps.end())
  {
    i->second->executeMacro(rmd);
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


///////////////////////////

// Parse XML

bool PIRMacroPack::parseMacroPack(
  QXmlStreamReader &sr)
{
  PIRMacro *m;

  while (!sr.atEnd())
  {
    sr.readNext();

    if (sr.isStartElement())
    {
      if (sr.name() == "macro")
      {
        QString name = "unnamed";
        char shortcut = 0;
        unsigned int button = 0;

        if (sr.attributes().hasAttribute("name"))
        {
          name = sr.attributes().value("name").toString();
        }

        if (sr.attributes().hasAttribute("shortcut"))
        {
          shortcut = sr.attributes().value("shortcut").at(0).toAscii();
        }

        if (sr.attributes().hasAttribute("button"))
        {
          button = sr.attributes().value("button").toString().toInt();
        }

        m = new PIRMacro(this, name, shortcut, button, mainWindow);

        if (m->parseMacro(sr))
        {
          // Add macro to the collections:
          macros[m->getName()] = m;

          if (m->hasButtonID())
          {
            buttons[m->getButtonID()] = m;
          }

          if (m->hasKey())
          {
            keymaps[m->getKey()] = m;
          }
        }
        else
        {
          // Wasn't able to construct macro:
          delete m;
          m = 0;
        }
      }
    }

    if (sr.isEndElement())
    {
      if (sr.name() == "pack")
      {
        break;
      }
    }
  }

  if (sr.hasError())
  {
    QString errStr = "QXmlStreamReader returned error: ";
    errStr += sr.errorString();
    QMaemo5InformationBox::information(0, errStr, 0);
    return false;
  }

  return true;
}


void PIRMacroPack::populateMacroComboBox(
  QComboBox *cb)
{
  MacroCollection::const_iterator i = macros.begin();

  while (i != macros.end())
  {
    cb->addItem(
      i->second->getName());

    ++i;
  }
}
