#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore/QCoreApplication>
#include <QMutex>
#include <QtGui/QMessageBox>
//#include <QtGui>
#include <QSettings>

#include "pirkeysetmetadata.h"
#include "pirkeysetwidgetitem.h"
#include "pirselectkeysetform.h"
#include "pirselectdeviceform.h"
#include "pirpanelselectionform.h"
#include "pirpreferencesform.h"
#include "pirdocumentationform.h"
#include "piraboutform.h"
#include "pirkeysetmanager.h"
#include "pirpanelmanager.h"

//#define DEBUGGING

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
    panelSelectionForm(0),
    preferencesForm(0),
    documentationForm(0),
    aboutForm(0),
    currentKeyset(0)
{
  ui->setupUi(this);

  // Make this a Maemo 5 stacked widget:
  setAttribute(Qt::WA_Maemo5StackedWindow);

  // Create the managers:
  myKeysets = new PIRKeysetManager();
  myPanels = new PIRPanelManager(this);

  // Set up the keyset selection window:
  selectKeysetForm = new PIRSelectKeysetForm(this);
  myKeysets->populateSelectionWidget(selectKeysetForm);

  // Set up the device selection window:
  selectDeviceForm = new PIRSelectDeviceForm(this);
  PIRKeysetMetaData::populateDevices(selectDeviceForm);

  // Set up the panel selection window:
  panelSelectionForm = new PIRPanelSelectionForm(this);
  myPanels->setupPanels(panelSelectionForm);

  // Set up the preferences window:
  preferencesForm = new PIRPreferencesForm(this);

  // Remember any favorites the user has already set:
  populateFavorites();

  // Retrieve the user's preferences:
  QSettings settings("pietrzak.org", "Pierogi");
  if (settings.contains("currentKeysetName"))
  {
    myKeysets->findKeysetID(
      settings.value("currentKeysetMake").toString(),
      settings.value("currentKeysetName").toString(),
      currentKeyset);
  }

  enableButtons();

  QListWidget *fkw = myPanels->getFavoritesListWidget();

  connect(
    fkw,
    SIGNAL(itemActivated(QListWidgetItem *)),
    this,
    SLOT(keysetSelectionChanged(QListWidgetItem *)),
    Qt::QueuedConnection);

  // Make sure the three selection lists don't show different selections:
  QListWidget *klw = selectKeysetForm->getKeysetListWidget();
  QListWidget *dlw = selectDeviceForm->getDeviceListWidget();

  // favorites -> keyset name
  connect(
    fkw,
    SIGNAL(itemActivated(QListWidgetItem *)),
    klw,
    SLOT(clearSelection()),
    Qt::QueuedConnection);

  // favorites -> device name
  connect(
    fkw,
    SIGNAL(itemActivated(QListWidgetItem *)),
    dlw,
    SLOT(clearSelection()),
    Qt::QueuedConnection);

  // keyset name -> favorites
  connect(
    klw,
    SIGNAL(itemActivated(QListWidgetItem *)),
    fkw,
    SLOT(clearSelection()),
    Qt::QueuedConnection);

  // device name -> favorites
  connect(
    dlw,
    SIGNAL(itemActivated(QListWidgetItem *)),
    fkw,
    SLOT(clearSelection()),
    Qt::QueuedConnection);

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
  if (panelSelectionForm) delete panelSelectionForm;
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

  myPanels->enableButtons(myKeysets, currentKeyset);
}


void MainWindow::useMainPanel()
{
  myPanels->useMainPanel();
}


void MainWindow::useAltMainPanel()
{
  myPanels->useAltMainPanel();
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

void MainWindow::on_actionSelect_Device_By_Name_triggered()
{
  selectDeviceForm->show();
}

void MainWindow::on_actionArrange_Button_Panels_triggered()
{
  panelSelectionForm->show();
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
  
  currentKeyset = kwi->getID();

  QSettings settings("pietrzak.org", "Pierogi");
//  settings.setValue("currentKeyset", currentKeyset);

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


void MainWindow::addCurrentKeyset(
  QListWidget *qlw)
{
  // Is the current keyset already a favorite?
  int count = qlw->count();
  int index = 0;
  PIRKeysetWidgetItem *kwi = NULL;
  while (index < count)
  {
    kwi = dynamic_cast<PIRKeysetWidgetItem *>(
      qlw->item(index));

    if (kwi && (kwi->getID() == currentKeyset))
    {
      // Current keyset already in list!  No need to continue.
      return;
    }
    ++index;
  }

  // Ok, add the current keyset to the favorites:
  PIRMakeName make = myKeysets->getMake(currentKeyset);

  QString name = makeManager.getMakeString(make);
  name.append(" ");
  name.append(myKeysets->getDisplayName(currentKeyset));

  qlw->addItem(new PIRKeysetWidgetItem(name, currentKeyset, make));

  // And, add the keyset id to the persistent list:
  QSettings settings("pietrzak.org", "Pierogi");

  int favSettingsSize = settings.beginReadArray("favorites");
  settings.endArray();

  settings.beginWriteArray("favorites");
  settings.setArrayIndex(favSettingsSize);
//  settings.setValue("keysetID", currentKeyset);

  settings.setValue(
    "keysetMake",
    makeManager.getMakeString(myKeysets->getMake(currentKeyset)));

  settings.setValue("keysetName", myKeysets->getDisplayName(currentKeyset));

  settings.endArray();
}


void MainWindow::removeFavoriteKeyset(
  QListWidget *qlw)
{
  // Deleting an item removes it from the list, so just grab the currently
  // selected item and delete it:
  QListWidgetItem *item = qlw->currentItem();

  if (item) delete item;

  // Remove this item from the persistent list.  Well, actually, it seems a
  // little more convenient to just blow away the existing list of favorites
  // and rewrite it, as modifying an existing QSettings array in the middle
  // seems a bit hard...
  QSettings settings("pietrzak.org", "Pierogi");

  settings.remove("favorites");

  int count = qlw->count();

  // If the count is empty, we can stop right here:
  if (count == 0) return;

  int index = 0;
  unsigned int id;
  PIRKeysetWidgetItem *kwi = NULL;
  settings.beginWriteArray("favorites");
  while (index < count)
  {
    kwi = dynamic_cast<PIRKeysetWidgetItem *>(qlw->item(index));

    settings.setArrayIndex(index);
//    settings.setValue("keysetID", kwi->getID());
    id = kwi->getID();

    settings.setValue(
      "keysetMake",
      makeManager.getMakeString(myKeysets->getMake(id)));

    settings.setValue("keysetName", myKeysets->getDisplayName(id));

    ++index;
  }
  settings.endArray();
}


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
      myPanels->addFavoritesItem(kwi);
    }

    ++index;
  }

  settings.endArray();
}


void MainWindow::startRepeating(
  PIRKeyName name)
{
  QMutexLocker locker(&commandIFMutex);
  if (!commandInFlight)
  {
    commandInFlight = true;
    emit buttonPressed(currentKeyset, name);
  }
}


void MainWindow::stopRepeating()
{
  QMutexLocker locker(&stopRepeatingMutex);
  stopRepeatingFlag = true;
}


void MainWindow::selectPrevFavKeyset()
{
  myPanels->selectPrevFavKeyset();
}


void MainWindow::selectNextFavKeyset()
{
  myPanels->selectNextFavKeyset();
}


void MainWindow::selectPanel(
  int index)
{
  ui->selectPanelComboBox->setCurrentIndex(index);
}


void MainWindow::managePanel(
  PIRPanelName name,
  int state)
{
  myPanels->managePanel(name, state);
}


void MainWindow::insertPanel(
  int index,
  QWidget *panel,
  const QString &displayName)
{
  ui->selectPanelComboBox->insertItem(index, displayName);
  ui->stackedButtonsWidget->insertWidget(index, panel);
}


void MainWindow::removePanel(
  int index,
  QWidget *panel)
{
  ui->stackedButtonsWidget->removeWidget(panel);
  ui->selectPanelComboBox->removeItem(index);
}


void MainWindow::on_prevPanelButton_clicked()
{
  int count = ui->selectPanelComboBox->count();

  // No need to do anything if there are less than two panels available:
  if (count < 2) return;

  int index = ui->selectPanelComboBox->currentIndex();
  if (index == 0)
  {
    index = count - 1;
  }
  else
  {
    --index;
  }

  ui->selectPanelComboBox->setCurrentIndex(index);
}


void MainWindow::on_nextPanelButton_clicked()
{
  int count = ui->selectPanelComboBox->count();

  // No need to do anything if there are less than two panels available:
  if (count < 2) return;

  int index = ui->selectPanelComboBox->currentIndex();
  if (index == count - 1)
  {
    index = 0;
  }
  else
  {
    ++index;
  }

  ui->selectPanelComboBox->setCurrentIndex(index);
}


void MainWindow::on_selectPanelComboBox_currentIndexChanged(int index)
{
  ui->stackedButtonsWidget->setCurrentIndex(index);
}
