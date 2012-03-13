#include "pirmacroform.h"
#include "ui_pirmacroform.h"

PIRMacroForm::PIRMacroForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRMacroForm)
{
  ui->setupUi(this);
}

PIRMacroForm::~PIRMacroForm()
{
  delete ui;
}

void PIRMacroForm::on_cycleCheckBox_stateChanged(int arg1)
{

}

void PIRMacroForm::on_spinBox_valueChanged(int arg1)
{

}

void PIRMacroForm::on_prevMacroButton_clicked()
{

}

void PIRMacroForm::on_nextMacroButton_clicked()
{

}

void PIRMacroForm::on_newMacroButton_clicked()
{

}
