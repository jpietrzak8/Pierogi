#ifndef PIRALTMAINFORM_H
#define PIRALTMAINFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRAltMainForm;
}

class PIRAltMainForm : public QWidget
{
  Q_OBJECT
  
public:
//  explicit PIRAltMainForm(QWidget *parent = 0);
  PIRAltMainForm(
    MainWindow *mw);

  ~PIRAltMainForm();

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
  void on_volumeUpButton_pressed();
  void on_volumeUpButton_released();
  void on_volumeDownButton_pressed();
  void on_volumeDownButton_released();
  void on_muteButton_pressed();
  void on_muteButton_released();
  void on_powerButton_pressed();
  void on_powerButton_released();
  void on_channelUpButton_pressed();
  void on_channelUpButton_released();
  void on_channelDownButton_pressed();
  void on_channelDownButton_released();

private:
  Ui::PIRAltMainForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRALTMAINFORM_H
