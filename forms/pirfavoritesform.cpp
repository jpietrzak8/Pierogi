#include "pirfavoritesform.h"
#include "ui_pirfavoritesform.h"

#include "mainwindow.h"
//#include "pirkeysetmanager.h"
#include "pirkeysetwidgetitem.h"

#include <QMaemo5InformationBox>

PIRFavoritesForm::PIRFavoritesForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRFavoritesForm),
    mainWindow(mw)
{
  ui->setupUi(this);
}

PIRFavoritesForm::~PIRFavoritesForm()
{
  delete ui;
}


void PIRFavoritesForm::selectPrevFavKeyset()
{
  int size = ui->favoriteKeysetsWidget->count();

  if (size == 0)
  {
    // No favorites, so nothing to do!
    return;
  }

  int position = ui->favoriteKeysetsWidget->currentRow();

  --position;
  if (position < 0)
  {
    position = size - 1;
  }

  ui->favoriteKeysetsWidget->setCurrentRow(
    position,
    QItemSelectionModel::ClearAndSelect);

  mainWindow->keysetSelectionChanged(
    ui->favoriteKeysetsWidget->currentItem());

  // Tell the user about the change:
  QMaemo5InformationBox::information(
    0,
    ui->favoriteKeysetsWidget->item(position)->text());
}


void PIRFavoritesForm::selectNextFavKeyset()
{
  int size = ui->favoriteKeysetsWidget->count();

  if (size == 0)
  {
    // No favorites, so just return:
    return;
  }

  int position = ui->favoriteKeysetsWidget->currentRow();

  ++position;
  if (position == size)
  {
    position = 0;
  }

  ui->favoriteKeysetsWidget->setCurrentRow(
    position,
    QItemSelectionModel::ClearAndSelect);

  mainWindow->keysetSelectionChanged(
    ui->favoriteKeysetsWidget->currentItem());

  // Tell the user about the change:
  QMaemo5InformationBox::information(
    0,
    ui->favoriteKeysetsWidget->item(position)->text());
}


void PIRFavoritesForm::addItem(
  PIRKeysetWidgetItem *item)
{
  ui->favoriteKeysetsWidget->addItem(item);
}


QListWidget *PIRFavoritesForm::getFavoritesListWidget()
{
  return ui->favoriteKeysetsWidget;
}


void PIRFavoritesForm::on_addKeysetButton_clicked()
{
  mainWindow->addCurrentKeyset(ui->favoriteKeysetsWidget);
}


void PIRFavoritesForm::on_removeKeysetButton_clicked()
{
  mainWindow->removeFavoriteKeyset(ui->favoriteKeysetsWidget);
}
