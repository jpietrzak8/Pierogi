#include "pirtabschoicedialog.h"
#include "ui_pirtabschoicedialog.h"

#include "pirtabswidgetitem.h"
#include "mainwindow.h"

PIRTabsChoiceDialog::PIRTabsChoiceDialog(
  MainWindow *mw)
  : QDialog(0),
    ui(new Ui::PIRTabsChoiceDialog),
    mainWindow(mw)
{
  ui->setupUi(this);

  ui->tabsChoiceListWidget->addItem(
    new PIRTabsWidgetItem("Universal Panels", Universal_Tabs));

  ui->tabsChoiceListWidget->addItem(
    new PIRTabsWidgetItem("Television Panels", TV_Tabs));

  ui->tabsChoiceListWidget->addItem(
    new PIRTabsWidgetItem("Video Media Panels", VideoMedia_Tabs));

  ui->tabsChoiceListWidget->addItem(
    new PIRTabsWidgetItem("Audio Device Panels", Audio_Tabs));

  ui->tabsChoiceListWidget->addItem(
    new PIRTabsWidgetItem("Recording Panels", Record_Tabs));

  ui->tabsChoiceListWidget->addItem(
    new PIRTabsWidgetItem("Air Conditioner Panels", AC_Tabs));

  ui->tabsChoiceListWidget->addItem(
    new PIRTabsWidgetItem("Camera Panels", Camera_Tabs));

  ui->tabsChoiceListWidget->addItem(
    new PIRTabsWidgetItem("Roomba Panels", Roomba_Tabs));

  ui->tabsChoiceListWidget->addItem(
    new PIRTabsWidgetItem("Macro Panels", Macro_Tabs));

//  ui->tabsChoiceListWidget->addItem(
//    new PIRTabsWidgetItem("Keyset Search Panels", PowerSearch_Tabs));

  ui->tabsChoiceListWidget->addItem(
    new PIRTabsWidgetItem("Advanced Settings", Advanced_Tabs));
}


PIRTabsChoiceDialog::~PIRTabsChoiceDialog()
{
  delete ui;
}


void PIRTabsChoiceDialog::on_tabsChoiceListWidget_itemClicked(
  QListWidgetItem *item)
{
  PIRTabsWidgetItem *twi = dynamic_cast<PIRTabsWidgetItem *> (item);

  mainWindow->setupTabs(twi->getTabBarName());

  // Exit from the dialog:
  accept();
}
