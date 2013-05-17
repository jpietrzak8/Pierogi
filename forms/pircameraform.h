#ifndef PIRCAMERAFORM_H
#define PIRCAMERAFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;
class PIRFlashLED;

namespace Ui {
class PIRCameraForm;
}

class PIRCameraForm : public QWidget
{
  Q_OBJECT
  
public:
//  explicit PIRCameraForm(QWidget *parent = 0);

  PIRCameraForm(
    MainWindow *mw);

  ~PIRCameraForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void openShutterEnabled(bool);
  void delayedOpenShutterEnabled(bool);
  
private slots:
  void on_openShutterButton_pressed();
  void on_openShutterButton_released();

private:
  Ui::PIRCameraForm *ui;

  MainWindow *mainWindow;

  PIRFlashLED *flash;
};

#endif // PIRCAMERAFORM_H
