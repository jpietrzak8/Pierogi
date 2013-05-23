//
// pirselectkeysetform.h
//
// Copyright 2012, 2013 by John Pietrzak  (jpietrzak8@gmail.com)
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

#ifndef PIRSELECTKEYSETFORM_H
#define PIRSELECTKEYSETFORM_H

#include <QWidget>
#include <QString>

#include "pirmakenames.h"

class QListWidget;
class QListWidgetItem;
class QKeyEvent;
class QComboBox;
class PIRKeysetWidgetItem;
class PIREditKeysetDialog;
class MainWindow;

namespace Ui {
class PIRSelectKeysetForm;
}

class PIRSelectKeysetForm : public QWidget
{
  Q_OBJECT
  
public:
//  explicit PIRSelectKeysetForm(QWidget *parent = 0);

  PIRSelectKeysetForm(
    MainWindow *mw);

  ~PIRSelectKeysetForm();

/*
  void addNameToList(
    QString name,
    unsigned int index,
    PIRMakeName make);
*/

  void addWidgetItem(
    PIRKeysetWidgetItem *kwi);

  // This is a bit of a hack, but not sure how to create a connection otherwise.
  QListWidget *getKeysetListWidget();

  bool selectNextKeyset();
  bool selectPrevKeyset();
  bool selectFirstKeyset();

  QString getCurrentKeysetName();

  QString getKeysetName(
    unsigned int id);

  void openCurrentKeysetDialog();

  void selectKeyset(
    unsigned int targetID);

  void populateKeysetComboBox(
    QComboBox *comboBox);

protected:
  void keyPressEvent(
    QKeyEvent *event);

private slots:
  void filterListByMake(
    int make);

  void filterListByString(
    QString string);

  void openKeysetDialog(
    QListWidgetItem *);
  
  void on_searchStringLineEdit_textChanged(const QString &arg1);
  void on_ssClosePushButton_clicked();
  void on_showFavoritesCheckBox_toggled(bool checked);

private:
  void refilterList();

  Ui::PIRSelectKeysetForm *ui;

  MainWindow *mainWindow;
  PIREditKeysetDialog *editDialog;

  bool showOnlyFavorites;
  PIRMakeName currentMake;
  QString searchString;
};

#endif // PIRSELECTKEYSETFORM_H
