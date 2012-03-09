#include "pirpanelmanager.h"

#include "pirpanelselectionform.h"

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
#include "forms/pirfavoritesform.h"

#include "mainwindow.h"

#include <QSettings>

// Debugging:
//#include <QMaemo5InformationBox>
#include <iostream>

PIRPanelManager::PIRPanelManager(MainWindow *mw)
  : mainForm(0),
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
    favoritesForm(0),
    altMainPanelFlag(false),
    mainWindow(mw)
{
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
  shortPanelNames[Favorites_Panel] = "Favorites";
  longPanelNames[Favorites_Panel] =
    "Favorites Panel - memorized keysets";

  activePanels[Main_Panel] = false;
  activePanels[Utility_Panel]= false;
  activePanels[Keypad_Panel]= false;
  activePanels[Menu_Panel]= false;
  activePanels[Media_Panel]= false;
  activePanels[Media2_Panel]= false;
  activePanels[Record_Panel]= false;
  activePanels[TV_Panel]= false;
  activePanels[Input_Panel]= false;
  activePanels[Adjust_Panel]= false;
  activePanels[AC_Panel]= false;
  activePanels[Favorites_Panel]= false;
}


PIRPanelManager::~PIRPanelManager()
{
  // Note!  We are _not_ deleting the panel forms here, because the Qt GUI
  // has ownership over some of them.  Moreover, the Panel Manager is not
  // currently designed to be destroyed until the program ends.  Should the
  // manager need to be destroyed earlier, this destructor will need to be
  // changed!
}


void PIRPanelManager::setupPanels(
  PIRPanelSelectionForm *psf)
{
  QSettings settings("pietrzak.org", "Pierogi");

  settings.beginGroup("Panels");

  // Do the panel settings exist? (We'll check for "Main_Panel".)
  if (!settings.contains(shortPanelNames[Main_Panel]))
  {
    // A default set of panels:
    psf->setCheckBox(Main_Panel, true);
    psf->setCheckBox(Utility_Panel, true);
    psf->setCheckBox(Keypad_Panel, true);
    psf->setCheckBox(Menu_Panel, true);
    psf->setCheckBox(Media_Panel, true);
    psf->setCheckBox(Favorites_Panel, true);
  }
  else
  {
    psf->setCheckBox(
      Main_Panel,
      settings.value(shortPanelNames[Main_Panel]).toBool());

    if (settings.contains(shortPanelNames[Utility_Panel]))
    {
      psf->setCheckBox(
        Utility_Panel,
        settings.value(shortPanelNames[Utility_Panel]).toBool());
    }

    if (settings.contains(shortPanelNames[Keypad_Panel]))
    {
      psf->setCheckBox(
        Keypad_Panel,
        settings.value(shortPanelNames[Keypad_Panel]).toBool());
    }

    if (settings.contains(shortPanelNames[Menu_Panel]))
    {
      psf->setCheckBox(
        Menu_Panel,
        settings.value(shortPanelNames[Menu_Panel]).toBool());
    }

    if (settings.contains(shortPanelNames[Media_Panel]))
    {
      psf->setCheckBox(
        Media_Panel,
        settings.value(shortPanelNames[Media_Panel]).toBool());
    }

    if (settings.contains(shortPanelNames[Media2_Panel]))
    {
      psf->setCheckBox(
        Media2_Panel,
        settings.value(shortPanelNames[Media2_Panel]).toBool());
    }

    if (settings.contains(shortPanelNames[Record_Panel]))
    {
      psf->setCheckBox(
        Record_Panel,
        settings.value(shortPanelNames[Record_Panel]).toBool());
    }

    if (settings.contains(shortPanelNames[TV_Panel]))
    {
      psf->setCheckBox(
        TV_Panel,
        settings.value(shortPanelNames[TV_Panel]).toBool());
    }

    if (settings.contains(shortPanelNames[Input_Panel]))
    {
      psf->setCheckBox(
        Input_Panel,
        settings.value(shortPanelNames[Input_Panel]).toBool());
    }

    if (settings.contains(shortPanelNames[Adjust_Panel]))
    {
      psf->setCheckBox(
        Adjust_Panel,
        settings.value(shortPanelNames[Adjust_Panel]).toBool());
    }

    if (settings.contains(shortPanelNames[AC_Panel]))
    {
      psf->setCheckBox(
        AC_Panel,
        settings.value(shortPanelNames[AC_Panel]).toBool());
    }

    if (settings.contains(shortPanelNames[Favorites_Panel]))
    {
      psf->setCheckBox(
        Favorites_Panel,
        settings.value(shortPanelNames[Favorites_Panel]).toBool());
    }
  }

  settings.endGroup();
}


void PIRPanelManager::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  if (altMainPanelFlag)
  {
    if (altMainForm) altMainForm->enableButtons(keyset, id);
  }
  else
  {
    if (mainForm) mainForm->enableButtons(keyset, id);
  }
  if (utilityForm) utilityForm->enableButtons(keyset, id);
  if (keypadForm) keypadForm->enableButtons(keyset, id);
  if (menuForm) menuForm->enableButtons(keyset, id);
  if (mediaForm) mediaForm->enableButtons(keyset, id);
  if (media2Form) media2Form->enableButtons(keyset, id);
  if (recordForm) recordForm->enableButtons(keyset, id);
  if (tvForm) tvForm->enableButtons(keyset, id);
  if (inputForm) inputForm->enableButtons(keyset, id);
  if (adjustForm) adjustForm->enableButtons(keyset, id);
  if (acForm) acForm->enableButtons(keyset, id);
}


void PIRPanelManager::managePanel(
  PIRPanelName name,
  int state)
{
  int currentPanel = 0;
  int displayCount = 0;

//  PIRPanelList::iterator i = panelList.begin();
  while (currentPanel < Last_Panel_Marker)
  {
    if (currentPanel == name)
    {
      break;
    }
    else if (activePanels[PIRPanelName(currentPanel)])
    {
      ++displayCount;
    }

    ++currentPanel;
  }

  if (currentPanel == Last_Panel_Marker)
  {
    // should throw an error message here!!!
    return;
  }

  QSettings settings("pietrzak.org", "Pierogi");

  settings.beginGroup("Panels");

  if (state == Qt::Unchecked && activePanels[PIRPanelName(currentPanel)])
  {
    hidePanel(name, displayCount);
    activePanels[PIRPanelName(currentPanel)] = false;
    settings.setValue(shortPanelNames[PIRPanelName(currentPanel)], false);
  }
  else if (state == Qt::Checked && !activePanels[PIRPanelName(currentPanel)])
  {
    showPanel(name, displayCount);
    activePanels[PIRPanelName(currentPanel)] = true;
    settings.setValue(shortPanelNames[PIRPanelName(currentPanel)], true);
  }

  settings.endGroup();
}


void PIRPanelManager::useMainPanel()
{
  if (!altMainPanelFlag)
  {
    // Already set correctly, nothing to do:
    return;
  }

  altMainPanelFlag = false;

  // Is the main panel currently active?
  if (activePanels[Main_Panel])
  {
    mainWindow->removePanel(0, altMainForm);
    if (!mainForm)
    {
      mainForm = new PIRMainForm(mainWindow);
    }

    mainWindow->insertPanel(0, mainForm, longPanelNames[Main_Panel]);
    mainWindow->selectPanel(0);
  }

  mainWindow->enableButtons();
}


void PIRPanelManager::useAltMainPanel()
{
  if (altMainPanelFlag)
  {
    // Already set correctly, nothing to do:
    return;
  }

  altMainPanelFlag = true;

  // Is the main panel currently active?
  if (activePanels[Main_Panel])
  {
    mainWindow->removePanel(0, mainForm);
    if (!altMainForm)
    {
      altMainForm = new PIRAltMainForm(mainWindow);
    }

    mainWindow->insertPanel(0, altMainForm, longPanelNames[Main_Panel]);
    mainWindow->selectPanel(0);
  }

  mainWindow->enableButtons();
}


void PIRPanelManager::hidePanel(
  PIRPanelName name,
  int index)
{
  switch (name)
  {
    case Main_Panel:
      if (altMainPanelFlag)
      {
        if (altMainForm) mainWindow->removePanel(index, altMainForm);
      }
      else
      {
        if (mainForm) mainWindow->removePanel(index, mainForm);
      }
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

    case Media2_Panel:
      if (media2Form) mainWindow->removePanel(index, media2Form);
      break;

    case Record_Panel:
      if (recordForm) mainWindow->removePanel(index, recordForm);
      break;

    case TV_Panel:
      if (tvForm) mainWindow->removePanel(index, tvForm);
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
      if (altMainPanelFlag)
      {
        if (!altMainForm)
        {
          altMainForm = new PIRAltMainForm(mainWindow);
          mainWindow->enableButtons();
        }

        mainWindow->insertPanel(
          index,
          altMainForm,
          longPanelNames[Main_Panel]);
      }
      else
      {
        if (!mainForm)
        {
          mainForm = new PIRMainForm(mainWindow);
          mainWindow->enableButtons();
        }

        mainWindow->insertPanel(
          index,
          mainForm,
          longPanelNames[Main_Panel]);
      }

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
        longPanelNames[Utility_Panel]);

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
        longPanelNames[Keypad_Panel]);

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
        longPanelNames[Menu_Panel]);

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
        longPanelNames[Media_Panel]);

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
        longPanelNames[Media2_Panel]);

      break;

    case Record_Panel:
      if (!recordForm)
      {
        recordForm = new PIRRecordForm(mainWindow);
        mainWindow->enableButtons();
      }

      mainWindow->insertPanel(
        index,
        recordForm,
        longPanelNames[Record_Panel]);

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
        longPanelNames[TV_Panel]);

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
        longPanelNames[Input_Panel]);

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
        longPanelNames[Adjust_Panel]);

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
        longPanelNames[AC_Panel]);

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
        longPanelNames[Favorites_Panel]);

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

