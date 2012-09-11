#ifndef PIRCREATECOMMANDDIALOG_H
#define PIRCREATECOMMANDDIALOG_H

#include <QDialog>

class MainWindow;

namespace Ui {
class PIRCreateCommandDialog;
}

class PIRCreateCommandDialog : public QDialog
{
  Q_OBJECT
  
public:
//  explicit PIRCreateCommandDialog(QWidget *parent = 0);

  PIRCreateCommandDialog(
    MainWindow *mw);

  ~PIRCreateCommandDialog();
  
private:
  Ui::PIRCreateCommandDialog *ui;
};

#endif // PIRCREATECOMMANDDIALOG_H
