// main.cpp
//
// For the Pierogi IR remote control app.
//
// Copyright (C) 2012 by John Pietrzak  (john@pietrzak.org)
//
// Licensed under the GNU GPL version 2.0 or later.

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
