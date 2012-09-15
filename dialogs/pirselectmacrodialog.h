#ifndef PIRSELECTMACRODIALOG_H
#define PIRSELECTMACRODIALOG_H

#include <QDialog>

class PIRMacroPack;
class PIRMacro;
class PIRReverseMultitap;
class QTreeWidgetItem;

namespace Ui {
class PIRSelectMacroDialog;
}

class PIRSelectMacroDialog : public QDialog
{
  Q_OBJECT
  
public:
//  explicit PIRSelectMacroDialog(QWidget *parent = 0);

  PIRSelectMacroDialog();

  ~PIRSelectMacroDialog();

  void addPack(
    PIRMacroPack *pack);

  void resetIndices();

signals:
  void macroChosen(
    QTreeWidgetItem *item);

  void newMacroRequested();

  void editMacroRequested(
    QTreeWidgetItem *item);

  void deleteMacroRequested(
    QTreeWidgetItem *item);
  
private slots:
  void on_buttonBox_accepted();
//  void on_buttonBox_rejected();
  void on_newButton_clicked();
  void on_editButton_clicked();
  void on_deleteButton_clicked();

private:
  Ui::PIRSelectMacroDialog *ui;
};

#endif // PIRSELECTMACRODIALOG_H
