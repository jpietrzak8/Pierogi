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

#include "pirkeysetmetadata.h"

#include "pirkeysetwidgetitem.h"
#include "pirselectkeysetform.h"
#include "pirselectdeviceform.h"
#include "pirpreferencesform.h"
#include "pirdocumentationform.h"
#include "piraboutform.h"
#include "dialogs/pirtabschoicedialog.h"
#include "dialogs/pirfavoritesdialog.h"

#include "pirkeysetmanager.h"
#include "pirpanelmanager.h"

//#define DEBUGGING
//#include <iostream>

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
    selectDeviceForm(0),
    preferencesForm(0),
    documentationForm(0),
    aboutForm(0),
    myKeysets(0),
    myPanels(0),
    currentKeyset(1) // Zero is not a valid keyset any more
{
  ui->setupUi(this);

  // Make this a Maemo 5 stacked widget:
  setAttribute(Qt::WA_Maemo5StackedWindow);

  // Create the managers:
  myKeysets = new PIRKeysetManager();
  myPanels = new PIRPanelManager(this);

  // Display the panels:
  myPanels->updateTabSet();

  // Construct the rest of the forms:
  selectKeysetForm = new PIRSelectKeysetForm(this);
  favoritesDialog = new PIRFavoritesDialog(this);
  myKeysets->populateListWidgets(selectKeysetForm, favoritesDialog);

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

  enableButtons();

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
  delete myKeysets;
  if (selectKeysetForm) delete selectKeysetForm;
  if (selectDeviceForm) delete selectDeviceForm;
//  if (panelSelectionForm) delete panelSelectionForm;
  if (documentationForm) delete documentationForm;
  if (aboutForm) delete aboutForm;
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
  return selectKeysetForm->getKeysetName();
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
}


void MainWindow::disableUpdates()
{
  ui->mainTabWidget->setUpdatesEnabled(false);
}


void MainWindow::enableUpdates()
{
  ui->mainTabWidget->setUpdatesEnabled(true);
}


void MainWindow::clearTabs()
{
  ui->mainTabWidget->clear();
}


void MainWindow::addTab(
  QWidget *page,
  QString label)
{
  ui->mainTabWidget->addTab(page, label);
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
