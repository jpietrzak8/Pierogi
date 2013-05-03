#ifndef PIRSTATEFULACFORM_H
#define PIRSTATEFULACFORM_H

#include <QWidget>

class MainWindow;
class PIRKeysetManager;

namespace Ui {
class PIRStatefulACForm;
}

class PIRStatefulACForm : public QWidget
{
  Q_OBJECT
  
public:
//  explicit PIRStatefulACForm(QWidget *parent = 0);
  PIRStatefulACForm(
    MainWindow *mw);

  ~PIRStatefulACForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  void sendCommandEnabled(bool);
  void powerComboBoxEnabled(bool);
  void tempComboBoxEnabled(bool);
  void fanComboBoxEnabled(bool);
  void modeComboBoxEnabled(bool);
  void swingComboBoxEnabled(bool);
  void turboComboBoxEnabled(bool);
  void airCleanComboBoxEnabled(bool);
  
private slots:
  void on_sendButton_pressed();
  void on_sendButton_released();

private:
  Ui::PIRStatefulACForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRSTATEFULACFORM_H
