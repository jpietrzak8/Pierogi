#include "pirselectdeviceform.h"
#include "ui_pirselectdeviceform.h"
#include "pirkeysetwidgetitem.h"

extern PIRMakeMgr makeManager;
extern PIRDeviceTypeMgr deviceManager;

PIRSelectDeviceForm::PIRSelectDeviceForm(
  QWidget *parent)
  : QWidget(parent),
    ui(new Ui::PIRSelectDeviceForm),
    currentMake(Any_Make),
    currentDevice(Any_Device)
{
  ui->setupUi(this);

  setAttribute(Qt::WA_Maemo5StackedWindow);
  setWindowFlags(windowFlags() | Qt::Window);

  // push the list of makers into the make combo box:
  makeManager.populateComboBox(ui->makeComboBox);
  deviceManager.populateComboBox(ui->deviceComboBox);

  // Connection telling main window that keyset has been selected:
  connect(
    ui->deviceListWidget,
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

  connect(
    ui->deviceComboBox,
    SIGNAL(currentIndexChanged(int)),
    this,
    SLOT(filterListByDeviceType(int)),
    Qt::QueuedConnection);
}

PIRSelectDeviceForm::~PIRSelectDeviceForm()
{
  delete ui;
}

void PIRSelectDeviceForm::addNameToList(
  QString name,
  unsigned int index,
  PIRMakeName make)
{
  ui->deviceListWidget->addItem(new PIRKeysetWidgetItem(name, index, make));
}

void PIRSelectDeviceForm::addWidgetItem(
  PIRKeysetWidgetItem *kwi)
{
  ui->deviceListWidget->addItem(kwi);
}

QListWidget *PIRSelectDeviceForm::getDeviceListWidget()
{
  return ui->deviceListWidget;
}

void PIRSelectDeviceForm::filterListByMake(
  int make)
{
  currentMake = (PIRMakeName) make;
  refilterList();
}

void PIRSelectDeviceForm::filterListByDeviceType(
  int deviceType)
{
  currentDevice = (PIRDeviceTypeName) deviceType;
  refilterList();
}

void PIRSelectDeviceForm::refilterList()
{
  int index = 0;
  int count = ui->deviceListWidget->count();
  PIRKeysetWidgetItem *item;
  while (index < count)
  {
    item = dynamic_cast<PIRKeysetWidgetItem *>(
      ui->deviceListWidget->item(index));

    // Does the keylist have the required make?
    if ((currentMake == Any_Make) || (item->getMake() == currentMake))
    {
      // And does it have the required type?
      if ( (currentDevice == Any_Device)
        || (item->getDeviceType() == currentDevice))
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
