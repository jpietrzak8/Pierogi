//
// pirtvform.h
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

#ifndef PIRTVFORM_H
#define PIRTVFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRTVForm;
}

class PIRTVForm : public QWidget
{
  Q_OBJECT
  
public:
  PIRTVForm(MainWindow *mw);
  ~PIRTVForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void teletextEnabled(bool);
  void teletextHoldEnabled(bool);
  void favoritesEnabled(bool);
  void pageUpEnabled(bool);
  void energySaverEnabled(bool);
  void smartHubEnabled(bool);
  void liveTVEnabled(bool);
  void pageDownEnabled(bool);
  void pipEnabled(bool);
  void pipSwapEnabled(bool);
  void pipMoveEnabled(bool);
  void pipSourceEnabled(bool);
  void pipChannelUpEnabled(bool);
  void pipChannelDownEnabled(bool);
  void pipPauseEnabled(bool);
  void pipSizeEnabled(bool);

private slots:
  void on_teletextButton_pressed();
  void on_teletextButton_released();
  void on_teletextHoldButton_pressed();
  void on_teletextHoldButton_released();
  void on_favoritesButton_pressed();
  void on_favoritesButton_released();
  void on_pageUpButton_pressed();
  void on_pageUpButton_released();
  void on_energySaverButton_pressed();
  void on_energySaverButton_released();
  void on_smartHubButton_pressed();
  void on_smartHubButton_released();
  void on_liveTVButton_pressed();
  void on_liveTVButton_released();
  void on_pageDownButton_pressed();
  void on_pageDownButton_released();
  void on_pipButton_pressed();
  void on_pipButton_released();
  void on_pipSwapButton_pressed();
  void on_pipSwapButton_released();
  void on_pipMoveButton_pressed();
  void on_pipMoveButton_released();
  void on_pipSourceButton_pressed();
  void on_pipSourceButton_released();
  void on_pipChannelUpButton_pressed();
  void on_pipChannelUpButton_released();
  void on_pipChannelDownButton_pressed();
  void on_pipChannelDownButton_released();
  void on_pipPauseButton_pressed();
  void on_pipPauseButton_released();
  void on_pipSizeButton_pressed();
  void on_pipSizeButton_released();

private:
  Ui::PIRTVForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRTVFORM_H
