// In order to take control of the keyboard when using a tabbed widget, I need
// to subclass QTabWidget and redefine the keyPressEvent() method.

#include <QTabWidget>

class QKeyEvent;
class MainWindow;

class PIRTabWidget: public QTabWidget
{
public:
  PIRTabWidget(
    QWidget *parent,
    MainWindow *mw);

protected:
  virtual void keyPressEvent(
    QKeyEvent *event);

  virtual void keyReleaseEvent(
    QKeyEvent *event);

private:
  MainWindow *mainWindow;
};
