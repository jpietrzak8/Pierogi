#include "pirstatefulacform.h"
#include "ui_pirstatefulacform.h"

#include "mainwindow.h"
#include "pirkeysetmanager.h"
#include "pirackeyset.h"

/*
PIRStatefulACForm::PIRStatefulACForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRStatefulACForm)
{
  ui->setupUi(this);
}
*/

PIRStatefulACForm::PIRStatefulACForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRStatefulACForm),
    mainWindow(mw)
{
  ui->setupUi(this);
}


PIRStatefulACForm::~PIRStatefulACForm()
{
  delete ui;
}

void PIRStatefulACForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  const PIRACKeyset *ackeys = keyset->getACKeyset(id);

  if (ackeys && keyset->hasKey(id, ACSendCommand_Key))
  {
    emit sendCommandEnabled(true);

    // Need to populate the combo boxes:
    PIRStatePairs pairs;
    PIRStatePairs::const_iterator i;

    // Populate the power combo:
    ackeys->getPowerPairs(pairs);
    i = pairs.begin();
    if (i == pairs.end())
    {
      // No power controls
      emit powerComboBoxEnabled(false);
    }
    else
    {
      while (i != pairs.end())
      {
        ui->powerComboBox->addItem((*i)->getName(), QVariant((*i)->getCode()));
        ++i;
      }

      emit powerComboBoxEnabled(true);
    }

    // Populate the temperature combo:
    ackeys->getTemperaturePairs(pairs);
    i = pairs.begin();
    if (i == pairs.end())
    {
      emit tempComboBoxEnabled(false);
    }
    else
    {
      while (i != pairs.end())
      {
        ui->tempComboBox->addItem((*i)->getName(), QVariant((*i)->getCode()));
        ++i;
      }

      emit tempComboBoxEnabled(true);
    }

    // Populate the fan combo:
    ackeys->getFanPairs(pairs);
    i = pairs.begin();
    if (i == pairs.end())
    {
      emit fanComboBoxEnabled(false);
    }
    else
    {
      while (i != pairs.end())
      {
        ui->fanComboBox->addItem((*i)->getName(), QVariant((*i)->getCode()));
        ++i;
      }

      emit fanComboBoxEnabled(true);
    }

    // Populate the mode combo:
    ackeys->getModePairs(pairs);
    i = pairs.begin();
    if (i == pairs.end())
    {
      emit modeComboBoxEnabled(false);
    }
    else
    {
      while (i != pairs.end())
      {
        ui->modeComboBox->addItem((*i)->getName(), QVariant((*i)->getCode()));
        ++i;
      }

      emit modeComboBoxEnabled(true);
    }

    ackeys->getSwingPairs(pairs);
    i = pairs.begin();
    if (i == pairs.end())
    {
      emit swingComboBoxEnabled(false);
    }
    else
    {
      while (i != pairs.end())
      {
        ui->swingComboBox->addItem((*i)->getName(), QVariant((*i)->getCode()));
        ++i;
      }

      emit swingComboBoxEnabled(true);
    }

    ackeys->getTurboModePairs(pairs);
    i = pairs.begin();
    if (i == pairs.end())
    {
      emit turboComboBoxEnabled(false);
    }
    else
    {
      while (i != pairs.end())
      {
        ui->turboComboBox->addItem((*i)->getName(), QVariant((*i)->getCode()));
        ++i;
      }

      emit turboComboBoxEnabled(true);
    }

    ackeys->getAirCleanPairs(pairs);
    i = pairs.begin();
    if (i == pairs.end())
    {
      emit airCleanComboBoxEnabled(false);
    }
    else
    {
      while (i != pairs.end())
      {
        ui->airCleanComboBox->addItem(
          (*i)->getName(), QVariant((*i)->getCode()));
        ++i;
      }

      emit airCleanComboBoxEnabled(true);
    }
  }
  else
  {
    emit sendCommandEnabled(false);
    emit powerComboBoxEnabled(false);
    emit tempComboBoxEnabled(false);
    emit fanComboBoxEnabled(false);
    emit modeComboBoxEnabled(false);
    emit swingComboBoxEnabled(false);
    emit turboComboBoxEnabled(false);
    emit airCleanComboBoxEnabled(false);
  }
}

void PIRStatefulACForm::on_sendButton_pressed()
{
  PIRACStateInfo state;

  if (ui->powerComboBox->isEnabled())
  {
    state.power = ui->powerComboBox->itemData(
      ui->powerComboBox->currentIndex()).toInt();
  }

  if (ui->tempComboBox->isEnabled())
  {
    state.temperature = ui->tempComboBox->itemData(
      ui->tempComboBox->currentIndex()).toInt();
  }

  if (ui->fanComboBox->isEnabled())
  {
    state.fan = ui->fanComboBox->itemData(
      ui->fanComboBox->currentIndex()).toInt();
  }

  if (ui->modeComboBox->isEnabled())
  {
    state.mode = ui->modeComboBox->itemData(
      ui->modeComboBox->currentIndex()).toInt();
  }

  if (ui->swingComboBox->isEnabled())
  {
    state.swing = ui->swingComboBox->itemData(
      ui->swingComboBox->currentIndex()).toInt();
  }

  if (ui->turboComboBox->isEnabled())
  {
    state.turbo = ui->turboComboBox->itemData(
      ui->swingComboBox->currentIndex()).toInt();
  }

  if (ui->airCleanComboBox->isEnabled())
  {
    state.airclean = ui->airCleanComboBox->itemData(
      ui->airCleanComboBox->currentIndex()).toInt();
  }

  mainWindow->startRepeating(state, ACSendCommand_Key);
}

void PIRStatefulACForm::on_sendButton_released()
{
  mainWindow->stopRepeating();
}
