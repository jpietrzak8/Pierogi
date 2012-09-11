#include "pirreversemultitap.h"

#include "pirmacro.h"
#include "pirmacrocommanditem.h"


PIRReverseMultitap::PIRReverseMultitap(
  QTreeWidget *qtw,
  MainWindow *mw)
  : PIRMacroPack(
      qtw,
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
  PIRMacro *m = new PIRMacro(this, "Multitap A", 'A');
  m->appendCommand(new PIRKeyCommandItem(Two_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterB()
{
  PIRMacro *m = new PIRMacro(this, "Multitap B", 'B');
  m->appendCommand(new PIRKeyCommandItem(Two_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Two_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterC()
{
  PIRMacro *m = new PIRMacro(this, "Multitap C", 'C');
  m->appendCommand(new PIRKeyCommandItem(Two_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Two_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Two_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterD()
{
  PIRMacro *m = new PIRMacro(this, "Multitap D", 'D');
  m->appendCommand(new PIRKeyCommandItem(Three_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterE()
{
  PIRMacro *m = new PIRMacro(this, "Multitap E", 'E');
  m->appendCommand(new PIRKeyCommandItem(Three_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Three_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterF()
{
  PIRMacro *m = new PIRMacro(this, "Multitap F", 'F');
  m->appendCommand(new PIRKeyCommandItem(Three_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Three_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Three_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterG()
{
  PIRMacro *m = new PIRMacro(this, "Multitap G", 'G');
  m->appendCommand(new PIRKeyCommandItem(Four_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterH()
{
  PIRMacro *m = new PIRMacro(this, "Multitap H", 'H');
  m->appendCommand(new PIRKeyCommandItem(Four_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Four_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterI()
{
  PIRMacro *m = new PIRMacro(this, "Multitap I", 'I');
  m->appendCommand(new PIRKeyCommandItem(Four_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Four_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Four_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterJ()
{
  PIRMacro *m = new PIRMacro(this, "Multitap J", 'J');
  m->appendCommand(new PIRKeyCommandItem(Five_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterK()
{
  PIRMacro *m = new PIRMacro(this, "Multitap K", 'K');
  m->appendCommand(new PIRKeyCommandItem(Five_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Five_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterL()
{
  PIRMacro *m = new PIRMacro(this, "Multitap L", 'L');
  m->appendCommand(new PIRKeyCommandItem(Five_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Five_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Five_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterM()
{
  PIRMacro *m = new PIRMacro(this, "Multitap M", 'M');
  m->appendCommand(new PIRKeyCommandItem(Six_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterN()
{
  PIRMacro *m = new PIRMacro(this, "Multitap N", 'N');
  m->appendCommand(new PIRKeyCommandItem(Six_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Six_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterO()
{
  PIRMacro *m = new PIRMacro(this, "Multitap O", 'O');
  m->appendCommand(new PIRKeyCommandItem(Six_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Six_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Six_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterP()
{
  PIRMacro *m = new PIRMacro(this, "Multitap P", 'P');
  m->appendCommand(new PIRKeyCommandItem(Seven_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterQ()
{
  PIRMacro *m = new PIRMacro(this, "Multitap Q", 'Q');
  m->appendCommand(new PIRKeyCommandItem(Seven_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Seven_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterR()
{
  PIRMacro *m = new PIRMacro(this, "Multitap R", 'R');
  m->appendCommand(new PIRKeyCommandItem(Seven_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Seven_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Seven_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterS()
{
  PIRMacro *m = new PIRMacro(this, "Multitap S", 'S');
  m->appendCommand(new PIRKeyCommandItem(Seven_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Seven_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Seven_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Seven_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterT()
{
  PIRMacro *m = new PIRMacro(this, "Multitap T", 'T');
  m->appendCommand(new PIRKeyCommandItem(Eight_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterU()
{
  PIRMacro *m = new PIRMacro(this, "Multitap U", 'U');
  m->appendCommand(new PIRKeyCommandItem(Eight_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Eight_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterV()
{
  PIRMacro *m = new PIRMacro(this, "Multitap V", 'V');
  m->appendCommand(new PIRKeyCommandItem(Eight_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Eight_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Eight_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterW()
{
  PIRMacro *m = new PIRMacro(this, "Multitap W", 'W');
  m->appendCommand(new PIRKeyCommandItem(Nine_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterX()
{
  PIRMacro *m = new PIRMacro(this, "Multitap X", 'X');
  m->appendCommand(new PIRKeyCommandItem(Nine_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Nine_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterY()
{
  PIRMacro *m = new PIRMacro(this, "Multitap Y", 'Y');
  m->appendCommand(new PIRKeyCommandItem(Nine_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Nine_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Nine_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateLetterZ()
{
  PIRMacro *m = new PIRMacro(this, "Multitap Z", 'Z');
  m->appendCommand(new PIRKeyCommandItem(Nine_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Nine_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Nine_Key, mainWindow));
  m->appendCommand(new PIRKeyCommandItem(Nine_Key, mainWindow));
//  macros[m->getName()] = m;
}

void PIRReverseMultitap::generateSpace()
{
  PIRMacro *m = new PIRMacro(this, "Multitap Space", ' ');
  m->appendCommand(new PIRKeyCommandItem(Zero_Key, mainWindow));
//  macros[m->getName()] = m;
}
