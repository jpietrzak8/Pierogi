//
// pirselectmacrodialog.cpp
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

#include "pirselectmacrodialog.h"
#include "ui_pirselectmacrodialog.h"

#include "macros/pirmacropack.h"
#include "macros/pirmacro.h"
#include "macros/pirreversemultitap.h"
#include "mainwindow.h"
#include <QMaemo5InformationBox>

// Debugging includes:
#include <iostream>

/*
PIRSelectMacroDialog::PIRSelectMacroDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::PIRSelectMacroDialog)
{
  ui->setupUi(this);
}
*/


PIRSelectMacroDialog::PIRSelectMacroDialog()
  : QDialog(0),
    ui(new Ui::PIRSelectMacroDialog)
{
  ui->setupUi(this);
}


PIRSelectMacroDialog::~PIRSelectMacroDialog()
{
  // This is a hack to get around object ownership issues:
  while (ui->macroTreeWidget->topLevelItemCount())
  {
    ui->macroTreeWidget->takeTopLevelItem(0);
  }

  delete ui;
}


void PIRSelectMacroDialog::addPack(
  PIRMacroPack *pack)
{
  ui->macroTreeWidget->addTopLevelItem(pack);
}


void PIRSelectMacroDialog::on_buttonBox_accepted()
{
  // Try to find a usable macro in the list of selected items.  (There should
  // only be one item in the list anyway.)
  QList<QTreeWidgetItem *> items = ui->macroTreeWidget->selectedItems();

  int index = 0;
  int size = items.size();

  while (index < size)
  {
    if (items[index]->parent() != 0)
    {
      emit macroChosen(items[index]);
      return;
    }

    ++index;
  }
}


/*
void PIRSelectMacroDialog::on_buttonBox_rejected()
{

}
*/

void PIRSelectMacroDialog::on_newButton_clicked()
{
  emit newMacroRequested();
  accept();
}


void PIRSelectMacroDialog::on_editButton_clicked()
{
  // Find the first selected macro, if any:
  QList<QTreeWidgetItem *> items = ui->macroTreeWidget->selectedItems();

  if (items.size() > 0)
  {
    if (items[0]->parent() == 0)
    {
      QMaemo5InformationBox::information(0, "Cannot Edit MacroPacks");
    }
    else
    {
      emit editMacroRequested(items[0]);
    }
  }

  accept();
}


void PIRSelectMacroDialog::on_deleteButton_clicked()
{
  // Find the first selected macro, if any:
  QList<QTreeWidgetItem *> items = ui->macroTreeWidget->selectedItems();

  if (items.size() > 0)
  {
    if (items[0]->parent() == 0)
    {
      QMaemo5InformationBox::information(0, "Cannot Delete MacroPacks");
    }
    else
    {
      emit deleteMacroRequested(items[0]);
    }
  }

  accept();
}


void PIRSelectMacroDialog::resetIndices()
{
  ui->macroTreeWidget->setCurrentItem(
    ui->macroTreeWidget->topLevelItem(0));
}
