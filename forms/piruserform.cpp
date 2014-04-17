//
// piruserform.cpp
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

#include "piruserform.h"
#include "ui_piruserform.h"

#include <QFileDialog>
#include "mainwindow.h"

/*
PIRUserForm::PIRUserForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRUserForm)
{
  ui->setupUi(this);
}
*/


PIRUserForm::PIRUserForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRUserForm),
    mainWindow(mw)
{
  ui->setupUi(this);
}


PIRUserForm::~PIRUserForm()
{
  delete ui;
}


void PIRUserForm::setupButtons()
{
  if (mainWindow->hasMacroButton(1))
  {
    ui->userDef1Button->setEnabled(true);
    ui->userDef1Button->setText(mainWindow->getMacroButtonText(1));
  }
  else
  {
    ui->userDef1Button->setEnabled(false);
    ui->userDef1Button->setText("Macro 1");
  }

  if (mainWindow->hasMacroButton(2))
  {
    ui->userDef2Button->setEnabled(true);
    ui->userDef2Button->setText(mainWindow->getMacroButtonText(2));
  }
  else
  {
    ui->userDef2Button->setEnabled(false);
    ui->userDef2Button->setText("Macro 2");
  }

  if (mainWindow->hasMacroButton(3))
  {
    ui->userDef3Button->setEnabled(true);
    ui->userDef3Button->setText(mainWindow->getMacroButtonText(3));
  }
  else
  {
    ui->userDef3Button->setEnabled(false);
    ui->userDef3Button->setText("Macro 3");
  }

  if (mainWindow->hasMacroButton(4))
  {
    ui->userDef4Button->setEnabled(true);
    ui->userDef4Button->setText(mainWindow->getMacroButtonText(4));
  }
  else
  {
    ui->userDef4Button->setEnabled(false);
    ui->userDef4Button->setText("Macro 4");
  }

  if (mainWindow->hasMacroButton(5))
  {
    ui->userDef5Button->setEnabled(true);
    ui->userDef5Button->setText(mainWindow->getMacroButtonText(5));
  }
  else
  {
    ui->userDef5Button->setEnabled(false);
    ui->userDef5Button->setText("Macro 5");
  }

  if (mainWindow->hasMacroButton(6))
  {
    ui->userDef6Button->setEnabled(true);
    ui->userDef6Button->setText(mainWindow->getMacroButtonText(6));
  }
  else
  {
    ui->userDef6Button->setEnabled(false);
    ui->userDef6Button->setText("Macro 6");
  }
}


void PIRUserForm::on_userDef1Button_clicked()
{
  mainWindow->executeMacroButton(1);
}

void PIRUserForm::on_userDef2Button_clicked()
{
  mainWindow->executeMacroButton(2);
}

void PIRUserForm::on_userDef3Button_clicked()
{
  mainWindow->executeMacroButton(3);
}

void PIRUserForm::on_userDef4Button_clicked()
{
  mainWindow->executeMacroButton(4);
}

void PIRUserForm::on_userDef5Button_clicked()
{
  mainWindow->executeMacroButton(5);
}

void PIRUserForm::on_userDef6Button_clicked()
{
  mainWindow->executeMacroButton(6);
}


void PIRUserForm::on_loadPackButton_clicked()
{
  QString filename = QFileDialog::getOpenFileName(
    this,
    tr("Select Macro XML File"),
    "~/MyDocs");

  if (!filename.isEmpty())
  {
    if (mainWindow->loadNewMacros(filename))
    {
      ui->macroComboBox->clear();

      mainWindow->populateMacroComboBox(
        ui->macroComboBox);

      if (ui->macroComboBox->count())
      {
        emit runEnabled(true);
      }
      else
      {
        emit runEnabled(false);
      }

      setupButtons();
    }
  }
}


void PIRUserForm::on_runButton_clicked()
{
  mainWindow->runMacro(
    ui->macroComboBox->currentText());
}


/*
void PIRUserForm::on_macroComboBox_currentIndexChanged(const QString &arg1)
{

}
*/
