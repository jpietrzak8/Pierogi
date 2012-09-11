#include "pircreatecommanddialog.h"
#include "ui_pircreatecommanddialog.h"

#include "mainwindow.h"

/*
PIRCreateCommandDialog::PIRCreateCommandDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::PIRCreateCommandDialog)
{
  ui->setupUi(this);
}
*/


PIRCreateCommandDialog::PIRCreateCommandDialog(
  MainWindow *mw)
  : QDialog(mw),
    ui(new Ui::PIRCreateCommandDialog)
{
  ui->setupUi(this);
}

PIRCreateCommandDialog::~PIRCreateCommandDialog()
{
  delete ui;
}
