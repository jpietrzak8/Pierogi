#include "pirselectmacrodialog.h"
#include "ui_pirselectmacrodialog.h"

#include "macros/pirmacropack.h"
#include "macros/pirmacro.h"
#include "macros/pirreversemultitap.h"
#include "mainwindow.h"
#include <QMaemo5InformationBox>

// Debugging includes:
#include <iostream>

/*
PIRSelectMacroDialog::PIRSelectMacroDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::PIRSelectMacroDialog)
{
  ui->setupUi(this);
}
*/


PIRSelectMacroDialog::PIRSelectMacroDialog()
  : QDialog(0),
    ui(new Ui::PIRSelectMacroDialog)
{
  ui->setupUi(this);
}


PIRSelectMacroDialog::~PIRSelectMacroDialog()
{
  // This is a hack to get around object ownership issues:
  while (ui->macroTreeWidget->topLevelItemCount())
  {
    ui->macroTreeWidget->takeTopLevelItem(0);
  }

  delete ui;
}


void PIRSelectMacroDialog::addPack(
  PIRMacroPack *pack)
{
  ui->macroTreeWidget->addTopLevelItem(pack);
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

void PIRSelectMacroDialog::on_newButton_clicked()
{
  emit newMacroRequested();
  accept();
}


void PIRSelectMacroDialog::on_editButton_clicked()
{
  // Find the first selected macro, if any:
  QList<QTreeWidgetItem *> items = ui->macroTreeWidget->selectedItems();

  if (items.size() > 0)
  {
    if (items[0]->parent() == 0)
    {
      QMaemo5InformationBox::information(0, "Cannot Edit MacroPacks");
    }
    else
    {
      emit editMacroRequested(items[0]);
    }
  }

  accept();
}


void PIRSelectMacroDialog::on_deleteButton_clicked()
{
  // Find the first selected macro, if any:
  QList<QTreeWidgetItem *> items = ui->macroTreeWidget->selectedItems();

  if (items.size() > 0)
  {
    if (items[0]->parent() == 0)
    {
      QMaemo5InformationBox::information(0, "Cannot Delete MacroPacks");
    }
    else
    {
      emit deleteMacroRequested(items[0]);
    }
  }

  accept();
}


void PIRSelectMacroDialog::resetIndices()
{
  ui->macroTreeWidget->setCurrentItem(
    ui->macroTreeWidget->topLevelItem(0));
}
