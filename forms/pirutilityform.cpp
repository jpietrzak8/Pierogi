#include "pirutilityform.h"
#include "ui_pirutilityform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

PIRUtilityForm::PIRUtilityForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRUtilityForm),
    mainWindow(mw)
{
  ui->setupUi(this);
}

PIRUtilityForm::~PIRUtilityForm()
{
  delete ui;
}


void PIRUtilityForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  emit redEnabled(keyset->hasKey(id, Red_Key));
  emit greenEnabled(keyset->hasKey(id, Green_Key));
  emit yellowEnabled(keyset->hasKey(id, Yellow_Key));
  emit blueEnabled(keyset->hasKey(id, Blue_Key));
  emit pictureModeEnabled(keyset->hasKey(id, PictureMode_Key));
  emit soundModeEnabled(keyset->hasKey(id, SoundMode_Key));
  emit aspectRatioEnabled(keyset->hasKey(id, AspectRatio_Key));
  emit audioEnabled(keyset->hasKey(id, Audio_Key));
  emit infoEnabled(keyset->hasKey(id, Info_Key));
  emit captionsEnabled(keyset->hasKey(id, Captions_Key));
  emit sleepEnabled(keyset->hasKey(id, Sleep_Key));
  emit inputEnabled(keyset->hasKey(id, Input_Key));
}


void PIRUtilityForm::on_redButton_pressed()
{
  mainWindow->startRepeating(Red_Key);
}

void PIRUtilityForm::on_redButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_greenButton_pressed()
{
  mainWindow->startRepeating(Green_Key);
}

void PIRUtilityForm::on_greenButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_yellowButton_pressed()
{
  mainWindow->startRepeating(Yellow_Key);
}

void PIRUtilityForm::on_yellowButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_blueButton_pressed()
{
  mainWindow->startRepeating(Blue_Key);
}

void PIRUtilityForm::on_blueButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_pictureModeButton_pressed()
{
  mainWindow->startRepeating(PictureMode_Key);
}

void PIRUtilityForm::on_pictureModeButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_soundModeButton_pressed()
{
  mainWindow->startRepeating(SoundMode_Key);
}

void PIRUtilityForm::on_soundModeButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_aspectRatioButton_pressed()
{
  mainWindow->startRepeating(AspectRatio_Key);
}

void PIRUtilityForm::on_aspectRatioButton_released()
{
  mainWindow->stopRepeating();
}

/*
void PIRUtilityForm::on_surroundButton_pressed()
{
  mainWindow->startRepeating(Surround_Key);
}

void PIRUtilityForm::on_surroundButton_released()
{
  mainWindow->stopRepeating();
}
*/

void PIRUtilityForm::on_audioButton_pressed()
{
  mainWindow->startRepeating(Audio_Key);
}

void PIRUtilityForm::on_audioButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_infoButton_pressed()
{
  mainWindow->startRepeating(Info_Key);
}

void PIRUtilityForm::on_infoButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_captionButton_pressed()
{
  mainWindow->startRepeating(Captions_Key);
}

void PIRUtilityForm::on_captionButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_inputButton_pressed()
{
  mainWindow->startRepeating(Input_Key);
}

void PIRUtilityForm::on_inputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRUtilityForm::on_sleepButton_pressed()
{
  mainWindow->startRepeating(Sleep_Key);
}

void PIRUtilityForm::on_sleepButton_released()
{
  mainWindow->stopRepeating();
}
