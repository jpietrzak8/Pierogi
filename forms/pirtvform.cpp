//
// pirtvform.cpp
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

#include "pirtvform.h"
#include "ui_pirtvform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

PIRTVForm::PIRTVForm(MainWindow *mw) :
  QWidget(0),
  ui(new Ui::PIRTVForm),
  mainWindow(mw)
{
  ui->setupUi(this);
}

PIRTVForm::~PIRTVForm()
{
  delete ui;
}


void PIRTVForm::enableButtons(
  const PIRKeysetManager *km,
  unsigned int id)
{
  emit teletextEnabled(km->hasKey(id, Teletext_Key));
  emit teletextHoldEnabled(km->hasKey(id, TeletextHold_Key));
  emit favoritesEnabled(km->hasKey(id, Favorites_Key));
  emit pageUpEnabled(km->hasKey(id, PageUp_Key));
  emit energySaverEnabled(km->hasKey(id, EnergySave_Key));
  emit smartHubEnabled(km->hasKey(id, SmartHub_Key));
  emit liveTVEnabled(km->hasKey(id, LiveTV_Key));
  emit pageDownEnabled(km->hasKey(id, PageDown_Key));
  emit pipEnabled(km->hasKey(id, PIP_Key));
  emit pipSwapEnabled(km->hasKey(id, PIPSwap_Key));
  emit pipMoveEnabled(km->hasKey(id, PIPMove_Key));
  emit pipSourceEnabled(km->hasKey(id, PIPSource_Key));
  emit pipChannelUpEnabled(km->hasKey(id, PIPChannelUp_Key));
  emit pipChannelDownEnabled(km->hasKey(id, PIPChannelDown_Key));
  emit pipPauseEnabled(km->hasKey(id, PIPPause_Key));
  emit pipSizeEnabled(km->hasKey(id, PIPSize_Key));
}


void PIRTVForm::on_teletextButton_pressed()
{
  mainWindow->startRepeating(Teletext_Key);
}

void PIRTVForm::on_teletextButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVForm::on_teletextHoldButton_pressed()
{
  mainWindow->startRepeating(TeletextHold_Key);
}

void PIRTVForm::on_teletextHoldButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVForm::on_favoritesButton_pressed()
{
  mainWindow->startRepeating(Favorites_Key);
}

void PIRTVForm::on_favoritesButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVForm::on_pageUpButton_pressed()
{
  mainWindow->startRepeating(PageUp_Key);
}

void PIRTVForm::on_pageUpButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVForm::on_energySaverButton_pressed()
{
  mainWindow->startRepeating(EnergySave_Key);
}

void PIRTVForm::on_energySaverButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVForm::on_smartHubButton_pressed()
{
  mainWindow->startRepeating(SmartHub_Key);
}

void PIRTVForm::on_smartHubButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVForm::on_liveTVButton_pressed()
{
  mainWindow->startRepeating(LiveTV_Key);
}

void PIRTVForm::on_liveTVButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVForm::on_pageDownButton_pressed()
{
  mainWindow->startRepeating(PageDown_Key);
}

void PIRTVForm::on_pageDownButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVForm::on_pipButton_pressed()
{
  mainWindow->startRepeating(PIP_Key);
}

void PIRTVForm::on_pipButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVForm::on_pipSwapButton_pressed()
{
  mainWindow->startRepeating(PIPSwap_Key);
}

void PIRTVForm::on_pipSwapButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVForm::on_pipMoveButton_pressed()
{
  mainWindow->startRepeating(PIPMove_Key);
}

void PIRTVForm::on_pipMoveButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVForm::on_pipSourceButton_pressed()
{
  mainWindow->startRepeating(PIPSource_Key);
}

void PIRTVForm::on_pipSourceButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVForm::on_pipChannelUpButton_pressed()
{
  mainWindow->startRepeating(PIPChannelUp_Key);
}

void PIRTVForm::on_pipChannelUpButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVForm::on_pipChannelDownButton_pressed()
{
  mainWindow->startRepeating(PIPChannelDown_Key);
}

void PIRTVForm::on_pipChannelDownButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVForm::on_pipPauseButton_pressed()
{
  mainWindow->startRepeating(PIPPause_Key);
}

void PIRTVForm::on_pipPauseButton_released()
{
  mainWindow->stopRepeating();
}

void PIRTVForm::on_pipSizeButton_pressed()
{
  mainWindow->startRepeating(PIPSize_Key);
}

void PIRTVForm::on_pipSizeButton_released()
{
  mainWindow->stopRepeating();
}
