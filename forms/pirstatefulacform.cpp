#include "pirstatefulacform.h"
#include "ui_pirstatefulacform.h"

PIRStatefulACForm::PIRStatefulACForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRStatefulACForm)
{
  ui->setupUi(this);
}

PIRStatefulACForm::~PIRStatefulACForm()
{
  delete ui;
}
