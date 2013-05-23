//
// pirmedia2form.cpp
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

#include "pirmedia2form.h"
#include "ui_pirmedia2form.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

PIRMedia2Form::PIRMedia2Form(MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRMedia2Form),
    mainWindow(mw)
{
  ui->setupUi(this);
}

PIRMedia2Form::~PIRMedia2Form()
{
  delete ui;
}


void PIRMedia2Form::enableButtons(
  const PIRKeysetManager *km,
  unsigned int id)
{
  emit tunerBandEnabled(km->hasKey(id, TunerInput_Key));
  emit programEnabled(km->hasKey(id, Program_Key));
  emit memoryEnabled(km->hasKey(id, Memory_Key));
  emit callEnabled(km->hasKey(id, Call_Key));
  emit autoTrackingEnabled(km->hasKey(id, AutoTracking_Key));
  emit trackingMinusEnabled(km->hasKey(id, TrackingMinus_Key));
  emit trackingPlusEnabled(km->hasKey(id, TrackingPlus_Key));
  emit vhsSpeedEnabled(km->hasKey(id, VHSSpeed_Key));
  emit slowEnabled(km->hasKey(id, Slow_Key));
  emit slowMinusEnabled(km->hasKey(id, SlowMinus_Key));
  emit slowPlusEnabled(km->hasKey(id, SlowPlus_Key));
  emit nextDiscEnabled(km->hasKey(id, NextDisc_Key));
  emit repeatEnabled(km->hasKey(id, Repeat_Key));
  emit repeatABEnabled(km->hasKey(id, RepeatAB_Key));
  emit randomEnabled(km->hasKey(id, Random_Key));
  emit discTitleEnabled(km->hasKey(id, DiscTitle_Key));
}


void PIRMedia2Form::on_tunerBandButton_pressed()
{
  mainWindow->startRepeating(TunerInput_Key);
}

void PIRMedia2Form::on_tunerBandButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMedia2Form::on_programButton_pressed()
{
  mainWindow->startRepeating(Program_Key);
}

void PIRMedia2Form::on_programButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMedia2Form::on_memoryButton_pressed()
{
  mainWindow->startRepeating(Memory_Key);
}

void PIRMedia2Form::on_memoryButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMedia2Form::on_callButton_pressed()
{
  mainWindow->startRepeating(Call_Key);
}

void PIRMedia2Form::on_callButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMedia2Form::on_autoTrackingButton_pressed()
{
  mainWindow->startRepeating(AutoTracking_Key);
}

void PIRMedia2Form::on_autoTrackingButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMedia2Form::on_trackingMinusButton_pressed()
{
  mainWindow->startRepeating(TrackingMinus_Key);
}

void PIRMedia2Form::on_trackingMinusButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMedia2Form::on_trackingPlusButton_pressed()
{
  mainWindow->startRepeating(TrackingPlus_Key);
}

void PIRMedia2Form::on_trackingPlusButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMedia2Form::on_vhsSpeedButton_pressed()
{
  mainWindow->startRepeating(VHSSpeed_Key);
}

void PIRMedia2Form::on_vhsSpeedButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMedia2Form::on_slowButton_pressed()
{
  mainWindow->startRepeating(Slow_Key);
}

void PIRMedia2Form::on_slowButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMedia2Form::on_slowMinusButton_pressed()
{
  mainWindow->startRepeating(SlowMinus_Key);
}

void PIRMedia2Form::on_slowMinusButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMedia2Form::on_slowPlusButton_pressed()
{
  mainWindow->startRepeating(SlowPlus_Key);
}

void PIRMedia2Form::on_slowPlusButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMedia2Form::on_discSelectButton_pressed()
{
  mainWindow->startRepeating(NextDisc_Key);
}

void PIRMedia2Form::on_discSelectButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMedia2Form::on_repeatButton_pressed()
{
  mainWindow->startRepeating(Repeat_Key);
}

void PIRMedia2Form::on_repeatButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMedia2Form::on_repeatABButton_pressed()
{
  mainWindow->startRepeating(RepeatAB_Key);
}

void PIRMedia2Form::on_repeatABButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMedia2Form::on_randomButton_pressed()
{
  mainWindow->startRepeating(Random_Key);
}

void PIRMedia2Form::on_randomButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMedia2Form::on_discTitleButton_pressed()
{
  mainWindow->startRepeating(DiscTitle_Key);
}

void PIRMedia2Form::on_discTitleButton_released()
{
  mainWindow->stopRepeating();
}
