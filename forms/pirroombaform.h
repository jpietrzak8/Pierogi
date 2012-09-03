#ifndef PIRROOMBAFORM_H
#define PIRROOMBAFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRRoombaForm;
}

class PIRRoombaForm : public QWidget
{
  Q_OBJECT
  
public:
//  explicit PIRRoombaForm(QWidget *parent = 0);
  PIRRoombaForm(
    MainWindow *mw);

  ~PIRRoombaForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void spotEnabled(bool);
  void forwardEnabled(bool);
  void cleanEnabled(bool);
  void ccwEnabled(bool);
  void pauseEnabled(bool);
  void cwEnabled(bool);
  void maxEnabled(bool);
  void powerEnabled(bool);
  
private slots:
  void on_spotButton_pressed();
  void on_spotButton_released();
  void on_forwardButton_pressed();
  void on_forwardButton_released();
  void on_cleanButton_pressed();
  void on_cleanButton_released();
  void on_ccwButton_pressed();
  void on_ccwButton_released();
  void on_pauseButton_pressed();
  void on_pauseButton_released();
  void on_cwButton_pressed();
  void on_cwButton_released();
  void on_maxButton_pressed();
  void on_maxButton_released();
  void on_powerButton_pressed();
  void on_powerButton_released();

private:
  Ui::PIRRoombaForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRROOMBAFORM_H
