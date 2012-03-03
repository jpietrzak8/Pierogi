#include "pirselectkeysetform.h"
#include "ui_pirselectkeysetform.h"
#include "pirkeysetwidgetitem.h"
#include <QListWidget>

extern PIRMakeMgr makeManager;

PIRSelectKeysetForm::PIRSelectKeysetForm(
  QWidget *parent)
  : QWidget(parent),
    ui(new Ui::PIRSelectKeysetForm),
    currentMake(Any_Make)
{
  ui->setupUi(this);

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

void PIRSelectKeysetForm::filterListByMake(
  int make)
{
  currentMake = (PIRMakeName) make;
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
      // Yes, we can show this keylist:
      item->setHidden(false);
    }
    else
    {
      item->setHidden(true);
    }

    ++index;
  }
}
