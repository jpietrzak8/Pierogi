#ifndef PIREDITMACRODIALOG_H
#define PIREDITMACRODIALOG_H

#include <QDialog>

class QTreeWidgetItem;

namespace Ui {
class PIREditMacroDialog;
}

class PIREditMacroDialog : public QDialog
{
  Q_OBJECT
  
public:
  explicit PIREditMacroDialog(QWidget *parent = 0);
  ~PIREditMacroDialog();

  void clear();

  void setup(
    QTreeWidgetItem *item);

  QString getText();

  char getKey();

  unsigned int getButtonID();
  
private:
  Ui::PIREditMacroDialog *ui;
};

#endif // PIREDITMACRODIALOG_H
