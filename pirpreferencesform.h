//
// pirpreferencesform.h
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

#ifndef PIRPREFERENCESFORM_H
#define PIRPREFERENCESFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;
class QComboBox;

namespace Ui {
class PIRPreferencesForm;
}

class PIRPreferencesForm : public QWidget
{
  Q_OBJECT
  
public:
  PIRPreferencesForm(
    QWidget *parent,
    const PIRKeysetManager *keysetManager);

  ~PIRPreferencesForm();

  unsigned int getDefaultKeyset()
  {
    return defaultKeyset;
  }

  bool defaultControlsVolume()
  {
    return useDefaultForVolume;
  }
  
private slots:
  void on_setDefaultButton_clicked();
  void on_clearDefaultButton_clicked();
  void on_useDefaultCheckBox_stateChanged(int arg1);
  void on_altMainCheckBox_stateChanged(int arg1);
  void on_carrierFrequencySpinBox_valueChanged(int arg1);
  void on_dutyCycleSpinBox_valueChanged(int arg1);

private:
  void setupMacroComboBox(
    QComboBox *cb);

  Ui::PIRPreferencesForm *ui;

  MainWindow *mainWindow;

  unsigned int defaultKeyset;
  bool useDefaultForVolume;
};

#endif // PIRPREFERENCESFORM_H
