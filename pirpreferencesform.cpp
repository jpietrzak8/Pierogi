#include "pirpreferencesform.h"
#include "ui_pirpreferencesform.h"
#include "pirkeysetmanager.h"

#include "mainwindow.h"

#include <QSettings>
#include <QComboBox>

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

  setupMacroComboBox(ui->macroKbdComboBox);
  setupMacroComboBox(ui->macroBtnComboBox);

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

  if (settings.contains("macroKbdFocus"))
  {
/*
    int index = mainWindow->findMacroPack(
      settings.value("macroKbdFocus").toString());
*/
    int index = settings.value("macroKbdFocus").toInt();

    ui->macroKbdComboBox->setCurrentIndex(index);
    mainWindow->setMacroKbdFocus(index);
  }
  else
  {
    mainWindow->setMacroKbdFocus(0);
  }

  if (settings.contains("macroBtnFocus"))
  {
/*
    int index = mainWindow->findMacroPack(
      settings.value("macroBtnFocus").toString());
*/
    int index = settings.value("macroBtnFocus").toInt();

    ui->macroBtnComboBox->setCurrentIndex(index);
    mainWindow->setMacroBtnFocus(index);
  }
  else
  {
    mainWindow->setMacroBtnFocus(0);
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


void PIRPreferencesForm::on_macroKbdComboBox_activated(int index)
{
  QSettings settings("pietrzak.org", "Pierogi");
  settings.beginGroup("Preferences");
  settings.setValue("macroKbdFocus", index);
  settings.endGroup();

  mainWindow->setMacroKbdFocus(index);
}


void PIRPreferencesForm::on_macroBtnComboBox_activated(int index)
{
  QSettings settings("pietrzak.org", "Pierogi");
  settings.beginGroup("Preferences");
  settings.setValue("macroBtnFocus", index);
  settings.endGroup();

  mainWindow->setMacroBtnFocus(index);
  mainWindow->updateUserButtons();
}


void PIRPreferencesForm::setupMacroComboBox(
  QComboBox *cb)
{
  // Crappy hardcoded list.  Need to replace this...
  cb->addItem("User Defined Macros");
  cb->addItem("Reverse Multitap Keboard Macros");
}
