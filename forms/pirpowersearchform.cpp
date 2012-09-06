#include "pirpowersearchform.h"
#include "ui_pirpowersearchform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

#include <QTimer>
#include <QMutex>

// Debugging includes:
#include <iostream>

// Check if a command is running:
extern bool commandInFlight;
extern QMutex commandIFMutex;

/*
PIRPowerSearchForm::PIRPowerSearchForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRPowerSearchForm)
{
  ui->setupUi(this);
}
*/


PIRPowerSearchForm::PIRPowerSearchForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRPowerSearchForm),
    mainWindow(mw),
    advanceTimer(0)
{
  ui->setupUi(this);
}


PIRPowerSearchForm::~PIRPowerSearchForm()
{
  delete ui;
  if (advanceTimer) delete advanceTimer;
}

void PIRPowerSearchForm::setKeysetName(
  QString name)
{
  ui->keysetNameLabel->setText(name);
}

void PIRPowerSearchForm::on_stepBackwardButton_pressed()
{
  if (mainWindow->selectPrevKeyset())
  {
    mainWindow->startRepeating(Power_Key);
  }
}

void PIRPowerSearchForm::on_stepBackwardButton_released()
{
  mainWindow->stopRepeating();
}

void PIRPowerSearchForm::on_stepForwardKey_pressed()
{
  if (mainWindow->selectNextKeyset())
  {
    mainWindow->startRepeating(Power_Key);
  }
}

void PIRPowerSearchForm::on_stepForwardKey_released()
{
  mainWindow->stopRepeating();
}

void PIRPowerSearchForm::on_fastBackwardButton_pressed()
{
  if (!mainWindow->selectPrevKeyset())
  {
    return;
  }

  mainWindow->startRepeating(Power_Key);

  advanceTimer = new QTimer();
  connect(advanceTimer, SIGNAL(timeout()), this, SLOT(gotoPrevKeyset()));
  advanceTimer->start(100);
}

void PIRPowerSearchForm::on_fastBackwardButton_released()
{
  delete advanceTimer;
  advanceTimer = 0;
  mainWindow->stopRepeating();
}

void PIRPowerSearchForm::on_fastForwardButton_pressed()
{
  if (!mainWindow->selectNextKeyset())
  {
    return;
  }

  mainWindow->startRepeating(Power_Key);

  advanceTimer = new QTimer();
  connect(advanceTimer, SIGNAL(timeout()), this, SLOT(gotoNextKeyset()));
  advanceTimer->start(50);
}


void PIRPowerSearchForm::on_fastForwardButton_released()
{
  delete advanceTimer;
  advanceTimer = 0;
  mainWindow->stopRepeating();
}


void PIRPowerSearchForm::gotoPrevKeyset()
{
  if (checkMutex())
  {
    mainWindow->stopRepeating();
  }
  else
  {
    if (mainWindow->selectPrevKeyset())
    {
      mainWindow->startRepeating(Power_Key);
    }
    else
    {
      delete advanceTimer;
      advanceTimer = 0;
    }
  }
}


void PIRPowerSearchForm::gotoNextKeyset()
{
  if (checkMutex())
  {
    mainWindow->stopRepeating();
  }
  else
  {
    if (mainWindow->selectNextKeyset())
    {
      mainWindow->startRepeating(Power_Key);
    }
    else
    {
      delete advanceTimer;
      advanceTimer = 0;
    }
  }
}


bool PIRPowerSearchForm::checkMutex()
{
  QMutexLocker locker(&commandIFMutex);
  return commandInFlight;
}
