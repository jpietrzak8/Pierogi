//
// pirpreferencesform.cpp
//
// Copyright 2012 - 2014 by John Pietrzak (jpietrzak8@gmail.com)
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

#include "pirpreferencesform.h"
#include "ui_pirpreferencesform.h"
#include "pirkeysetmanager.h"

#include "mainwindow.h"

#include <QSettings>
#include <QComboBox>
#include <QFileDialog>

//#include <iostream>

PIRPreferencesForm::PIRPreferencesForm(
  QWidget *parent,
  const PIRKeysetManager *keysetManager)
  : QWidget(parent),
    ui(new Ui::PIRPreferencesForm),
    defaultKeyset(0),
    useDefaultForVolume(false)
{
  ui->setupUi(this);

  mainWindow = dynamic_cast<MainWindow *>(parent);

  setAttribute(Qt::WA_Maemo5StackedWindow);
  setWindowFlags(windowFlags() | Qt::Window);

  QSettings settings("pietrzak.org", "Pierogi");

  settings.beginGroup("Preferences");

  if (settings.contains("defaultKeysetName"))
  {
    keysetManager->findKeysetID(
      settings.value("defaultKeysetMake").toString(),
      settings.value("defaultKeysetName").toString(),
      defaultKeyset);

    QString displayName = settings.value("defaultKeysetMake").toString();
    displayName.append(" ");
    displayName.append(settings.value("defaultKeysetName").toString());

    ui->defaultKeysetNameLabel->setText(displayName);
    ui->useDefaultCheckBox->setEnabled(true);
  }

  if (settings.contains("useDefaultForVolume"))
  {
    useDefaultForVolume = settings.value("useDefaultForVolume").toBool();

    if (useDefaultForVolume)
    {
      ui->useDefaultCheckBox->setChecked(true);
    }
  }

  if (settings.contains("useAltMain"))
  {
    if (settings.value("useAltMain").toBool())
    {
      ui->altMainCheckBox->setChecked(true);
      mainWindow->useAltMainPanel();
    }
  }

  if (settings.contains("tabsOnTop"))
  {
    if (!settings.value("tabsOnTop").toBool())
    {
      ui->tabsOnBottomCheckBox->setChecked(true);
      mainWindow->placeTabsOnTop(false);
    }
  }

  if (settings.contains("macroFileName"))
  {
    QString filename = settings.value("macroFileName").toString();

    if (filename != "No File Selected")
    {
      loadMacroFile(filename);
    }
  }

  settings.endGroup();
}


PIRPreferencesForm::~PIRPreferencesForm()
{
  delete ui;
}


void PIRPreferencesForm::on_setDefaultButton_clicked()
{
  QString make = mainWindow->getCurrentMake();
  QString name = mainWindow->getCurrentName();
  defaultKeyset = mainWindow->getCurrentKeyset();
  ui->useDefaultCheckBox->setEnabled(true);

  QString displayName = make;
  displayName.append(" ");
  displayName.append(name);
  ui->defaultKeysetNameLabel->setText(displayName);

  QSettings settings("pietrzak.org", "Pierogi");
  settings.beginGroup("Preferences");
  settings.setValue("defaultKeysetMake", make);
  settings.setValue("defaultKeysetName", name);
  settings.endGroup();

  mainWindow->enableButtons();

  emit useDefaultEnabled(true);
}

void PIRPreferencesForm::on_clearDefaultButton_clicked()
{
  defaultKeyset = 0;
  ui->defaultKeysetNameLabel->setText("None");
  ui->useDefaultCheckBox->setEnabled(false);

  QSettings settings("pietrzak.org", "Pierogi");
  settings.beginGroup("Preferences");
  settings.remove("defaultKeysetMake");
  settings.remove("defaultKeysetName");
  settings.endGroup();

  mainWindow->enableButtons();

  emit useDefaultEnabled(false);
}


void PIRPreferencesForm::on_useDefaultCheckBox_stateChanged(int arg1)
{
  QSettings settings("pietrzak.org", "Pierogi");
  settings.beginGroup("Preferences");

  if (arg1 == Qt::Checked)
  {
    useDefaultForVolume = true;
    settings.setValue("useDefaultForVolume", true);
  }
  else
  {
    useDefaultForVolume = false;
    settings.setValue("useDefaultForVolume", false);
  }

  settings.endGroup();

  mainWindow->enableButtons();
}


void PIRPreferencesForm::on_altMainCheckBox_stateChanged(
  int arg1)
{
  QSettings settings("pietrzak.org", "Pierogi");

  settings.beginGroup("Preferences");

  if (arg1 == Qt::Checked)
  {
    settings.setValue("useAltMain", true);

    mainWindow->useAltMainPanel();
  }
  else
  {
    settings.setValue("useAltMain", false);

    mainWindow->useMainPanel();
  }

  settings.endGroup();
}

void PIRPreferencesForm::on_tabsOnBottomCheckBox_stateChanged(
  int arg1)
{
  QSettings settings("pietrzak.org", "Pierogi");

  settings.beginGroup("Preferences");

  if (arg1 == Qt::Checked)
  {
    settings.setValue("tabsOnTop", false);

    mainWindow->placeTabsOnTop(false);
  }
  else
  {
    settings.setValue("tabsOnTop", true);

    mainWindow->placeTabsOnTop(true);
  }

  settings.endGroup();
}


void PIRPreferencesForm::on_carrierFrequencySpinBox_valueChanged(int arg1)
{
  if (arg1 < 30000) arg1 = 30000;
  if (arg1 > 60000) arg1 = 60000;
  mainWindow->setCarrierFrequency((unsigned int) arg1);
}


void PIRPreferencesForm::on_dutyCycleSpinBox_valueChanged(int arg1)
{
  mainWindow->setDutyCycle((unsigned int) arg1);
}


void PIRPreferencesForm::on_macroFilenameButton_clicked()
{
  QString filename = QFileDialog::getOpenFileName(
    0,
    tr("Select Macro XML File"));

  loadMacroFile(filename);

  QSettings settings("pietrzak.org", "Pierogi");
  settings.beginGroup("Preferences");
  settings.setValue("macroFileName", ui->macroFilenameButton->text());
  settings.endGroup();
}


void PIRPreferencesForm::loadMacroFile(
  QString filename)
{
  if (filename.isEmpty())
  {
    ui->macroFilenameButton->setText("No File Selected");
    mainWindow->setupMacroForm();
    return;
  }

  if (!mainWindow->loadNewMacros(filename))
  {
    ui->macroFilenameButton->setText("No File Selected");
    mainWindow->setupMacroForm();
    return;
  }

  ui->macroFilenameButton->setText(filename);

  mainWindow->setupMacroForm();
}
