#ifndef PIRDELETEMACRODIALOG_H
#define PIRDELETEMACRODIALOG_H

#include <QDialog>

class PIRMacro;

namespace Ui {
class PIRDeleteMacroDialog;
}

class PIRDeleteMacroDialog : public QDialog
{
  Q_OBJECT
  
public:
  explicit PIRDeleteMacroDialog(QWidget *parent = 0);
  ~PIRDeleteMacroDialog();

  void setup(
    PIRMacro *macro);
  
private:
  Ui::PIRDeleteMacroDialog *ui;
};

#endif // PIRDELETEMACRODIALOG_H
