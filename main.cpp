//
// main.cpp
//
// The implementation of the main routine for Pierogi.
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


#include "mainwindow.h"
#include "pirapplication.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
//  QApplication app(argc, argv);
  PIRApplication app(argc, argv);

  MainWindow mainWindow;
  mainWindow.setOrientation(MainWindow::ScreenOrientationLockLandscape);
//  mainWindow.setOrientation(MainWindow::ScreenOrientationAuto);

  // Take control over the volume rocker switch:
  app.setupRockerSwitch(&mainWindow);

  mainWindow.showExpanded();

  app.connect(
    &app,
    SIGNAL(decreaseRockerPressed()),
    &mainWindow,
    SLOT(selectPrevFavKeyset()));

  app.connect(
    &app,
    SIGNAL(increaseRockerPressed()),
    &mainWindow,
    SLOT(selectNextFavKeyset()));

  // A connection to perform any final cleanup work:
  app.connect(
    &app,
    SIGNAL(aboutToQuit()),
    &mainWindow,
    SLOT(finalCleanup()),
    Qt::DirectConnection);

  return app.exec();
}
