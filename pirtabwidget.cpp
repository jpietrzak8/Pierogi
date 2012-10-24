#include "pirtabwidget.h"

#include <QKeyEvent>
#include <QSizePolicy>

#include "mainwindow.h"

PIRTabWidget::PIRTabWidget(
  QWidget *parent,
  MainWindow *mw)
  : QTabWidget(parent),
    mainWindow(mw)
{
  setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}


void PIRTabWidget::keyPressEvent(
  QKeyEvent *event)
{
  switch(event->key())
  {
  case Qt::Key_A:
    mainWindow->handleKeypress('A');
    break;
  case Qt::Key_B:
    mainWindow->handleKeypress('B');
    break;
  case Qt::Key_C:
    mainWindow->handleKeypress('C');
    break;
  case Qt::Key_D:
    mainWindow->handleKeypress('D');
    break;
  case Qt::Key_E:
    mainWindow->handleKeypress('E');
    break;
  case Qt::Key_F:
    mainWindow->handleKeypress('F');
    break;
  case Qt::Key_G:
    mainWindow->handleKeypress('G');
    break;
  case Qt::Key_H:
    mainWindow->handleKeypress('H');
    break;
  case Qt::Key_I:
    mainWindow->handleKeypress('I');
    break;
  case Qt::Key_J:
    mainWindow->handleKeypress('J');
    break;
  case Qt::Key_K:
    mainWindow->handleKeypress('K');
    break;
  case Qt::Key_L:
    mainWindow->handleKeypress('L');
    break;
  case Qt::Key_M:
    mainWindow->handleKeypress('M');
    break;
  case Qt::Key_N:
    mainWindow->handleKeypress('N');
    break;
  case Qt::Key_O:
    mainWindow->handleKeypress('O');
    break;
  case Qt::Key_P:
    mainWindow->handleKeypress('P');
    break;
  case Qt::Key_Q:
    mainWindow->handleKeypress('Q');
    break;
  case Qt::Key_R:
    mainWindow->handleKeypress('R');
    break;
  case Qt::Key_S:
    mainWindow->handleKeypress('S');
    break;
  case Qt::Key_T:
    mainWindow->handleKeypress('T');
    break;
  case Qt::Key_U:
    mainWindow->handleKeypress('U');
    break;
  case Qt::Key_V:
    mainWindow->handleKeypress('V');
    break;
  case Qt::Key_W:
    mainWindow->handleKeypress('W');
    break;
  case Qt::Key_X:
    mainWindow->handleKeypress('X');
    break;
  case Qt::Key_Y:
    mainWindow->handleKeypress('Y');
    break;
  case Qt::Key_Z:
    mainWindow->handleKeypress('Z');
    break;
  case Qt::Key_Space:
    mainWindow->handleKeypress(' ');
    break;

  case Qt::Key_Up:
    mainWindow->gotoPreviousTabs();
    break;
  case Qt::Key_Down:
    mainWindow->gotoNextTabs();
    break;
  case Qt::Key_Left:
    mainWindow->startRepeating(VolumeDown_Key);
    break;
  case Qt::Key_Right:
    mainWindow->startRepeating(VolumeUp_Key);
    break;
  case Qt::Key_Backspace:
    mainWindow->startRepeating(Power_Key);
    break;
  case Qt::Key_Return:
    mainWindow->startRepeating(Mute_Key);
    break;

  default:
    QTabWidget::keyPressEvent(event);
    break;
  }
}


void PIRTabWidget::keyReleaseEvent(
  QKeyEvent *event)
{
  switch(event->key())
  {
  case Qt::Key_Up:
  case Qt::Key_Down:
    break;

  case Qt::Key_Left:
  case Qt::Key_Right:
  case Qt::Key_Backspace:
  case Qt::Key_Return:
    mainWindow->stopRepeating();
    break;

  default:
    QTabWidget::keyReleaseEvent(event);
    break;
  }
}
