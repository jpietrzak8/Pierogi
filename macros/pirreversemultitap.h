#ifndef PIRREVERSEMULTITAP_H
#define PIRREVERSEMULTITAP_H

#include "pirmacropack.h"

class QTreeWidget;
class MainWindow;

class PIRReverseMultitap: public PIRMacroPack
{
public:
  PIRReverseMultitap(
    QTreeWidget *qtw,
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
