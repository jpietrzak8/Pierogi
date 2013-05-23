//
// pireditmacrodialog.cpp
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
