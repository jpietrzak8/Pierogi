#include "piradjustform.h"
#include "ui_piradjustform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"

PIRAdjustForm::PIRAdjustForm(MainWindow *mw) :
  QWidget(0),
  ui(new Ui::PIRAdjustForm),
  mainWindow(mw)
{
  ui->setupUi(this);
}

PIRAdjustForm::~PIRAdjustForm()
{
  delete ui;
}


void PIRAdjustForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  emit bassUpEnabled(keyset->hasKey(id, BassUp_Key));
  emit trebleUpEnabled(keyset->hasKey(id, TrebleUp_Key));
  emit enhancedBassEnabled(keyset->hasKey(id, EnhancedBass_Key));
  emit noiseReductionEnabled(keyset->hasKey(id, NoiseReduction_Key));
  emit bassDownEnabled(keyset->hasKey(id, BassDown_Key));
  emit trebleDownEnabled(keyset->hasKey(id, TrebleDown_Key));
  emit balanceLeftEnabled(keyset->hasKey(id, BalanceLeft_Key));
  emit balanceRightEnabled(keyset->hasKey(id, BalanceRight_Key));
  emit surroundEnabled(keyset->hasKey(id, Surround_Key));
  emit colorUpEnabled(keyset->hasKey(id, ColorUp_Key));
  emit brightnessUpEnabled(keyset->hasKey(id, BrightnessUp_Key));
  emit contrastUpEnabled(keyset->hasKey(id, ContrastUp_Key));
  emit zoomEnabled(keyset->hasKey(id, Zoom_Key));
  emit colorDownEnabled(keyset->hasKey(id, ColorDown_Key));
  emit brightnessDownEnabled(keyset->hasKey(id, BrightnessDown_Key));
  emit contrastDownEnabled(keyset->hasKey(id, ContrastDown_Key));
}


void PIRAdjustForm::on_bassUpButton_pressed()
{
  mainWindow->startRepeating(BassUp_Key);
}

void PIRAdjustForm::on_bassUpButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAdjustForm::on_trebleUpButton_pressed()
{
  mainWindow->startRepeating(TrebleUp_Key);
}

void PIRAdjustForm::on_trebleUpButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAdjustForm::on_enhancedBassButton_pressed()
{
  mainWindow->startRepeating(EnhancedBass_Key);
}

void PIRAdjustForm::on_enhancedBassButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAdjustForm::on_noiseReductionButton_pressed()
{
  mainWindow->startRepeating(NoiseReduction_Key);
}

void PIRAdjustForm::on_noiseReductionButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAdjustForm::on_bassDownButton_pressed()
{
  mainWindow->startRepeating(BassDown_Key);
}

void PIRAdjustForm::on_bassDownButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAdjustForm::on_trebleDownButton_pressed()
{
  mainWindow->startRepeating(TrebleDown_Key);
}

void PIRAdjustForm::on_trebleDownButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAdjustForm::on_balanceLeftButton_pressed()
{
  mainWindow->startRepeating(BalanceLeft_Key);
}

void PIRAdjustForm::on_balanceLeftButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAdjustForm::on_balanceRightButton_pressed()
{
  mainWindow->startRepeating(BalanceRight_Key);
}

void PIRAdjustForm::on_balanceRightButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAdjustForm::on_surroundButton_pressed()
{
  mainWindow->startRepeating(Surround_Key);
}

void PIRAdjustForm::on_surroundButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAdjustForm::on_colorUpButton_pressed()
{
  mainWindow->startRepeating(ColorUp_Key);
}

void PIRAdjustForm::on_colorUpButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAdjustForm::on_brightnessUpButton_pressed()
{
  mainWindow->startRepeating(BrightnessUp_Key);
}

void PIRAdjustForm::on_brightnessUpButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAdjustForm::on_contrastUpButton_pressed()
{
  mainWindow->startRepeating(ContrastUp_Key);
}

void PIRAdjustForm::on_contrastUpButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAdjustForm::on_zoomButton_pressed()
{
  mainWindow->startRepeating(Zoom_Key);
}

void PIRAdjustForm::on_zoomButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAdjustForm::on_colorDownButton_pressed()
{
  mainWindow->startRepeating(ColorDown_Key);
}

void PIRAdjustForm::on_colorDownButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAdjustForm::on_brightnessDownButton_pressed()
{
  mainWindow->startRepeating(BrightnessDown_Key);
}

void PIRAdjustForm::on_brightnessDownButton_released()
{
  mainWindow->stopRepeating();
}

void PIRAdjustForm::on_contrastDownButton_pressed()
{
  mainWindow->startRepeating(ContrastDown_Key);
}

void PIRAdjustForm::on_contrastDownButton_released()
{
  mainWindow->stopRepeating();
}
