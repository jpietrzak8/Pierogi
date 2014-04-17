//
// pirtabschoicedialog.cpp
//
// Copyright 2012, 2013 by John Pietrzak (jpietrzak8@gmail.com)
//
// This file is part of Pierogi.
//
// Pierogi is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// Pierogi is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

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
    new PIRTabsWidgetItem("Standard A/C Panels", StandardAC_Tabs));

  ui->tabsChoiceListWidget->addItem(
    new PIRTabsWidgetItem("Stateful A/C Panels", StatefulAC_Tabs));

  ui->tabsChoiceListWidget->addItem(
    new PIRTabsWidgetItem("Camera Panels", Camera_Tabs));

  ui->tabsChoiceListWidget->addItem(
    new PIRTabsWidgetItem("Roomba Panels", Roomba_Tabs));

  ui->tabsChoiceListWidget->addItem(
    new PIRTabsWidgetItem("Game Console Panels", Console_Tabs));

//  ui->tabsChoiceListWidget->addItem(
//    new PIRTabsWidgetItem("Macro Panels", Macro_Tabs));

//  ui->tabsChoiceListWidget->addItem(
//    new PIRTabsWidgetItem("Keyset Search Panels", PowerSearch_Tabs));

//  ui->tabsChoiceListWidget->addItem(
//    new PIRTabsWidgetItem("Advanced Settings", Advanced_Tabs));
}


PIRTabsChoiceDialog::~PIRTabsChoiceDialog()
{
  delete ui;
}


void PIRTabsChoiceDialog::switchToTabBar(
  PIRTabBarName name)
{
  // This is a cheap hack, just wanted to get it out quickly:
  switch (name)
  {
  case Universal_Tabs:
    ui->tabsChoiceListWidget->setCurrentRow(0);
    break;

  case TV_Tabs:
    ui->tabsChoiceListWidget->setCurrentRow(1);
    break;

  case VideoMedia_Tabs:
    ui->tabsChoiceListWidget->setCurrentRow(2);
    break;

  case Audio_Tabs:
    ui->tabsChoiceListWidget->setCurrentRow(3);
    break;

  case Record_Tabs:
    ui->tabsChoiceListWidget->setCurrentRow(4);
    break;

  case StandardAC_Tabs:
    ui->tabsChoiceListWidget->setCurrentRow(5);
    break;

  case StatefulAC_Tabs:
    ui->tabsChoiceListWidget->setCurrentRow(6);
    break;

  case Camera_Tabs:
    ui->tabsChoiceListWidget->setCurrentRow(7);
    break;

  case Roomba_Tabs:
    ui->tabsChoiceListWidget->setCurrentRow(8);
    break;

  case Console_Tabs:
    ui->tabsChoiceListWidget->setCurrentRow(9);
    break;

//  case Macro_Tabs:
//    ui->tabsChoiceListWidget->setCurrentRow(10);
//    break;

//  case Advanced_Tabs:
//    ui->tabsChoiceListWidget->setCurrentRow(11);
//    break;

  default:
    // Leave it as is.
    break;
  }
}


void PIRTabsChoiceDialog::on_tabsChoiceListWidget_itemClicked(
  QListWidgetItem *item)
{
  PIRTabsWidgetItem *twi = dynamic_cast<PIRTabsWidgetItem *> (item);

  mainWindow->setupTabs(twi->getTabBarName());

  // Exit from the dialog:
  accept();
}
