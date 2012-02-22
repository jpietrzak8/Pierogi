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
  app.setupRockerSwitch(mainWindow.getSecondaryWindow());

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
