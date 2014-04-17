//
// pirrunmacrodialog.cpp
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

#include "pirrunmacrodialog.h"
#include "ui_pirrunmacrodialog.h"

#include "mainwindow.h"

PIRRunMacroDialog::PIRRunMacroDialog(
  MainWindow *mw)
  : QDialog(),
    mainWindow(mw),
    ui(new Ui::PIRRunMacroDialog)
{
  ui->setupUi(this);
}

PIRRunMacroDialog::~PIRRunMacroDialog()
{
  delete ui;
}


void PIRRunMacroDialog::setMacroName(
  QString macroName)
{
  ui->nameLabel->setText(macroName);
}

void PIRRunMacroDialog::setCommandName(
  QString commandName)
{
  ui->commandNameLabel->setText(commandName);
}

void PIRRunMacroDialog::on_buttonBox_accepted()
{
  // Do nothing here?  Not sure.
}

void PIRRunMacroDialog::on_buttonBox_rejected()
{
  // Stop the running macro:
  mainWindow->abortMacro();
}
