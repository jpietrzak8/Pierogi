#include "pirpanelmanager.h"

#include "forms/pirmainform.h"
#include "forms/pirutilityform.h"
#include "forms/pirkeypadform.h"
#include "forms/pirmenuform.h"
#include "forms/pirmediaform.h"
#include "forms/pirfavoritesform.h"
#include "forms/pirtvform.h"
#include "forms/pirmedia2form.h"
#include "forms/pirinputform.h"
#include "forms/piradjustform.h"
#include "forms/pirairconditionerform.h"

#include "mainwindow.h"

PIRPanelManager::PIRPanelManager(MainWindow *mw)
  : mainForm(0),
    utilityForm(0),
    keypadForm(0),
    menuForm(0),
    mediaForm(0),
    media2Form(0),
    tvForm(0),
    inputForm(0),
    adjustForm(0),
    acForm(0),
    favoritesForm(0),
    mainWindow(mw)
{
  panelList.push_back(PIRPanelPair(Main_Panel, false));
  panelList.push_back(PIRPanelPair(Utility_Panel, false));
  panelList.push_back(PIRPanelPair(Keypad_Panel, false));
  panelList.push_back(PIRPanelPair(Menu_Panel, false));
  panelList.push_back(PIRPanelPair(Media_Panel, false));
  panelList.push_back(PIRPanelPair(Media2_Panel, false));
  panelList.push_back(PIRPanelPair(TV_Panel, false));
  panelList.push_back(PIRPanelPair(Input_Panel, false));
  panelList.push_back(PIRPanelPair(Adjust_Panel, false));
  panelList.push_back(PIRPanelPair(AC_Panel, false));
  panelList.push_back(PIRPanelPair(Favorites_Panel, false));
}


PIRPanelManager::~PIRPanelManager()
{
  // Note!  We are _not_ deleting the panel forms here, because the Qt GUI
  // has ownership over some of them.  Moreover, the Panel Manager is not
  // currently designed to be destroyed until the program ends.  Should the
  // manager need to be destroyed earlier, this destructor will need to be
  // changed!
}


/*
void PIRPanelManager::setupPanels(
  PIRPanelSelectionForm *psf)
{
}
*/


void PIRPanelManager::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  if (mainForm) mainForm->enableButtons(keyset, id);
  if (utilityForm) utilityForm->enableButtons(keyset, id);
  if (keypadForm) keypadForm->enableButtons(keyset, id);
  if (menuForm) menuForm->enableButtons(keyset, id);
  if (mediaForm) mediaForm->enableButtons(keyset, id);
  if (media2Form) media2Form->enableButtons(keyset, id);
  if (tvForm) tvForm->enableButtons(keyset, id);
  if (inputForm) inputForm->enableButtons(keyset, id);
  if (adjustForm) adjustForm->enableButtons(keyset, id);
  if (acForm) acForm->enableButtons(keyset, id);
}


void PIRPanelManager::managePanel(
  PIRPanelName name,
  int state)
{
  int index = 0;

  PIRPanelList::iterator i = panelList.begin();
  while (i != panelList.end())
  {
    if (i->name == name)
    {
      break;
    }
    else if (i->displayed)
    {
      ++index;
    }
    ++i;
  }

  if (i == panelList.end())
  {
    // should throw an error message here!!!
    return;
  }

  if (state == Qt::Unchecked && i->displayed)
  {
    hidePanel(name, index);
    i->displayed = false;
  }
  else if (state == Qt::Checked && !i->displayed)
  {
    showPanel(name, index);
    i->displayed = true;
  }
}


void PIRPanelManager::hidePanel(
  PIRPanelName name,
  int index)
{
  switch (name)
  {
    case Main_Panel:
      if (mainForm) mainWindow->removePanel(index, mainForm);
      break;

    case Utility_Panel:
      if (utilityForm) mainWindow->removePanel(index, utilityForm);
      break;

    case Keypad_Panel:
      if (keypadForm) mainWindow->removePanel(index, keypadForm);
      break;

    case Menu_Panel:
      if (menuForm) mainWindow->removePanel(index, menuForm);
      break;

    case Media_Panel:
      if (mediaForm) mainWindow->removePanel(index, mediaForm);
      break;

    case TV_Panel:
      if (tvForm) mainWindow->removePanel(index, tvForm);
      break;

    case Media2_Panel:
      if (media2Form) mainWindow->removePanel(index, media2Form);
      break;

    case Input_Panel:
      if (inputForm) mainWindow->removePanel(index, inputForm);
      break;

    case Adjust_Panel:
      if (adjustForm) mainWindow->removePanel(index, adjustForm);
      break;

    case AC_Panel:
      if (acForm) mainWindow->removePanel(index, acForm);
      break;

    case Favorites_Panel:
      if (favoritesForm) mainWindow->removePanel(index, favoritesForm);
      break;

    default:
      return; 
      break;
  }
}


void PIRPanelManager::showPanel(
  PIRPanelName name,
  int index)
{
  switch (name)
  {
    case Main_Panel:
      if (!mainForm)
      {
        mainForm = new PIRMainForm(mainWindow);
        mainWindow->enableButtons();
      }

      mainWindow->insertPanel(
        index,
        mainForm,
        QString("Main Panel - power, volume, and channel controls"));

      break;

    case Utility_Panel:
      if (!utilityForm)
      {
        utilityForm = new PIRUtilityForm(mainWindow);
        mainWindow->enableButtons();
      }

      mainWindow->insertPanel(
        index,
        utilityForm,
        QString("Utility Panel - commonly used controls"));

      break;

    case Keypad_Panel:
      if (!keypadForm)
      {
        keypadForm = new PIRKeypadForm(mainWindow);
        mainWindow->enableButtons();
      }

      mainWindow->insertPanel(
        index,
        keypadForm,
        QString("Keypad Panel - numeric value entry"));

      break;

    case Menu_Panel:
      if (!menuForm)
      {
        menuForm = new PIRMenuForm(mainWindow);
        mainWindow->enableButtons();
      }

      mainWindow->insertPanel(
        index,
        menuForm,
        QString("Menu Panel - enter, exit, and navigate menus"));

      break;

    case Media_Panel:
      if (!mediaForm)
      {
        mediaForm = new PIRMediaForm(mainWindow);
        mainWindow->enableButtons();
      }

      mainWindow->insertPanel(
        index,
        mediaForm,
        QString("Media Panel - control over recorded data"));

      break;

    case Media2_Panel:
      if (!media2Form)
      {
        media2Form = new PIRMedia2Form(mainWindow);
        mainWindow->enableButtons();
      }

      mainWindow->insertPanel(
        index,
        media2Form,
        QString("Media2 Panel - additonal media controls"));

      break;

    case TV_Panel:
      if (!tvForm)
      {
        tvForm = new PIRTVForm(mainWindow);
        mainWindow->enableButtons();
      }

      mainWindow->insertPanel(
        index,
        tvForm,
        QString("TV Panel - teletext and picture-in-picture"));

      break;

    case Input_Panel:
      if (!inputForm)
      {
        inputForm = new PIRInputForm(mainWindow);
        mainWindow->enableButtons();
      }

      mainWindow->insertPanel(
        index,
        inputForm,
        QString("Input Panel - manage data sources"));

      break;

    case Adjust_Panel:
      if (!adjustForm)
      {
        adjustForm = new PIRAdjustForm(mainWindow);
        mainWindow->enableButtons();
      }

      mainWindow->insertPanel(
        index,
        adjustForm,
        QString("Adjust Panel - modify audio and video"));

      break;

    case AC_Panel:
      if (!acForm)
      {
        acForm = new PIRAirConditionerForm(mainWindow);
        mainWindow->enableButtons();
      }

      mainWindow->insertPanel(
        index,
        acForm,
        QString("A/C Panel - air conditioner controls"));

      break;

    case Favorites_Panel:
      if (!favoritesForm)
      {
        favoritesForm = new PIRFavoritesForm(mainWindow);
        mainWindow->enableButtons();
      }

      mainWindow->insertPanel(
        index,
        favoritesForm,
        QString("Favorites Panel - memorized keysets"));

      break;

    default:
      break;
  }
}


void PIRPanelManager::selectPrevFavKeyset()
{
  // If the favorites form doesn't exist, no need to continue:
  if (!favoritesForm) return;

  favoritesForm->selectPrevFavKeyset();
}


void PIRPanelManager::selectNextFavKeyset()
{
  // If the favorites form doesn't exist, no need to continue:
  if (!favoritesForm) return;

  favoritesForm->selectNextFavKeyset();
}


void PIRPanelManager::addFavoritesItem(
  PIRKeysetWidgetItem *item)
{
  if (!favoritesForm)
  {
    favoritesForm = new PIRFavoritesForm(mainWindow);
  }

  favoritesForm->addItem(item);
}


QListWidget *PIRPanelManager::getFavoritesListWidget()
{
  if (!favoritesForm)
  {
    favoritesForm = new PIRFavoritesForm(mainWindow);
  }

  return favoritesForm->getFavoritesListWidget();
}

