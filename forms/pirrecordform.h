#ifndef PIRRECORDFORM_H
#define PIRRECORDFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRRecordForm;
}

class PIRRecordForm : public QWidget
{
  Q_OBJECT

public:
  PIRRecordForm(
    MainWindow *mw);

  ~PIRRecordForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void timerEnabled(bool);
  void programEnabled(bool);
  void memoryEnabled(bool);
  void callEnabled(bool);
  void favoritesEnabled(bool);
  void scanEnabled(bool);
  void prevPresetEnabled(bool);
  void nextPresetEnabled(bool);
  void recordEnabled(bool);
  void recordPauseEnabled(bool);
  void recordStopEnabled(bool);
  void recordMuteEnabled(bool);

private slots:
  void on_timerButton_pressed();
  void on_timerButton_released();
  void on_programButton_pressed();
  void on_programButton_released();
  void on_memoryButton_pressed();
  void on_memoryButton_released();
  void on_callButton_pressed();
  void on_callButton_released();
  void on_favoritesButton_pressed();
  void on_favoritesButton_released();
  void on_scanButton_pressed();
  void on_scanButton_released();
  void on_prevPresetButton_pressed();
  void on_prevPresetButton_released();
  void on_nextPresetButton_pressed();
  void on_nextPresetButton_released();
  void on_recordButton_pressed();
  void on_recordButton_released();
  void on_recordPauseButton_pressed();
  void on_recordPauseButton_released();
  void on_recordStopButton_pressed();
  void on_recordStopButton_released();
  void on_recordMuteButton_pressed();
  void on_recordMuteButton_released();

private:
  Ui::PIRRecordForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRRECORDFORM_H
