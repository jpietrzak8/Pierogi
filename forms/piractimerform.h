#ifndef PIRACTIMERFORM_H
#define PIRACTIMERFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRACTimerForm;
}

class PIRACTimerForm : public QWidget
{
  Q_OBJECT

public:
//  explicit PIRACTimerForm(QWidget *parent = 0);
  PIRACTimerForm(
    MainWindow *mw);

  ~PIRACTimerForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void setTimerButtonEnabled(bool);
  void timerOptionComboBoxEnabled(bool);
  void timeValueSpinBoxEnabled(bool);

private slots:
  void on_setTimerButton_pressed();
  void on_setTimerButton_released();

private:
  Ui::PIRACTimerForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRACTIMERFORM_H
