#include "pirpreferencesform.h"
#include "ui_pirpreferencesform.h"

#include "mainwindow.h"

#include <QSettings>

PIRPreferencesForm::PIRPreferencesForm(
  QWidget *parent)
  : QWidget(parent),
    ui(new Ui::PIRPreferencesForm)
{
  ui->setupUi(this);

  mainWindow = dynamic_cast<MainWindow *>(parent);

  setAttribute(Qt::WA_Maemo5StackedWindow);
  setWindowFlags(windowFlags() | Qt::Window);

  QSettings settings("pietrzak.org", "Pierogi");

  settings.beginGroup("Preferences");

  if (settings.contains("useAltMain"))
  {
    if (settings.value("useAltMain").toBool())
    {
      ui->altMainCheckBox->setChecked(true);
      mainWindow->useAltMainPanel();
    }
  }

  settings.endGroup();
}


PIRPreferencesForm::~PIRPreferencesForm()
{
  delete ui;
}


void PIRPreferencesForm::on_altMainCheckBox_stateChanged(
  int arg1)
{
  QSettings settings("pietrzak.org", "Pierogi");

  settings.beginGroup("Preferences");

  if (arg1 == Qt::Checked)
  {
    settings.setValue("useAltMain", true);

    mainWindow->useAltMainPanel();
  }
  else
  {
    settings.setValue("useAltMain", false);

    mainWindow->useMainPanel();
  }

  settings.endGroup();
}
