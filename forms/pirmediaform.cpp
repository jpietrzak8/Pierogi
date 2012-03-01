#include "pirmediaform.h"
#include "ui_pirmediaform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

PIRMediaForm::PIRMediaForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRMediaForm),
    mainWindow(mw)
{
  ui->setupUi(this);
}

PIRMediaForm::~PIRMediaForm()
{
  delete ui;
}


void PIRMediaForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  emit nextEnabled(keyset->hasKey(id, Next_Key));
  emit previousEnabled(keyset->hasKey(id, Previous_Key));
  emit advanceEnabled(keyset->hasKey(id, Advance_Key));
  emit replayEnabled(keyset->hasKey(id, Replay_Key));
  emit stepForwardEnabled(keyset->hasKey(id, StepForward_Key));
  emit stepBackEnabled(keyset->hasKey(id, StepBack_Key));
  emit fastForwardEnabled(keyset->hasKey(id, FastForward_Key));
  emit reverseEnabled(keyset->hasKey(id, Rewind_Key));
  emit playEnabled(keyset->hasKey(id, Play_Key));
  emit pauseEnabled(keyset->hasKey(id, Pause_Key));
  emit stopEnabled(keyset->hasKey(id, Stop_Key));
  emit ejectEnabled(keyset->hasKey(id, Eject_Key));
}


void PIRMediaForm::on_mediaPreviousButton_pressed()
{
  mainWindow->startRepeating(Previous_Key);
}

void PIRMediaForm::on_mediaPreviousButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMediaForm::on_mediaNextButton_pressed()
{
  mainWindow->startRepeating(Next_Key);
}

void PIRMediaForm::on_mediaNextButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMediaForm::on_replayButton_pressed()
{
  mainWindow->startRepeating(Replay_Key);
}

void PIRMediaForm::on_replayButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMediaForm::on_advanceButton_pressed()
{
  mainWindow->startRepeating(Advance_Key);
}

void PIRMediaForm::on_advanceButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMediaForm::on_stepBackButton_pressed()
{
  mainWindow->startRepeating(StepBack_Key);
}

void PIRMediaForm::on_stepBackButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMediaForm::on_stepForwardButton_pressed()
{
  mainWindow->startRepeating(StepForward_Key);
}

void PIRMediaForm::on_stepForwardButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMediaForm::on_reverseButton_pressed()
{
  mainWindow->startRepeating(Rewind_Key);
}

void PIRMediaForm::on_reverseButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMediaForm::on_fastForwardButton_pressed()
{
  mainWindow->startRepeating(FastForward_Key);
}

void PIRMediaForm::on_fastForwardButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMediaForm::on_playButton_pressed()
{
  mainWindow->startRepeating(Play_Key);
}

void PIRMediaForm::on_playButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMediaForm::on_pauseButton_pressed()
{
  mainWindow->startRepeating(Pause_Key);
}

void PIRMediaForm::on_pauseButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMediaForm::on_stopButton_pressed()
{
  mainWindow->startRepeating(Stop_Key);
}

void PIRMediaForm::on_stopButton_released()
{
  mainWindow->stopRepeating();
}

void PIRMediaForm::on_ejectButton_pressed()
{
  mainWindow->startRepeating(Eject_Key);
}

void PIRMediaForm::on_ejectButton_released()
{
  mainWindow->stopRepeating();
}
