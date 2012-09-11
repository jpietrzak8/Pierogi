#include "pirselectmacrodialog.h"
#include "ui_pirselectmacrodialog.h"

#include "macros/pirmacropack.h"
#include "macros/pirreversemultitap.h"
#include "mainwindow.h"

/*
PIRSelectMacroDialog::PIRSelectMacroDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::PIRSelectMacroDialog)
{
  ui->setupUi(this);
}
*/


PIRSelectMacroDialog::PIRSelectMacroDialog(
  MainWindow *mw)
  : QDialog(mw),
    ui(new Ui::PIRSelectMacroDialog)
//    mainWindow(mw)
{
  ui->setupUi(this);

  userPack = new PIRMacroPack(ui->macroTreeWidget, "User Defined Macros");
  multitapPack = new PIRReverseMultitap(ui->macroTreeWidget, mw);
}


PIRSelectMacroDialog::~PIRSelectMacroDialog()
{
  delete ui;

  delete userPack;
  delete multitapPack;
}


void PIRSelectMacroDialog::on_buttonBox_accepted()
{
  // Try to find a usable macro in the list of selected items.  (There should
  // only be one item in the list anyway.)
  QList<QTreeWidgetItem *> items = ui->macroTreeWidget->selectedItems();

  int index = 0;
  int size = items.size();

  while (index < size)
  {
    if (items[index]->parent() != 0)
    {
      emit macroChosen(items[index]);
      return;
    }

    ++index;
  }
}


/*
void PIRSelectMacroDialog::on_buttonBox_rejected()
{

}
*/
