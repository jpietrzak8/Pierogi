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
}

PIRPanelSelectionForm::~PIRPanelSelectionForm()
{
  delete ui;
}

void PIRPanelSelectionForm::setCheckBox(
  PIRPanelName name,
  bool setting)
{
  switch (name)
  {
  case Main_Panel:
    ui->mainCheckBox->setChecked(setting);
    break;

  case Utility_Panel:
    ui->utilityCheckBox->setChecked(setting);
    break;

  case Keypad_Panel:
    ui->keypadCheckBox->setChecked(setting);
    break;

  case Menu_Panel:
    ui->menuCheckBox->setChecked(setting);
    break;

  case Media_Panel:
    ui->mediaCheckBox->setChecked(setting);
    break;

  case Media2_Panel:
    ui->media2CheckBox->setChecked(setting);
    break;

  case Record_Panel:
    ui->recordCheckBox->setChecked(setting);
    break;

  case TV_Panel:
    ui->tvCheckBox->setChecked(setting);
    break;

  case Input_Panel:
    ui->inputCheckBox->setChecked(setting);
    break;

  case Adjust_Panel:
    ui->adjustCheckBox->setChecked(setting);
    break;

  case AC_Panel:
    ui->acCheckBox->setChecked(setting);
    break;

  case Favorites_Panel:
    ui->favoritesCheckBox->setChecked(setting);
    break;

  default:
    break;
  }
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

void PIRPanelSelectionForm::on_media2CheckBox_stateChanged(int arg1)
{
  mainWindow->managePanel(Media2_Panel, arg1);
}

void PIRPanelSelectionForm::on_recordCheckBox_stateChanged(int arg1)
{
  mainWindow->managePanel(Record_Panel, arg1);
}

void PIRPanelSelectionForm::on_tvCheckBox_stateChanged(int arg1)
{
  mainWindow->managePanel(TV_Panel, arg1);
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
