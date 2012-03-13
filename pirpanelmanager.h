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
class PIRPanelSelectionForm;
class PIRKeysetManager;
class QListWidget;
class MainWindow;

#include <map>
#include <QString>
typedef std::map<PIRPanelName, const char *> PIRPanelDisplayNameCollection;
typedef std::map<PIRPanelName, bool> PIRActivePanelCollection;
typedef std::map<QString, PIRPanelName> PIRReversePanelIndex;

class PIRPanelManager
{
public:
  PIRPanelManager(
    MainWindow *mw);

  ~PIRPanelManager();

  void setupPanels(
    PIRPanelSelectionForm *psf);

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int currentID,
    unsigned int defaultID);

  void managePanel(
    PIRPanelName name,
    int state);

  void useMainPanel();
  void useAltMainPanel();

  void selectPrevFavKeyset();
  void selectNextFavKeyset();
 
  void addFavoritesItem(
    PIRKeysetWidgetItem *item);

  // This is a hack:
  QListWidget *getFavoritesListWidget();

private:
  void commonEnableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

  void hidePanel(
    PIRPanelName name,
    int index);

  void showPanel(
    PIRPanelName name,
    int index);
  
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
  PIRActivePanelCollection activePanels;
//  PIRReversePanelIndex reverseIndex;

  bool altMainPanelFlag;

  MainWindow *mainWindow;
};

#endif // PIRPANELMANAGER_H
