//
// pirselectmacrodialog.h
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

#ifndef PIRSELECTMACRODIALOG_H
#define PIRSELECTMACRODIALOG_H

#include <QDialog>

class PIRMacroPack;
class PIRMacro;
class PIRReverseMultitap;
class QTreeWidgetItem;

namespace Ui {
class PIRSelectMacroDialog;
}

class PIRSelectMacroDialog : public QDialog
{
  Q_OBJECT
  
public:
//  explicit PIRSelectMacroDialog(QWidget *parent = 0);

  PIRSelectMacroDialog();

  ~PIRSelectMacroDialog();

  void addPack(
    PIRMacroPack *pack);

  void resetIndices();

signals:
  void macroChosen(
    QTreeWidgetItem *item);

  void newMacroRequested();

  void editMacroRequested(
    QTreeWidgetItem *item);

  void deleteMacroRequested(
    QTreeWidgetItem *item);
  
private slots:
  void on_buttonBox_accepted();
//  void on_buttonBox_rejected();
  void on_newButton_clicked();
  void on_editButton_clicked();
  void on_deleteButton_clicked();

private:
  Ui::PIRSelectMacroDialog *ui;
};

#endif // PIRSELECTMACRODIALOG_H
