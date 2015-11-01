//
// pirstatefulacform.h
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

#ifndef PIRSTATEFULACFORM_H
#define PIRSTATEFULACFORM_H

#include <QWidget>

#include "piracstateinfo.h"

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRStatefulACForm;
}

class PIRStatefulACForm : public QWidget
{
  Q_OBJECT
  
public:
//  explicit PIRStatefulACForm(QWidget *parent = 0);
  PIRStatefulACForm(
    MainWindow *mw);

  ~PIRStatefulACForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void sendCommandEnabled(bool);
  void powerComboBoxEnabled(bool);
  void tempComboBoxEnabled(bool);
  void fanComboBoxEnabled(bool);
  void modeComboBoxEnabled(bool);
  void swingComboBoxEnabled(bool);
  void turboComboBoxEnabled(bool);
  void airCleanComboBoxEnabled(bool);
  
private slots:
  void on_sendButton_pressed();
  void on_sendButton_released();

private:
  Ui::PIRStatefulACForm *ui;

  PIRACSettings settings;

  MainWindow *mainWindow;
};

#endif // PIRSTATEFULACFORM_H
