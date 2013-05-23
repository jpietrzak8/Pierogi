//
// pirmenuform.cpp
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

#include "pirmenuform.h"
#include "ui_pirmenuform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

PIRMenuForm::PIRMenuForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRMenuForm),
    mainWindow(mw)
{
  ui->setupUi(this);
}

PIRMenuForm::~PIRMenuForm()
{
  delete ui;
}


void PIRMenuForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  emit upEnabled(keyset->hasKey(id, Up_Key));
  emit downEnabled(keyset->hasKey(id, Down_Key));
  emit leftEnabled(keyset->hasKey(id, Left_Key));
  emit rightEnabled(keyset->hasKey(id, Right_Key));
  emit selectEnabled(keyset->hasKey(id, Select_Key));
  emit menuEnabled(keyset->hasKey(id, Menu_Key));
  emit exitEnabled(keyset->hasKey(id, Exit_Key));
  emit guideEnabled(keyset->hasKey(id, Guide_Key));
  emit discMenuEnabled(keyset->hasKey(id, DiscMenu_Key));
}


void PIRMenuForm::on_upButton_pressed()
{
  mainWindow->startRepeating(Up_Key);
}

void PIRMenuForm::on_upButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMenuForm::on_leftButton_pressed()
{
  mainWindow->startRepeating(Left_Key);
}

void PIRMenuForm::on_leftButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMenuForm::on_rightButton_pressed()
{
  mainWindow->startRepeating(Right_Key);
}

void PIRMenuForm::on_rightButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMenuForm::on_downButton_pressed()
{
  mainWindow->startRepeating(Down_Key);
}

void PIRMenuForm::on_downButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMenuForm::on_selectButton_pressed()
{
  mainWindow->startRepeating(Select_Key);
}

void PIRMenuForm::on_selectButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMenuForm::on_menuButton_pressed()
{
  mainWindow->startRepeating(Menu_Key);
}

void PIRMenuForm::on_menuButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMenuForm::on_exitButton_pressed()
{
  mainWindow->startRepeating(Exit_Key);
}

void PIRMenuForm::on_exitButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMenuForm::on_guideButton_pressed()
{
  mainWindow->startRepeating(Guide_Key);
}

void PIRMenuForm::on_guideButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMenuForm::on_discMenuButton_pressed()
{
  mainWindow->startRepeating(DiscMenu_Key);
}

void PIRMenuForm::on_discMenuButton_released()
{
  mainWindow->stopRepeating();
}
