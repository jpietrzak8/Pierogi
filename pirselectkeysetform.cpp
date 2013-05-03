#include "pirselectkeysetform.h"
#include "ui_pirselectkeysetform.h"

//#include <QListWidget>
//#include <QListWidgetItem>
#include <QKeyEvent>
#include <QComboBox>

#include "mainwindow.h"
#include "pirkeysetwidgetitem.h"
#include "dialogs/pireditkeysetdialog.h"

// Debugging include:
//#include <iostream>

extern PIRMakeMgr makeManager;

PIRSelectKeysetForm::PIRSelectKeysetForm(
  MainWindow *mw)
  : QWidget(mw), // is this right?
    ui(new Ui::PIRSelectKeysetForm),
    mainWindow(mw),
    editDialog(0),
    showOnlyFavorites(false),
    currentMake(Any_Make)
{
  ui->setupUi(this);

  // Make sure the user can only select one keyset at a time:
  ui->keysetListWidget->setSelectionMode(
    QAbstractItemView::SingleSelection);

  // Don't want to start with the line editor visible:
  ui->searchStringLineEdit->hide();
  ui->searchStringLineEdit->lower();
  ui->ssClosePushButton->hide();

  // Set some initial flags:
  setAttribute(Qt::WA_Maemo5StackedWindow);
  setWindowFlags(windowFlags() | Qt::Window);

  // push the list of makers into the make combo box:
  makeManager.populateComboBox(ui->makeComboBox);

  // Connection telling main window that keyset has been selected:
  connect(
    ui->keysetListWidget,
    SIGNAL(itemActivated(QListWidgetItem *)),
    mainWindow,
    SLOT(keysetSelectionChanged(QListWidgetItem *)),
    Qt::QueuedConnection);

  // Connection used to filter keyset list:
  connect(
    ui->makeComboBox,
    SIGNAL(currentIndexChanged(int)),
    this,
    SLOT(filterListByMake(int)),
    Qt::QueuedConnection);

  // Open editor dialog for indivual keysets:
  connect(
    ui->keysetListWidget,
    SIGNAL(itemClicked(QListWidgetItem *)),
    this,
    SLOT(openKeysetDialog(QListWidgetItem *)),
    Qt::QueuedConnection);

  // Go ahead and construct the dialog window right now:
  editDialog = new PIREditKeysetDialog(mainWindow);
}


PIRSelectKeysetForm::~PIRSelectKeysetForm()
{
  if (editDialog) delete editDialog;

  delete ui;
}


/*
void PIRSelectKeysetForm::addNameToList(
  QString name,
  unsigned int index,
  PIRMakeName make)
{
  ui->keysetListWidget->addItem(new PIRKeysetWidgetItem(name, index, make));
}
*/


void PIRSelectKeysetForm::addWidgetItem(
  PIRKeysetWidgetItem *kwi)
{
  ui->keysetListWidget->addItem(kwi);
}


QListWidget *PIRSelectKeysetForm::getKeysetListWidget()
{
  return ui->keysetListWidget;
}


bool PIRSelectKeysetForm::selectNextKeyset()
{
  int currentRow = ui->keysetListWidget->currentRow();

  // If we're at the end of the list, give up:
  if (currentRow >= (ui->keysetListWidget->count() -1))
  {
    return false;
  }

  ui->keysetListWidget->setCurrentRow(
    currentRow + 1,
    QItemSelectionModel::ClearAndSelect);

  mainWindow->keysetSelectionChanged(
    ui->keysetListWidget->currentItem());

  return true;
}


bool PIRSelectKeysetForm::selectPrevKeyset()
{
  int currentRow = ui->keysetListWidget->currentRow();

  // If we're at the beginning of the list, give up:
  if (currentRow <= 0)
  {
    return false;
  }

  ui->keysetListWidget->setCurrentRow(
    currentRow - 1,
    QItemSelectionModel::ClearAndSelect);

  mainWindow->keysetSelectionChanged(
    ui->keysetListWidget->currentItem());

  return true;
}


bool PIRSelectKeysetForm::selectFirstKeyset()
{
  if (ui->keysetListWidget->count() == 0)
  {
    return false;
  }

  if (ui->keysetListWidget->currentRow() != 0)
  {
    ui->keysetListWidget->setCurrentRow(
      0, QItemSelectionModel::ClearAndSelect);

    mainWindow->keysetSelectionChanged(
      ui->keysetListWidget->currentItem());
  }

  return true;
}


QString PIRSelectKeysetForm::getCurrentKeysetName()
{
  QListWidgetItem *item = ui->keysetListWidget->currentItem();

  if (item)
  {
    return item->text();
  }
  else
  {
    return "";
  }
}


QString PIRSelectKeysetForm::getKeysetName(
  unsigned int id)
{
  int count = ui->keysetListWidget->count();

  if (count == 0) return "";

  QListWidgetItem *localItem;
  PIRKeysetWidgetItem *kwi;
  int row = 0;

  while (row < count)
  {
    localItem = ui->keysetListWidget->item(row);

    if (localItem)
    {
      kwi = dynamic_cast<PIRKeysetWidgetItem *> (localItem);

      if (kwi->getID() == id)
      {
        return kwi->text();
      }
    }

    ++row;
  }

  return "";
}


void PIRSelectKeysetForm::keyPressEvent(
  QKeyEvent *event)
{
  ui->searchStringLineEdit->show();
  ui->searchStringLineEdit->raise();
  ui->ssClosePushButton->show();

  ui->searchStringLineEdit->setText(event->text());
  ui->searchStringLineEdit->setFocus();
}


void PIRSelectKeysetForm::on_searchStringLineEdit_textChanged(
  const QString &arg1)
{
  filterListByString(arg1);
}


void PIRSelectKeysetForm::on_ssClosePushButton_clicked()
{
  ui->searchStringLineEdit->hide();
  ui->searchStringLineEdit->lower();
  ui->ssClosePushButton->hide();
  ui->searchStringLineEdit->clear();
}


void PIRSelectKeysetForm::filterListByMake(
  int make)
{
  currentMake = (PIRMakeName) make;
  refilterList();
}


void PIRSelectKeysetForm::filterListByString(
  QString string)
{
  searchString = string;
  refilterList();
}


void PIRSelectKeysetForm::refilterList()
{
  int index = 0;
  int count = ui->keysetListWidget->count();
  PIRKeysetWidgetItem *item;
  while (index < count)
  {
    item = dynamic_cast<PIRKeysetWidgetItem *>(
      ui->keysetListWidget->item(index));

    // Does the keylist have the required make?
    if ((currentMake == Any_Make) || (item->getMake() == currentMake))
    {
      // If required, is the keyset a favorite?
      if (!showOnlyFavorites || (item->isFavorite()))
      {
        // Does this keylist match the search string?
        if ( searchString.isEmpty()
          || item->text().contains(searchString, Qt::CaseInsensitive))
        {
          // Yes, we can show this keylist:
          item->setHidden(false);
        }
        else
        {
          item->setHidden(true);
        }
      }
      else
      {
        item->setHidden(true);
      }
    }
    else
    {
      item->setHidden(true);
    }

    ++index;
  }
}


void PIRSelectKeysetForm::openKeysetDialog(
  QListWidgetItem *item)
{
  PIRKeysetWidgetItem *kwi = dynamic_cast<PIRKeysetWidgetItem *>(item);

  editDialog->setupDialog(kwi);

  editDialog->exec();
}


void PIRSelectKeysetForm::openCurrentKeysetDialog()
{
  PIRKeysetWidgetItem *kwi = dynamic_cast<PIRKeysetWidgetItem *> (
    ui->keysetListWidget->currentItem());

  editDialog->setupDialog(kwi);

  editDialog->exec();
}


void PIRSelectKeysetForm::on_showFavoritesCheckBox_toggled(bool checked)
{
  showOnlyFavorites = checked;
  refilterList();
}


void PIRSelectKeysetForm::selectKeyset(
  unsigned int targetID)
{
  int count = ui->keysetListWidget->count();

  if (count == 0) return;

  QListWidgetItem *localItem;
  PIRKeysetWidgetItem *kwi;
  int row = 0;

  while (row < count)
  {
    localItem = ui->keysetListWidget->item(row);

    if (localItem)
    {
      kwi = dynamic_cast<PIRKeysetWidgetItem *> (localItem);

      if (kwi->getID() == targetID)
      {
        ui->keysetListWidget->setCurrentRow(
          row, QItemSelectionModel::ClearAndSelect);

        mainWindow->keysetSelectionChanged(
          ui->keysetListWidget->currentItem());

        return;
      }
    }

    ++row;
  }
}


void PIRSelectKeysetForm::populateKeysetComboBox(
  QComboBox *comboBox)
{
  int count = ui->keysetListWidget->count();

  if (count == 0) return;

  QListWidgetItem *localItem;
  PIRKeysetWidgetItem *kwi;
  int row = 0;

  while (row < count)
  {
    localItem = ui->keysetListWidget->item(row);

    if (localItem)
    {
      kwi = dynamic_cast<PIRKeysetWidgetItem *> (localItem);

      comboBox->addItem(
        kwi->text(),
        QVariant(kwi->getID()));
    }

    ++row;
  }
}
