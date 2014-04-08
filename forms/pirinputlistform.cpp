//
// pirinputlistform.cpp
//
// Copyright 2014 by John Pietrzak (jpietrzak8@gmail.com)
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

#include "pirinputlistform.h"
#include "ui_pirinputlistform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

PIRInputListForm::PIRInputListForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRInputListForm),
    mainWindow(mw)
{
  ui->setupUi(this);
}

PIRInputListForm::~PIRInputListForm()
{
  delete ui;
}

void PIRInputListForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  keyset->populateInputList(ui->inputSelectorComboBox, id);

  emit selectInputEnabled(ui->inputSelectorComboBox->count() > 0);
}

void PIRInputListForm::on_selectInputPushButton_pressed()
{
  int i = ui->inputSelectorComboBox->currentIndex();

  mainWindow->startRepeating(
    PIRKeyName(
      ui->inputSelectorComboBox->itemData(i).toInt()));
}

void PIRInputListForm::on_selectInputPushButton_released()
{
  mainWindow->stopRepeating();
}
