//
// pireditkeysetdialog.h
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

#ifndef PIREDITKEYSETDIALOG_H
#define PIREDITKEYSETDIALOG_H

#include <QDialog>

class PIRKeysetWidgetItem;
class MainWindow;

namespace Ui {
class PIREditKeysetDialog;
}

class PIREditKeysetDialog : public QDialog
{
  Q_OBJECT
  
public:
//  explicit PIREditKeysetDialog(QWidget *parent = 0);

  PIREditKeysetDialog(
    MainWindow *mw);

  ~PIREditKeysetDialog();

  void setupDialog(
    PIRKeysetWidgetItem *kwi);
  
private slots:
  void enactChanges();

private:
  void updateQSettingsNickname();
  void removeQSettingsNickname();

  Ui::PIREditKeysetDialog *ui;

  MainWindow *mainWindow;
  PIRKeysetWidgetItem *keysetItem;
};

#endif // PIREDITKEYSETDIALOG_H
