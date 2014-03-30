//
// pircameraform.cpp
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

#include "pircameraform.h"
#include "ui_pircameraform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"
#include "pirflashled.h"

/*
PIRCameraForm::PIRCameraForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRCameraForm)
{
  ui->setupUi(this);
}
*/


PIRCameraForm::PIRCameraForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRCameraForm),
    mainWindow(mw),
    flash(0)
{
  ui->setupUi(this);
}


PIRCameraForm::~PIRCameraForm()
{
  if (flash) delete flash;

  delete ui;
}


void PIRCameraForm::enableButtons(
  const PIRKeysetManager *km,
  unsigned int id)
{
  emit openShutterEnabled(km->hasKey(id, OpenShutter_Key));
  emit delayedOpenShutterEnabled(km->hasKey(id, DelayedOpenShutter_Key));
}


void PIRCameraForm::on_openShutterButton_pressed()
{
  if ( ui->delayedShutterCheckBox->isEnabled()
    && ui->delayedShutterCheckBox->isChecked())
  {
    mainWindow->startRepeating(DelayedOpenShutter_Key);
  }
  else
  {
    if (ui->remoteFlashCheckBox->isChecked())
    {
      flash = new PIRFlashLED();
      flash->strobe();
    }

    mainWindow->startRepeating(OpenShutter_Key);
  }
}


void PIRCameraForm::on_openShutterButton_released()
{
  mainWindow->stopRepeating();

  if (flash)
  {
    delete flash;
    flash = 0;
  }
}

