#ifndef PIRMENUFORM_H
#define PIRMENUFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRMenuForm;
}

class PIRMenuForm : public QWidget
{
  Q_OBJECT

public:
//  explicit PIRMenuForm(QWidget *parent = 0);
  PIRMenuForm(MainWindow *mw);
  ~PIRMenuForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void menuEnabled(bool);
  void upEnabled(bool);
  void downEnabled(bool);
  void leftEnabled(bool);
  void rightEnabled(bool);
  void selectEnabled(bool);
  void exitEnabled(bool);
  void guideEnabled(bool);
  void discMenuEnabled(bool);

private slots:
  void on_upButton_pressed();
  void on_upButton_released();
  void on_leftButton_pressed();
  void on_leftButton_released();
  void on_rightButton_pressed();
  void on_rightButton_released();
  void on_downButton_pressed();
  void on_downButton_released();
  void on_selectButton_pressed();
  void on_selectButton_released();
  void on_menuButton_pressed();
  void on_menuButton_released();
  void on_exitButton_pressed();
  void on_exitButton_released();
  void on_guideButton_pressed();
  void on_guideButton_released();
  void on_discMenuButton_pressed();
  void on_discMenuButton_released();

private:
  Ui::PIRMenuForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRMENUFORM_H
