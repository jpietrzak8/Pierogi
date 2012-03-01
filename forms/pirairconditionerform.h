#ifndef PIRAIRCONDITIONERFORM_H
#define PIRAIRCONDITIONERFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRAirConditionerForm;
}

class PIRAirConditionerForm : public QWidget
{
  Q_OBJECT
  
public:
  PIRAirConditionerForm(MainWindow *mw);
  ~PIRAirConditionerForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void oscillateEnabled(bool);
  void powerEnabled(bool);
  void timerEnabled(bool);
  void modeEnabled(bool);
  void fanFasterEnabled(bool);
  void heatEnabled(bool);
  void fanEnabled(bool);
  void tempUpEnabled(bool);
  void fanSlowerEnabled(bool);
  void energySaveEnabled(bool);
  void coolEnabled(bool);
  void tempDownEnabled(bool);
  
private slots:
  void on_oscillateButton_pressed();
  void on_oscillateButton_released();
  void on_powerButton_pressed();
  void on_powerButton_released();
  void on_timerButton_pressed();
  void on_timerButton_released();
  void on_modeButton_pressed();
  void on_modeButton_released();
  void on_fanFasterButton_pressed();
  void on_fanFasterButton_released();
  void on_heatButton_pressed();
  void on_heatButton_released();
  void on_fanButton_pressed();
  void on_fanButton_released();
  void on_tempUpButton_pressed();
  void on_tempUpButton_released();
  void on_fanSlowerButton_pressed();
  void on_fanSlowerButton_released();
  void on_energySaveButton_pressed();
  void on_energySaveButton_released();
  void on_coolButton_pressed();
  void on_coolButton_released();
  void on_tempDownButton_pressed();
  void on_tempDownButton_released();

private:
  Ui::PIRAirConditionerForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRAIRCONDITIONERFORM_H
