#ifndef PIRAUDIODEVICEFORM_H
#define PIRAUDIODEVICEFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRAudioDeviceForm;
}

class PIRAudioDeviceForm : public QWidget
{
  Q_OBJECT
  
public:
//  explicit PIRAudioDeviceForm(QWidget *parent = 0);

  PIRAudioDeviceForm(
    MainWindow *mw);

  ~PIRAudioDeviceForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void cdEnabled(bool);
  void tapeEnabled(bool);
  void phonoEnabled(bool);
  void auxEnabled(bool);
  void tunerEnabled(bool);
  void fmEnabled(bool);
  void amEnabled(bool);
  void lwEnabled(bool);
  void fmModeEnabled(bool);
  void repeatEnabled(bool);
  void repeatABEnabled(bool);
  void randomEnabled(bool);
  void nextDiscEnabled(bool);
  void prevDiscEnabled(bool);
  void sleepEnabled(bool);
  void infoEnabled(bool);
  
private slots:
  void on_cdButton_pressed();
  void on_cdButton_released();
  void on_tapeButton_pressed();
  void on_tapeButton_released();
  void on_phonoButton_pressed();
  void on_phonoButton_released();
  void on_auxButton_pressed();
  void on_auxButton_released();
  void on_tunerButton_pressed();
  void on_tunerButton_released();
  void on_fmButton_pressed();
  void on_fmButton_released();
  void on_amButton_pressed();
  void on_amButton_released();
  void on_lwButton_pressed();
  void on_lwButton_released();
  void on_fmModeButton_pressed();
  void on_fmModeButton_released();
  void on_repeatButton_pressed();
  void on_repeatButton_released();
  void on_repeatABButton_pressed();
  void on_repeatABButton_released();
  void on_randomButton_pressed();
  void on_randomButton_released();
  void on_nextDiscButton_pressed();
  void on_nextDiscButton_released();
  void on_prevDiscButton_pressed();
  void on_prevDiscButton_released();
  void on_sleepButton_pressed();
  void on_sleepButton_released();
  void on_infoButton_pressed();
  void on_infoButton_released();

private:
  Ui::PIRAudioDeviceForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRAUDIODEVICEFORM_H
