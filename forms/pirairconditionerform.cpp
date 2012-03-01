#include "pirairconditionerform.h"
#include "ui_pirairconditionerform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

PIRAirConditionerForm::PIRAirConditionerForm(MainWindow *mw) :
  QWidget(0),
  ui(new Ui::PIRAirConditionerForm),
  mainWindow(mw)
{
  ui->setupUi(this);
}

PIRAirConditionerForm::~PIRAirConditionerForm()
{
  delete ui;
}


void PIRAirConditionerForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  emit oscillateEnabled(keyset->hasKey(id, Oscillate_Key));
  emit powerEnabled(keyset->hasKey(id, Power_Key));
  emit timerEnabled(keyset->hasKey(id, Timer_Key));
  emit modeEnabled(keyset->hasKey(id, Mode_Key));
  emit fanFasterEnabled(keyset->hasKey(id, FanFaster_Key));
  emit heatEnabled(keyset->hasKey(id, Heat_Key));
  emit fanEnabled(keyset->hasKey(id, Fan_Key));
  emit tempUpEnabled(keyset->hasKey(id, TempUp_Key));
  emit fanSlowerEnabled(keyset->hasKey(id, FanSlower_Key));
  emit energySaveEnabled(keyset->hasKey(id, EnergySave_Key));
  emit coolEnabled(keyset->hasKey(id, Cool_Key));
  emit tempDownEnabled(keyset->hasKey(id, TempDown_Key));
}

void PIRAirConditionerForm::on_oscillateButton_pressed()
{
  mainWindow->startRepeating(Oscillate_Key);
}

void PIRAirConditionerForm::on_oscillateButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAirConditionerForm::on_powerButton_pressed()
{
  mainWindow->startRepeating(Power_Key);
}

void PIRAirConditionerForm::on_powerButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAirConditionerForm::on_timerButton_pressed()
{
  mainWindow->startRepeating(Timer_Key);
}

void PIRAirConditionerForm::on_timerButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAirConditionerForm::on_modeButton_pressed()
{
  mainWindow->startRepeating(Mode_Key);
}

void PIRAirConditionerForm::on_modeButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAirConditionerForm::on_fanFasterButton_pressed()
{
  mainWindow->startRepeating(FanFaster_Key);
}

void PIRAirConditionerForm::on_fanFasterButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAirConditionerForm::on_heatButton_pressed()
{
  mainWindow->startRepeating(Heat_Key);
}

void PIRAirConditionerForm::on_heatButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAirConditionerForm::on_fanButton_pressed()
{
  mainWindow->startRepeating(Fan_Key);
}

void PIRAirConditionerForm::on_fanButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAirConditionerForm::on_tempUpButton_pressed()
{
  mainWindow->startRepeating(TempUp_Key);
}

void PIRAirConditionerForm::on_tempUpButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAirConditionerForm::on_fanSlowerButton_pressed()
{
  mainWindow->startRepeating(FanSlower_Key);
}

void PIRAirConditionerForm::on_fanSlowerButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAirConditionerForm::on_energySaveButton_pressed()
{
  mainWindow->startRepeating(EnergySave_Key);
}

void PIRAirConditionerForm::on_energySaveButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAirConditionerForm::on_coolButton_pressed()
{
  mainWindow->startRepeating(Cool_Key);
}

void PIRAirConditionerForm::on_coolButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAirConditionerForm::on_tempDownButton_pressed()
{
  mainWindow->startRepeating(TempDown_Key);
}

void PIRAirConditionerForm::on_tempDownButton_released()
{
  mainWindow->stopRepeating();
}
