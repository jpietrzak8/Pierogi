#ifndef PIRSELECTMACRODIALOG_H
#define PIRSELECTMACRODIALOG_H

#include <QDialog>

class MainWindow;
class PIRMacroPack;
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

  PIRSelectMacroDialog(
    MainWindow *mw);

  ~PIRSelectMacroDialog();

signals:
  void macroChosen(
    QTreeWidgetItem *item);
  
private slots:
  void on_buttonBox_accepted();
//  void on_buttonBox_rejected();

private:
  Ui::PIRSelectMacroDialog *ui;

  PIRMacroPack *userPack;
  PIRReverseMultitap *multitapPack;

//  MainWindow *mainWindow;
};

#endif // PIRSELECTMACRODIALOG_H
