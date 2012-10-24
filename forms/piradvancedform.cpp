#include "piradvancedform.h"
#include "ui_piradvancedform.h"

#include "pirkeysetmanager.h"

PIRAdvancedForm::PIRAdvancedForm()
  : QWidget(0),
    ui(new Ui::PIRAdvancedForm)
{
  ui->setupUi(this);
}

PIRAdvancedForm::~PIRAdvancedForm()
{
  delete ui;
}


void PIRAdvancedForm::setupForm(
  PIRKeysetManager *pkm,
  unsigned int id)
{
  keysetManager = pkm;
  keysetID = id;

  ui->carrierFrequencySpinBox->setValue(pkm->getCarrierFrequency(id));
  ui->dutyCycleSpinBox->setValue(pkm->getDutyCycle(id));
}


void PIRAdvancedForm::on_carrierFrequencySpinBox_valueChanged(int arg1)
{
  if (arg1 < 30000) arg1 = 30000;
  if (arg1 > 60000) arg1 = 60000;
  keysetManager->setCarrierFrequency((unsigned int) arg1, keysetID);
}

void PIRAdvancedForm::on_dutyCycleSpinBox_valueChanged(int arg1)
{
  keysetManager->setDutyCycle((unsigned int) arg1, keysetID);
}
