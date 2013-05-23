//
// pirplaystationform.cpp
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

#include "pirplaystationform.h"
#include "ui_pirplaystationform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"


/*
PIRPlaystationForm::PIRPlaystationForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRPlaystationForm)
{
  ui->setupUi(this);
}
*/


PIRPlaystationForm::PIRPlaystationForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRPlaystationForm),
    mainWindow(mw)
{
  ui->setupUi(this);
}


PIRPlaystationForm::~PIRPlaystationForm()
{
  delete ui;
}


void PIRPlaystationForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  emit selectEnabled(keyset->hasKey(id, PSSelect_Key));
  emit startEnabled(keyset->hasKey(id, PSStart_Key));
  emit l1Enabled(keyset->hasKey(id, PSL1_Key));
  emit l2Enabled(keyset->hasKey(id, PSL2_Key));
  emit l3Enabled(keyset->hasKey(id, PSL3_Key));
  emit r1Enabled(keyset->hasKey(id, PSR1_Key));
  emit r2Enabled(keyset->hasKey(id, PSR2_Key));
  emit r3Enabled(keyset->hasKey(id, PSR3_Key));
  emit upEnabled(keyset->hasKey(id, PSUp_Key));
  emit downEnabled(keyset->hasKey(id, PSDown_Key));
  emit leftEnabled(keyset->hasKey(id, PSLeft_Key));
  emit rightEnabled(keyset->hasKey(id, PSRight_Key));
  emit triangleEnabled(keyset->hasKey(id, PSTriangle_Key));
  emit crossEnabled(keyset->hasKey(id, PSCross_Key));
  emit squareEnabled(keyset->hasKey(id, PSSquare_Key));
  emit circleEnabled(keyset->hasKey(id, PSCircle_Key));
}

void PIRPlaystationForm::on_selectButton_pressed()
{
  mainWindow->startRepeating(PSSelect_Key);
}

void PIRPlaystationForm::on_selectButton_released()
{
  mainWindow->stopRepeating();
}

void PIRPlaystationForm::on_startButton_pressed()
{
  mainWindow->startRepeating(PSStart_Key);
}

void PIRPlaystationForm::on_startButton_released()
{
  mainWindow->stopRepeating();
}

void PIRPlaystationForm::on_l1Button_pressed()
{
  mainWindow->startRepeating(PSL1_Key);
}

void PIRPlaystationForm::on_l1Button_released()
{
  mainWindow->stopRepeating();
}

void PIRPlaystationForm::on_l2Button_pressed()
{
  mainWindow->startRepeating(PSL2_Key);
}

void PIRPlaystationForm::on_l2Button_released()
{
  mainWindow->stopRepeating();
}

void PIRPlaystationForm::on_l3Button_pressed()
{
  mainWindow->startRepeating(PSL3_Key);
}

void PIRPlaystationForm::on_l3Button_released()
{
  mainWindow->stopRepeating();
}

void PIRPlaystationForm::on_r1Button_pressed()
{
  mainWindow->startRepeating(PSR1_Key);
}

void PIRPlaystationForm::on_r1Button_released()
{
  mainWindow->stopRepeating();
}

void PIRPlaystationForm::on_r2Button_pressed()
{
  mainWindow->startRepeating(PSR2_Key);
}

void PIRPlaystationForm::on_r2Button_released()
{
  mainWindow->stopRepeating();
}

void PIRPlaystationForm::on_r3Button_pressed()
{
  mainWindow->startRepeating(PSR3_Key);
}

void PIRPlaystationForm::on_r3Button_released()
{
  mainWindow->stopRepeating();
}

void PIRPlaystationForm::on_upButton_pressed()
{
  mainWindow->startRepeating(PSUp_Key);
}

void PIRPlaystationForm::on_upButton_released()
{
  mainWindow->stopRepeating();
}

void PIRPlaystationForm::on_downButton_pressed()
{
  mainWindow->startRepeating(PSDown_Key);
}

void PIRPlaystationForm::on_downButton_released()
{
  mainWindow->stopRepeating();
}

void PIRPlaystationForm::on_leftButton_pressed()
{
  mainWindow->startRepeating(PSLeft_Key);
}

void PIRPlaystationForm::on_leftButton_released()
{
  mainWindow->stopRepeating();
}

void PIRPlaystationForm::on_rightButton_pressed()
{
  mainWindow->startRepeating(PSRight_Key);
}

void PIRPlaystationForm::on_rightButton_released()
{
  mainWindow->stopRepeating();
}

void PIRPlaystationForm::on_triangleButton_pressed()
{
  mainWindow->startRepeating(PSTriangle_Key);
}

void PIRPlaystationForm::on_triangleButton_released()
{
  mainWindow->stopRepeating();
}

void PIRPlaystationForm::on_crossButton_pressed()
{
  mainWindow->startRepeating(PSCross_Key);
}

void PIRPlaystationForm::on_crossButton_released()
{
  mainWindow->stopRepeating();
}

void PIRPlaystationForm::on_squareButton_pressed()
{
  mainWindow->startRepeating(PSSquare_Key);
}

void PIRPlaystationForm::on_squareButton_released()
{
  mainWindow->stopRepeating();
}

void PIRPlaystationForm::on_circleButton_pressed()
{
  mainWindow->startRepeating(PSCircle_Key);
}

void PIRPlaystationForm::on_circleButton_released()
{
  mainWindow->stopRepeating();
}
