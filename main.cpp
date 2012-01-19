#include "mainwindow.h"
#include <QtGui/QApplication>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  MainWindow mainWindow;
  mainWindow.setOrientation(MainWindow::ScreenOrientationLockLandscape);
  mainWindow.showExpanded();

  // A connection to perform any final cleanup work:
  app.connect(
    &app,
    SIGNAL(aboutToQuit()),
    &mainWindow,
    SLOT(finalCleanup()),
    Qt::DirectConnection);

  return app.exec();
}
