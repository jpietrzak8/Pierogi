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

#ifndef PIRREVERSEMULTITAP_H
#define PIRREVERSEMULTITAP_H

#include "pirmacropack.h"

class QTreeWidget;
class MainWindow;

class PIRReverseMultitap: public PIRMacroPack
{
public:
  PIRReverseMultitap(
    MainWindow *mw);

private:
  void generateLetterA();
  void generateLetterB();
  void generateLetterC();
  void generateLetterD();
  void generateLetterE();
  void generateLetterF();
  void generateLetterG();
  void generateLetterH();
  void generateLetterI();
  void generateLetterJ();
  void generateLetterK();
  void generateLetterL();
  void generateLetterM();
  void generateLetterN();
  void generateLetterO();
  void generateLetterP();
  void generateLetterQ();
  void generateLetterR();
  void generateLetterS();
  void generateLetterT();
  void generateLetterU();
  void generateLetterV();
  void generateLetterW();
  void generateLetterX();
  void generateLetterY();
  void generateLetterZ();
  void generateSpace();

private:
  MainWindow *mainWindow;
};

#endif // PIRREVERSEMULTITAP_H
