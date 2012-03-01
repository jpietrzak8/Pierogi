#ifndef PIRMAINFORM_H
#define PIRMAINFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRMainForm;
}

class PIRMainForm : public QWidget
{
  Q_OBJECT

public:
//  explicit PIRMainForm(QWidget *parent = 0);
  PIRMainForm(MainWindow *mw);
  ~PIRMainForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void powerEnabled(bool);
  void volumeUpEnabled(bool);
  void volumeDownEnabled(bool);
  void channelUpEnabled(bool);
  void channelDownEnabled(bool);
  void muteEnabled(bool);

  void keysetMakeChanged(QString);
  void keysetNameChanged(QString);

private slots:
  void on_powerButton_pressed();
  void on_powerButton_released();
  void on_mainChannelUpButton_pressed();
  void on_mainChannelUpButton_released();
  void on_mainChannelDownButton_pressed();
  void on_mainChannelDownButton_released();
  void on_mainVolumeUp_pressed();
  void on_mainVolumeUp_released();
  void on_mainVolumeDownButton_pressed();
  void on_mainVolumeDownButton_released();
  void on_muteButton_pressed();
  void on_muteButton_released();

private:
  Ui::PIRMainForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRMAINFORM_H
