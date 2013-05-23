//
// piraltmainform.h
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

#ifndef PIRALTMAINFORM_H
#define PIRALTMAINFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRAltMainForm;
}

class PIRAltMainForm : public QWidget
{
  Q_OBJECT
  
public:
//  explicit PIRAltMainForm(QWidget *parent = 0);
  PIRAltMainForm(
    MainWindow *mw);

  ~PIRAltMainForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int currentID,
    unsigned int defaultID);

signals:
  void powerEnabled(bool);
  void volumeUpEnabled(bool);
  void volumeDownEnabled(bool);
  void channelUpEnabled(bool);
  void channelDownEnabled(bool);
  void muteEnabled(bool);

  void keysetMakeChanged(QString);
  void keysetNameChanged(QString);
  
private slots:
  void on_volumeUpButton_pressed();
  void on_volumeUpButton_released();
  void on_volumeDownButton_pressed();
  void on_volumeDownButton_released();
  void on_muteButton_pressed();
  void on_muteButton_released();
  void on_powerButton_pressed();
  void on_powerButton_released();
  void on_channelUpButton_pressed();
  void on_channelUpButton_released();
  void on_channelDownButton_pressed();
  void on_channelDownButton_released();

private:
  Ui::PIRAltMainForm *ui;

  MainWindow *mainWindow;
  unsigned int defaultID;
};

#endif // PIRALTMAINFORM_H
