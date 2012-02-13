#include "sideshotleftform.h"
#include "ui_sideshotleftform.h"

SideshotLeftForm::SideshotLeftForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::SideshotLeftForm)
{
  ui->setupUi(this);
}

SideshotLeftForm::~SideshotLeftForm()
{
  delete ui;
}
