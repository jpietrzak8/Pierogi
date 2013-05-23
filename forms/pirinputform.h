//
// pirinputform.h
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

#ifndef PIRINPUTFORM_H
#define PIRINPUTFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRInputForm;
}

class PIRInputForm : public QWidget
{
  Q_OBJECT
  
public:
  PIRInputForm(MainWindow *mw);
  ~PIRInputForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void cdInputEnabled(bool);
  void tapeInputEnabled(bool);
  void phonoInputEnabled(bool);
  void tunerInputEnabled(bool);
  void pcInputEnabled(bool);
  void hdmiInputEnabled(bool);
  void dvdInputEnabled(bool);
  void vcrInputEnabled(bool);
  void antennaInputEnabled(bool);
  void cableInputEnabled(bool);
  void satelliteInputEnabled(bool);
  void auxInputEnabled(bool);
  void compositeInputEnabled(bool);
  void scartInputEnabled(bool);
  void componentInputEnabled(bool);
  void hddInputEnabled(bool);

private slots:
  void on_cdInputButton_pressed();
  void on_cdInputButton_released();
  void on_tapeInputButton_pressed();
  void on_tapeInputButton_released();
  void on_phonoInputButton_pressed();
  void on_phonoInputButton_released();
  void on_tunerInputButton_pressed();
  void on_tunerInputButton_released();
  void on_pcInputButton_pressed();
  void on_pcInputButton_released();
  void on_hdmiInputButton_pressed();
  void on_hdmiInputButton_released();
  void on_dvdInputButton_pressed();
  void on_dvdInputButton_released();
  void on_vcrInputButton_pressed();
  void on_vcrInputButton_released();
  void on_antennaInputButton_pressed();
  void on_antennaInputButton_released();
  void on_cableInputButton_pressed();
  void on_cableInputButton_released();
  void on_satelliteInputButton_pressed();
  void on_satelliteInputButton_released();
  void on_auxInputButton_pressed();
  void on_auxInputButton_released();
  void on_compositeInputButton_pressed();
  void on_compositeInputButton_released();
  void on_scartInputButton_pressed();
  void on_scartInputButton_released();
  void on_componentInputButton_pressed();
  void on_componentInputButton_released();
  void on_hddInputButton_pressed();
  void on_hddInputButton_released();

private:
  Ui::PIRInputForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRINPUTFORM_H
