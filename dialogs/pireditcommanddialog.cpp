#include "pireditcommanddialog.h"
#include "ui_pireditcommanddialog.h"

#include "macros/pirmacrocommanditem.h"

PIREditCommandDialog::PIREditCommandDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::PIREditCommandDialog)
{
  ui->setupUi(this);
}

PIREditCommandDialog::~PIREditCommandDialog()
{
  delete ui;
}


void PIREditCommandDialog::setup(
  QString typeString,
  QString name)
{
  ui->commandTypeLabel->setText(typeString);

  ui->commandValueLabel->setText(name);
}


void PIREditCommandDialog::on_moveUpButton_clicked()
{
  emit moveCommandUp();
  accept();
}

void PIREditCommandDialog::on_moveDownButton_clicked()
{
  emit moveCommandDown();
  accept();
}

void PIREditCommandDialog::on_deleteButton_clicked()
{
  emit deleteCommand();
  accept();
}
