//
// piraudiodeviceform.cpp
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

#include "piraudiodeviceform.h"
#include "ui_piraudiodeviceform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

PIRAudioDeviceForm::PIRAudioDeviceForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRAudioDeviceForm),
    mainWindow(mw)
{
  ui->setupUi(this);
}

PIRAudioDeviceForm::~PIRAudioDeviceForm()
{
  delete ui;
}


void PIRAudioDeviceForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  emit cdEnabled(keyset->hasKey(id, CDInput_Key));
  emit tapeEnabled(keyset->hasKey(id, TapeInput_Key));
  emit phonoEnabled(keyset->hasKey(id, PhonoInput_Key));
  emit auxEnabled(keyset->hasKey(id, AuxInput_Key));
  emit tunerEnabled(keyset->hasKey(id, TunerInput_Key));
  emit fmEnabled(keyset->hasKey(id, FM_Key));
  emit amEnabled(keyset->hasKey(id, AM_Key));
  emit lwEnabled(keyset->hasKey(id, LW_Key));
  emit fmModeEnabled(keyset->hasKey(id, FMMode_Key));
  emit repeatEnabled(keyset->hasKey(id, Repeat_Key));
  emit repeatABEnabled(keyset->hasKey(id, RepeatAB_Key));
  emit randomEnabled(keyset->hasKey(id, Random_Key));
  emit nextDiscEnabled(keyset->hasKey(id, NextDisc_Key));
  emit prevDiscEnabled(keyset->hasKey(id, PrevDisc_Key));
  emit sleepEnabled(keyset->hasKey(id, Sleep_Key));
  emit infoEnabled(keyset->hasKey(id, Info_Key));
}

void PIRAudioDeviceForm::on_cdButton_pressed()
{
  mainWindow->startRepeating(CDInput_Key);
}

void PIRAudioDeviceForm::on_cdButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_tapeButton_pressed()
{
  mainWindow->startRepeating(TapeInput_Key);
}

void PIRAudioDeviceForm::on_tapeButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_phonoButton_pressed()
{
  mainWindow->startRepeating(PhonoInput_Key);
}

void PIRAudioDeviceForm::on_phonoButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_auxButton_pressed()
{
  mainWindow->startRepeating(AuxInput_Key);
}

void PIRAudioDeviceForm::on_auxButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_tunerButton_pressed()
{
  mainWindow->startRepeating(TunerInput_Key);
}

void PIRAudioDeviceForm::on_tunerButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_fmButton_pressed()
{
  mainWindow->startRepeating(FM_Key);
}

void PIRAudioDeviceForm::on_fmButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_amButton_pressed()
{
  mainWindow->startRepeating(AM_Key);
}

void PIRAudioDeviceForm::on_amButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_lwButton_pressed()
{
  mainWindow->startRepeating(LW_Key);
}

void PIRAudioDeviceForm::on_lwButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_fmModeButton_pressed()
{
  mainWindow->startRepeating(FMMode_Key);
}

void PIRAudioDeviceForm::on_fmModeButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_repeatButton_pressed()
{
  mainWindow->startRepeating(Repeat_Key);
}

void PIRAudioDeviceForm::on_repeatButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_repeatABButton_pressed()
{
  mainWindow->startRepeating(RepeatAB_Key);
}

void PIRAudioDeviceForm::on_repeatABButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_randomButton_pressed()
{
  mainWindow->startRepeating(Random_Key);
}

void PIRAudioDeviceForm::on_randomButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_nextDiscButton_pressed()
{
  mainWindow->startRepeating(NextDisc_Key);
}

void PIRAudioDeviceForm::on_nextDiscButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_prevDiscButton_pressed()
{
  mainWindow->startRepeating(PrevDisc_Key);
}

void PIRAudioDeviceForm::on_prevDiscButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_sleepButton_pressed()
{
  mainWindow->startRepeating(Sleep_Key);
}

void PIRAudioDeviceForm::on_sleepButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAudioDeviceForm::on_infoButton_pressed()
{
  mainWindow->startRepeating(Info_Key);
}

void PIRAudioDeviceForm::on_infoButton_released()
{
  mainWindow->stopRepeating();
}
