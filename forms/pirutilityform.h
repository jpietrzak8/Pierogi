#ifndef PIRUTILITYFORM_H
#define PIRUTILITYFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRUtilityForm;
}

class PIRUtilityForm : public QWidget
{
  Q_OBJECT

public:
//  explicit PIRUtilityForm(QWidget *parent = 0);
  PIRUtilityForm(MainWindow *mw);
  ~PIRUtilityForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void redEnabled(bool);
  void greenEnabled(bool);
  void yellowEnabled(bool);
  void blueEnabled(bool);
  void pictureModeEnabled(bool);
  void soundModeEnabled(bool);
  void aspectRatioEnabled(bool);
  void audioEnabled(bool);
  void infoEnabled(bool);
  void captionsEnabled(bool);
  void inputEnabled(bool);
  void sleepEnabled(bool);

private slots:
  void on_redButton_pressed();
  void on_redButton_released();
  void on_greenButton_pressed();
  void on_greenButton_released();
  void on_yellowButton_pressed();
  void on_yellowButton_released();
  void on_blueButton_pressed();
  void on_blueButton_released();
  void on_pictureModeButton_pressed();
  void on_pictureModeButton_released();
  void on_soundModeButton_pressed();
  void on_soundModeButton_released();
  void on_aspectRatioButton_pressed();
  void on_aspectRatioButton_released();
  void on_audioButton_pressed();
  void on_audioButton_released();
  void on_infoButton_pressed();
  void on_infoButton_released();
  void on_captionButton_pressed();
  void on_captionButton_released();
  void on_inputButton_pressed();
  void on_inputButton_released();
  void on_sleepButton_pressed();
  void on_sleepButton_released();

private:
  Ui::PIRUtilityForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRUTILITYFORM_H
