#ifndef PIRPOWERSEARCHFORM_H
#define PIRPOWERSEARCHFORM_H

#include <QWidget>
#include <QString>

class MainWindow;
class PIRKeysetManager;
class QTimer;

namespace Ui {
class PIRPowerSearchForm;
}

class PIRPowerSearchForm : public QWidget
{
  Q_OBJECT
  
public:
//  explicit PIRPowerSearchForm(QWidget *parent = 0);

  PIRPowerSearchForm(
    MainWindow *mw);

  ~PIRPowerSearchForm();

  void setKeysetName(
    QString name);
  
private slots:
  void on_stepBackwardButton_pressed();
  void on_stepBackwardButton_released();
  void on_stepForwardKey_pressed();
  void on_stepForwardKey_released();
  void on_fastBackwardButton_pressed();
  void on_fastBackwardButton_released();
  void on_fastForwardButton_pressed();
  void on_fastForwardButton_released();

  void gotoPrevKeyset();
  void gotoNextKeyset();

private:
  bool checkMutex();

  Ui::PIRPowerSearchForm *ui;

  MainWindow *mainWindow;

  QTimer *advanceTimer;
};

#endif // PIRPOWERSEARCHFORM_H
