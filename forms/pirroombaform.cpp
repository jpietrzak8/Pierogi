#include "pirroombaform.h"
#include "ui_pirroombaform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

/*
PIRRoombaForm::PIRRoombaForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRRoombaForm)
{
  ui->setupUi(this);
}
*/

PIRRoombaForm::PIRRoombaForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRRoombaForm),
    mainWindow(mw)
{
  ui->setupUi(this);
}

PIRRoombaForm::~PIRRoombaForm()
{
  delete ui;
}

void PIRRoombaForm::enableButtons(
  const PIRKeysetManager *km,
  unsigned int id)
{
  emit spotEnabled(km->hasKey(id, RobotSpot_Key));
  emit forwardEnabled(km->hasKey(id, RobotForward_Key));
  emit cleanEnabled(km->hasKey(id, RobotClean_Key));
  emit ccwEnabled(km->hasKey(id, RobotCCW_Key));
  emit pauseEnabled(km->hasKey(id, Pause_Key));
  emit cwEnabled(km->hasKey(id, RobotCW_Key));
  emit maxEnabled(km->hasKey(id, RobotMax_Key));
  emit powerEnabled(km->hasKey(id, Power_Key));
}

void PIRRoombaForm::on_spotButton_pressed()
{
  mainWindow->startRepeating(RobotSpot_Key);
}

void PIRRoombaForm::on_spotButton_released()
{
  mainWindow->stopRepeating();
}

void PIRRoombaForm::on_forwardButton_pressed()
{
  mainWindow->startRepeating(RobotForward_Key);
}

void PIRRoombaForm::on_forwardButton_released()
{
  mainWindow->stopRepeating();
}

void PIRRoombaForm::on_cleanButton_pressed()
{
  mainWindow->startRepeating(RobotClean_Key);
}

void PIRRoombaForm::on_cleanButton_released()
{
  mainWindow->stopRepeating();
}

void PIRRoombaForm::on_ccwButton_pressed()
{
  mainWindow->startRepeating(RobotCCW_Key);
}

void PIRRoombaForm::on_ccwButton_released()
{
  mainWindow->stopRepeating();
}

void PIRRoombaForm::on_pauseButton_pressed()
{
  mainWindow->startRepeating(Pause_Key);
}

void PIRRoombaForm::on_pauseButton_released()
{
  mainWindow->stopRepeating();
}

void PIRRoombaForm::on_cwButton_pressed()
{
  mainWindow->startRepeating(RobotCW_Key);
}

void PIRRoombaForm::on_cwButton_released()
{
  mainWindow->stopRepeating();
}

void PIRRoombaForm::on_maxButton_pressed()
{
  mainWindow->startRepeating(RobotMax_Key);
}

void PIRRoombaForm::on_maxButton_released()
{
  mainWindow->stopRepeating();
}

void PIRRoombaForm::on_powerButton_pressed()
{
  mainWindow->startRepeating(Power_Key);
}

void PIRRoombaForm::on_powerButton_released()
{
  mainWindow->stopRepeating();
}
