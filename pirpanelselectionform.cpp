#include "pirpanelselectionform.h"
#include "ui_pirpanelselectionform.h"

#include "mainwindow.h"

PIRPanelSelectionForm::PIRPanelSelectionForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRPanelSelectionForm)
{
  ui->setupUi(this);

  mainWindow = dynamic_cast<MainWindow *>(parent);

  setAttribute(Qt::WA_Maemo5StackedWindow);
  setWindowFlags(windowFlags() | Qt::Window);

  // Start by setting up a few initial panels:
  ui->mainCheckBox->setChecked(true);
  ui->utilityCheckBox->setChecked(true);
  ui->keypadCheckBox->setChecked(true);
  ui->menuCheckBox->setChecked(true);
  ui->mediaCheckBox->setChecked(true);
  ui->favoritesCheckBox->setChecked(true);
}

PIRPanelSelectionForm::~PIRPanelSelectionForm()
{
  delete ui;
}

void PIRPanelSelectionForm::on_mainCheckBox_stateChanged(int arg1)
{
  mainWindow->managePanel(Main_Panel, arg1);
}

void PIRPanelSelectionForm::on_utilityCheckBox_stateChanged(int arg1)
{
  mainWindow->managePanel(Utility_Panel, arg1);
}

void PIRPanelSelectionForm::on_keypadCheckBox_stateChanged(int arg1)
{
  mainWindow->managePanel(Keypad_Panel, arg1);
}

void PIRPanelSelectionForm::on_menuCheckBox_stateChanged(int arg1)
{
  mainWindow->managePanel(Menu_Panel, arg1);
}

void PIRPanelSelectionForm::on_mediaCheckBox_stateChanged(int arg1)
{
  mainWindow->managePanel(Media_Panel, arg1);
}

void PIRPanelSelectionForm::on_tvCheckBox_stateChanged(int arg1)
{
  mainWindow->managePanel(TV_Panel, arg1);
}

void PIRPanelSelectionForm::on_media2CheckBox_stateChanged(int arg1)
{
  mainWindow->managePanel(Media2_Panel, arg1);
}

void PIRPanelSelectionForm::on_inputCheckBox_stateChanged(int arg1)
{
  mainWindow->managePanel(Input_Panel, arg1);
}

void PIRPanelSelectionForm::on_adjustCheckBox_stateChanged(int arg1)
{
  mainWindow->managePanel(Adjust_Panel, arg1);
}

void PIRPanelSelectionForm::on_acCheckBox_stateChanged(int arg1)
{
  mainWindow->managePanel(AC_Panel, arg1);
}

void PIRPanelSelectionForm::on_favoritesCheckBox_stateChanged(int arg1)
{
  mainWindow->managePanel(Favorites_Panel, arg1);
}
