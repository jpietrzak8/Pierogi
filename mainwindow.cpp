// mainwindow.cpp
//
// For the Pierogi IR remote control app.
//
// Copyright (C) 2012 by John Pietrzak  (john@pietrzak.org)
//
// Licensed under the GNU GPL version 2.0 or later.

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore/QCoreApplication>
#include <QMutex>
#include <QtGui/QMessageBox>
#include <QPushButton>
#include <QDialog>
#include <QDialogButtonBox>
#include <QScrollArea>
#include <QSettings>
#include <QKeyEvent>

//#include "pirtabwidget.h"

#include "pirkeysetmetadata.h"

#include "pirkeysetwidgetitem.h"
#include "pirselectkeysetform.h"
#include "forms/pirpowersearchform.h"
#include "pirselectdeviceform.h"
#include "pirpreferencesform.h"
#include "pirdocumentationform.h"
#include "piraboutform.h"
#include "dialogs/pirtabschoicedialog.h"
#include "dialogs/pirfavoritesdialog.h"

#include "pirkeysetmanager.h"
#include "pirpanelmanager.h"
#include "macros/pirmacromanager.h"

//#define DEBUGGING
#include <iostream>

// Some ugly globals used for thread communications:

// A global to show that a command is being processed:
bool commandInFlight = false;
QMutex commandIFMutex;

// The stopRepeatingFlag boolean is the method used to tell running commands
// in the worker thread to stop:
bool stopRepeatingFlag = false;
QMutex stopRepeatingMutex;


extern PIRMakeMgr makeManager;


MainWindow::MainWindow(QWidget *parent)
  : QMainWindow(parent),
    ui(new Ui::MainWindow),
    selectKeysetForm(0),
    powerSearchForm(0),
    selectDeviceForm(0),
    preferencesForm(0),
    documentationForm(0),
    aboutForm(0),
    favoritesDialog(0),
    myKeysets(0),
    myPanels(0),
    myMacros(0),
    currentKeyset(1) // Zero is not a valid keyset any more
{
  // Create the tab widget:
//  myTabWidget = new PIRTabWidget(ui->centralWidget, this);

  ui->setupUi(this);

  // Make this a Maemo 5 stacked widget:
  setAttribute(Qt::WA_Maemo5StackedWindow);

  // Create the managers:
  myKeysets = new PIRKeysetManager();
  myMacros = new PIRMacroManager(this);
  myPanels = new PIRPanelManager(this);

  // Display the panels:
  myPanels->updateTabSet();

  // Construct the rest of the forms:
  selectKeysetForm = new PIRSelectKeysetForm(this);
  favoritesDialog = new PIRFavoritesDialog(this);
  myKeysets->populateListWidgets(selectKeysetForm, favoritesDialog);
  selectKeysetForm->populateKeysetComboBox(myPanels->getKeysetComboBox());

  powerSearchForm = new PIRPowerSearchForm(this);

  selectDeviceForm = new PIRSelectDeviceForm(this);
  PIRKeysetMetaData::populateDevices(selectDeviceForm);

  preferencesForm = new PIRPreferencesForm(this, myKeysets);

  // Retrieve the user's preferences:
  QSettings settings("pietrzak.org", "Pierogi");
  if (settings.contains("currentKeysetName"))
  {
    myKeysets->findKeysetID(
      settings.value("currentKeysetMake").toString(),
      settings.value("currentKeysetName").toString(),
      currentKeyset);
  }

  selectKeysetForm->selectKeyset(currentKeyset);

  // Add the corner buttons:
  insertCornerButtons();

  // Set up all the buttons:
  enableButtons();
  myPanels->updateUserButtons();

  // Make sure the three selection lists don't show different selections:
  QListWidget *klw = selectKeysetForm->getKeysetListWidget();
  QListWidget *dlw = selectDeviceForm->getDeviceListWidget();

  // keyset name -> device name
  connect(
    klw,
    SIGNAL(itemActivated(QListWidgetItem *)),
    dlw,
    SLOT(clearSelection()),
    Qt::QueuedConnection);

  // device name -> keyset name
  connect(
    dlw,
    SIGNAL(itemActivated(QListWidgetItem *)),
    klw,
    SLOT(clearSelection()),
    Qt::QueuedConnection);

#ifndef DEBUGGING
  // The PIRModprobe object should take care of setting up and shutting down
  // the lirc_rx51 kernel module, if necessary:
 
  if (modprobeObj.loadRX51Module() != 0)
  {
    // Couldn't load module, quit:
    QMessageBox errBox;
    errBox.setText("Couldn't load lirc_rx51 kernel module!");
    errBox.setIcon(QMessageBox::Warning);
    errBox.exec();
//    throw; // Need a clean way to exit here!!!
  }
#endif
}


MainWindow::~MainWindow()
{
  if (aboutForm) delete aboutForm;
  if (documentationForm) delete documentationForm;
  if (preferencesForm) delete preferencesForm;
  if (selectDeviceForm) delete selectDeviceForm;
  if (powerSearchForm) delete powerSearchForm;
  if (favoritesDialog) delete favoritesDialog;
  if (selectKeysetForm) delete selectKeysetForm;

  if (myPanels) delete myPanels;
  if (myMacros) delete myMacros;
  if (myKeysets) delete myKeysets;
  delete ui;
}


void MainWindow::setOrientation(ScreenOrientation orientation)
{
#if defined(Q_OS_SYMBIAN)
    // If the version of Qt on the device is < 4.7.2, that attribute won't work
    if (orientation != ScreenOrientationAuto) {
        const QStringList v = QString::fromAscii(qVersion()).split(QLatin1Char('.'));
        if (v.count() == 3 && (v.at(0).toInt() << 16 | v.at(1).toInt() << 8 | v.at(2).toInt()) < 0x040702) {
            qWarning("Screen orientation locking only supported with Qt 4.7.2 and above");
            return;
        }
    }
#endif // Q_OS_SYMBIAN

    Qt::WidgetAttribute attribute;
    switch (orientation) {
#if QT_VERSION < 0x040702
    // Qt < 4.7.2 does not yet have the Qt::WA_*Orientation attributes
    case ScreenOrientationLockPortrait:
        attribute = static_cast<Qt::WidgetAttribute>(128);
        break;
    case ScreenOrientationLockLandscape:
        attribute = static_cast<Qt::WidgetAttribute>(129);
        break;
    default:
    case ScreenOrientationAuto:
        attribute = static_cast<Qt::WidgetAttribute>(130);
        break;
#else // QT_VERSION < 0x040702
    case ScreenOrientationLockPortrait:
        attribute = Qt::WA_LockPortraitOrientation;
        break;
    case ScreenOrientationLockLandscape:
        attribute = Qt::WA_LockLandscapeOrientation;
        break;
    default:
    case ScreenOrientationAuto:
        attribute = Qt::WA_AutoOrientation;
        break;
#endif // QT_VERSION < 0x040702
    };
    setAttribute(attribute, true);
}

void MainWindow::showExpanded()
{
#if defined(Q_OS_SYMBIAN) || defined(Q_WS_SIMULATOR)
    showFullScreen();
#elif defined(Q_WS_MAEMO_5)
    showMaximized();
#else
    show();
#endif
}


void MainWindow::enableButtons()
{
  // Just to be sure, check to see if the keyset has been populated:
  myKeysets->populateKeyset(this, currentKeyset);

  if (preferencesForm)
  {
    unsigned int dk = preferencesForm->getDefaultKeyset();
    if (preferencesForm->defaultControlsVolume() && dk)
    {
      myKeysets->populateKeyset(this, dk);
      myPanels->enableButtons(myKeysets, currentKeyset, dk);
    }
    else
    {
      myPanels->enableButtons(myKeysets, currentKeyset);
    }
  }
  else
  {
    myPanels->enableButtons(myKeysets, currentKeyset);
  }

  // Finally, update the power search panel with the new keyset name:
  powerSearchForm->setKeysetName(selectKeysetForm->getCurrentKeysetName());
}


void MainWindow::useMainPanel()
{
  myPanels->useMainPanel();
}


void MainWindow::useAltMainPanel()
{
  myPanels->useAltMainPanel();
}


QString MainWindow::getCurrentMake()
{
  return makeManager.getMakeString(myKeysets->getMake(currentKeyset));
}


QString MainWindow::getCurrentName()
{
  return myKeysets->getDisplayName(currentKeyset);
}


QString MainWindow::getCurrentFullName()
{
  return selectKeysetForm->getCurrentKeysetName();
}


QString MainWindow::getKeysetMake(
  unsigned int id)
{
  return makeManager.getMakeString(myKeysets->getMake(id));
}


QString MainWindow::getKeysetName(
  unsigned int id)
{
  return myKeysets->getDisplayName(id);
}


QString MainWindow::getFullKeysetName(
  unsigned int id)
{
  return selectKeysetForm->getKeysetName(id);
}


bool MainWindow::findKeysetID(
  QString make,
  QString name,
  unsigned int &id)
{
  return myKeysets->findKeysetID(make, name, id);
}


void MainWindow::receivedExternalWarning(
  const char *warning)
{
  QMessageBox errBox;
  errBox.setText(warning);
  errBox.setIcon(QMessageBox::Warning);
  errBox.exec();
}


// Menu actions:

void MainWindow::on_actionSelectKeyset_triggered()
{
  selectKeysetForm->show();
}

void MainWindow::on_actionAutomatic_Keyset_Search_triggered()
{
  powerSearchForm->show();
}

void MainWindow::on_actionBrowse_Device_List_triggered()
{
  selectDeviceForm->show();
}

void MainWindow::on_actionPreferences_triggered()
{
  preferencesForm->show();
}

void MainWindow::on_actionAbout_triggered()
{
  if (!aboutForm)
  {
    aboutForm = new PIRAboutForm(this);
  }

  aboutForm->show();
}

void MainWindow::on_actionDocumentation_triggered()
{
  if (!documentationForm)
  {
    documentationForm = new PIRDocumentationForm(this);
  }

  documentationForm->show();
}


// Other actions:

void MainWindow::keysetSelectionChanged(
  QListWidgetItem *item)
{
  if (!item) return;  // Should probably display error message here!

  PIRKeysetWidgetItem *kwi = dynamic_cast<PIRKeysetWidgetItem *>(item);

  if (!kwi) return; // Also need to say something here

  if (currentKeyset == kwi->getID())
  {
    // We're already on that keyset, so nothing to do:
    return;
  }

  // Clean up and remove the current keyset:
  myKeysets->clearKeyset(currentKeyset);
  
  currentKeyset = kwi->getID();

  QSettings settings("pietrzak.org", "Pierogi");

  settings.setValue(
    "currentKeysetMake",
    makeManager.getMakeString(kwi->getMake()));

  settings.setValue(
    "currentKeysetName",
    myKeysets->getDisplayName(currentKeyset));

  enableButtons();
}


void MainWindow::finalCleanup()
{
  // Perform any necessary cleanup work here.

  // Make certain that the thread stops repeating:
  stopRepeating();
}


void MainWindow::addToFavorites(
  PIRKeysetWidgetItem *kwi)
{
  //Add keyset to the favorites:
  favoritesDialog->addItem(new PIRKeysetWidgetItem(kwi));

  // And, add the keyset id to the persistent list:
  QSettings settings("pietrzak.org", "Pierogi");

  int favSettingsSize = settings.beginReadArray("favorites");
  settings.endArray();

  settings.beginWriteArray("favorites");
  settings.setArrayIndex(favSettingsSize);

  settings.setValue(
    "keysetMake",
    makeManager.getMakeString(kwi->getMake()));

  settings.setValue("keysetName", kwi->getInternalName());

  settings.endArray();
}


void MainWindow::removeFromFavorites(
  unsigned int keysetID)
{
  favoritesDialog->removeItem(keysetID);

  // Remove this item from the persistent list.  Well, actually, it seems a
  // little more convenient to just blow away the existing list of favorites
  // and rewrite it, as modifying an existing QSettings array in the middle
  // seems a bit hard...
  QSettings settings("pietrzak.org", "Pierogi");

  settings.remove("favorites");

  int count = favoritesDialog->getCount();

  // If the count is empty, we can stop right here:
  if (count == 0) return;

  int index = 0;
  unsigned int id;
  PIRKeysetWidgetItem *kwi = NULL;
  settings.beginWriteArray("favorites");
  while (index < count)
  {
    kwi = favoritesDialog->getItem(index);

    settings.setArrayIndex(index);
    id = kwi->getID();

    settings.setValue(
      "keysetMake",
      makeManager.getMakeString(myKeysets->getMake(id)));

    settings.setValue("keysetName", myKeysets->getDisplayName(id));

    ++index;
  }
  settings.endArray();
}


/*
void MainWindow::populateFavorites()
{
  QSettings settings("pietrzak.org", "Pierogi");

  int size = settings.beginReadArray("favorites");
  int index = 0;
  QString make;
  QString name;
  PIRKeysetWidgetItem *kwi;

  while (index < size)
  {
    settings.setArrayIndex(index);
    make = settings.value("keysetMake").toString();
    name = settings.value("keysetName").toString();

    kwi = myKeysets->makeKeysetItem(make, name);

    // Did the item creation work?
    if (kwi)
    {
      // Keyset does exist, so continue:
      favoritesDialog->addItem(kwi);
    }

    ++index;
  }

  settings.endArray();
}
*/


bool MainWindow::startRepeating(
  PIRKeyName name)
{
  QMutexLocker locker(&commandIFMutex);
  if (!commandInFlight)
  {
    commandInFlight = true;
    emit buttonPressed(currentKeyset, name);
    return true;
  }
  else
  {
    return false;
  }
}


bool MainWindow::startRepeating(
  PIRKeyName name,
  unsigned int keysetID)
{
  QMutexLocker locker(&commandIFMutex);
  if (!commandInFlight)
  {
    commandInFlight = true;
    emit buttonPressed(keysetID, name);
    return true;
  }
  else
  {
    return false;
  }
}


bool MainWindow::startRepeating(
  PIRACStateInfo state,
  PIRKeyName name)
{
  QMutexLocker locker(&commandIFMutex);
  if (!commandInFlight)
  {
    commandInFlight = true;
    emit buttonPressed(state, currentKeyset, name);
    return true;
  }
  else
  {
    return false;
  }
}


void MainWindow::stopRepeating()
{
  QMutexLocker locker(&stopRepeatingMutex);
  stopRepeatingFlag = true;
}


void MainWindow::selectPrevFavKeyset()
{
  favoritesDialog->selectPrevFavKeyset();
}


void MainWindow::selectNextFavKeyset()
{
  favoritesDialog->selectNextFavKeyset();
}


void MainWindow::insertCornerButtons()
{
  // Set up the dialog boxes:
  PIRTabsChoiceDialog *tcd = new PIRTabsChoiceDialog(this);
//  favoritesDialog = new PIRFavoritesDialog(this);

  // Next, set up the corner buttons:
  QPushButton *button =
    new QPushButton(QIcon(":/icons/folder_plus_icon&32.png"), "");

  button->setFlat(true);

  connect(
    button,
    SIGNAL(clicked()),
    tcd,
    SLOT(exec()),
    Qt::QueuedConnection);

  ui->mainTabWidget->setCornerWidget(button, Qt::TopRightCorner);
//  myTabWidget->setCornerWidget(button, Qt::TopRightCorner);

  button =
    new QPushButton(QIcon(":/icons/align_just_icon&32.png"), "");

  button->setFlat(true);

  connect(
    button,
    SIGNAL(clicked()),
    favoritesDialog,
    SLOT(exec()),
    Qt::QueuedConnection);

  ui->mainTabWidget->setCornerWidget(button, Qt::TopLeftCorner);
//  myTabWidget->setCornerWidget(button, Qt::TopLeftCorner);
}


void MainWindow::disableUpdates()
{
  ui->mainTabWidget->setUpdatesEnabled(false);
//  myTabWidget->setUpdatesEnabled(false);
}


void MainWindow::enableUpdates()
{
  ui->mainTabWidget->setUpdatesEnabled(true);
//  myTabWidget->setUpdatesEnabled(true);
}


void MainWindow::clearTabs()
{
  ui->mainTabWidget->clear();
//  myTabWidget->clear();
}


void MainWindow::addTab(
  QWidget *page,
  QString label)
{
  ui->mainTabWidget->addTab(page, label);
//  myTabWidget->addTab(page, label);
}

void MainWindow::setupTabs(
  PIRTabBarName name)
{
  myPanels->setupTabs(name);
}


bool MainWindow::selectNextKeyset()
{
  return selectKeysetForm->selectNextKeyset();
}


bool MainWindow::selectPrevKeyset()
{
  return selectKeysetForm->selectPrevKeyset();
}


bool MainWindow::selectFirstKeyset()
{
  return selectKeysetForm->selectFirstKeyset();
}


void MainWindow::openCurrentKeysetDialog()
{
  selectKeysetForm->openCurrentKeysetDialog();
}


void MainWindow::updateKeysetSelection(
  unsigned int targetID)
{
  selectKeysetForm->selectKeyset(targetID);
}


PIRMacroPack *MainWindow::getUserPack()
{
  return myMacros->getUserPack();
}


PIRMacroPack *MainWindow::getMultitapPack()
{
  return myMacros->getMultitapPack();
}


void MainWindow::handleKeypress(
  char key)
{
  myMacros->handleKeypress(key);
}


/*
void MainWindow::handleKeyRelease(
  char key)
{
}
*/


void MainWindow::gotoPreviousTabs()
{
  myPanels->gotoPreviousTabs();
}


void MainWindow::gotoNextTabs()
{
  myPanels->gotoNextTabs();
}

 
/*
void MainWindow::keyPressEvent(
  QKeyEvent *event)
{
  switch(event->key())
  {
  case Qt::Key_A:
    myMacros->handleKeypress('A');
    break;
  case Qt::Key_B:
    myMacros->handleKeypress('B');
    break;
  case Qt::Key_C:
    myMacros->handleKeypress('C');
    break;
  case Qt::Key_D:
    myMacros->handleKeypress('D');
    break;
  case Qt::Key_E:
    myMacros->handleKeypress('E');
    break;
  case Qt::Key_F:
    myMacros->handleKeypress('F');
    break;
  case Qt::Key_G:
    myMacros->handleKeypress('G');
    break;
  case Qt::Key_H:
    myMacros->handleKeypress('H');
    break;
  case Qt::Key_I:
    myMacros->handleKeypress('I');
    break;
  case Qt::Key_J:
    myMacros->handleKeypress('J');
    break;
  case Qt::Key_K:
    myMacros->handleKeypress('K');
    break;
  case Qt::Key_L:
    myMacros->handleKeypress('L');
    break;
  case Qt::Key_M:
    myMacros->handleKeypress('M');
    break;
  case Qt::Key_N:
    myMacros->handleKeypress('N');
    break;
  case Qt::Key_O:
    myMacros->handleKeypress('O');
    break;
  case Qt::Key_P:
    myMacros->handleKeypress('P');
    break;
  case Qt::Key_Q:
    myMacros->handleKeypress('Q');
    break;
  case Qt::Key_R:
    myMacros->handleKeypress('R');
    break;
  case Qt::Key_S:
    myMacros->handleKeypress('S');
    break;
  case Qt::Key_T:
    myMacros->handleKeypress('T');
    break;
  case Qt::Key_U:
    myMacros->handleKeypress('U');
    break;
  case Qt::Key_V:
    myMacros->handleKeypress('V');
    break;
  case Qt::Key_W:
    myMacros->handleKeypress('W');
    break;
  case Qt::Key_X:
    myMacros->handleKeypress('X');
    break;
  case Qt::Key_Y:
    myMacros->handleKeypress('Y');
    break;
  case Qt::Key_Z:
    myMacros->handleKeypress('Z');
    break;
  case Qt::Key_Space:
    myMacros->handleKeypress(' ');
    break;

  case Qt::Key_Up:
    myPanels->gotoPreviousTabs();
    break;
  case Qt::Key_Down:
    myPanels->gotoNextTabs();
    break;


  case Qt::Key_Left:
    startRepeating(VolumeDown_Key);
    break;
  case Qt::Key_Right:
    startRepeating(VolumeUp_Key);
    break;

  case Qt::Key_Backspace:
    startRepeating(Power_Key);
    break;
  case Qt::Key_Return:
    startRepeating(Mute_Key);
    break;

  default:
    QMainWindow::keyPressEvent(event);
    break;
  }
}
*/


/*
void MainWindow::keyReleaseEvent(
  QKeyEvent *event)
{
  switch(event->key())
  {

  case Qt::Key_Up:
  case Qt::Key_Down:
  case Qt::Key_Left:
  case Qt::Key_Right:

  case Qt::Key_Backspace:
  case Qt::Key_Return:
    stopRepeating();
    break;

  default:
    QMainWindow::keyReleaseEvent(event);
    break;
  }
}
*/


bool MainWindow::hasMacroButton(
  unsigned int buttonID)
{
  return myMacros->hasMacroButton(buttonID);
}


QString MainWindow::getMacroButtonText(
  unsigned int buttonID)
{
  return myMacros->getMacroButtonText(buttonID);
}


void MainWindow::executeMacroButton(
  unsigned int buttonID)
{
  myMacros->executeMacroButton(buttonID);
}


void MainWindow::updateUserButtons()
{
  myPanels->updateUserButtons();
}


void MainWindow::storeMacros()
{
  myMacros->storeSettings();
}


void MainWindow::setMacroKbdFocus(
  int index)
{
  myMacros->setKbdFocus(index);
}


void MainWindow::setMacroBtnFocus(
  int index)
{
  myMacros->setBtnFocus(index);
}


void MainWindow::switchToTab(
  int tabNumber)
{
  int count = ui->mainTabWidget->count();

  if (tabNumber < 0)
  {
    ui->mainTabWidget->setCurrentIndex(0);
  }
  else if (tabNumber >= count)
  {
    ui->mainTabWidget->setCurrentIndex(count-1);
  }
  else
  {
    ui->mainTabWidget->setCurrentIndex(tabNumber);
  }
}


void MainWindow::switchToNextTab()
{
  int i = ui->mainTabWidget->currentIndex();
  int count = ui->mainTabWidget->count();

  ++i;

  if (i == count) return;  // already at end of tabs

  ui->mainTabWidget->setCurrentIndex(i);
}


void MainWindow::switchToPrevTab()
{
  int i = ui->mainTabWidget->currentIndex();

  if (i <= 0) return;  // already at start of tabs

  ui->mainTabWidget->setCurrentIndex(--i);
}
