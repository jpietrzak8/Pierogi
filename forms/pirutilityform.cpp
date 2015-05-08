//
// pirutilityform.cpp
//
// Copyright 2012 - 2015 by John Pietrzak (jpietrzak8@gmail.com)
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

#include "pirutilityform.h"
#include "ui_pirutilityform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

PIRUtilityForm::PIRUtilityForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRUtilityForm),
    mainWindow(mw)
{
  ui->setupUi(this);
}

PIRUtilityForm::~PIRUtilityForm()
{
  delete ui;
}


void PIRUtilityForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  emit redEnabled(keyset->hasKey(id, Red_Key));
  emit greenEnabled(keyset->hasKey(id, Green_Key));
  emit yellowEnabled(keyset->hasKey(id, Yellow_Key));
  emit blueEnabled(keyset->hasKey(id, Blue_Key));
  emit pictureModeEnabled(keyset->hasKey(id, PictureMode_Key));
  emit soundModeEnabled(keyset->hasKey(id, SoundMode_Key));
  emit aspectRatioEnabled(keyset->hasKey(id, AspectRatio_Key));
  emit audioEnabled(keyset->hasKey(id, Audio_Key));
  emit infoEnabled(keyset->hasKey(id, Info_Key));
  emit captionsEnabled(keyset->hasKey(id, Captions_Key));
  emit sleepEnabled(keyset->hasKey(id, Sleep_Key));
  emit inputEnabled(keyset->hasKey(id, Input_Key));
  emit guideEnabled(keyset->hasKey(id, Guide_Key));
  emit energySaveEnabled(keyset->hasKey(id, EnergySave_Key));
  emit zoomEnabled(keyset->hasKey(id, Zoom_Key));
  emit favoriteEnabled(keyset->hasKey(id, Favorites_Key));
}


void PIRUtilityForm::on_redButton_pressed()
{
  mainWindow->startRepeating(Red_Key);
}

void PIRUtilityForm::on_redButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_greenButton_pressed()
{
  mainWindow->startRepeating(Green_Key);
}

void PIRUtilityForm::on_greenButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_yellowButton_pressed()
{
  mainWindow->startRepeating(Yellow_Key);
}

void PIRUtilityForm::on_yellowButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_blueButton_pressed()
{
  mainWindow->startRepeating(Blue_Key);
}

void PIRUtilityForm::on_blueButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_pictureModeButton_pressed()
{
  mainWindow->startRepeating(PictureMode_Key);
}

void PIRUtilityForm::on_pictureModeButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_soundModeButton_pressed()
{
  mainWindow->startRepeating(SoundMode_Key);
}

void PIRUtilityForm::on_soundModeButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_aspectRatioButton_pressed()
{
  mainWindow->startRepeating(AspectRatio_Key);
}

void PIRUtilityForm::on_aspectRatioButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_audioButton_pressed()
{
  mainWindow->startRepeating(Audio_Key);
}

void PIRUtilityForm::on_audioButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_infoButton_pressed()
{
  mainWindow->startRepeating(Info_Key);
}

void PIRUtilityForm::on_infoButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_captionButton_pressed()
{
  mainWindow->startRepeating(Captions_Key);
}

void PIRUtilityForm::on_captionButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_inputButton_pressed()
{
  mainWindow->startRepeating(Input_Key);
}

void PIRUtilityForm::on_inputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_sleepButton_pressed()
{
  mainWindow->startRepeating(Sleep_Key);
}

void PIRUtilityForm::on_sleepButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_guideButton_pressed()
{
  mainWindow->startRepeating(Guide_Key);
}

void PIRUtilityForm::on_guideButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_energySaveButton_pressed()
{
  mainWindow->startRepeating(EnergySave_Key);
}

void PIRUtilityForm::on_energySaveButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_zoomButton_pressed()
{
  mainWindow->startRepeating(Zoom_Key);
}

void PIRUtilityForm::on_zoomButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_favoriteButton_pressed()
{
  mainWindow->startRepeating(Favorites_Key);
}

void PIRUtilityForm::on_favoriteButton_released()
{
  mainWindow->stopRepeating();
}
