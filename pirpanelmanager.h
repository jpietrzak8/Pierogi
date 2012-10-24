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
class PIRAudioDeviceForm;
class PIRCameraForm;
class PIRRoombaForm;
class PIRUserForm;
class PIRMacroForm;
class PIRPowerSearchForm;
class PIRAdvancedForm;

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
typedef std::map<PIRPanelName, const char *> PIRPanelDisplayNameCollection;
typedef std::map<QString, PIRPanelName> PIRReversePanelIndex;

class PIRPanelManager
{
public:
  PIRPanelManager(
    MainWindow *mw);

  ~PIRPanelManager();

  void updateTabSet();

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
  void setupTabs(PIRTabBarName name);

  QComboBox *getKeysetComboBox();

  void gotoPreviousTabs();
  void gotoNextTabs();

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
  PIRAudioDeviceForm *audioDeviceForm;
  PIRCameraForm *cameraForm;
  PIRRoombaForm *roombaForm;
  PIRUserForm *userForm;
  PIRMacroForm *macroForm;
  PIRPowerSearchForm *powerSearchForm;
  PIRAdvancedForm *advancedForm;

  PIRPanelDisplayNameCollection shortPanelNames;
  PIRPanelDisplayNameCollection longPanelNames;
//  PIRReversePanelIndex reverseIndex;
  PIRTabsCollection tabLists;
  PIRPanelCollection panels;

  bool altMainPanelFlag;

  PIRTabBarName currentTabsName;

  MainWindow *mainWindow;
};

#endif // PIRPANELMANAGER_H
