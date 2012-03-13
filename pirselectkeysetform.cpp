#include "pirselectkeysetform.h"
#include "ui_pirselectkeysetform.h"
#include "pirkeysetwidgetitem.h"
//#include <QListWidget>
#include <QKeyEvent>

extern PIRMakeMgr makeManager;

PIRSelectKeysetForm::PIRSelectKeysetForm(
  QWidget *parent)
  : QWidget(parent),
    ui(new Ui::PIRSelectKeysetForm),
    currentMake(Any_Make)
{
  ui->setupUi(this);

  // Don't want to start with the line editor visible:
  ui->searchStringLineEdit->hide();
  ui->searchStringLineEdit->lower();
  ui->ssClosePushButton->hide();

  // Set some initial flags:
  setAttribute(Qt::WA_Maemo5StackedWindow);
  setWindowFlags(windowFlags() | Qt::Window);

  // push the list of makers into the make combo box:
  makeManager.populateComboBox(ui->makeComboBox);

  // Connection telling main window that keyset has been selected:
  connect(
    ui->keysetListWidget,
    SIGNAL(itemActivated(QListWidgetItem *)),
    parent,
    SLOT(keysetSelectionChanged(QListWidgetItem *)),
    Qt::QueuedConnection);

  // Connection used to filter keyset list:
  connect(
    ui->makeComboBox,
    SIGNAL(currentIndexChanged(int)),
    this,
    SLOT(filterListByMake(int)),
    Qt::QueuedConnection);
}


PIRSelectKeysetForm::~PIRSelectKeysetForm()
{
  delete ui;
}


/*
void PIRSelectKeysetForm::addNameToList(
  QString name,
  unsigned int index,
  PIRMakeName make)
{
  ui->keysetListWidget->addItem(new PIRKeysetWidgetItem(name, index, make));
}
*/


void PIRSelectKeysetForm::addWidgetItem(
  PIRKeysetWidgetItem *kwi)
{
  ui->keysetListWidget->addItem(kwi);
}


QListWidget *PIRSelectKeysetForm::getKeysetListWidget()
{
  return ui->keysetListWidget;
}


void PIRSelectKeysetForm::keyPressEvent(
  QKeyEvent *event)
{
  ui->searchStringLineEdit->show();
  ui->searchStringLineEdit->raise();
  ui->ssClosePushButton->show();

  ui->searchStringLineEdit->setText(event->text());
  ui->searchStringLineEdit->setFocus();
}


void PIRSelectKeysetForm::on_searchStringLineEdit_textChanged(
  const QString &arg1)
{
  filterListByString(arg1);
}


void PIRSelectKeysetForm::on_ssClosePushButton_clicked()
{
  ui->searchStringLineEdit->hide();
  ui->searchStringLineEdit->lower();
  ui->ssClosePushButton->hide();
  ui->searchStringLineEdit->clear();
}


void PIRSelectKeysetForm::filterListByMake(
  int make)
{
  currentMake = (PIRMakeName) make;
  refilterList();
}


void PIRSelectKeysetForm::filterListByString(
  QString string)
{
  searchString = string;
  refilterList();
}


void PIRSelectKeysetForm::refilterList()
{
  int index = 0;
  int count = ui->keysetListWidget->count();
  PIRKeysetWidgetItem *item;
  while (index < count)
  {
    item = dynamic_cast<PIRKeysetWidgetItem *>(
      ui->keysetListWidget->item(index));

    // Does the keylist have the required make?
    if ((currentMake == Any_Make) || (item->getMake() == currentMake))
    {
      // Does this keylist match the search string?
      if ( searchString.isEmpty()
        || item->text().contains(searchString, Qt::CaseInsensitive))
      {
        // Yes, we can show this keylist:
        item->setHidden(false);
      }
      else
      {
        item->setHidden(true);
      }
    }
    else
    {
      item->setHidden(true);
    }

    ++index;
  }
}
