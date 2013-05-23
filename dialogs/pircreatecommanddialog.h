//
// pircreatecommanddialog.h
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

#ifndef PIRCREATECOMMANDDIALOG_H
#define PIRCREATECOMMANDDIALOG_H

#include <QDialog>

#include "pirkeynames.h"

class QComboBox;

enum CommandType
{
  No_Command,
  Key_Command,
  Keyset_Command,
  Pause_Command
};

namespace Ui {
class PIRCreateCommandDialog;
}

class PIRCreateCommandDialog : public QDialog
{
  Q_OBJECT
  
public:
//  explicit PIRCreateCommandDialog(QWidget *parent = 0);

  PIRCreateCommandDialog();

  ~PIRCreateCommandDialog();

  QComboBox *getKeysetComboBox();

  CommandType getCommandType();

  QString getKeysetName();

  unsigned int getKeysetID();

  PIRKeyName getKeyName();

  unsigned int getTimeToWait();

  void init();
  
private:
  void setupPowerKeys(
    QComboBox *cb);

  void setupNumericKeys(
    QComboBox *cb);

  void setupChannelKeys(
    QComboBox *cb);

  void setupVolumeKeys(
    QComboBox *cb);

  void setupMenuKeys(
    QComboBox *cb);

  void setupMediaKeys(
    QComboBox *cb);

  void setupInputKeys(
    QComboBox *cb);

  void setupKey(
    QComboBox *cb,
    PIRKeyName keyName);

  Ui::PIRCreateCommandDialog *ui;
};

#endif // PIRCREATECOMMANDDIALOG_H
