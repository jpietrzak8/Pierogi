#ifndef PIRMACROFORM_H
#define PIRMACROFORM_H

#include <QWidget>
#include "dialogs/pirselectmacrodialog.h"
#include "dialogs/pircreatecommanddialog.h"

class PIRMacro;

namespace Ui {
class PIRMacroForm;
}

class PIRMacroForm : public QWidget
{
  Q_OBJECT
  
public:
//  explicit PIRMacroForm(QWidget *parent = 0);

  PIRMacroForm(
    MainWindow *mw);

  ~PIRMacroForm();
  
private slots:
  void on_chooseMacroButton_clicked();
  void on_addButton_clicked();
  void on_runButton_clicked();

  void displayMacro(
    QTreeWidgetItem *item);

private:
  Ui::PIRMacroForm *ui;

  PIRSelectMacroDialog smd;
  PIRCreateCommandDialog ccd;

  PIRMacro *currentMacro;
};

#endif // PIRMACROFORM_H
