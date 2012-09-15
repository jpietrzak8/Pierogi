#include "pirmacroform.h"
#include "ui_pirmacroform.h"

#include "mainwindow.h"
#include "macros/pirmacro.h"
#include "macros/pirmacropack.h"
#include "macros/pirmacrocommanditem.h"

#include <iostream>

class QTreeWidgetItem;

/*
PIRMacroForm::PIRMacroForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRMacroForm)
{
  ui->setupUi(this);
}
*/

PIRMacroForm::PIRMacroForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRMacroForm),
    currentMacro(0),
    userRequestMacro(0),
    request(No_Request),
    mainWindow(mw)
{
  ui->setupUi(this);

  PIRMacroPack *userPack = mainWindow->getUserPack();
  if (userPack)
  {
    if (userPack->childCount())
    {
      currentMacro = dynamic_cast<PIRMacro *> (userPack->child(0));
      if (currentMacro)
      {
        ui->macroNameLabel->setText(currentMacro->getName());
        currentMacro->populateList(ui->macroListWidget);
        ui->addButton->setEnabled(true);
      }
    }
  }

  connect(
    &smd,
    SIGNAL(macroChosen(QTreeWidgetItem *)),
    this,
    SLOT(displayMacro(QTreeWidgetItem *)));

  connect(
    &smd,
    SIGNAL(newMacroRequested()),
    this,
    SLOT(createNewMacro()));

  connect(
    &smd,
    SIGNAL(editMacroRequested(QTreeWidgetItem *)),
    this,
    SLOT(editMacro(QTreeWidgetItem *)));

  connect(
    &smd,
    SIGNAL(deleteMacroRequested(QTreeWidgetItem *)),
    this,
    SLOT(deleteMacro(QTreeWidgetItem *)));

  // Set up the select macro dialog:
  smd.addPack(mw->getUserPack());
  smd.addPack(mw->getMultitapPack());

  // Connect to edit command dialog signals:
  connect(
    &ecd,
    SIGNAL(deleteCommand()),
    this,
    SLOT(deleteCurrentCommand()));

  connect(
    &ecd,
    SIGNAL(moveCommandUp()),
    this,
    SLOT(moveCurrentCommandUp()));

  connect(
    &ecd,
    SIGNAL(moveCommandDown()),
    this,
    SLOT(moveCurrentCommandDown()));
}


PIRMacroForm::~PIRMacroForm()
{
  delete ui;
}


void PIRMacroForm::on_chooseMacroButton_clicked()
{
  request = No_Request;
  smd.exec();

  // Loop until the user either selects a macro to display,
  // or makes no request:
  while (request != No_Request)
  {
    switch (request)
    {
    case DisplayMacro_Request:
      currentMacro = userRequestMacro;
      userRequestMacro = 0;

      ui->macroNameLabel->setText(currentMacro->getName());

      // Turn on the "new" button
      ui->addButton->setEnabled(true);

      currentMacro->populateList(ui->macroListWidget);

      return;

    case NewMacro_Request:
      emd.clear();
      if (emd.exec() == QDialog::Accepted)
      {
        // Create the new macro:
        currentMacro = new PIRMacro(
          mainWindow->getUserPack(),
          emd.getText(),
          emd.getKey(),
          emd.getButtonID(),
          mainWindow);

        ui->macroNameLabel->setText(emd.getText());

        // Turn on the "new" button
        ui->addButton->setEnabled(true);

        mainWindow->updateUserButtons();

        ui->macroListWidget->clear();

        mainWindow->storeMacros();

        return;
      }
      break;

    case EditMacro_Request:
      emd.setup(userRequestMacro);
      if (emd.exec() == QDialog::Accepted)
      {
        // Store the changes:
        userRequestMacro->setName(emd.getText());
        userRequestMacro->setKey(emd.getKey());
        userRequestMacro->setButtonID(emd.getButtonID());

        mainWindow->updateUserButtons();

        mainWindow->storeMacros();
      }
      userRequestMacro = 0;
      break;

    case DeleteMacro_Request:
      dmd.setup(userRequestMacro);
      if (dmd.exec() == QDialog::Accepted)
      {
        if (currentMacro == userRequestMacro)
        {
          currentMacro = 0;
          ui->macroNameLabel->setText("No Macro Selected");
          ui->addButton->setEnabled(false);
          ui->macroListWidget->clear();
        }

        // Delete the macro:
        delete userRequestMacro;

        // Make sure no dangling buttons exist:
        mainWindow->updateUserButtons();

        mainWindow->storeMacros();

        smd.resetIndices();
      }
      userRequestMacro = 0;
      break;

    default:
      break;
    }

    // Return to the selector dialog:
    request = No_Request;
    smd.exec();
  }
}


void PIRMacroForm::on_runButton_clicked()
{
  if (currentMacro) currentMacro->executeMacro();
}


void PIRMacroForm::displayMacro(
  QTreeWidgetItem *item)
{
  if (!item) return;

  PIRMacro *m = dynamic_cast<PIRMacro *> (item);

  if (!m) return;

  userRequestMacro = m;
  request = DisplayMacro_Request;
}


QComboBox *PIRMacroForm::getKeysetComboBox()
{
  return ccd.getKeysetComboBox();
}


void PIRMacroForm::createNewMacro()
{
  request = NewMacro_Request;
}


void PIRMacroForm::editMacro(
  QTreeWidgetItem *item)
{
  if (!item) return;
  userRequestMacro = dynamic_cast<PIRMacro *> (item);
  request = EditMacro_Request;
}


void PIRMacroForm::deleteMacro(
  QTreeWidgetItem *item)
{
  if (!item) return;
  userRequestMacro = dynamic_cast<PIRMacro *> (item);
  request = DeleteMacro_Request;
}


void PIRMacroForm::on_addButton_clicked()
{
  // Sanity check:
  if (!currentMacro) return;

  // Initialize the choose command dialog:
  ccd.init();

  // Check whether the user has actually created a command:
  if (ccd.exec() != QDialog::Accepted) return;

  int index = ui->macroListWidget->currentRow();

  switch (ccd.getCommandType())
  {
  case Keyset_Command:
    currentMacro->appendCommand(
      new PIRKeysetCommandItem(
        ccd.getKeysetID(),
        mainWindow));

    currentMacro->populateList(ui->macroListWidget);
    ui->macroListWidget->setCurrentRow(index);

    mainWindow->storeMacros();

    break;

  case Key_Command:
    currentMacro->appendCommand(
      new PIRKeyCommandItem(
        ccd.getKeyName(),
        mainWindow));

    currentMacro->populateList(ui->macroListWidget);
    ui->macroListWidget->setCurrentRow(index);

    mainWindow->storeMacros();

    break;

  case Pause_Command:
    currentMacro->appendCommand(
      new PIRPauseCommandItem(
        ccd.getTimeToWait()));

    currentMacro->populateList(ui->macroListWidget);
    ui->macroListWidget->setCurrentRow(index);

    mainWindow->storeMacros();

    break;

  case No_Command:
  default:
    break;
  }
}


void PIRMacroForm::deleteCurrentCommand()
{
  int index = ui->macroListWidget->currentRow();
  if (currentMacro->deleteCommand(index))
  {
    currentMacro->populateList(ui->macroListWidget);

    if (index == ui->macroListWidget->count()) --index;

    if (index)
    {
      ui->macroListWidget->setCurrentRow(index);
    }

    mainWindow->storeMacros();
  }
}


void PIRMacroForm::moveCurrentCommandUp()
{
  int index = ui->macroListWidget->currentRow();
  if (currentMacro->moveUp(index))
  {
    currentMacro->populateList(ui->macroListWidget);
    ui->macroListWidget->setCurrentRow(index - 1);

    mainWindow->storeMacros();
  }
}


void PIRMacroForm::moveCurrentCommandDown()
{
  int index = ui->macroListWidget->currentRow();

  if (currentMacro->moveDown(index))
  {
    currentMacro->populateList(ui->macroListWidget);
    ui->macroListWidget->setCurrentRow(index + 1);

    mainWindow->storeMacros();
  }
}


//void PIRMacroForm::on_macroListWidget_itemClicked(QListWidgetItem *item)
void PIRMacroForm::on_macroListWidget_itemClicked()
{
  ecd.setup(
    currentMacro->getCommandType(ui->macroListWidget->currentRow()),
    currentMacro->getCommandName(ui->macroListWidget->currentRow()));

  ecd.exec();
}


/*
void PIRMacroForm::on_newMacroButton_clicked()
{
  emd.clear();

  // If no new macro, just give up:
  if (emd.exec() != QDialog::Accepted) return;

  // Create the new macro:
  currentMacro = new PIRMacro(
    mainWindow->getUserPack(),
    emd.getText(),
    emd.getKey(),
    emd.getButtonID());

  ui->macroNameLabel->setText(emd.getText());

  // Turn on the "new" button
  ui->addButton->setEnabled(true);

  if (emd.getButtonID())
  {
    mainWindow->updateUserButtons();
  }

  ui->macroListWidget->clear();

  mainWindow->storeMacros();
}
*/

