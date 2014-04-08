//
// pirreceiverform.cpp
//
// Copyright 2012 to 2014 by John Pietrzak (jpietrzak8@gmail.com)
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

#include "pirreceiverform.h"
#include "ui_pirreceiverform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

// Hacky global:
extern PIRMakeMgr makeManager;

/*
PIRReceiverForm::PIRReceiverForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRReceiverForm)
{
  ui->setupUi(this);
}
*/


PIRReceiverForm::PIRReceiverForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRReceiverForm),
    mainWindow(mw)
{
  ui->setupUi(this);
}

PIRReceiverForm::~PIRReceiverForm()
{
  delete ui;
}

void PIRReceiverForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  QString keysetName = makeManager.getMakeString(keyset->getMake(id));
  keysetName += " ";
  keysetName += keyset->getDisplayName(id);
  emit keysetNameChanged(keysetName);

  emit prevPresetEnabled(keyset->hasKey(id, PrevPreset_Key));
  emit nextPresetEnabled(keyset->hasKey(id, NextPreset_Key));
  emit tuneUpEnabled(keyset->hasKey(id, ChannelUp_Key));
  emit tuneDownEnabled(keyset->hasKey(id, ChannelDown_Key));
  emit powerEnabled(keyset->hasKey(id, Power_Key));
  emit muteEnabled(keyset->hasKey(id, Mute_Key));
  emit volumeUpEnabled(keyset->hasKey(id, VolumeUp_Key));
  emit volumeDownEnabled(keyset->hasKey(id, VolumeDown_Key));
  emit toggleBandEnabled(keyset->hasKey(id, ToggleBand_Key));
  emit fmEnabled(keyset->hasKey(id, FM_Key));
  emit amEnabled(keyset->hasKey(id, AM_Key));
  emit lwEnabled(keyset->hasKey(id, LW_Key));
}


void PIRReceiverForm::on_prevPresetButton_pressed()
{
  mainWindow->startRepeating(PrevPreset_Key);
}

void PIRReceiverForm::on_prevPresetButton_released()
{
  mainWindow->stopRepeating();
}

void PIRReceiverForm::on_nextPresetButton_pressed()
{
  mainWindow->startRepeating(NextPreset_Key);
}

void PIRReceiverForm::on_nextPresetButton_released()
{
  mainWindow->stopRepeating();
}

void PIRReceiverForm::on_powerButton_pressed()
{
  mainWindow->startRepeating(Power_Key);
}

void PIRReceiverForm::on_powerButton_released()
{
  mainWindow->stopRepeating();
}

void PIRReceiverForm::on_muteButton_pressed()
{
  mainWindow->startRepeating(Mute_Key);
}

void PIRReceiverForm::on_muteButton_released()
{
  mainWindow->stopRepeating();
}

void PIRReceiverForm::on_volumeUpButton_pressed()
{
  mainWindow->startRepeating(VolumeUp_Key);
}

void PIRReceiverForm::on_volumeUpButton_released()
{
  mainWindow->stopRepeating();
}

void PIRReceiverForm::on_volumeDownButton_pressed()
{
  mainWindow->startRepeating(VolumeDown_Key);
}

void PIRReceiverForm::on_volumeDownButton_released()
{
  mainWindow->stopRepeating();
}

void PIRReceiverForm::on_tuneUpButton_pressed()
{
  mainWindow->startRepeating(ChannelUp_Key);
}

void PIRReceiverForm::on_tuneUpButton_released()
{
  mainWindow->stopRepeating();
}

void PIRReceiverForm::on_tuneDownButton_pressed()
{
  mainWindow->startRepeating(ChannelDown_Key);
}

void PIRReceiverForm::on_tuneDownButton_released()
{
  mainWindow->stopRepeating();
}

void PIRReceiverForm::on_toggleBandButton_pressed()
{
  mainWindow->startRepeating(ToggleBand_Key);
}

void PIRReceiverForm::on_toggleBandButton_released()
{
  mainWindow->stopRepeating();
}

void PIRReceiverForm::on_lwButton_pressed()
{
  mainWindow->startRepeating(LW_Key);
}

void PIRReceiverForm::on_lwButton_released()
{
  mainWindow->stopRepeating();
}

void PIRReceiverForm::on_amButton_pressed()
{
  mainWindow->startRepeating(AM_Key);
}

void PIRReceiverForm::on_amButton_released()
{
  mainWindow->stopRepeating();
}

void PIRReceiverForm::on_fmButton_pressed()
{
  mainWindow->startRepeating(FM_Key);
}

void PIRReceiverForm::on_fmButton_released()
{
  mainWindow->stopRepeating();
}
