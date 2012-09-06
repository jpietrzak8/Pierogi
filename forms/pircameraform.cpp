#include "pircameraform.h"
#include "ui_pircameraform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

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
    mainWindow(mw)
{
  ui->setupUi(this);
}


PIRCameraForm::~PIRCameraForm()
{
  delete ui;
}


void PIRCameraForm::enableButtons(
  const PIRKeysetManager *km,
  unsigned int id)
{
  emit openShutterEnabled(km->hasKey(id, OpenShutter_Key));
  emit delayedOpenShutterEnabled(km->hasKey(id, DelayedOpenShutter_Key));
}


void PIRCameraForm::on_delayedShutterButton_pressed()
{
  mainWindow->startRepeating(DelayedOpenShutter_Key);
}

void PIRCameraForm::on_delayedShutterButton_released()
{
  mainWindow->stopRepeating();
}

void PIRCameraForm::on_openShutterButton_pressed()
{
  mainWindow->startRepeating(OpenShutter_Key);
}

void PIRCameraForm::on_openShutterButton_released()
{
  mainWindow->stopRepeating();
}
