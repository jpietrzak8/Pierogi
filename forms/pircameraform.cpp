#include "pircameraform.h"
#include "ui_pircameraform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"
#include "pirflashled.h"

/*
PIRCameraForm::PIRCameraForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRCameraForm)
{
  ui->setupUi(this);
}
*/


PIRCameraForm::PIRCameraForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRCameraForm),
    mainWindow(mw),
    flash(0)
{
  ui->setupUi(this);
}


PIRCameraForm::~PIRCameraForm()
{
  if (flash) delete flash;

  delete ui;
}


void PIRCameraForm::enableButtons(
  const PIRKeysetManager *km,
  unsigned int id)
{
  emit openShutterEnabled(km->hasKey(id, OpenShutter_Key));
  emit delayedOpenShutterEnabled(km->hasKey(id, DelayedOpenShutter_Key));
}


void PIRCameraForm::on_openShutterButton_pressed()
{
  if (ui->delayedShutterCheckBox->isChecked())
  {
    mainWindow->startRepeating(DelayedOpenShutter_Key);
  }
  else
  {
    if (ui->remoteFlashCheckBox->isChecked())
    {
      flash = new PIRFlashLED();
      flash->strobe();
    }

    mainWindow->startRepeating(OpenShutter_Key);
  }
}

void PIRCameraForm::on_openShutterButton_released()
{
  mainWindow->stopRepeating();

  if (flash)
  {
    delete flash;
    flash = 0;
  }
}
