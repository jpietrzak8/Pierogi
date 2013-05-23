//
// pirreversemultitap.cpp
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

#include "pirreversemultitap.h"

#include "pirmacro.h"
#include "pirmacrocommanditem.h"

#include <iostream>

PIRReverseMultitap::PIRReverseMultitap(
  MainWindow *mw)
  : PIRMacroPack(
      "Reverse Multitap Keyboard Macros"),
    mainWindow(mw)
{
  generateLetterA();
  generateLetterB();
  generateLetterC();
  generateLetterD();
  generateLetterE();
  generateLetterF();
  generateLetterG();
  generateLetterH();
  generateLetterI();
  generateLetterJ();
  generateLetterK();
  generateLetterL();
  generateLetterM();
  generateLetterN();
  generateLetterO();
  generateLetterP();
  generateLetterQ();
  generateLetterR();
  generateLetterS();
  generateLetterT();
  generateLetterU();
  generateLetterV();
  generateLetterW();
  generateLetterX();
  generateLetterY();
  generateLetterZ();
  generateSpace();
}

void PIRReverseMultitap::generateLetterA()
{
  PIRMacro *m = new PIRMacro(this, "Multitap A", 'A', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Two_Key, mainWindow));
//  registerKey('A', m);
}

void PIRReverseMultitap::generateLetterB()
{
  PIRMacro *m = new PIRMacro(this, "Multitap B", 'B', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Two_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Two_Key, mainWindow));
//  registerKey('B', m);
}

void PIRReverseMultitap::generateLetterC()
{
  PIRMacro *m = new PIRMacro(this, "Multitap C", 'C', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Two_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Two_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Two_Key, mainWindow));
//  registerKey('C', m);
}

void PIRReverseMultitap::generateLetterD()
{
  PIRMacro *m = new PIRMacro(this, "Multitap D", 'D', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Three_Key, mainWindow));
//  registerKey('D', m);
}

void PIRReverseMultitap::generateLetterE()
{
  PIRMacro *m = new PIRMacro(this, "Multitap E", 'E', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Three_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Three_Key, mainWindow));
//  registerKey('E', m);
}

void PIRReverseMultitap::generateLetterF()
{
  PIRMacro *m = new PIRMacro(this, "Multitap F", 'F', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Three_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Three_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Three_Key, mainWindow));
//  registerKey('F', m);
}

void PIRReverseMultitap::generateLetterG()
{
  PIRMacro *m = new PIRMacro(this, "Multitap G", 'G', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Four_Key, mainWindow));
//  registerKey('G', m);
}

void PIRReverseMultitap::generateLetterH()
{
  PIRMacro *m = new PIRMacro(this, "Multitap H", 'H', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Four_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Four_Key, mainWindow));
//  registerKey('H', m);
}

void PIRReverseMultitap::generateLetterI()
{
  PIRMacro *m = new PIRMacro(this, "Multitap I", 'I', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Four_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Four_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Four_Key, mainWindow));
//  registerKey('I', m);
}

void PIRReverseMultitap::generateLetterJ()
{
  PIRMacro *m = new PIRMacro(this, "Multitap J", 'J', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Five_Key, mainWindow));
//  registerKey('J', m);
}

void PIRReverseMultitap::generateLetterK()
{
  PIRMacro *m = new PIRMacro(this, "Multitap K", 'K', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Five_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Five_Key, mainWindow));
//  registerKey('K', m);
}

void PIRReverseMultitap::generateLetterL()
{
  PIRMacro *m = new PIRMacro(this, "Multitap L", 'L', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Five_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Five_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Five_Key, mainWindow));
//  registerKey('L', m);
}

void PIRReverseMultitap::generateLetterM()
{
  PIRMacro *m = new PIRMacro(this, "Multitap M", 'M', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Six_Key, mainWindow));
//  registerKey('M', m);
}

void PIRReverseMultitap::generateLetterN()
{
  PIRMacro *m = new PIRMacro(this, "Multitap N", 'N', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Six_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Six_Key, mainWindow));
//  registerKey('N', m);
}

void PIRReverseMultitap::generateLetterO()
{
  PIRMacro *m = new PIRMacro(this, "Multitap O", 'O', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Six_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Six_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Six_Key, mainWindow));
//  registerKey('O', m);
}

void PIRReverseMultitap::generateLetterP()
{
  PIRMacro *m = new PIRMacro(this, "Multitap P", 'P', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Seven_Key, mainWindow));
//  registerKey('P', m);
}

void PIRReverseMultitap::generateLetterQ()
{
  PIRMacro *m = new PIRMacro(this, "Multitap Q", 'Q', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Seven_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Seven_Key, mainWindow));
//  registerKey('Q', m);
}

void PIRReverseMultitap::generateLetterR()
{
  PIRMacro *m = new PIRMacro(this, "Multitap R", 'R', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Seven_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Seven_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Seven_Key, mainWindow));
//  registerKey('R', m);
}

void PIRReverseMultitap::generateLetterS()
{
  PIRMacro *m = new PIRMacro(this, "Multitap S", 'S', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Seven_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Seven_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Seven_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Seven_Key, mainWindow));
//  registerKey('S', m);
}

void PIRReverseMultitap::generateLetterT()
{
  PIRMacro *m = new PIRMacro(this, "Multitap T", 'T', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Eight_Key, mainWindow));
//  registerKey('T', m);
}

void PIRReverseMultitap::generateLetterU()
{
  PIRMacro *m = new PIRMacro(this, "Multitap U", 'U', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Eight_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Eight_Key, mainWindow));
//  registerKey('U', m);
}

void PIRReverseMultitap::generateLetterV()
{
  PIRMacro *m = new PIRMacro(this, "Multitap V", 'V', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Eight_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Eight_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Eight_Key, mainWindow));
//  registerKey('V', m);
}

void PIRReverseMultitap::generateLetterW()
{
  PIRMacro *m = new PIRMacro(this, "Multitap W", 'W', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Nine_Key, mainWindow));
//  registerKey('W', m);
}

void PIRReverseMultitap::generateLetterX()
{
  PIRMacro *m = new PIRMacro(this, "Multitap X", 'X', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Nine_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Nine_Key, mainWindow));
//  registerKey('X', m);
}

void PIRReverseMultitap::generateLetterY()
{
  PIRMacro *m = new PIRMacro(this, "Multitap Y", 'Y', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Nine_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Nine_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Nine_Key, mainWindow));
//  registerKey('Y', m);
}

void PIRReverseMultitap::generateLetterZ()
{
  PIRMacro *m = new PIRMacro(this, "Multitap Z", 'Z', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Nine_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Nine_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Nine_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Nine_Key, mainWindow));
//  registerKey('Z', m);
}

void PIRReverseMultitap::generateSpace()
{
  PIRMacro *m = new PIRMacro(this, "Multitap Space", ' ', 0, mainWindow);
  m->appendCommand(new PIRKeyCommandItem(Zero_Key, mainWindow));
//  registerKey(' ', m);
}
