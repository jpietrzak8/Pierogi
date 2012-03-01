#ifndef PIRMEDIAFORM_H
#define PIRMEDIAFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRMediaForm;
}

class PIRMediaForm : public QWidget
{
  Q_OBJECT

public:
//  explicit PIRMediaForm(QWidget *parent = 0);
  PIRMediaForm(MainWindow *mw);
  ~PIRMediaForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void playEnabled(bool);
  void pauseEnabled(bool);
  void stopEnabled(bool);
  void fastForwardEnabled(bool);
  void reverseEnabled(bool);
  void nextEnabled(bool);
  void previousEnabled(bool);
  void stepForwardEnabled(bool);
  void stepBackEnabled(bool);
  void advanceEnabled(bool);
  void replayEnabled(bool);
  void ejectEnabled(bool);

private slots:
  void on_mediaPreviousButton_pressed();
  void on_mediaPreviousButton_released();
  void on_mediaNextButton_pressed();
  void on_mediaNextButton_released();
  void on_replayButton_pressed();
  void on_replayButton_released();
  void on_advanceButton_pressed();
  void on_advanceButton_released();
  void on_stepBackButton_pressed();
  void on_stepBackButton_released();
  void on_stepForwardButton_pressed();
  void on_stepForwardButton_released();
  void on_reverseButton_pressed();
  void on_reverseButton_released();
  void on_fastForwardButton_pressed();
  void on_fastForwardButton_released();
  void on_playButton_pressed();
  void on_playButton_released();
  void on_pauseButton_pressed();
  void on_pauseButton_released();
  void on_stopButton_pressed();
  void on_stopButton_released();
  void on_ejectButton_pressed();
  void on_ejectButton_released();

private:
  Ui::PIRMediaForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRMEDIAFORM_H
