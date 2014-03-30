//
// pirintervalometerform.h
//
// Copyright 2014 by John Pietrzak (jpietrzak8@gmail.com)
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

#ifndef PIRINTERVALOMETERFORM_H
#define PIRINTERVALOMETERFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;
class QTimer;

namespace Ui {
class PIRIntervalometerForm;
}

class PIRIntervalometerForm : public QWidget
{
  Q_OBJECT
  
public:
  PIRIntervalometerForm(
    MainWindow *mw);

  ~PIRIntervalometerForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void openShutterEnabled(bool);

private slots:
  void on_startPushButton_clicked();
  void on_quitPushButton_clicked();

  void startIntervalometer();
  void executeInterval();

private:
  Ui::PIRIntervalometerForm *ui;

  QTimer *intervalTimer;
  int exposureCount;
  int intervalValue;

  MainWindow *mainWindow;
};

#endif // PIRINTERVALOMETERFORM_H
