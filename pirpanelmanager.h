//
// pirpanelmanager.h
//
// Copyright 2012, 2013 by John Pietrzak  (jpietrzak8@gmail.com)
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

#ifndef PIRPANELMANAGER_H
#define PIRPANELMANAGER_H

#include "pirpanelnames.h"

class PIRMainForm;
class PIRAltMainForm;
class PIRUtilityForm;
class PIRKeypadForm;
class PIRMenuForm;
class PIRMediaForm;
class PIRMedia2Form;
class PIRRecordForm;
class PIRTVForm;
class PIRInputForm;
class PIRAdjustForm;
class PIRAirConditionerForm;
class PIRStatefulACForm;
class PIRACTimerForm;
class PIRAudioDeviceForm;
class PIRCameraForm;
class PIRIntervalometerForm;
class PIRRoombaForm;
class PIRPlaystationForm;
class PIRUserForm;

// These need to go elsewhere:
class PIRMacroForm;
//class PIRPowerSearchForm;
//class PIRAdvancedForm;

class PIRKeysetWidgetItem;
class PIRKeysetManager;
class QListWidget;
class QComboBox;
class MainWindow;

#include <list>
#include <map>
#include <QString>
#include <QWidget>

typedef std::list<PIRPanelName> PIRPanelNameList;
typedef std::map<PIRTabBarName, PIRPanelNameList> PIRTabsCollection;

typedef std::map<PIRPanelName, QWidget *> PIRPanelCollection;
typedef std::map<PIRPanelName, QString> PIRPanelDisplayNameCollection;
typedef std::map<QString, PIRPanelName> PIRReversePanelIndex;

class PIRPanelManager
{
public:
  PIRPanelManager(
    MainWindow *mw);

  ~PIRPanelManager();

//  void updateTabSet();
  void setupTabs(PIRTabBarName name);

  void enableButtons(
    PIRKeysetManager *keyset,
    unsigned int id);

  void enableButtons(
    PIRKeysetManager *keyset,
    unsigned int currentID,
    unsigned int defaultID);

  void updateUserButtons();

  void useMainPanel();
  void useAltMainPanel();

/*
  void setupUniversalTabs();
  void setupTVTabs();
  void setupVideoTabs();
  void setupACTabs();
  void setupRecordTabs();
*/

  QComboBox *getKeysetComboBox();

//  void gotoPreviousTabs();
//  void gotoNextTabs();

private:
  void commonEnableButtons(
    PIRKeysetManager *keyset,
    unsigned int id);

  PIRMainForm *mainForm;
  PIRAltMainForm *altMainForm;
  PIRUtilityForm *utilityForm;
  PIRKeypadForm *keypadForm;
  PIRMenuForm *menuForm;
  PIRMediaForm *mediaForm;
  PIRMedia2Form *media2Form;
  PIRRecordForm *recordForm;
  PIRTVForm *tvForm;
  PIRInputForm *inputForm;
  PIRAdjustForm *adjustForm;
  PIRAirConditionerForm *acForm;
  PIRStatefulACForm *statefulACForm;
  PIRACTimerForm *acTimerForm;
  PIRAudioDeviceForm *audioDeviceForm;
  PIRCameraForm *cameraForm;
  PIRIntervalometerForm *intervalometerForm;
  PIRRoombaForm *roombaForm;
  PIRPlaystationForm *playstationForm;
  PIRUserForm *userForm;
  PIRMacroForm *macroForm;
//  PIRPowerSearchForm *powerSearchForm;
//  PIRAdvancedForm *advancedForm;

  PIRPanelDisplayNameCollection shortPanelNames;
  PIRPanelDisplayNameCollection longPanelNames;
//  PIRReversePanelIndex reverseIndex;
  PIRTabsCollection tabLists;
  PIRPanelCollection panels;

  bool altMainPanelFlag;

  MainWindow *mainWindow;
};

#endif // PIRPANELMANAGER_H
