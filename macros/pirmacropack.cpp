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
