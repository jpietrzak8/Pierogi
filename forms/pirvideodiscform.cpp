#include "pirvideodiscform.h"
#include "ui_pirvideodiscform.h"

PIRVideoDiscForm::PIRVideoDiscForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRVideoDiscForm)
{
  ui->setupUi(this);
}

PIRVideoDiscForm::~PIRVideoDiscForm()
{
  delete ui;
}
