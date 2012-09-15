#include "pirdeletemacrodialog.h"
#include "ui_pirdeletemacrodialog.h"

#include "macros/pirmacro.h"

PIRDeleteMacroDialog::PIRDeleteMacroDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::PIRDeleteMacroDialog)
{
  ui->setupUi(this);
}

PIRDeleteMacroDialog::~PIRDeleteMacroDialog()
{
  delete ui;
}


void PIRDeleteMacroDialog::setup(
  PIRMacro *macro)
{
  ui->macroNameLabel->setText(macro->getName());
}
