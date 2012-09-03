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
#include "forms/pirinputform.h"
#include "forms/piradjustform.h"
#include "forms/pirairconditionerform.h"
#include "forms/piraudiodeviceform.h"
#include "forms/pirroombaform.h"

#include "mainwindow.h"

#include <QSettings>
#include <QDialogButtonBox>
#include <QPushButton>

// Debugging:
//#include <QMaemo5InformationBox>
//#include <iostream>

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
    inputForm(0),
    adjustForm(0),
    acForm(0),
    audioDeviceForm(0),
    roombaForm(0),
    altMainPanelFlag(false),
    currentTabsName(Universal_Tabs),
    mainWindow(mw)
{
  QSettings settings("pietrzak.org", "Pierogi");
  if (settings.contains("currentTabsName"))
  {
    currentTabsName = PIRTabBarName(settings.value("currentTabsName").toInt());
  }

  // Set up the panel names:
  shortPanelNames[Main_Panel] = "Main";
  longPanelNames[Main_Panel] =
    "Main Panel - power, volume, and channel controls";
  shortPanelNames[Utility_Panel] = "Utility";
  longPanelNames[Utility_Panel] = 
    "Utility Panel - commonly used controls";
  shortPanelNames[Keypad_Panel] = "Keypad";
  longPanelNames[Keypad_Panel] =
    "Keypad Panel - numeric value entry";
  shortPanelNames[Menu_Panel] = "Menu";
  longPanelNames[Menu_Panel] =
    "Menu Panel - enter, exit, and navigate menus";
  shortPanelNames[Media_Panel] = "Media";
  longPanelNames[Media_Panel] =
    "Media Panel - control over recorded data";
  shortPanelNames[Media2_Panel] = "Media2";
  longPanelNames[Media2_Panel] =
    "Media2 Panel - additonal media controls";
  shortPanelNames[Record_Panel] = "Record";
  longPanelNames[Record_Panel] =
    "Program/Record Panel - control over memory and storage";
  shortPanelNames[TV_Panel] = "TV";
  longPanelNames[TV_Panel] =
    "TV Panel - teletext and picture-in-picture";
  shortPanelNames[Input_Panel] = "Input";
  longPanelNames[Input_Panel] =
    "Input Panel - manage data sources";
  shortPanelNames[Adjust_Panel] = "Adjust";
  longPanelNames[Adjust_Panel] =
    "Adjust Panel - modify audio and video";
  shortPanelNames[AC_Panel] = "AC";
  longPanelNames[AC_Panel] =
    "A/C Panel - air conditioner controls";
  shortPanelNames[Audio_Panel] = "Audio";
  longPanelNames[Audio_Panel] =
    "Audio Device Panel - various audio related buttons";
  shortPanelNames[Roomba_Panel] = "Roomba";
  longPanelNames[Roomba_Panel] =
    "Roomba Panel - robotic vacuum cleaner controls";

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

  inputForm = new PIRInputForm(mainWindow);
  panels[Input_Panel] = inputForm;

  adjustForm = new PIRAdjustForm(mainWindow);
  panels[Adjust_Panel] = adjustForm;

  acForm = new PIRAirConditionerForm(mainWindow);
  panels[AC_Panel] = acForm;

  audioDeviceForm = new PIRAudioDeviceForm(mainWindow);
  panels[Audio_Panel] = audioDeviceForm;

  roombaForm = new PIRRoombaForm(mainWindow);
  panels[Roomba_Panel] = roombaForm;

  // Set up the panel collections:
  PIRPanelNameList pset;

  // The universal collection:
  pset.push_back(Main_Panel);
  pset.push_back(Utility_Panel);
  pset.push_back(Keypad_Panel);
  pset.push_back(Menu_Panel);
  pset.push_back(Media_Panel);
//  pset.push_back(Input_Panel);
  tabLists[Universal_Tabs] = pset;

  // The TV collection:
  pset.clear();
  pset.push_back(Main_Panel);
  pset.push_back(Utility_Panel);
  pset.push_back(Keypad_Panel);
  pset.push_back(Menu_Panel);
  pset.push_back(TV_Panel);
  pset.push_back(Adjust_Panel);
  tabLists[TV_Tabs] = pset;

  // The video media collection:
  pset.clear();
  pset.push_back(Main_Panel);
  pset.push_back(Menu_Panel);
  pset.push_back(Media_Panel);
  pset.push_back(Media2_Panel);
  pset.push_back(Input_Panel);
  tabLists[VideoMedia_Tabs] = pset;

  // Audio panel collection:
  pset.clear();
  pset.push_back(Main_Panel);
  pset.push_back(Keypad_Panel);
  pset.push_back(Media_Panel);
  pset.push_back(Audio_Panel);
  tabLists[Audio_Tabs] = pset;

  // The air conditioner collection:
  pset.clear();
  pset.push_back(AC_Panel);
  tabLists[AC_Tabs] = pset;

  // The recording collection:
  pset.clear();
  pset.push_back(Record_Panel);
  pset.push_back(Keypad_Panel);
  tabLists[Record_Tabs] = pset;

  // The Roomba collection:
  pset.clear();
  pset.push_back(Roomba_Panel);
  tabLists[Roomba_Tabs] = pset;
}


PIRPanelManager::~PIRPanelManager()
{
  // Note!  We are _not_ deleting the panel forms here, because the Qt GUI
  // has ownership over some of them.  Moreover, the Panel Manager is not
  // currently designed to be destroyed until the program ends.  Should the
  // manager need to be destroyed earlier, this destructor will need to be
  // changed!
}


void PIRPanelManager::updateTabSet()
{
  QSettings settings("pietrzak.org", "Pierogi");
  settings.setValue("currentTabsName", currentTabsName);

  mainWindow->disableUpdates();
  mainWindow->clearTabs();

  PIRPanelNameList::const_iterator i = tabLists[currentTabsName].begin();

  while (i != tabLists[currentTabsName].end())
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

  mainWindow->enableUpdates();
}


void PIRPanelManager::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  mainForm->enableButtons(keyset, id);
  altMainForm->enableButtons(keyset, id);
  commonEnableButtons(keyset, id);
}


void PIRPanelManager::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int currentID,
  unsigned int defaultID)
{
  mainForm->enableButtons(keyset, currentID, defaultID);
  altMainForm->enableButtons(keyset, currentID, defaultID);
  commonEnableButtons(keyset, currentID);
}


void PIRPanelManager::commonEnableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  utilityForm->enableButtons(keyset, id);
  keypadForm->enableButtons(keyset, id);
  menuForm->enableButtons(keyset, id);
  mediaForm->enableButtons(keyset, id);
  media2Form->enableButtons(keyset, id);
  recordForm->enableButtons(keyset, id);
  tvForm->enableButtons(keyset, id);
  inputForm->enableButtons(keyset, id);
  adjustForm->enableButtons(keyset, id);
  acForm->enableButtons(keyset, id);
  audioDeviceForm->enableButtons(keyset, id);
  roombaForm->enableButtons(keyset, id);
}


void PIRPanelManager::useMainPanel()
{
  if (!altMainPanelFlag)
  {
    // Already set correctly, nothing to do:
    return;
  }

  altMainPanelFlag = false;

  updateTabSet();
}


void PIRPanelManager::useAltMainPanel()
{
  if (altMainPanelFlag)
  {
    // Already set correctly, nothing to do:
    return;
  }

  altMainPanelFlag = true;

  updateTabSet();
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


void PIRPanelManager::setupTabs(
  PIRTabBarName name)
{
  if (currentTabsName == name) return;

  currentTabsName = name;
  updateTabSet();
}
