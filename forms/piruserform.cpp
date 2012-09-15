#include "piruserform.h"
#include "ui_piruserform.h"

#include "mainwindow.h"

/*
PIRUserForm::PIRUserForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRUserForm)
{
  ui->setupUi(this);
}
*/


PIRUserForm::PIRUserForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRUserForm),
    mainWindow(mw)
{
  ui->setupUi(this);
}


PIRUserForm::~PIRUserForm()
{
  delete ui;
}


void PIRUserForm::setupButtons()
{

  if (mainWindow->hasMacroButton(1))
  {
    ui->userDef1Button->setEnabled(true);
    ui->userDef1Button->setText(mainWindow->getMacroButtonText(1));
  }
  else
  {
    ui->userDef1Button->setEnabled(false);
    ui->userDef1Button->setText("User Defined 1");
  }

  if (mainWindow->hasMacroButton(2))
  {
    ui->userDef2Button->setEnabled(true);
    ui->userDef2Button->setText(mainWindow->getMacroButtonText(2));
  }
  else
  {
    ui->userDef2Button->setEnabled(false);
    ui->userDef2Button->setText("User Defined 2");
  }

  if (mainWindow->hasMacroButton(3))
  {
    ui->userDef3Button->setEnabled(true);
    ui->userDef3Button->setText(mainWindow->getMacroButtonText(3));
  }
  else
  {
    ui->userDef3Button->setEnabled(false);
    ui->userDef3Button->setText("User Defined 3");
  }

  if (mainWindow->hasMacroButton(4))
  {
    ui->userDef4Button->setEnabled(true);
    ui->userDef4Button->setText(mainWindow->getMacroButtonText(4));
  }
  else
  {
    ui->userDef4Button->setEnabled(false);
    ui->userDef4Button->setText("User Defined 4");
  }

  if (mainWindow->hasMacroButton(5))
  {
    ui->userDef5Button->setEnabled(true);
    ui->userDef5Button->setText(mainWindow->getMacroButtonText(5));
  }
  else
  {
    ui->userDef5Button->setEnabled(false);
    ui->userDef5Button->setText("User Defined 5");
  }

  if (mainWindow->hasMacroButton(6))
  {
    ui->userDef6Button->setEnabled(true);
    ui->userDef6Button->setText(mainWindow->getMacroButtonText(6));
  }
  else
  {
    ui->userDef6Button->setEnabled(false);
    ui->userDef6Button->setText("User Defined 6");
  }

}


void PIRUserForm::on_userDef1Button_clicked()
{
  mainWindow->executeMacroButton(1);
}

void PIRUserForm::on_userDef2Button_clicked()
{
  mainWindow->executeMacroButton(2);
}

void PIRUserForm::on_userDef3Button_clicked()
{
  mainWindow->executeMacroButton(3);
}

void PIRUserForm::on_userDef4Button_clicked()
{
  mainWindow->executeMacroButton(4);
}

void PIRUserForm::on_userDef5Button_clicked()
{
  mainWindow->executeMacroButton(5);
}

void PIRUserForm::on_userDef6Button_clicked()
{
  mainWindow->executeMacroButton(6);
}
