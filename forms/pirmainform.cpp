#include "pirmainform.h"
#include "ui_pirmainform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

// Ugly global:
extern PIRMakeMgr makeManager;


PIRMainForm::PIRMainForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRMainForm),
    mainWindow(mw)
{
  ui->setupUi(this);
}

PIRMainForm::~PIRMainForm()
{
  delete ui;
}


void PIRMainForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  emit powerEnabled(keyset->hasKey(id, Power_Key));
  emit volumeUpEnabled(keyset->hasKey(id, VolumeUp_Key));
  emit volumeDownEnabled(keyset->hasKey(id, VolumeDown_Key));
  emit channelUpEnabled(keyset->hasKey(id, ChannelUp_Key));
  emit channelDownEnabled(keyset->hasKey(id, ChannelDown_Key));
  emit muteEnabled(keyset->hasKey(id, Mute_Key));

  emit keysetMakeChanged(makeManager.getMakeString(keyset->getMake(id)));
  emit keysetNameChanged(keyset->getDisplayName(id));
}


void PIRMainForm::on_powerButton_pressed()
{
  mainWindow->startRepeating(Power_Key);
}

void PIRMainForm::on_powerButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMainForm::on_mainChannelUpButton_pressed()
{
  mainWindow->startRepeating(ChannelUp_Key);
}

void PIRMainForm::on_mainChannelUpButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMainForm::on_mainChannelDownButton_pressed()
{
  mainWindow->startRepeating(ChannelDown_Key);
}

void PIRMainForm::on_mainChannelDownButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMainForm::on_mainVolumeUp_pressed()
{
  mainWindow->startRepeating(VolumeUp_Key);
}

void PIRMainForm::on_mainVolumeUp_released()
{
  mainWindow->stopRepeating();
}

void PIRMainForm::on_mainVolumeDownButton_pressed()
{
  mainWindow->startRepeating(VolumeDown_Key);
}

void PIRMainForm::on_mainVolumeDownButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMainForm::on_muteButton_pressed()
{
  mainWindow->startRepeating(Mute_Key);
}

void PIRMainForm::on_muteButton_released()
{
  mainWindow->stopRepeating();
}
