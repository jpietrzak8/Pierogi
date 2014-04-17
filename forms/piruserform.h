//
// piruserform.h
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

#ifndef PIRUSERFORM_H
#define PIRUSERFORM_H

#include <QWidget>

class MainWindow;

namespace Ui {
class PIRUserForm;
}

class PIRUserForm : public QWidget
{
  Q_OBJECT
  
public:
//  explicit PIRUserForm(QWidget *parent = 0);

  PIRUserForm(
    MainWindow *mw);

  ~PIRUserForm();

  void setupButtons();

signals:
  void runEnabled(bool);
  
private slots:
  void on_userDef1Button_clicked();
  void on_userDef2Button_clicked();
  void on_userDef3Button_clicked();
  void on_userDef4Button_clicked();
  void on_userDef5Button_clicked();
  void on_userDef6Button_clicked();
  void on_loadPackButton_clicked();
  void on_runButton_clicked();
//  void on_macroComboBox_currentIndexChanged(const QString &arg1);

private:
  Ui::PIRUserForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRUSERFORM_H
