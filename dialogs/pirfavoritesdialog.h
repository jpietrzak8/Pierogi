//
// pirfavoritesdialog.h
//
// Copyright 2012, 2013 by John Pietrzak (jpietrzak8@gmail.com)
//
// This file is part of Pierogi.
//
// Pierogi is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// Pierogi is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#ifndef PIRFAVORITESDIALOG_H
#define PIRFAVORITESDIALOG_H

#include <QDialog>

#include "pirpanelnames.h"

class QListWidget;
class PIRKeysetWidgetItem;
class QListWidgetItem;
class MainWindow;

namespace Ui {
class PIRFavoritesDialog;
}

class PIRFavoritesDialog : public QDialog
{
  Q_OBJECT
  
public:
//  explicit PIRFavoritesDialog(QWidget *parent = 0);

  PIRFavoritesDialog(
    MainWindow *mw);

  ~PIRFavoritesDialog();

  QListWidget *getFavoritesListWidget();

  void addItem(
    PIRKeysetWidgetItem *item);

//  int getCount();

//  PIRKeysetWidgetItem *getItem(
//    int index);

  void removeItem(
    unsigned int keysetID);

  void selectPrevFavKeyset();
  void selectNextFavKeyset();

  int selectFavorite(
    PIRKeysetWidgetItem *targetItem);

  void updateTabBarName(
    int favoritesIndex,
    PIRTabBarName name);

  void updatePanelIndex(
    int favoritesIndex,
    int panelIndex);

private slots:
  void on_favoritesListWidget_itemClicked(
    QListWidgetItem *item);
  
private:
  Ui::PIRFavoritesDialog *ui;

  MainWindow *mainWindow;
};

#endif // PIRFAVORITESDIALOG_H
