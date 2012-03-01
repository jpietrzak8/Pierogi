#ifndef PIRINPUTFORM_H
#define PIRINPUTFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRInputForm;
}

class PIRInputForm : public QWidget
{
  Q_OBJECT
  
public:
  PIRInputForm(MainWindow *mw);
  ~PIRInputForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void cdInputEnabled(bool);
  void tapeInputEnabled(bool);
  void phonoInputEnabled(bool);
  void tunerInputEnabled(bool);
  void pcInputEnabled(bool);
  void hdmiInputEnabled(bool);
  void dvdInputEnabled(bool);
  void vcrInputEnabled(bool);
  void antennaInputEnabled(bool);
  void cableInputEnabled(bool);
  void satelliteInputEnabled(bool);
  void auxInputEnabled(bool);

private slots:
  void on_cdInputButton_pressed();
  void on_cdInputButton_released();
  void on_tapeInputButton_pressed();
  void on_tapeInputButton_released();
  void on_phonoInputButton_pressed();
  void on_phonoInputButton_released();
  void on_tunerInputButton_pressed();
  void on_tunerInputButton_released();
  void on_pcInputButton_pressed();
  void on_pcInputButton_released();
  void on_hdmiInputButton_pressed();
  void on_hdmiInputButton_released();
  void on_dvdInputButton_pressed();
  void on_dvdInputButton_released();
  void on_vcrInputButton_pressed();
  void on_vcrInputButton_released();
  void on_antennaInputButton_pressed();
  void on_antennaInputButton_released();
  void on_cableInputButton_pressed();
  void on_cableInputButton_released();
  void on_satelliteInputButton_pressed();
  void on_satelliteInputButton_released();
  void on_auxInputButton_pressed();
  void on_auxInputButton_released();

private:
  Ui::PIRInputForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRINPUTFORM_H
