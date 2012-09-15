#include "pircreatecommanddialog.h"
#include "ui_pircreatecommanddialog.h"

#include "mainwindow.h"

extern PIRKeynameMgr keynameMgr;

/*
PIRCreateCommandDialog::PIRCreateCommandDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::PIRCreateCommandDialog)
{
  ui->setupUi(this);
}
*/


PIRCreateCommandDialog::PIRCreateCommandDialog()
  : QDialog(0),
    ui(new Ui::PIRCreateCommandDialog)
{
  ui->setupUi(this);

  setupPowerKeys(ui->powerKeysComboBox);
  setupNumericKeys(ui->numericKeysComboBox);
  setupChannelKeys(ui->channelKeysComboBox);
  setupVolumeKeys(ui->volumeKeysComboBox);
  setupMenuKeys(ui->menuKeysComboBox);
  setupMediaKeys(ui->mediaKeysComboBox);
  setupInputKeys(ui->inputKeysComboBox);
  keynameMgr.populateComboBox(ui->allKeysComboBox);
}


PIRCreateCommandDialog::~PIRCreateCommandDialog()
{
  delete ui;
}


QComboBox *PIRCreateCommandDialog::getKeysetComboBox()
{
  return ui->keysetComboBox;
}


CommandType PIRCreateCommandDialog::getCommandType()
{
  switch (ui->commandTypeComboBox->currentIndex())
  {
  case 0:
    return Keyset_Command;

  case 1:
    return Key_Command;

  case 2:
    return Pause_Command;

  default:
    return No_Command;
  }
}


QString PIRCreateCommandDialog::getKeysetName()
{
  return ui->keysetComboBox->itemText(
    ui->keysetComboBox->currentIndex());
}


unsigned int PIRCreateCommandDialog::getKeysetID()
{
  return ui->keysetComboBox->itemData(
    ui->keysetComboBox->currentIndex()).toInt();
}


PIRKeyName PIRCreateCommandDialog::getKeyName()
{
  switch (ui->keyCategoryComboBox->currentIndex())
  {
  case 0:
    return (PIRKeyName) ui->powerKeysComboBox->itemData(
      ui->powerKeysComboBox->currentIndex()).toInt();

  case 1:
    return (PIRKeyName) ui->numericKeysComboBox->itemData(
      ui->numericKeysComboBox->currentIndex()).toInt();

  case 2:
    return (PIRKeyName) ui->channelKeysComboBox->itemData(
      ui->channelKeysComboBox->currentIndex()).toInt();

  case 3:
    return (PIRKeyName) ui->volumeKeysComboBox->itemData(
      ui->volumeKeysComboBox->currentIndex()).toInt();

  case 4:
    return (PIRKeyName) ui->menuKeysComboBox->itemData(
      ui->menuKeysComboBox->currentIndex()).toInt();

  case 5:
    return (PIRKeyName) ui->mediaKeysComboBox->itemData(
      ui->mediaKeysComboBox->currentIndex()).toInt();

  case 6:
    return (PIRKeyName) ui->inputKeysComboBox->itemData(
      ui->inputKeysComboBox->currentIndex()).toInt();

  case 7:
    return (PIRKeyName) ui->allKeysComboBox->itemData(
      ui->allKeysComboBox->currentIndex()).toInt();

  default:
    return Unmapped_Key;
  }
}


unsigned int PIRCreateCommandDialog::getTimeToWait()
{
  return ui->pauseTimeSpinBox->value();
}


void PIRCreateCommandDialog::setupPowerKeys(
  QComboBox *cb)
{
  setupKey(cb, Power_Key);
  setupKey(cb, PowerOn_Key);
  setupKey(cb, PowerOff_Key);
}


void PIRCreateCommandDialog::setupNumericKeys(
  QComboBox *cb)
{
  setupKey(cb, Zero_Key);
  setupKey(cb, One_Key);
  setupKey(cb, Two_Key);
  setupKey(cb, Three_Key);
  setupKey(cb, Four_Key);
  setupKey(cb, Five_Key);
  setupKey(cb, Six_Key);
  setupKey(cb, Seven_Key);
  setupKey(cb, Eight_Key);
  setupKey(cb, Nine_Key);
  setupKey(cb, Enter_Key);
  setupKey(cb, Clear_Key);
  setupKey(cb, PlusOneHundred_Key);
  setupKey(cb, Dash_Key);
  setupKey(cb, DoubleDigit_Key);
}


void PIRCreateCommandDialog::setupChannelKeys(
  QComboBox *cb)
{
  setupKey(cb, ChannelUp_Key);
  setupKey(cb, ChannelDown_Key);
  setupKey(cb, PrevChannel_Key);
}


void PIRCreateCommandDialog::setupVolumeKeys(
  QComboBox *cb)
{
  setupKey(cb, VolumeUp_Key);
  setupKey(cb, VolumeDown_Key);
  setupKey(cb, Mute_Key);
  setupKey(cb, Surround_Key);
  setupKey(cb, RearVolumeUp_Key);
  setupKey(cb, RearVolumeDown_Key);
  setupKey(cb, CenterVolumeUp_Key);
  setupKey(cb, CenterVolumeDown_Key);
  setupKey(cb, WooferUp_Key);
  setupKey(cb, WooferDown_Key);
}


void PIRCreateCommandDialog::setupMenuKeys(
  QComboBox *cb)
{
  setupKey(cb, Menu_Key);
  setupKey(cb, Up_Key);
  setupKey(cb, Down_Key);
  setupKey(cb, Left_Key);
  setupKey(cb, Right_Key);
  setupKey(cb, Select_Key);
  setupKey(cb, Exit_Key);
  setupKey(cb, Guide_Key);
}


void PIRCreateCommandDialog::setupMediaKeys(
  QComboBox *cb)
{
  setupKey(cb, Play_Key);
  setupKey(cb, Pause_Key);
  setupKey(cb, Stop_Key);
  setupKey(cb, FastForward_Key);
  setupKey(cb, Rewind_Key);
  setupKey(cb, PlayX2_Key);
  setupKey(cb, Next_Key);
  setupKey(cb, Previous_Key);
  setupKey(cb, StepForward_Key);
  setupKey(cb, StepBack_Key);
  setupKey(cb, Advance_Key);
  setupKey(cb, Replay_Key);
  setupKey(cb, Eject_Key);
  setupKey(cb, Random_Key);
  setupKey(cb, Repeat_Key);
  setupKey(cb, RepeatAB_Key);
  setupKey(cb, Slow_Key);
  setupKey(cb, SlowPlus_Key);
  setupKey(cb, SlowMinus_Key);
}


void PIRCreateCommandDialog::setupInputKeys(
  QComboBox *cb)
{
  setupKey(cb, Input_Key);
  setupKey(cb, CDInput_Key);
  setupKey(cb, PhonoInput_Key);
  setupKey(cb, TunerInput_Key);
  setupKey(cb, LineInput_Key);
  setupKey(cb, TapeInput_Key);
  setupKey(cb, AntennaInput_Key);
  setupKey(cb, Antenna2Input_Key);
  setupKey(cb, PCInput_Key);
  setupKey(cb, CompositeInput_Key);
  setupKey(cb, Composite2Input_Key);
  setupKey(cb, SVideoInput_Key);
  setupKey(cb, SVideo2Input_Key);
  setupKey(cb, ComponentInput_Key);
  setupKey(cb, Component2Input_Key);
  setupKey(cb, HDMIInput_Key);
  setupKey(cb, HDMI2Input_Key);
  setupKey(cb, HDMI3Input_Key);
  setupKey(cb, ScartInput_Key);
  setupKey(cb, AuxInput_Key);
  setupKey(cb, MDInput_Key);
  setupKey(cb, LDInput_Key);
  setupKey(cb, DVDInput_Key);
  setupKey(cb, VCRInput_Key);
  setupKey(cb, HDDInput_Key);
  setupKey(cb, CableInput_Key);
  setupKey(cb, SatInput_Key);
  setupKey(cb, DVRInput_Key);
  setupKey(cb, OpticalInput_Key);
  setupKey(cb, DigitalCoaxInput_Key);
  setupKey(cb, USBInput_Key);
}


void PIRCreateCommandDialog::setupKey(
  QComboBox *cb,
  PIRKeyName keyName)
{
  cb->addItem(
    keynameMgr.getKeynameString(keyName),
    QVariant(keyName));
}


void PIRCreateCommandDialog::init()
{
  ui->commandTypeComboBox->setCurrentIndex(0);
  ui->commandEditorStackedWidget->setCurrentIndex(0);
}
