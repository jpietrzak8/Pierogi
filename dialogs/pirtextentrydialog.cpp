#include "pirtextentrydialog.h"
#include "ui_pirtextentrydialog.h"

PIRTextEntryDialog::PIRTextEntryDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::PIRTextEntryDialog)
{
  ui->setupUi(this);
}

PIRTextEntryDialog::~PIRTextEntryDialog()
{
  delete ui;
}
