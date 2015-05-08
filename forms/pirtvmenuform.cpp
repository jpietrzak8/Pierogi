//
// pirtvmenuform.cpp
//
// Copyright 2015 by John Pietrzak (jpietrzak8@gmail.com)
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

#include "pirtvmenuform.h"
#include "ui_pirtvmenuform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

PIRTVMenuForm::PIRTVMenuForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRTVMenuForm),
    mainWindow(mw)
{
  ui->setupUi(this);
}

PIRTVMenuForm::~PIRTVMenuForm()
{
  delete ui;
}


void PIRTVMenuForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  emit menuEnabled(keyset->hasKey(id, Menu_Key));
  emit cecEnabled(keyset->hasKey(id, CECMenu_Key));
  emit appsEnabled(keyset->hasKey(id, AppsMenu_Key));
  emit quickEnabled(keyset->hasKey(id, QuickMenu_Key));
  emit toolsEnabled(keyset->hasKey(id, ToolsMenu_Key));
  emit upEnabled(keyset->hasKey(id, Up_Key));
  emit downEnabled(keyset->hasKey(id, Down_Key));
  emit leftEnabled(keyset->hasKey(id, Left_Key));
  emit rightEnabled(keyset->hasKey(id, Right_Key));
  emit selectEnabled(keyset->hasKey(id, Select_Key));
  emit backEnabled(keyset->hasKey(id, Back_Key));
  emit exitEnabled(keyset->hasKey(id, Exit_Key));
}


void PIRTVMenuForm::on_menuButton_pressed()
{
  mainWindow->startRepeating(Menu_Key);
}

void PIRTVMenuForm::on_menuButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVMenuForm::on_cecButton_pressed()
{
  mainWindow->startRepeating(CECMenu_Key);
}

void PIRTVMenuForm::on_cecButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVMenuForm::on_appsButton_pressed()
{
  mainWindow->startRepeating(AppsMenu_Key);
}

void PIRTVMenuForm::on_appsButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVMenuForm::on_quickMenuButton_pressed()
{
  mainWindow->startRepeating(QuickMenu_Key);
}

void PIRTVMenuForm::on_quickMenuButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVMenuForm::on_leftButton_pressed()
{
  mainWindow->startRepeating(Left_Key);
}

void PIRTVMenuForm::on_leftButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVMenuForm::on_toolsButton_pressed()
{
  mainWindow->startRepeating(ToolsMenu_Key);
}

void PIRTVMenuForm::on_toolsButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVMenuForm::on_upButton_pressed()
{
  mainWindow->startRepeating(Up_Key);
}

void PIRTVMenuForm::on_upButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVMenuForm::on_selectButton_pressed()
{
  mainWindow->startRepeating(Select_Key);
}

void PIRTVMenuForm::on_selectButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVMenuForm::on_downButton_pressed()
{
  mainWindow->startRepeating(Down_Key);
}

void PIRTVMenuForm::on_downButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVMenuForm::on_backButton_pressed()
{
  mainWindow->startRepeating(Back_Key);
}

void PIRTVMenuForm::on_backButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVMenuForm::on_rightButton_pressed()
{
  mainWindow->startRepeating(Right_Key);
}

void PIRTVMenuForm::on_rightButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVMenuForm::on_exitButton_pressed()
{
  mainWindow->startRepeating(Exit_Key);
}

void PIRTVMenuForm::on_exitButton_released()
{
  mainWindow->stopRepeating();
}
