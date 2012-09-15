#include "pireditmacrodialog.h"
#include "ui_pireditmacrodialog.h"

#include <QTreeWidgetItem>
#include "macros/pirmacro.h"

#include <iostream>

PIREditMacroDialog::PIREditMacroDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::PIREditMacroDialog)
{
  ui->setupUi(this);

  // Set up the button names:
  ui->macroButtonComboBox->addItem("None");
  ui->macroButtonComboBox->addItem("User Defined 1");
  ui->macroButtonComboBox->addItem("User Defined 2");
  ui->macroButtonComboBox->addItem("User Defined 3");
  ui->macroButtonComboBox->addItem("User Defined 4");
  ui->macroButtonComboBox->addItem("User Defined 5");
  ui->macroButtonComboBox->addItem("User Defined 6");

  // Set up the key names:
  ui->macroKeyComboBox->addItem("None", 0);
  ui->macroKeyComboBox->addItem("A", 'A');
  ui->macroKeyComboBox->addItem("B", 'B');
  ui->macroKeyComboBox->addItem("C", 'C');
  ui->macroKeyComboBox->addItem("D", 'D');
  ui->macroKeyComboBox->addItem("E", 'E');
  ui->macroKeyComboBox->addItem("F", 'F');
  ui->macroKeyComboBox->addItem("G", 'G');
  ui->macroKeyComboBox->addItem("H", 'H');
  ui->macroKeyComboBox->addItem("I", 'I');
  ui->macroKeyComboBox->addItem("J", 'J');
  ui->macroKeyComboBox->addItem("K", 'K');
  ui->macroKeyComboBox->addItem("L", 'L');
  ui->macroKeyComboBox->addItem("M", 'M');
  ui->macroKeyComboBox->addItem("N", 'N');
  ui->macroKeyComboBox->addItem("O", 'O');
  ui->macroKeyComboBox->addItem("P", 'P');
  ui->macroKeyComboBox->addItem("Q", 'Q');
  ui->macroKeyComboBox->addItem("R", 'R');
  ui->macroKeyComboBox->addItem("S", 'S');
  ui->macroKeyComboBox->addItem("T", 'T');
  ui->macroKeyComboBox->addItem("U", 'U');
  ui->macroKeyComboBox->addItem("V", 'V');
  ui->macroKeyComboBox->addItem("W", 'W');
  ui->macroKeyComboBox->addItem("X", 'X');
  ui->macroKeyComboBox->addItem("Y", 'Y');
  ui->macroKeyComboBox->addItem("Z", 'Z');
  ui->macroKeyComboBox->addItem("Space", ' ');
}


PIREditMacroDialog::~PIREditMacroDialog()
{
  delete ui;
}


void PIREditMacroDialog::clear()
{
  ui->macroNameLineEdit->clear();

  ui->macroButtonComboBox->setCurrentIndex(0);

  ui->macroKeyComboBox->setCurrentIndex(0);
}


void PIREditMacroDialog::setup(
  QTreeWidgetItem *item)
{
  if (!item) return;

  PIRMacro *m = dynamic_cast<PIRMacro *> (item);

  if (!m) return;

  ui->macroNameLineEdit->setText(m->getName());

  ui->macroButtonComboBox->setCurrentIndex(m->getButtonID());

  char key = m->getKey();
  int index = 0;
  int count = ui->macroKeyComboBox->count();

  while (index < count)
  {
    if (ui->macroKeyComboBox->itemData(index).toInt() == key)
    {
      ui->macroKeyComboBox->setCurrentIndex(index);
      break;
    }

    ++index;
  }
}


QString PIREditMacroDialog::getText()
{
  return ui->macroNameLineEdit->text();
}


char PIREditMacroDialog::getKey()
{
  return ui->macroKeyComboBox->itemData(
    ui->macroKeyComboBox->currentIndex()).toInt();
}


unsigned int PIREditMacroDialog::getButtonID()
{
  return ui->macroButtonComboBox->currentIndex();
}
