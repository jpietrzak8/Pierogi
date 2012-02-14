#ifndef PIRAPPLICATION_H
#define PIRAPPLICATION_H

#include <QApplication>

class QWidget;

class PIRApplication: public QApplication
{
  Q_OBJECT
public:
  PIRApplication(
    int &argc,
    char **argv);

  void setupRockerSwitch(
    QWidget *window);

  virtual bool x11EventFilter(
    XEvent *event);

signals:
  void increaseRockerPressed();
  void decreaseRockerPressed();
};

#endif // PIRAPPLICATION_H
