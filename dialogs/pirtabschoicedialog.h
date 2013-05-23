//
// pirtabschoicedialog.h
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

#ifndef PIRTABSCHOICEDIALOG_H
#define PIRTABSCHOICEDIALOG_H

#include <QDialog>

#include "pirpanelnames.h"

class QListWidgetItem;
class MainWindow;

namespace Ui {
class PIRTabsChoiceDialog;
}

class PIRTabsChoiceDialog : public QDialog
{
  Q_OBJECT
  
public:
//  explicit PIRTabsChoiceDialog(QWidget *parent = 0);
  PIRTabsChoiceDialog(MainWindow *mw);
  ~PIRTabsChoiceDialog();

  void switchToTabBar(
    PIRTabBarName name);
  
private slots:
  void on_tabsChoiceListWidget_itemClicked(QListWidgetItem *item);

private:
  Ui::PIRTabsChoiceDialog *ui;

  MainWindow *mainWindow;
};

#endif // PIRTABSCHOICEDIALOG_H
