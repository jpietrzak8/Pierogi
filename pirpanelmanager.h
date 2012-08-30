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
class PIRFavoritesForm;

class PIRKeysetWidgetItem;
class PIRKeysetManager;
class QListWidget;
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
    const PIRKeysetManager *keyset,
    unsigned int id);

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int currentID,
    unsigned int defaultID);

  void useMainPanel();
  void useAltMainPanel();

  void selectPrevFavKeyset();
  void selectNextFavKeyset();
 
  void addFavoritesItem(
    PIRKeysetWidgetItem *item);

  // This is a hack:
  QListWidget *getFavoritesListWidget();

  void setupUniversalTabs();
  void setupTVTabs();
  void setupVideoTabs();
  void setupACTabs();
  void setupRecordTabs();
  void setupTabs(PIRTabBarName name);

private:
  void commonEnableButtons(
    const PIRKeysetManager *keyset,
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
  PIRFavoritesForm *favoritesForm;

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
