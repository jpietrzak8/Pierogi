//
// pirinputform.cpp
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

#include "pirinputform.h"
#include "ui_pirinputform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

PIRInputForm::PIRInputForm(MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRInputForm),
    mainWindow(mw)
{
  ui->setupUi(this);
}

PIRInputForm::~PIRInputForm()
{
  delete ui;
}


void PIRInputForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  emit cdInputEnabled(keyset->hasKey(id, CDInput_Key));
  emit tapeInputEnabled(keyset->hasKey(id, TapeInput_Key));
  emit phonoInputEnabled(keyset->hasKey(id, PhonoInput_Key));
  emit tunerInputEnabled(keyset->hasKey(id, TunerInput_Key));
  emit pcInputEnabled(keyset->hasKey(id, PCInput_Key));
  emit hdmiInputEnabled(keyset->hasKey(id, HDMIInput_Key));
  emit dvdInputEnabled(keyset->hasKey(id, DVDInput_Key));
  emit vcrInputEnabled(keyset->hasKey(id, VCRInput_Key));
  emit antennaInputEnabled(keyset->hasKey(id, AntennaInput_Key));
  emit cableInputEnabled(keyset->hasKey(id, CableInput_Key));
  emit satelliteInputEnabled(keyset->hasKey(id, SatInput_Key));
  emit auxInputEnabled(keyset->hasKey(id, AuxInput_Key));
  emit compositeInputEnabled(keyset->hasKey(id, CompositeInput_Key));
  emit componentInputEnabled(keyset->hasKey(id, ComponentInput_Key));
  emit scartInputEnabled(keyset->hasKey(id, ScartInput_Key));
  emit hddInputEnabled(keyset->hasKey(id, HDDInput_Key));
}


void PIRInputForm::on_cdInputButton_pressed()
{
  mainWindow->startRepeating(CDInput_Key);
}

void PIRInputForm::on_cdInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRInputForm::on_tapeInputButton_pressed()
{
  mainWindow->startRepeating(TapeInput_Key);
}

void PIRInputForm::on_tapeInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRInputForm::on_phonoInputButton_pressed()
{
  mainWindow->startRepeating(PhonoInput_Key);
}

void PIRInputForm::on_phonoInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRInputForm::on_tunerInputButton_pressed()
{
  mainWindow->startRepeating(TunerInput_Key);
}

void PIRInputForm::on_tunerInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRInputForm::on_pcInputButton_pressed()
{
  mainWindow->startRepeating(PCInput_Key);
}

void PIRInputForm::on_pcInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRInputForm::on_hdmiInputButton_pressed()
{
  mainWindow->startRepeating(HDMIInput_Key);
}

void PIRInputForm::on_hdmiInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRInputForm::on_dvdInputButton_pressed()
{
  mainWindow->startRepeating(DVDInput_Key);
}

void PIRInputForm::on_dvdInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRInputForm::on_vcrInputButton_pressed()
{
  mainWindow->startRepeating(VCRInput_Key);
}

void PIRInputForm::on_vcrInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRInputForm::on_antennaInputButton_pressed()
{
  mainWindow->startRepeating(AntennaInput_Key);
}

void PIRInputForm::on_antennaInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRInputForm::on_cableInputButton_pressed()
{
  mainWindow->startRepeating(CableInput_Key);
}

void PIRInputForm::on_cableInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRInputForm::on_satelliteInputButton_pressed()
{
  mainWindow->startRepeating(SatInput_Key);
}

void PIRInputForm::on_satelliteInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRInputForm::on_auxInputButton_pressed()
{
  mainWindow->startRepeating(AuxInput_Key);
}

void PIRInputForm::on_auxInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRInputForm::on_compositeInputButton_pressed()
{
  mainWindow->startRepeating(CompositeInput_Key);
}

void PIRInputForm::on_compositeInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRInputForm::on_scartInputButton_pressed()
{
  mainWindow->startRepeating(ScartInput_Key);
}

void PIRInputForm::on_scartInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRInputForm::on_componentInputButton_pressed()
{
  mainWindow->startRepeating(ComponentInput_Key);
}

void PIRInputForm::on_componentInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRInputForm::on_hddInputButton_pressed()
{
  mainWindow->startRepeating(HDDInput_Key);
}

void PIRInputForm::on_hddInputButton_released()
{
  mainWindow->stopRepeating();
}
