#include "selectionwindow.h"
#include "pirkeysetwidgetitem.h"

#include <QString>

#include "pirexception.h"

extern PIRMakeMgr makeManager;

SelectionWindow::SelectionWindow(
  QWidget *parent)
  : QWidget(parent)
{
  // This widget will be the window holding everything else.
  setAttribute(Qt::WA_Maemo5StackedWindow);
  setWindowFlags(windowFlags() | Qt::Window);
  setFixedSize(800, 445);

  // First things first, need a QList of some sort to display the names:
  nameListWidget = new QListWidget();

  // Now, some filters:
//  deviceTypeLabel = new QLabel("Filter by Device Type:");
//  deviceTypeComboBox = new QComboBox();
//  deviceTypeComboBox->insertItem(0, QString("Any"));
  makeLabel = new QLabel("Make:");
//  makeLabel->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
  makeComboBox = new QComboBox();
  makeComboBox->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
  makeManager.populateComboBox(makeComboBox);
//  makeComboBox->insertItem(0, QString("Any"));

  layout = new QGridLayout;
//  layout->addWidget(deviceTypeLabel, 0, 0);
//  layout->addWidget(deviceTypeComboBox, 1, 0);
  layout->addWidget(makeLabel, 0, 0);
  layout->addWidget(makeComboBox, 0, 1);
  layout->addWidget(nameListWidget, 1, 0, 1, 2);

  setLayout(layout);

  connect(
    nameListWidget,
    SIGNAL(itemActivated(QListWidgetItem *)),
    parent,
    SLOT(keysetSelectionChanged(QListWidgetItem *)),
    Qt::QueuedConnection);

  connect(
    makeComboBox,
    SIGNAL(currentIndexChanged(int)),
    this,
    SLOT(filterListByMake(int)),
    Qt::QueuedConnection);
}


SelectionWindow::~SelectionWindow()
{
//  if (deviceTypeLabel) delete deviceTypeLabel;
//  if (deviceTypeComboBox) delete deviceTypeComboBox;
  if (makeLabel) delete makeLabel;
  if (makeComboBox) delete makeComboBox;
  if (layout) delete layout;
  if (nameListWidget) delete nameListWidget;
}


void SelectionWindow::addNameToList(
  QString name,
  unsigned int index,
  PIRMakeName make)
{
  nameListWidget->addItem(new PIRKeysetWidgetItem(name, index, make));
}


void SelectionWindow::filterListByMake(
  int make)
{
  int index = 0;
  int count = nameListWidget->count();
  PIRKeysetWidgetItem *item;
  while (index < count)
  {
    item = dynamic_cast<PIRKeysetWidgetItem *>(nameListWidget->item(index));
    if ((make == Any_Make) || (item->getMake() == make))
    {
      item->setHidden(false);
    }
    else
    {
      item->setHidden(true);
    }

    ++index;
  }
}

