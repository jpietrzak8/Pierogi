#ifndef PIRMACROFORM_H
#define PIRMACROFORM_H

#include <QWidget>
#include "dialogs/pirselectmacrodialog.h"
#include "dialogs/pireditmacrodialog.h"
#include "dialogs/pirdeletemacrodialog.h"
#include "dialogs/pircreatecommanddialog.h"
//#include "dialogs/pireditcommanddialog.h"

class PIRMacro;
class QComboBox;
class QListWidgetItem;
class MainWindow;

enum UserRequest {
  No_Request,
  DisplayMacro_Request,
  NewMacro_Request,
  EditMacro_Request,
  DeleteMacro_Request
};

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

  QComboBox *getKeysetComboBox();
  
private slots:
  void on_chooseMacroButton_clicked();
//  void on_newMacroButton_clicked();
  void on_runButton_clicked();
  void on_addButton_clicked();
  void on_commandUpButton_clicked();
  void on_commandDownIcon_clicked();
  void on_deleteButton_clicked();
  void on_copyButton_clicked();
//  void on_macroListWidget_itemClicked(QListWidgetItem *item);
//  void on_macroListWidget_itemClicked();
  void on_macroListWidget_currentRowChanged(int currentRow);

  void displayMacro(
    QTreeWidgetItem *item);

  void createNewMacro();

  void editMacro(
    QTreeWidgetItem *item);

  void deleteMacro(
    QTreeWidgetItem *item);

//  void deleteCurrentCommand();
//  void moveCurrentCommandUp();
//  void moveCurrentCommandDown();
//  void copyCurrentCommand();

private:
  Ui::PIRMacroForm *ui;

  PIRSelectMacroDialog smd;
  PIREditMacroDialog emd;
  PIRDeleteMacroDialog dmd;
  PIRCreateCommandDialog ccd;
//  PIREditCommandDialog ecd;

  PIRMacro *currentMacro;
  PIRMacro *userRequestMacro;

  UserRequest request;

  MainWindow *mainWindow;
};

#endif // PIRMACROFORM_H
