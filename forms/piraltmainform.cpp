//
// piraltmainform.cpp
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

#include "piraltmainform.h"
#include "ui_piraltmainform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

// Ugly global:
extern PIRMakeMgr makeManager;


PIRAltMainForm::PIRAltMainForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRAltMainForm),
    mainWindow(mw),
    defaultID(0)
{
  ui->setupUi(this);
}


PIRAltMainForm::~PIRAltMainForm()
{
  delete ui;
}


void PIRAltMainForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  // No default id:
  defaultID = 0;

  emit powerEnabled(keyset->hasKey(id, Power_Key));
  emit volumeUpEnabled(keyset->hasKey(id, VolumeUp_Key));
  emit volumeDownEnabled(keyset->hasKey(id, VolumeDown_Key));
  emit channelUpEnabled(keyset->hasKey(id, ChannelUp_Key));
  emit channelDownEnabled(keyset->hasKey(id, ChannelDown_Key));
  emit muteEnabled(keyset->hasKey(id, Mute_Key));

  emit keysetMakeChanged(makeManager.getMakeString(keyset->getMake(id)));
  emit keysetNameChanged(keyset->getDisplayName(id));
}


void PIRAltMainForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int cID,
  unsigned int dID)
{
  defaultID = dID;
  emit powerEnabled(keyset->hasKey(cID, Power_Key));
  emit volumeUpEnabled(keyset->hasKey(dID, VolumeUp_Key));
  emit volumeDownEnabled(keyset->hasKey(dID, VolumeDown_Key));
  emit channelUpEnabled(keyset->hasKey(cID, ChannelUp_Key));
  emit channelDownEnabled(keyset->hasKey(cID, ChannelDown_Key));
  emit muteEnabled(keyset->hasKey(dID, Mute_Key));

  emit keysetMakeChanged(makeManager.getMakeString(keyset->getMake(cID)));
  emit keysetNameChanged(keyset->getDisplayName(cID));
}


void PIRAltMainForm::on_volumeUpButton_pressed()
{
  if (defaultID)
  {
    mainWindow->startRepeating(VolumeUp_Key, defaultID);
  }
  else
  {
    mainWindow->startRepeating(VolumeUp_Key);
  }
}

void PIRAltMainForm::on_volumeUpButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAltMainForm::on_volumeDownButton_pressed()
{
  if (defaultID)
  {
    mainWindow->startRepeating(VolumeDown_Key, defaultID);
  }
  else
  {
    mainWindow->startRepeating(VolumeDown_Key);
  }
}

void PIRAltMainForm::on_volumeDownButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAltMainForm::on_muteButton_pressed()
{
  if (defaultID)
  {
    mainWindow->startRepeating(Mute_Key, defaultID);
  }
  else
  {
    mainWindow->startRepeating(Mute_Key);
  }
}

void PIRAltMainForm::on_muteButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAltMainForm::on_powerButton_pressed()
{
  mainWindow->startRepeating(Power_Key);
}

void PIRAltMainForm::on_powerButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAltMainForm::on_channelUpButton_pressed()
{
  mainWindow->startRepeating(ChannelUp_Key);
}

void PIRAltMainForm::on_channelUpButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAltMainForm::on_channelDownButton_pressed()
{
  mainWindow->startRepeating(ChannelDown_Key);
}

void PIRAltMainForm::on_channelDownButton_released()
{
  mainWindow->stopRepeating();
}
