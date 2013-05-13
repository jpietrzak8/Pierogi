#include "pirfavoritesdialog.h"
#include "ui_pirfavoritesdialog.h"

//#include <QListWidget>

#include "mainwindow.h"
#include "pirkeysetwidgetitem.h"
#include <QMaemo5InformationBox>
#include <QSettings>

#include "pirmakenames.h"
extern PIRMakeMgr makeManager;

#include <iostream>

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
  // Destroy and recreate the favorites list here:
  QSettings settings("pietrzak.org", "Pierogi");
  settings.remove("favorites");

  int count = ui->favoritesListWidget->count();

  // If the count is empty, we can stop right here:
  if (count == 0) return;

  int index = 0;
  PIRKeysetWidgetItem *kwi = NULL;
  settings.beginWriteArray("favorites");
  while (index < count)
  {
    kwi = dynamic_cast<PIRKeysetWidgetItem *>(
      ui->favoritesListWidget->item(index));

    // Not sure what to do if the pointer is bad here...
    if (!kwi)
    {
      continue;
    }

    settings.setArrayIndex(index);

    settings.setValue("keysetMake", 
      makeManager.getMakeString(kwi->getMake()));
    settings.setValue("keysetName", kwi->getInternalName());
    settings.setValue("tabBarName", kwi->getTabBarName());
    settings.setValue("panelIndex", kwi->getPanelIndex());

    ++index;
  }
  settings.endArray();

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

  PIRKeysetWidgetItem *kwi = dynamic_cast<PIRKeysetWidgetItem *> (
    ui->favoritesListWidget->currentItem());

  mainWindow->updateFavoriteKeysetSelection(
    kwi->getID(),
    position,
//    kwi->getMake(),
    kwi->getTabBarName(),
    kwi->getPanelIndex());

  // Tell the user about the change:
  QMaemo5InformationBox::information(0, kwi->text());
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

  PIRKeysetWidgetItem *kwi = dynamic_cast<PIRKeysetWidgetItem *> (
      ui->favoritesListWidget->currentItem());

  mainWindow->updateFavoriteKeysetSelection(
    kwi->getID(),
    position,
//    kwi->getMake(),
    kwi->getTabBarName(),
    kwi->getPanelIndex());

  // Tell the user about the change:
  QMaemo5InformationBox::information(0, kwi->text());
}


void PIRFavoritesDialog::addItem(
  PIRKeysetWidgetItem *item)
{
  PIRKeysetWidgetItem *itemCopy = new PIRKeysetWidgetItem(item);
  ui->favoritesListWidget->addItem(itemCopy);
  ui->favoritesListWidget->sortItems();
}


/*
int PIRFavoritesDialog::getCount()
{
  return ui->favoritesListWidget->count();
}
*/


/*
PIRKeysetWidgetItem *PIRFavoritesDialog::getItem(
  int index)
{
  return dynamic_cast<PIRKeysetWidgetItem *>(
    ui->favoritesListWidget->item(index));
}
*/


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


void PIRFavoritesDialog::on_favoritesListWidget_itemClicked(
  QListWidgetItem *item)
{
  if (item)
  {
    PIRKeysetWidgetItem *kwi = dynamic_cast<PIRKeysetWidgetItem *> (item);

    mainWindow->updateFavoriteKeysetSelection(
      kwi->getID(),
      ui->favoritesListWidget->currentRow(),
//      kwi->getMake(),
      kwi->getTabBarName(),
      kwi->getPanelIndex());
  }

  // Exit from the dialog:
  accept();
}


int PIRFavoritesDialog::selectFavorite(
  PIRKeysetWidgetItem *targetItem)
{
  // Try to find the corresponding widget in our list:
  PIRKeysetWidgetItem *kwi;
  unsigned int targetID = targetItem->getID();
  int index = 0;
  int count = ui->favoritesListWidget->count();
  while (index < count)
  {
    kwi = dynamic_cast<PIRKeysetWidgetItem *> (
      ui->favoritesListWidget->item(index));

    if (kwi->getID() == targetID)
    {
      ui->favoritesListWidget->setCurrentItem(kwi);
      mainWindow->setupFavoriteTabs(
        kwi->getTabBarName(), kwi->getPanelIndex());
      // Return this index:
      return index;
    }
  
    ++index;
  }

  // Favorite not found, return flag value:
  return -1;
}


void PIRFavoritesDialog::updateTabBarName(
  int favoritesIndex,
  PIRTabBarName name)
{
  // Sanity check first:
  if ( (favoritesIndex < 0)
    || (favoritesIndex >= ui->favoritesListWidget->count()))
  {
    // Perform error handling here?
    return;
  }

  PIRKeysetWidgetItem *kwi = dynamic_cast<PIRKeysetWidgetItem *> (
    ui->favoritesListWidget->item(favoritesIndex));

  kwi->setTabBarName(name);
}


void PIRFavoritesDialog::updatePanelIndex(
  int favoritesIndex,
  int panelIndex)
{

  // Sanity check:
  if ( (favoritesIndex < 0)
    || (favoritesIndex >= ui->favoritesListWidget->count()))
  {
    return;
  }


  PIRKeysetWidgetItem *kwi = dynamic_cast<PIRKeysetWidgetItem *> (
    ui->favoritesListWidget->item(favoritesIndex));

  kwi->setPanelIndex(panelIndex);
}
