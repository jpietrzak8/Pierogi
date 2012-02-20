#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QtCore/QCoreApplication>
#include <QMutex>
#include <QtGui/QMessageBox>
#include <QSettings>
#include <QMaemo5InformationBox>

#include "pirkeysetwidgetitem.h"
#include "pirselectkeysetform.h"
#include "pirsecondaryform.h"
#include "pirdocumentationform.h"
#include "piraboutform.h"
#include "pirkeysetmanager.h"

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
    secondaryForm(0),
    documentationForm(0),
    aboutForm(0),
    currentKeyset(0)
{
  ui->setupUi(this);

  // Make this a Maemo 5 stacked widget:
  setAttribute(Qt::WA_Maemo5StackedWindow);

  // Collect the keysets:
  myKeysets = new PIRKeysetManager();

  // Set up the keyset selection window:
  selectKeysetForm = new PIRSelectKeysetForm(this);

  // Set up the secondary buttons window:
  secondaryForm = new PIRSecondaryForm(this);

  myKeysets->populateGuiWidget(selectKeysetForm);

  // Remember any favorites the user has already set:
  populateFavorites();

  QSettings settings("pietrzak.org", "Pierogi");
  if (settings.contains("currentKeysetName"))
  {
    myKeysets->findKeysetID(
      settings.value("currentKeysetMake").toString(),
      settings.value("currentKeysetName").toString(),
      currentKeyset);
//    currentKeyset = settings.value("currentKeyset").toInt();
  }

  enableButtons();

  connect(
    ui->favoriteKeysetsWidget,
//    SIGNAL(itemActivated(QListWidgetItem *)),
    SIGNAL(currentItemChanged(QListWidgetItem *, QListWidgetItem *)),
    this,
    SLOT(keysetSelectionChanged(QListWidgetItem *)),
    Qt::QueuedConnection);

  // Make sure the two selection lists don't show different selections:
  QListWidget *klw = selectKeysetForm->getKeysetListWidget();
  connect(
    ui->favoriteKeysetsWidget,
    SIGNAL(itemActivated(QListWidgetItem *)),
    klw,
    SLOT(clearSelection()),
    Qt::QueuedConnection);

  connect(
    klw,
    SIGNAL(itemActivated(QListWidgetItem *)),
    ui->favoriteKeysetsWidget,
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

  // This is going to be a little painful...
  // Main keys
  emit powerEnabled(myKeysets->hasKey(currentKeyset, Power_Key));
  emit volumeUpEnabled(myKeysets->hasKey(currentKeyset, VolumeUp_Key));
  emit volumeDownEnabled(myKeysets->hasKey(currentKeyset, VolumeDown_Key));
  emit channelUpEnabled(myKeysets->hasKey(currentKeyset, ChannelUp_Key));
  emit channelDownEnabled(myKeysets->hasKey(currentKeyset, ChannelDown_Key));
  emit muteEnabled(myKeysets->hasKey(currentKeyset, Mute_Key));

  // Main tab labels:
  emit keysetMakeChanged(
    makeManager.getMakeString(myKeysets->getMake(currentKeyset)));
  emit keysetNameChanged(myKeysets->getDisplayName(currentKeyset));

  // Utility keys:
  emit redEnabled(myKeysets->hasKey(currentKeyset, Red_Key));
  emit greenEnabled(myKeysets->hasKey(currentKeyset, Green_Key));
  emit yellowEnabled(myKeysets->hasKey(currentKeyset, Yellow_Key));
  emit blueEnabled(myKeysets->hasKey(currentKeyset, Blue_Key));
  emit pictureModeEnabled(myKeysets->hasKey(currentKeyset, PictureMode_Key));
  emit soundModeEnabled(myKeysets->hasKey(currentKeyset, SoundMode_Key));
  emit aspectRatioEnabled(myKeysets->hasKey(currentKeyset, AspectRatio_Key));
//  emit surroundEnabled(myKeysets->hasKey(currentKeyset, Surround_Key));
  emit audioEnabled(myKeysets->hasKey(currentKeyset, Audio_Key));
  emit infoEnabled(myKeysets->hasKey(currentKeyset, Info_Key));
  emit captionsEnabled(myKeysets->hasKey(currentKeyset, Captions_Key));
  emit sleepEnabled(myKeysets->hasKey(currentKeyset, Sleep_Key));
  emit inputEnabled(myKeysets->hasKey(currentKeyset, Input_Key));

  // Keypad keys
  emit zeroEnabled(myKeysets->hasKey(currentKeyset, Zero_Key));
  emit oneEnabled(myKeysets->hasKey(currentKeyset, One_Key));
  emit twoEnabled(myKeysets->hasKey(currentKeyset, Two_Key));
  emit threeEnabled(myKeysets->hasKey(currentKeyset, Three_Key));
  emit fourEnabled(myKeysets->hasKey(currentKeyset, Four_Key));
  emit fiveEnabled(myKeysets->hasKey(currentKeyset, Five_Key));
  emit sixEnabled(myKeysets->hasKey(currentKeyset, Six_Key));
  emit sevenEnabled(myKeysets->hasKey(currentKeyset, Seven_Key));
  emit eightEnabled(myKeysets->hasKey(currentKeyset, Eight_Key));
  emit nineEnabled(myKeysets->hasKey(currentKeyset, Nine_Key));
  emit enterEnabled(myKeysets->hasKey(currentKeyset, Enter_Key));
  emit clearEnabled(myKeysets->hasKey(currentKeyset, Clear_Key));
  emit dashEnabled(myKeysets->hasKey(currentKeyset, Dash_Key));
  emit plusOneHundredEnabled(myKeysets->hasKey(currentKeyset, PlusOneHundred_Key));
  emit doubleDigitEnabled(myKeysets->hasKey(currentKeyset, DoubleDigit_Key));
  emit prevChannelEnabled(myKeysets->hasKey(currentKeyset, PrevChannel_Key));

  // Menu keys:
  emit upEnabled(myKeysets->hasKey(currentKeyset, Up_Key));
  emit downEnabled(myKeysets->hasKey(currentKeyset, Down_Key));
  emit leftEnabled(myKeysets->hasKey(currentKeyset, Left_Key));
  emit rightEnabled(myKeysets->hasKey(currentKeyset, Right_Key));
  emit selectEnabled(myKeysets->hasKey(currentKeyset, Select_Key));
  emit menuEnabled(myKeysets->hasKey(currentKeyset, Menu_Key));
  emit exitEnabled(myKeysets->hasKey(currentKeyset, Exit_Key));
  emit guideEnabled(myKeysets->hasKey(currentKeyset, Guide_Key));
  emit discMenuEnabled(myKeysets->hasKey(currentKeyset, DiscMenu_Key));

  // Media keys:
  emit nextEnabled(myKeysets->hasKey(currentKeyset, Next_Key));
  emit previousEnabled(myKeysets->hasKey(currentKeyset, Previous_Key));
  emit advanceEnabled(myKeysets->hasKey(currentKeyset, Advance_Key));
  emit replayEnabled(myKeysets->hasKey(currentKeyset, Replay_Key));
  emit stepForwardEnabled(myKeysets->hasKey(currentKeyset, StepForward_Key));
  emit stepBackEnabled(myKeysets->hasKey(currentKeyset, StepBack_Key));
  emit fastForwardEnabled(myKeysets->hasKey(currentKeyset, FastForward_Key));
  emit reverseEnabled(myKeysets->hasKey(currentKeyset, Rewind_Key));
  emit playEnabled(myKeysets->hasKey(currentKeyset, Play_Key));
  emit pauseEnabled(myKeysets->hasKey(currentKeyset, Pause_Key));
  emit stopEnabled(myKeysets->hasKey(currentKeyset, Stop_Key));
  emit ejectEnabled(myKeysets->hasKey(currentKeyset, Eject_Key));

  // Also enable the buttons on the secondary form:
  secondaryForm->enableButtons(myKeysets, currentKeyset);
}


void MainWindow::receivedExternalWarning(
  const char *warning)
{
  QMessageBox errBox;
  errBox.setText(warning);
  errBox.setIcon(QMessageBox::Warning);
  errBox.exec();
}


// Main tab buttons:

void MainWindow::on_powerButton_pressed()
{
  startRepeating(Power_Key);
}

void MainWindow::on_powerButton_released()
{
  stopRepeating();
}

void MainWindow::on_mainChannelUpButton_pressed()
{
  startRepeating(ChannelUp_Key);
}

void MainWindow::on_mainChannelUpButton_released()
{
  stopRepeating();
}

void MainWindow::on_mainChannelDownButton_pressed()
{
  startRepeating(ChannelDown_Key);
}

void MainWindow::on_mainChannelDownButton_released()
{
  stopRepeating();
}

void MainWindow::on_mainVolumeUp_pressed()
{
  startRepeating(VolumeUp_Key);
}

void MainWindow::on_mainVolumeUp_released()
{
  stopRepeating();
}

void MainWindow::on_mainVolumeDownButton_pressed()
{
  startRepeating(VolumeDown_Key);
}

void MainWindow::on_mainVolumeDownButton_released()
{
  stopRepeating();
}

void MainWindow::on_muteButton_pressed()
{
  startRepeating(Mute_Key);
}

void MainWindow::on_muteButton_released()
{
  stopRepeating();
}


// Utility tab buttons:

void MainWindow::on_redButton_pressed()
{
  startRepeating(Red_Key);
}

void MainWindow::on_redButton_released()
{
  stopRepeating();
}

void MainWindow::on_greenButton_pressed()
{
  startRepeating(Green_Key);
}

void MainWindow::on_greenButton_released()
{
  stopRepeating();
}

void MainWindow::on_yellowButton_pressed()
{
  startRepeating(Yellow_Key);
}

void MainWindow::on_yellowButton_released()
{
  stopRepeating();
}

void MainWindow::on_blueButton_pressed()
{
  startRepeating(Blue_Key);
}

void MainWindow::on_blueButton_released()
{
  stopRepeating();
}

void MainWindow::on_pictureModeButton_pressed()
{
  startRepeating(PictureMode_Key);
}

void MainWindow::on_pictureModeButton_released()
{
  stopRepeating();
}

void MainWindow::on_soundModeButton_pressed()
{
  startRepeating(SoundMode_Key);
}

void MainWindow::on_soundModeButton_released()
{
  stopRepeating();
}

void MainWindow::on_aspectRatioButton_pressed()
{
  startRepeating(AspectRatio_Key);
}

void MainWindow::on_aspectRatioButton_released()
{
  stopRepeating();
}

/*
void MainWindow::on_surroundButton_pressed()
{
  startRepeating(Surround_Key);
}

void MainWindow::on_surroundButton_released()
{
  stopRepeating();
}
*/

void MainWindow::on_audioButton_pressed()
{
  startRepeating(Audio_Key);
}

void MainWindow::on_audioButton_released()
{
  stopRepeating();
}

void MainWindow::on_infoButton_pressed()
{
  startRepeating(Info_Key);
}

void MainWindow::on_infoButton_released()
{
  stopRepeating();
}

void MainWindow::on_captionButton_pressed()
{
  startRepeating(Captions_Key);
}

void MainWindow::on_captionButton_released()
{
  stopRepeating();
}

void MainWindow::on_inputButton_pressed()
{
  startRepeating(Input_Key);
}

void MainWindow::on_inputButton_released()
{
  stopRepeating();
}

void MainWindow::on_sleepButton_pressed()
{
  startRepeating(Sleep_Key);
}

void MainWindow::on_sleepButton_released()
{
  stopRepeating();
}


// Keypad tab buttons:

void MainWindow::on_oneButton_pressed()
{
  startRepeating(One_Key);
}

void MainWindow::on_oneButton_released()
{
  stopRepeating();
}

void MainWindow::on_twoButton_pressed()
{
  startRepeating(Two_Key);
}

void MainWindow::on_twoButton_released()
{
  stopRepeating();
}

void MainWindow::on_threeButton_pressed()
{
  startRepeating(Three_Key);
}

void MainWindow::on_threeButton_released()
{
  stopRepeating();
}

void MainWindow::on_fourButton_pressed()
{
  startRepeating(Four_Key);
}

void MainWindow::on_fourButton_released()
{
  stopRepeating();
}

void MainWindow::on_fiveButton_pressed()
{
  startRepeating(Five_Key);
}

void MainWindow::on_fiveButton_released()
{
  stopRepeating();
}

void MainWindow::on_sixButton_pressed()
{
  startRepeating(Six_Key);
}

void MainWindow::on_sixButton_released()
{
  stopRepeating();
}

void MainWindow::on_sevenButton_pressed()
{
  startRepeating(Seven_Key);
}

void MainWindow::on_sevenButton_released()
{
  stopRepeating();
}

void MainWindow::on_eightButton_pressed()
{
  startRepeating(Eight_Key);
}

void MainWindow::on_eightButton_released()
{
  stopRepeating();
}

void MainWindow::on_nineButton_pressed()
{
  startRepeating(Nine_Key);
}

void MainWindow::on_nineButton_released()
{
  stopRepeating();
}

void MainWindow::on_zeroButton_pressed()
{
  startRepeating(Zero_Key);
}

void MainWindow::on_zeroButton_released()
{
  stopRepeating();
}

void MainWindow::on_enterButton_pressed()
{
  startRepeating(Enter_Key);
}

void MainWindow::on_enterButton_released()
{
  stopRepeating();
}

void MainWindow::on_clearButton_pressed()
{
  startRepeating(Clear_Key);
}

void MainWindow::on_clearButton_released()
{
  stopRepeating();
}

void MainWindow::on_prevChannelButton_pressed()
{
  startRepeating(PrevChannel_Key);
}

void MainWindow::on_prevChannelButton_released()
{
  stopRepeating();
}

void MainWindow::on_plusOneHundredButton_pressed()
{
  startRepeating(PlusOneHundred_Key);
}

void MainWindow::on_plusOneHundredButton_released()
{
  stopRepeating();
}

void MainWindow::on_dashButton_pressed()
{
  startRepeating(Dash_Key);
}

void MainWindow::on_dashButton_released()
{
  stopRepeating();
}

void MainWindow::on_doubleDigitButton_pressed()
{
  startRepeating(DoubleDigit_Key);
}

void MainWindow::on_doubleDigitButton_released()
{
  stopRepeating();
}


// Menu tab buttons:

void MainWindow::on_upButton_pressed()
{
  startRepeating(Up_Key);
}

void MainWindow::on_upButton_released()
{
  stopRepeating();
}

void MainWindow::on_leftButton_pressed()
{
  startRepeating(Left_Key);
}

void MainWindow::on_leftButton_released()
{
  stopRepeating();
}

void MainWindow::on_rightButton_pressed()
{
  startRepeating(Right_Key);
}

void MainWindow::on_rightButton_released()
{
  stopRepeating();
}

void MainWindow::on_downButton_pressed()
{
  startRepeating(Down_Key);
}

void MainWindow::on_downButton_released()
{
  stopRepeating();
}

void MainWindow::on_selectButton_pressed()
{
  startRepeating(Select_Key);
}

void MainWindow::on_selectButton_released()
{
  stopRepeating();
}

void MainWindow::on_menuButton_pressed()
{
  startRepeating(Menu_Key);
}

void MainWindow::on_menuButton_released()
{
  stopRepeating();
}

void MainWindow::on_exitButton_pressed()
{
  startRepeating(Exit_Key);
}

void MainWindow::on_exitButton_released()
{
  stopRepeating();
}

void MainWindow::on_guideButton_pressed()
{
  startRepeating(Guide_Key);
}

void MainWindow::on_guideButton_released()
{
  stopRepeating();
}

void MainWindow::on_discMenuButton_pressed()
{
  startRepeating(DiscMenu_Key);
}

void MainWindow::on_discMenuButton_released()
{
  stopRepeating();
}


// Media tab buttons:

void MainWindow::on_mediaPreviousButton_pressed()
{
  startRepeating(Previous_Key);
}

void MainWindow::on_mediaPreviousButton_released()
{
  stopRepeating();
}

void MainWindow::on_mediaNextButton_pressed()
{
  startRepeating(Next_Key);
}

void MainWindow::on_mediaNextButton_released()
{
  stopRepeating();
}

void MainWindow::on_replayButton_pressed()
{
  startRepeating(Replay_Key);
}

void MainWindow::on_replayButton_released()
{
  stopRepeating();
}

void MainWindow::on_advanceButton_pressed()
{
  startRepeating(Advance_Key);
}

void MainWindow::on_advanceButton_released()
{
  stopRepeating();
}

void MainWindow::on_stepBackButton_pressed()
{
  startRepeating(StepBack_Key);
}

void MainWindow::on_stepBackButton_released()
{
  stopRepeating();
}

void MainWindow::on_stepForwardButton_pressed()
{
  startRepeating(StepForward_Key);
}

void MainWindow::on_stepForwardButton_released()
{
  stopRepeating();
}

void MainWindow::on_reverseButton_pressed()
{
  startRepeating(Rewind_Key);
}

void MainWindow::on_reverseButton_released()
{
  stopRepeating();
}

void MainWindow::on_fastForwardButton_pressed()
{
  startRepeating(FastForward_Key);
}

void MainWindow::on_fastForwardButton_released()
{
  stopRepeating();
}

void MainWindow::on_playButton_pressed()
{
  startRepeating(Play_Key);
}

void MainWindow::on_playButton_released()
{
  stopRepeating();
}

void MainWindow::on_pauseButton_pressed()
{
  startRepeating(Pause_Key);
}

void MainWindow::on_pauseButton_released()
{
  stopRepeating();
}

void MainWindow::on_stopButton_pressed()
{
  startRepeating(Stop_Key);
}

void MainWindow::on_stopButton_released()
{
  stopRepeating();
}

void MainWindow::on_ejectButton_pressed()
{
  startRepeating(Eject_Key);
}

void MainWindow::on_ejectButton_released()
{
  stopRepeating();
}


// Menu actions:

void MainWindow::on_actionSelectKeyset_triggered()
{
  selectKeysetForm->show();
}

void MainWindow::on_actionSecondary_Buttons_triggered()
{
  if (!secondaryForm)
  {
    secondaryForm = new PIRSecondaryForm(this);
  }

  secondaryForm->show();
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


void MainWindow::on_addKeysetButton_clicked()
{
  // Is the current keyset already a favorite?
  int count = ui->favoriteKeysetsWidget->count();
  int index = 0;
  PIRKeysetWidgetItem *kwi = NULL;
  while (index < count)
  {
    kwi = dynamic_cast<PIRKeysetWidgetItem *>(
      ui->favoriteKeysetsWidget->item(index));

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

  ui->favoriteKeysetsWidget->addItem(
    new PIRKeysetWidgetItem(name, currentKeyset, make));

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


void MainWindow::on_removeKeysetButton_clicked()
{
  // Deleting an item removes it from the list, so just grab the currently
  // selected item and delete it:
  QListWidgetItem *item = ui->favoriteKeysetsWidget->currentItem();

  if (item) delete item;

  // Remove this item from the persistent list.  Well, actually, it seems a
  // little more convenient to just blow away the existing list of favorites
  // and rewrite it, as modifying an existing QSettings array in the middle
  // seems a bit hard...
  QSettings settings("pietrzak.org", "Pierogi");

  settings.remove("favorites");

  int count = ui->favoriteKeysetsWidget->count();

  // If the count is empty, we can stop right here:
  if (count == 0) return;

  int index = 0;
  unsigned int id;
  PIRKeysetWidgetItem *kwi = NULL;
  settings.beginWriteArray("favorites");
  while (index < count)
  {
    kwi = dynamic_cast<PIRKeysetWidgetItem *>(
      ui->favoriteKeysetsWidget->item(index));

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
      ui->favoriteKeysetsWidget->addItem(kwi);
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


QWidget *MainWindow::getSecondaryWindow()
{
  return secondaryForm;
}


void MainWindow::selectPrevFavKeyset()
{
  int size = ui->favoriteKeysetsWidget->count();

  if (size == 0)
  {
    // No favorites, so nothing to do!
    return;
  }

  int position = ui->favoriteKeysetsWidget->currentRow();

  --position;
  if (position < 0)
  {
    position = size - 1;
  }

  ui->favoriteKeysetsWidget->setCurrentRow(
    position,
    QItemSelectionModel::ClearAndSelect);

  // Tell the user about the change:
  QMaemo5InformationBox::information(
    0,
    ui->favoriteKeysetsWidget->item(position)->text());
}


void MainWindow::selectNextFavKeyset()
{
  int size = ui->favoriteKeysetsWidget->count();

  if (size == 0)
  {
    // No favorites, so just return:
    return;
  }

  int position = ui->favoriteKeysetsWidget->currentRow();

  ++position;
  if (position == size)
  {
    position = 0;
  }

  ui->favoriteKeysetsWidget->setCurrentRow(
    position,
    QItemSelectionModel::ClearAndSelect);

  // Tell the user about the change:
  QMaemo5InformationBox::information(
    0,
    ui->favoriteKeysetsWidget->item(position)->text());
}
