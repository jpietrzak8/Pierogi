#ifndef PIRPANELMANAGER_H
#define PIRPANELMANAGER_H

#include "pirpanelnames.h"

class PIRMainForm;
class PIRUtilityForm;
class PIRKeypadForm;
class PIRMenuForm;
class PIRMediaForm;
class PIRFavoritesForm;
class PIRTVForm;
class PIRMedia2Form;
class PIRInputForm;
class PIRAdjustForm;
class PIRAirConditionerForm;

class PIRKeysetWidgetItem;
class PIRPanelSelectionForm;
class PIRKeysetManager;
class QListWidget;
class MainWindow;

#include <list>

class PIRPanelPair
{
public:
  PIRPanelPair(
    PIRPanelName n,
    bool d)
    : name(n),
      displayed(d)
  {}

  PIRPanelName name;
  bool displayed;
};

typedef std::list<PIRPanelPair> PIRPanelList;

class PIRPanelManager
{
public:
  PIRPanelManager(
    MainWindow *mw);

  ~PIRPanelManager();

/*
  void setupPanels(
    PIRPanelSelectionForm *psf);
*/

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

  void managePanel(
    PIRPanelName name,
    int state);

  void selectPrevFavKeyset();
  void selectNextFavKeyset();
 
  void addFavoritesItem(
    PIRKeysetWidgetItem *item);

  // This is a hack:
  QListWidget *getFavoritesListWidget();

private:
  void hidePanel(
    PIRPanelName name,
    int index);

  void showPanel(
    PIRPanelName name,
    int index);
  
  PIRMainForm *mainForm;
  PIRUtilityForm *utilityForm;
  PIRKeypadForm *keypadForm;
  PIRMenuForm *menuForm;
  PIRMediaForm *mediaForm;
  PIRMedia2Form *media2Form;
  PIRTVForm *tvForm;
  PIRInputForm *inputForm;
  PIRAdjustForm *adjustForm;
  PIRAirConditionerForm *acForm;
  PIRFavoritesForm *favoritesForm;

  PIRPanelList panelList;

  MainWindow *mainWindow;
};

#endif // PIRPANELMANAGER_H
