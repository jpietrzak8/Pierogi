#ifndef PIRUSERFORM_H
#define PIRUSERFORM_H

#include <QWidget>

class MainWindow;

namespace Ui {
class PIRUserForm;
}

class PIRUserForm : public QWidget
{
  Q_OBJECT
  
public:
//  explicit PIRUserForm(QWidget *parent = 0);

  PIRUserForm(
    MainWindow *mw);

  ~PIRUserForm();

  void setupButtons();
  
private slots:
  void on_userDef1Button_clicked();
  void on_userDef2Button_clicked();
  void on_userDef3Button_clicked();
  void on_userDef4Button_clicked();
  void on_userDef5Button_clicked();
  void on_userDef6Button_clicked();

private:
  Ui::PIRUserForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRUSERFORM_H
