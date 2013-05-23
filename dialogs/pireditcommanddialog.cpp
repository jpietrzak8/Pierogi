//
// pireditcommanddialog.cpp
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

#include "pireditcommanddialog.h"
#include "ui_pireditcommanddialog.h"

#include "macros/pirmacrocommanditem.h"

PIREditCommandDialog::PIREditCommandDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::PIREditCommandDialog)
{
  ui->setupUi(this);
}

PIREditCommandDialog::~PIREditCommandDialog()
{
  delete ui;
}


void PIREditCommandDialog::setup(
  QString typeString,
  QString name)
{
  ui->commandTypeLabel->setText(typeString);

  ui->commandValueLabel->setText(name);
}

/*
void PIREditCommandDialog::on_moveUpButton_clicked()
{
  emit moveCommandUp();
  accept();
}

void PIREditCommandDialog::on_moveDownButton_clicked()
{
  emit moveCommandDown();
  accept();
}
*/

void PIREditCommandDialog::on_deleteButton_clicked()
{
  emit deleteCommand();
  accept();
}

void PIREditCommandDialog::on_copyButton_clicked()
{
  emit copyCommand();
  accept();
}
