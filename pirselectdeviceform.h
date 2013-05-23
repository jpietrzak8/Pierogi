//
// pirselectdeviceform.h
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

#ifndef PIRSELECTDEVICEFORM_H
#define PIRSELECTDEVICEFORM_H

#include <QWidget>

#include "pirmakenames.h"
#include "pirdevicetypenames.h"
#include "pirdeviceinfo.h"

class PIRKeysetWidgetItem;
class QListWidget;
class QKeyEvent;

namespace Ui {
class PIRSelectDeviceForm;
}

class PIRSelectDeviceForm : public QWidget
{
  Q_OBJECT
  
public:
  explicit PIRSelectDeviceForm(
    QWidget *parent = 0);

  ~PIRSelectDeviceForm();

/*
  void addNameToList(
    QString name,
    unsigned int index,
    PIRMakeName make);
*/

  void addWidgetItem(
    PIRKeysetWidgetItem *kwi);

  // This is a bit of a hack, but not sure how to create a connection otherwise.
  QListWidget *getDeviceListWidget();

protected:
  void keyPressEvent(
    QKeyEvent *event);

private slots:
  void filterListByMake(
    int make);

  void filterListByDeviceType(
    int deviceType);

  void filterListByString(
    QString string);

  void on_searchStringLineEdit_textChanged(const QString &arg1);
  void on_ssClosePushButton_clicked();

private:
  void refilterList();

  Ui::PIRSelectDeviceForm *ui;

  PIRMakeName currentMake;
  PIRDeviceTypeName currentDevice;
  QString searchString;
};

#endif // PIRSELECTDEVICEFORM_H
