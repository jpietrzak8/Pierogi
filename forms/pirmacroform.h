#ifndef PIRMACROFORM_H
#define PIRMACROFORM_H

#include <QWidget>

namespace Ui {
class PIRMacroForm;
}

class PIRMacroForm : public QWidget
{
  Q_OBJECT
  
public:
  explicit PIRMacroForm(QWidget *parent = 0);
  ~PIRMacroForm();
  
private slots:
  void on_cycleCheckBox_stateChanged(int arg1);

  void on_spinBox_valueChanged(int arg1);

  void on_prevMacroButton_clicked();

  void on_nextMacroButton_clicked();

  void on_newMacroButton_clicked();

private:
  Ui::PIRMacroForm *ui;
};

#endif // PIRMACROFORM_H
