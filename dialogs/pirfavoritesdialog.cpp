#include "pirfavoritesdialog.h"
#include "ui_pirfavoritesdialog.h"

//#include <QListWidget>

#include "mainwindow.h"
#include "pirkeysetwidgetitem.h"
#include <QMaemo5InformationBox>

/*
PIRFavoritesDialog::PIRFavoritesDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::PIRFavoritesDialog)
{
  ui->setupUi(this);
}
*/


PIRFavoritesDialog::PIRFavoritesDialog(
  MainWindow *mw)
  : QDialog(0),
    ui(new Ui::PIRFavoritesDialog),
    mainWindow(mw)
{
  ui->setupUi(this);
}


PIRFavoritesDialog::~PIRFavoritesDialog()
{
  delete ui;
}


void PIRFavoritesDialog::selectPrevFavKeyset()
{
  int size = ui->favoritesListWidget->count();

  if (size == 0)
  {
    // No favorites, so nothing to do!
    return;
  }

  int position = ui->favoritesListWidget->currentRow();

  --position;
  if (position < 0)
  {
    position = size - 1;
  }

  ui->favoritesListWidget->setCurrentRow(
    position,
    QItemSelectionModel::ClearAndSelect);

  mainWindow->keysetSelectionChanged(
    ui->favoritesListWidget->currentItem());

  // Tell the user about the change:
  QMaemo5InformationBox::information(
    0,
    ui->favoritesListWidget->item(position)->text());
}


void PIRFavoritesDialog::selectNextFavKeyset()
{
  int size = ui->favoritesListWidget->count();

  if (size == 0)
  {
    // No favorites, so just return:
    return;
  }

  int position = ui->favoritesListWidget->currentRow();

  ++position;
  if (position == size)
  {
    position = 0;
  }

  ui->favoritesListWidget->setCurrentRow(
    position,
    QItemSelectionModel::ClearAndSelect);

  mainWindow->keysetSelectionChanged(
    ui->favoritesListWidget->currentItem());

  // Tell the user about the change:
  QMaemo5InformationBox::information(
    0,
    ui->favoritesListWidget->item(position)->text());
}


void PIRFavoritesDialog::addItem(
  PIRKeysetWidgetItem *item)
{
  PIRKeysetWidgetItem *itemCopy = new PIRKeysetWidgetItem(item);
  ui->favoritesListWidget->addItem(itemCopy);
  ui->favoritesListWidget->sortItems();
}


int PIRFavoritesDialog::getCount()
{
  return ui->favoritesListWidget->count();
}


PIRKeysetWidgetItem *PIRFavoritesDialog::getItem(
  int index)
{
  return dynamic_cast<PIRKeysetWidgetItem *>(
    ui->favoritesListWidget->item(index));
}


void PIRFavoritesDialog::removeItem(
  unsigned int keysetID)
{
  // Find the keyset in the list (if it is there):
  int count = ui->favoritesListWidget->count();
  int index = 0;
  PIRKeysetWidgetItem *kwi;

  while (index < count)
  {
    kwi = dynamic_cast<PIRKeysetWidgetItem *>(
         ui->favoritesListWidget->item(index));

    if (kwi->getID() == keysetID)
    {
      // Deleting the item removes it from the list:
      delete kwi;
      return;
    }

    ++index;
  }
}


QListWidget *PIRFavoritesDialog::getFavoritesListWidget()
{
  return ui->favoritesListWidget;
}


void PIRFavoritesDialog::on_favoritesListWidget_itemClicked()
{
  // Exit from the dialog:
  accept();
}
