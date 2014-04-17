//
// pirpanelmanager.cpp
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

#include "pirpanelmanager.h"

#include "forms/pirmainform.h"
#include "forms/piraltmainform.h"
#include "forms/pirutilityform.h"
#include "forms/pirkeypadform.h"
#include "forms/pirmenuform.h"
#include "forms/pirmediaform.h"
#include "forms/pirmedia2form.h"
#include "forms/pirrecordform.h"
#include "forms/pirtvform.h"
#include "forms/pirreceiverform.h"
#include "forms/pirinputform.h"
#include "forms/pirinputlistform.h"
#include "forms/piradjustform.h"
#include "forms/pirairconditionerform.h"
#include "forms/pirstatefulacform.h"
#include "forms/piractimerform.h"
#include "forms/piraudiodeviceform.h"
#include "forms/pircameraform.h"
#include "forms/pirintervalometerform.h"
#include "forms/pirroombaform.h"
#include "forms/pirplaystationform.h"
#include "forms/piruserform.h"
//#include "forms/pirmacroform.h"
//#include "forms/pirpowersearchform.h"
//#include "forms/piradvancedform.h"

#include "mainwindow.h"

#include <QSettings>
#include <QDialogButtonBox>
#include <QPushButton>

// Debugging:
//#include <QMaemo5InformationBox>
#include <iostream>

PIRPanelManager::PIRPanelManager(
  MainWindow *mw):
    mainForm(0),
    altMainForm(0),
    utilityForm(0),
    keypadForm(0),
    menuForm(0),
    mediaForm(0),
    media2Form(0),
    recordForm(0),
    tvForm(0),
    receiverForm(0),
    inputForm(0),
    inputListForm(0),
    adjustForm(0),
    acForm(0),
    statefulACForm(0),
    acTimerForm(0),
    audioDeviceForm(0),
    cameraForm(0),
    intervalometerForm(0),
    roombaForm(0),
    playstationForm(0),
    userForm(0),
//    macroForm(0),
//    powerSearchForm(0),
//    advancedForm(0),
    altMainPanelFlag(false),
    mainWindow(mw)
{
  // Set up the panel names:
  shortPanelNames[Main_Panel] = MainWindow::tr("Main");
  longPanelNames[Main_Panel] =
    MainWindow::tr("Main Panel - power, volume, and channel controls");
  shortPanelNames[Utility_Panel] = MainWindow::tr("Utility");
  longPanelNames[Utility_Panel] = 
    MainWindow::tr("Utility Panel - commonly used controls");
  shortPanelNames[Keypad_Panel] = MainWindow::tr("Keypad");
  longPanelNames[Keypad_Panel] =
    MainWindow::tr("Keypad Panel - numeric value entry");
  shortPanelNames[Menu_Panel] = MainWindow::tr("Menu");
  longPanelNames[Menu_Panel] =
    MainWindow::tr("Menu Panel - enter, exit, and navigate menus");
  shortPanelNames[Media_Panel] = MainWindow::tr("Media");
  longPanelNames[Media_Panel] =
    MainWindow::tr("Media Panel - control over recorded data");
  shortPanelNames[Media2_Panel] = MainWindow::tr("Media2");
  longPanelNames[Media2_Panel] =
    MainWindow::tr("Media2 Panel - additonal media controls");
  shortPanelNames[Record_Panel] = MainWindow::tr("Record");
  longPanelNames[Record_Panel] =
    MainWindow::tr("Program/Record Panel - control over memory and storage");
  shortPanelNames[TV_Panel] = MainWindow::tr("TV");
  longPanelNames[TV_Panel] =
    MainWindow::tr("TV Panel - teletext and picture-in-picture");
  shortPanelNames[Receiver_Panel] = MainWindow::tr("Receiver");
  longPanelNames[Receiver_Panel] =
    MainWindow::tr("Receiver Panel - main controls for receivers");
  shortPanelNames[Input_Panel] = MainWindow::tr("Input");
  longPanelNames[Input_Panel] =
    MainWindow::tr("Input Panel - manage data sources");
  shortPanelNames[InputList_Panel] = MainWindow::tr("Input");
  longPanelNames[InputList_Panel] =
    MainWindow::tr("Input Panel - manage data sources");
  shortPanelNames[Adjust_Panel] = MainWindow::tr("Adjust");
  longPanelNames[Adjust_Panel] =
    MainWindow::tr("Adjust Panel - modify audio and video");
  shortPanelNames[AC_Panel] = MainWindow::tr("A/C General");
  longPanelNames[AC_Panel] =
    MainWindow::tr("A/C Panel - air conditioner controls");
  shortPanelNames[StatefulAC_Panel] = MainWindow::tr("A/C General");
  longPanelNames[StatefulAC_Panel] =
    MainWindow::tr("Stateful A/C Panel - for A/C remotes with LCD screens");
  shortPanelNames[ACTimer_Panel] = MainWindow::tr("A/C Timer");
  longPanelNames[ACTimer_Panel] =
    MainWindow::tr("A/C Timer Panel - set (or cancel) the on/off timer");
  shortPanelNames[Audio_Panel] = MainWindow::tr("Audio");
  longPanelNames[Audio_Panel] =
    MainWindow::tr("Audio Device Panel - various audio related buttons");
  shortPanelNames[Camera_Panel] = MainWindow::tr("Camera");
  longPanelNames[Camera_Panel] =
    MainWindow::tr("Camera Panel - simple shutter controls");
  shortPanelNames[Intervalometer_Panel] = MainWindow::tr("Intervalometer");
  longPanelNames[Intervalometer_Panel] =
    MainWindow::tr("Intervalometer Panel - for time-lapse photography");
  shortPanelNames[Roomba_Panel] = MainWindow::tr("Roomba");
  longPanelNames[Roomba_Panel] =
    MainWindow::tr("Roomba Panel - robotic vacuum cleaner controls");
  shortPanelNames[Playstation_Panel] = MainWindow::tr("Playstation");
  longPanelNames[Playstation_Panel] =
    MainWindow::tr("Playstation Panel - support for gamepad buttons");
  shortPanelNames[User_Panel] = MainWindow::tr("Macros");
  longPanelNames[User_Panel] =
    MainWindow::tr("Macro Panel - macro control buttons");
//  shortPanelNames[Macro_Panel] = MainWindow::tr("Edit Macro Contents");
//  longPanelNames[Macro_Panel] =
//    MainWindow::tr("Edit Macros Panel - create, delete, edit, and manage macros");
//  shortPanelNames[PowerSearch_Panel] = "Keyset Search";
//  longPanelNames[PowerSearch_Panel] =
//    "Keyset Search Panel - execute power button in each keyset";
//  shortPanelNames[Advanced_Panel] = "Advanced Settings";
//  longPanelNames[Advanced_Panel] =
//    "Advanced Settings - allows adjustment of protocol settings";

  mainForm = new PIRMainForm(mainWindow);
  panels[Main_Panel] = mainForm;

  altMainForm = new PIRAltMainForm(mainWindow);
  panels[Alt_Main_Panel] = altMainForm;

  utilityForm = new PIRUtilityForm(mainWindow);
  panels[Utility_Panel] = utilityForm;

  keypadForm = new PIRKeypadForm(mainWindow);
  panels[Keypad_Panel] = keypadForm;

  menuForm = new PIRMenuForm(mainWindow);
  panels[Menu_Panel] = menuForm;

  mediaForm = new PIRMediaForm(mainWindow);
  panels[Media_Panel] = mediaForm;

  media2Form = new PIRMedia2Form(mainWindow);
  panels[Media2_Panel] = media2Form;

  recordForm = new PIRRecordForm(mainWindow);
  panels[Record_Panel] = recordForm;

  tvForm = new PIRTVForm(mainWindow);
  panels[TV_Panel] = tvForm;

  receiverForm = new PIRReceiverForm(mainWindow);
  panels[Receiver_Panel] = receiverForm;

  inputForm = new PIRInputForm(mainWindow);
  panels[Input_Panel] = inputForm;

  inputListForm = new PIRInputListForm(mainWindow);
  panels[InputList_Panel] = inputListForm;

  adjustForm = new PIRAdjustForm(mainWindow);
  panels[Adjust_Panel] = adjustForm;

  acForm = new PIRAirConditionerForm(mainWindow);
  panels[AC_Panel] = acForm;

  statefulACForm = new PIRStatefulACForm(mainWindow);
  panels[StatefulAC_Panel] = statefulACForm;

  acTimerForm = new PIRACTimerForm(mainWindow);
  panels[ACTimer_Panel] = acTimerForm;

  audioDeviceForm = new PIRAudioDeviceForm(mainWindow);
  panels[Audio_Panel] = audioDeviceForm;

  cameraForm = new PIRCameraForm(mainWindow);
  panels[Camera_Panel] = cameraForm;

  intervalometerForm = new PIRIntervalometerForm(mainWindow);
  panels[Intervalometer_Panel] = intervalometerForm;

  roombaForm = new PIRRoombaForm(mainWindow);
  panels[Roomba_Panel] = roombaForm;

  playstationForm = new PIRPlaystationForm(mainWindow);
  panels[Playstation_Panel] = playstationForm;

  userForm = new PIRUserForm(mainWindow);
  panels[User_Panel] = userForm;

//  macroForm = new PIRMacroForm(mainWindow);
//  panels[Macro_Panel] = macroForm;

//  powerSearchForm = new PIRPowerSearchForm(mainWindow);
//  panels[PowerSearch_Panel] = powerSearchForm;

//  advancedForm = new PIRAdvancedForm();
//  panels[Advanced_Panel] = advancedForm;

  // Set up the panel collections:
  PIRPanelNameList pset;

  // The universal collection:
  pset.push_back(Main_Panel);
  pset.push_back(Utility_Panel);
  pset.push_back(Keypad_Panel);
  pset.push_back(Menu_Panel);
  pset.push_back(Media_Panel);
  pset.push_back(User_Panel);
//  pset.push_back(Input_Panel);
  tabLists[Universal_Tabs] = pset;

  // The TV collection:
  pset.clear();
  pset.push_back(Main_Panel);
  pset.push_back(Utility_Panel);
  pset.push_back(Keypad_Panel);
  pset.push_back(Menu_Panel);
  pset.push_back(TV_Panel);
//  pset.push_back(Input_Panel);
  pset.push_back(InputList_Panel);
  tabLists[TV_Tabs] = pset;

  // The video media collection:
  pset.clear();
  pset.push_back(Main_Panel);
  pset.push_back(Menu_Panel);
  pset.push_back(Media_Panel);
  pset.push_back(Media2_Panel);
//  pset.push_back(Input_Panel);
  pset.push_back(InputList_Panel);
  pset.push_back(Adjust_Panel);
  tabLists[VideoMedia_Tabs] = pset;

  // Audio panel collection:
  pset.clear();
//  pset.push_back(Main_Panel);
  pset.push_back(Receiver_Panel);
  pset.push_back(Keypad_Panel);
  pset.push_back(Media_Panel);
  pset.push_back(Audio_Panel);
  pset.push_back(InputList_Panel);
  tabLists[Audio_Tabs] = pset;

  // The standard air conditioner collection:
  pset.clear();
  pset.push_back(AC_Panel);
  tabLists[StandardAC_Tabs] = pset;

  // The stateful air conditioner collection:
  pset.clear();
  pset.push_back(StatefulAC_Panel);
  pset.push_back(ACTimer_Panel);
  tabLists[StatefulAC_Tabs] = pset;

  // The recording collection:
  pset.clear();
  pset.push_back(Record_Panel);
  pset.push_back(Keypad_Panel);
  tabLists[Record_Tabs] = pset;

  // The camera control collection:
  pset.clear();
  pset.push_back(Camera_Panel);
  pset.push_back(Intervalometer_Panel);
  tabLists[Camera_Tabs] = pset;

  // The Roomba collection:
  pset.clear();
  pset.push_back(Roomba_Panel);
  tabLists[Roomba_Tabs] = pset;

  // The Console collection:
  pset.clear();
  pset.push_back(Playstation_Panel);
  tabLists[Console_Tabs] = pset;

  // The Macro Management collection:
//  pset.clear();
//  pset.push_back(Macro_Panel);
//  tabLists[Macro_Tabs] = pset;

  // The Power Search collection:
//  pset.clear();
//  pset.push_back(PowerSearch_Panel);
//  tabLists[PowerSearch_Tabs] = pset;

  // The Advanced Settings collection:
//  pset.clear();
//  pset.push_back(Advanced_Panel);
//  tabLists[Advanced_Tabs] = pset;
}


PIRPanelManager::~PIRPanelManager()
{
  // Note!  We are _not_ deleting the panel forms here, because the Qt GUI
  // has ownership over some of them.  Moreover, the Panel Manager is not
  // currently designed to be destroyed until the program ends.  Should the
  // manager need to be destroyed earlier, this destructor will need to be
  // changed!
}


void PIRPanelManager::setupTabs(
  PIRTabBarName tabsName)
{
//  mainWindow->disableUpdates();
//  mainWindow->clearTabs();

  PIRPanelNameList::const_iterator i = tabLists[tabsName].begin();

  while (i != tabLists[tabsName].end())
  {
    if ((*i == Main_Panel) && altMainPanelFlag)
    {
      mainWindow->addTab(altMainForm, shortPanelNames[Main_Panel]);
    }
    else
    {
      mainWindow->addTab(panels[*i], shortPanelNames[*i]);
    }

    ++i;
  }

//  mainWindow->enableUpdates();
}


void PIRPanelManager::enableButtons(
  PIRKeysetManager *keyset,
  unsigned int id)
{
  mainForm->enableButtons(keyset, id);
  altMainForm->enableButtons(keyset, id);
  commonEnableButtons(keyset, id);
}


void PIRPanelManager::enableButtons(
  PIRKeysetManager *keyset,
  unsigned int currentID,
  unsigned int defaultID)
{
  mainForm->enableButtons(keyset, currentID, defaultID);
  altMainForm->enableButtons(keyset, currentID, defaultID);
  commonEnableButtons(keyset, currentID);
}


void PIRPanelManager::commonEnableButtons(
  PIRKeysetManager *keyset,
  unsigned int id)
{
  utilityForm->enableButtons(keyset, id);
  keypadForm->enableButtons(keyset, id);
  menuForm->enableButtons(keyset, id);
  mediaForm->enableButtons(keyset, id);
  media2Form->enableButtons(keyset, id);
  recordForm->enableButtons(keyset, id);
  tvForm->enableButtons(keyset, id);
  receiverForm->enableButtons(keyset, id);
  inputForm->enableButtons(keyset, id);
  inputListForm->enableButtons(keyset, id);
  adjustForm->enableButtons(keyset, id);
  acForm->enableButtons(keyset, id);
  statefulACForm->enableButtons(keyset, id);
  acTimerForm->enableButtons(keyset, id);
  audioDeviceForm->enableButtons(keyset, id);
  cameraForm->enableButtons(keyset, id);
  intervalometerForm->enableButtons(keyset, id);
  roombaForm->enableButtons(keyset, id);
  playstationForm->enableButtons(keyset, id);

  // Also, set the label in the power search form:
//  powerSearchForm->setKeysetName(mainWindow->getCurrentFullName());

  // Set up the advanced parameters:
//  advancedForm->setupForm(keyset, id);
}


void PIRPanelManager::updateUserButtons()
{
  userForm->setupButtons();
}


void PIRPanelManager::useMainPanel()
{
  if (!altMainPanelFlag)
  {
    // Already set correctly, nothing to do:
    return;
  }

  altMainPanelFlag = false;

//  updateTabSet();
}


void PIRPanelManager::useAltMainPanel()
{
  if (altMainPanelFlag)
  {
    // Already set correctly, nothing to do:
    return;
  }

  altMainPanelFlag = true;

//  updateTabSet();
}


/*
void PIRPanelManager::setupUniversalTabs()
{
  if (currentTabsName == Universal_Tabs) return;

  currentTabsName = Universal_Tabs;
  updateTabSet();
}


void PIRPanelManager::setupTVTabs()
{
  if (currentTabsName == TV_Tabs) return;

  currentTabsName = TV_Tabs;
  updateTabSet();
}


void PIRPanelManager::setupVideoTabs()
{
  if (currentTabsName == VideoMedia_Tabs) return;

  currentTabsName = VideoMedia_Tabs;
  updateTabSet();
}


void PIRPanelManager::setupACTabs()
{
  if (currentTabsName == AC_Tabs) return;

  currentTabsName = AC_Tabs;
  updateTabSet();
}


void PIRPanelManager::setupRecordTabs()
{
  if (currentTabsName == Record_Tabs) return;

  currentTabsName = Record_Tabs;
  updateTabSet();
}
*/


/*
void PIRPanelManager::setupTabs(
  PIRTabBarName name)
{
  if (currentTabsName == name) return;

  currentTabsName = name;
  updateTabSet();
}
*/

/*
void PIRPanelManager::gotoPreviousTabs()
{
  PIRTabsCollection::const_iterator i = tabLists.find(currentTabsName);

  if (i == tabLists.end())
  {
    // Couldn't find currentTabsName!  Throw an error here?
    return;
  }

  if (i == tabLists.begin())
  {
    // Already at first collection, nothing to do:
    return;
  }

  --i;
  currentTabsName = i->first;
  updateTabSet();
}


void PIRPanelManager::gotoNextTabs()
{
  PIRTabsCollection::const_iterator i = tabLists.find(currentTabsName);

  if (i == tabLists.end())
  {
    // Couldn't find currentTabsName!  Throw an error?
    return;
  }

  ++i;

  if (i == tabLists.end())
  {
    // We're already at the last collection, nothing to do:
    return;
  }

  currentTabsName = i->first;
  updateTabSet();
}
*/


/*
QComboBox *PIRPanelManager::getKeysetComboBox()
{
  return macroForm->getKeysetComboBox();
}
*/
