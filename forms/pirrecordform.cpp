//
// pirrecordform.cpp
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

#include "pirrecordform.h"
#include "ui_pirrecordform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

PIRRecordForm::PIRRecordForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRRecordForm),
    mainWindow(mw)
{
  ui->setupUi(this);
}

PIRRecordForm::~PIRRecordForm()
{
  delete ui;
}

void PIRRecordForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  emit timerEnabled(keyset->hasKey(id, Timer_Key));
  emit programEnabled(keyset->hasKey(id, Program_Key));
  emit memoryEnabled(keyset->hasKey(id, Memory_Key));
  emit callEnabled(keyset->hasKey(id, Call_Key));
  emit favoritesEnabled(keyset->hasKey(id, Favorites_Key));
  emit scanEnabled(keyset->hasKey(id, Scan_Key));
  emit prevPresetEnabled(keyset->hasKey(id, PrevPreset_Key));
  emit nextPresetEnabled(keyset->hasKey(id, NextPreset_Key));
  emit recordEnabled(keyset->hasKey(id, Record_Key));
  emit recordPauseEnabled(keyset->hasKey(id, RecordPause_Key));
  emit recordStopEnabled(keyset->hasKey(id, RecordStop_Key));
  emit recordMuteEnabled(keyset->hasKey(id, RecordMute_Key));
}

void PIRRecordForm::on_timerButton_pressed()
{
  mainWindow->startRepeating(Timer_Key);
}

void PIRRecordForm::on_timerButton_released()
{
  mainWindow->stopRepeating();
}

void PIRRecordForm::on_programButton_pressed()
{
  mainWindow->startRepeating(Program_Key);
}

void PIRRecordForm::on_programButton_released()
{
  mainWindow->stopRepeating();
}

void PIRRecordForm::on_memoryButton_pressed()
{
  mainWindow->startRepeating(Memory_Key);
}

void PIRRecordForm::on_memoryButton_released()
{
  mainWindow->stopRepeating();
}

void PIRRecordForm::on_callButton_pressed()
{
  mainWindow->startRepeating(Call_Key);
}

void PIRRecordForm::on_callButton_released()
{
  mainWindow->stopRepeating();
}

void PIRRecordForm::on_favoritesButton_pressed()
{
  mainWindow->startRepeating(Favorites_Key);
}

void PIRRecordForm::on_favoritesButton_released()
{
  mainWindow->stopRepeating();
}

void PIRRecordForm::on_scanButton_pressed()
{
  mainWindow->startRepeating(Scan_Key);
}

void PIRRecordForm::on_scanButton_released()
{
  mainWindow->stopRepeating();
}

void PIRRecordForm::on_prevPresetButton_pressed()
{
  mainWindow->startRepeating(PrevPreset_Key);
}

void PIRRecordForm::on_prevPresetButton_released()
{
  mainWindow->stopRepeating();
}

void PIRRecordForm::on_nextPresetButton_pressed()
{
  mainWindow->startRepeating(NextPreset_Key);
}

void PIRRecordForm::on_nextPresetButton_released()
{
  mainWindow->stopRepeating();
}

void PIRRecordForm::on_recordButton_pressed()
{
  mainWindow->startRepeating(Record_Key);
}

void PIRRecordForm::on_recordButton_released()
{
  mainWindow->stopRepeating();
}

void PIRRecordForm::on_recordPauseButton_pressed()
{
  mainWindow->startRepeating(RecordPause_Key);
}

void PIRRecordForm::on_recordPauseButton_released()
{
  mainWindow->stopRepeating();
}

void PIRRecordForm::on_recordStopButton_pressed()
{
  mainWindow->startRepeating(RecordStop_Key);
}

void PIRRecordForm::on_recordStopButton_released()
{
  mainWindow->stopRepeating();
}

void PIRRecordForm::on_recordMuteButton_pressed()
{
  mainWindow->startRepeating(RecordMute_Key);
}

void PIRRecordForm::on_recordMuteButton_released()
{
  mainWindow->stopRepeating();
}
