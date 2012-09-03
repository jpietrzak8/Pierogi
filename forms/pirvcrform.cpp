#include "pirvcrform.h"
#include "ui_pirvcrform.h"

PIRVCRForm::PIRVCRForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRVCRForm)
{
  ui->setupUi(this);
}

PIRVCRForm::~PIRVCRForm()
{
  delete ui;
}
