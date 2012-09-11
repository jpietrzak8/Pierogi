#include "pirmacroform.h"
#include "ui_pirmacroform.h"

//#include "mainwindow.h"
#include "macros/pirmacro.h"

class QTreeWidgetItem;
class MainWindow;

/*
PIRMacroForm::PIRMacroForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRMacroForm)
{
  ui->setupUi(this);
}
*/

PIRMacroForm::PIRMacroForm(
  MainWindow *mw)
  : QWidget(0),
    ui(new Ui::PIRMacroForm),
    smd(mw),
    ccd(mw),
    currentMacro(0)
{
  ui->setupUi(this);

  connect(
    &smd,
    SIGNAL(macroChosen(QTreeWidgetItem *)),
    this,
    SLOT(displayMacro(QTreeWidgetItem *)));
}

PIRMacroForm::~PIRMacroForm()
{
  delete ui;
}


void PIRMacroForm::on_chooseMacroButton_clicked()
{
  smd.exec();
}


void PIRMacroForm::on_runButton_clicked()
{
  currentMacro->executeMacro();
}


void PIRMacroForm::displayMacro(
  QTreeWidgetItem *item)
{
  if (!item) return;

  PIRMacro *m = dynamic_cast<PIRMacro *> (item);

  if (!m) return;

  currentMacro = m;

  currentMacro->populateList(ui->macroListWidget);
}


void PIRMacroForm::on_addButton_clicked()
{
  ccd.exec();
}
