#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pirkeysetwidgetitem.h"

//#include "pirexception.h"

#include <QtCore/QCoreApplication>
#include <QMutex>
#include <QtGui/QMessageBox>
#include <QSettings>
//#include <QDesktopServices>
//#include <QUrl>

//#include <iostream>

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
    documentationForm(0),
    aboutForm(0),
    currentKeyset(0)
{
  ui->setupUi(this);

  // Make this a Maemo 5 stacked widget:
  setAttribute(Qt::WA_Maemo5StackedWindow);

  // Collect the keysets:
  myKeysets = new PIRKeysetManager(this);

  // Set up the keyset selection window:
  selectKeysetForm = new PIRSelectKeysetForm(this);

  myKeysets->populateGuiWidget(selectKeysetForm);

  // Remember any favorites the user has already set:
  populateFavorites();

  QSettings settings("pietrzak.org", "Pierogi");
  if (settings.contains("currentKeyset"))
  {
    currentKeyset = settings.value("currentKeyset").toInt();
  }

  enableButtons();

  connect(
    ui->favoriteKeysetsWidget,
    SIGNAL(itemActivated(QListWidgetItem *)),
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
  // This is going to be a little painful...
  // Main keys
  emit powerEnabled(myKeysets->hasKey(currentKeyset, Power_Key));
  emit volumeUpEnabled(myKeysets->hasKey(currentKeyset, VolumeUp_Key));
  emit volumeDownEnabled(myKeysets->hasKey(currentKeyset, VolumeDown_Key));
  emit channelUpEnabled(myKeysets->hasKey(currentKeyset, ChannelUp_Key));
  emit channelDownEnabled(myKeysets->hasKey(currentKeyset, ChannelDown_Key));

  // Utility keys:
  emit redEnabled(myKeysets->hasKey(currentKeyset, Red_Key));
  emit greenEnabled(myKeysets->hasKey(currentKeyset, Green_Key));
  emit yellowEnabled(myKeysets->hasKey(currentKeyset, Yellow_Key));
  emit blueEnabled(myKeysets->hasKey(currentKeyset, Blue_Key));
  emit aspectRatioEnabled(myKeysets->hasKey(currentKeyset, AspectRatio_Key));
  emit surroundEnabled(myKeysets->hasKey(currentKeyset, Surround_Key));
  emit languageEnabled(myKeysets->hasKey(currentKeyset, Language_Key));
  emit favoritesEnabled(myKeysets->hasKey(currentKeyset, Favorites_Key));
  emit captionsEnabled(myKeysets->hasKey(currentKeyset, Captions_Key));
  emit sleepEnabled(myKeysets->hasKey(currentKeyset, Sleep_Key));
  emit inputEnabled(myKeysets->hasKey(currentKeyset, Input_Key));
  emit muteEnabled(myKeysets->hasKey(currentKeyset, Mute_Key));

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
  emit menuEnabled(myKeysets->hasKey(currentKeyset, Menu_Key));
  emit upEnabled(myKeysets->hasKey(currentKeyset, Up_Key));
  emit downEnabled(myKeysets->hasKey(currentKeyset, Down_Key));
  emit leftEnabled(myKeysets->hasKey(currentKeyset, Left_Key));
  emit rightEnabled(myKeysets->hasKey(currentKeyset, Right_Key));
  emit selectEnabled(myKeysets->hasKey(currentKeyset, Select_Key));
  emit exitEnabled(myKeysets->hasKey(currentKeyset, Exit_Key));
  emit infoEnabled(myKeysets->hasKey(currentKeyset, Info_Key));
  emit guideEnabled(myKeysets->hasKey(currentKeyset, Guide_Key));

  // Media keys:
  emit playEnabled(myKeysets->hasKey(currentKeyset, Play_Key));
  emit pauseEnabled(myKeysets->hasKey(currentKeyset, Pause_Key));
  emit stopEnabled(myKeysets->hasKey(currentKeyset, Stop_Key));
  emit fastForwardEnabled(myKeysets->hasKey(currentKeyset, FastForward_Key));
  emit reverseEnabled(myKeysets->hasKey(currentKeyset, Rewind_Key));
  emit nextEnabled(myKeysets->hasKey(currentKeyset, Next_Key));
  emit previousEnabled(myKeysets->hasKey(currentKeyset, Previous_Key));
  emit stepForwardEnabled(myKeysets->hasKey(currentKeyset, StepForward_Key));
  emit stepBackEnabled(myKeysets->hasKey(currentKeyset, StepBack_Key));
  emit advanceEnabled(myKeysets->hasKey(currentKeyset, Advance_Key));
  emit replayEnabled(myKeysets->hasKey(currentKeyset, Replay_Key));
  emit ejectEnabled(myKeysets->hasKey(currentKeyset, Eject_Key));

  // Other keys:
  emit pipEnabled(myKeysets->hasKey(currentKeyset, PIP_Key));
  emit pipSwapEnabled(myKeysets->hasKey(currentKeyset, PIPSwap_Key));
  emit pipMoveEnabled(myKeysets->hasKey(currentKeyset, PIPMove_Key));
  emit pipSourceEnabled(myKeysets->hasKey(currentKeyset, PIPSource_Key));
  emit scanEnabled(myKeysets->hasKey(currentKeyset, Scan_Key));
  emit programEnabled(myKeysets->hasKey(currentKeyset, Program_Key));
  emit pictureModeEnabled(myKeysets->hasKey(currentKeyset, PictureMode_Key));
  emit soundModeEnabled(myKeysets->hasKey(currentKeyset, SoundMode_Key));
  emit discTitleEnabled(myKeysets->hasKey(currentKeyset, DiscTitle_Key));
  emit discMenuEnabled(myKeysets->hasKey(currentKeyset, DiscMenu_Key));
  emit discSelectEnabled(myKeysets->hasKey(currentKeyset, DiscSelect_Key));
  emit recordEnabled(myKeysets->hasKey(currentKeyset, Record_Key));
  emit trackingMinusEnabled(myKeysets->hasKey(currentKeyset, TrackingMinus_Key));
  emit trackingPlusEnabled(myKeysets->hasKey(currentKeyset, TrackingPlus_Key));
  emit autoTrackingEnabled(myKeysets->hasKey(currentKeyset, AutoTracking_Key));
  emit vhsSpeedEnabled(myKeysets->hasKey(currentKeyset, VHSSpeed_Key));

  emit keysetMakeChanged(
    makeManager.getMakeString(myKeysets->getMake(currentKeyset)));

  emit keysetNameChanged(myKeysets->getDisplayName(currentKeyset));
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
  startRepeating(currentKeyset, Power_Key);
}

void MainWindow::on_powerButton_released()
{
  stopRepeating();
}

void MainWindow::on_mainChannelUpButton_pressed()
{
  startRepeating(currentKeyset, ChannelUp_Key);
}

void MainWindow::on_mainChannelUpButton_released()
{
  stopRepeating();
}

void MainWindow::on_mainChannelDownButton_pressed()
{
  startRepeating(currentKeyset, ChannelDown_Key);
}

void MainWindow::on_mainChannelDownButton_released()
{
  stopRepeating();
}

void MainWindow::on_mainVolumeUp_pressed()
{
  startRepeating(currentKeyset, VolumeUp_Key);
}

void MainWindow::on_mainVolumeUp_released()
{
  stopRepeating();
}

void MainWindow::on_mainVolumeDownButton_pressed()
{
  startRepeating(currentKeyset, VolumeDown_Key);
}

void MainWindow::on_mainVolumeDownButton_released()
{
  stopRepeating();
}


// Utility tab buttons:

void MainWindow::on_redButton_pressed()
{
  startRepeating(currentKeyset, Red_Key);
}

void MainWindow::on_redButton_released()
{
  stopRepeating();
}

void MainWindow::on_greenButton_pressed()
{
  startRepeating(currentKeyset, Green_Key);
}

void MainWindow::on_greenButton_released()
{
  stopRepeating();
}

void MainWindow::on_yellowButton_pressed()
{
  startRepeating(currentKeyset, Yellow_Key);
}

void MainWindow::on_yellowButton_released()
{
  stopRepeating();
}

void MainWindow::on_blueButton_pressed()
{
  startRepeating(currentKeyset, Blue_Key);
}

void MainWindow::on_blueButton_released()
{
  stopRepeating();
}

void MainWindow::on_aspectRatioButton_pressed()
{
  startRepeating(currentKeyset, AspectRatio_Key);
}

void MainWindow::on_aspectRatioButton_released()
{
  stopRepeating();
}

void MainWindow::on_surroundButton_pressed()
{
  startRepeating(currentKeyset, Surround_Key);
}

void MainWindow::on_surroundButton_released()
{
  stopRepeating();
}

void MainWindow::on_languageButton_pressed()
{
  startRepeating(currentKeyset, Language_Key);
}

void MainWindow::on_languageButton_released()
{
  stopRepeating();
}

void MainWindow::on_favoritesButton_pressed()
{
  startRepeating(currentKeyset, Favorites_Key);
}

void MainWindow::on_favoritesButton_released()
{
  stopRepeating();
}

void MainWindow::on_captionButton_pressed()
{
  startRepeating(currentKeyset, Captions_Key);
}

void MainWindow::on_captionButton_released()
{
  stopRepeating();
}

void MainWindow::on_inputButton_pressed()
{
  startRepeating(currentKeyset, Input_Key);
}

void MainWindow::on_inputButton_released()
{
  stopRepeating();
}

void MainWindow::on_sleepButton_pressed()
{
  startRepeating(currentKeyset, Sleep_Key);
}

void MainWindow::on_sleepButton_released()
{
  stopRepeating();
}

void MainWindow::on_muteButton_pressed()
{
  startRepeating(currentKeyset, Mute_Key);
}

void MainWindow::on_muteButton_released()
{
  stopRepeating();
}


// Keypad tab buttons:

void MainWindow::on_oneButton_pressed()
{
  startRepeating(currentKeyset, One_Key);
}

void MainWindow::on_oneButton_released()
{
  stopRepeating();
}

void MainWindow::on_twoButton_pressed()
{
  startRepeating(currentKeyset, Two_Key);
}

void MainWindow::on_twoButton_released()
{
  stopRepeating();
}

void MainWindow::on_threeButton_pressed()
{
  startRepeating(currentKeyset, Three_Key);
}

void MainWindow::on_threeButton_released()
{
  stopRepeating();
}

void MainWindow::on_fourButton_pressed()
{
  startRepeating(currentKeyset, Four_Key);
}

void MainWindow::on_fourButton_released()
{
  stopRepeating();
}

void MainWindow::on_fiveButton_pressed()
{
  startRepeating(currentKeyset, Five_Key);
}

void MainWindow::on_fiveButton_released()
{
  stopRepeating();
}

void MainWindow::on_sixButton_pressed()
{
  startRepeating(currentKeyset, Six_Key);
}

void MainWindow::on_sixButton_released()
{
  stopRepeating();
}

void MainWindow::on_sevenButton_pressed()
{
  startRepeating(currentKeyset, Seven_Key);
}

void MainWindow::on_sevenButton_released()
{
  stopRepeating();
}

void MainWindow::on_eightButton_pressed()
{
  startRepeating(currentKeyset, Eight_Key);
}

void MainWindow::on_eightButton_released()
{
  stopRepeating();
}

void MainWindow::on_nineButton_pressed()
{
  startRepeating(currentKeyset, Nine_Key);
}

void MainWindow::on_nineButton_released()
{
  stopRepeating();
}

void MainWindow::on_zeroButton_pressed()
{
  startRepeating(currentKeyset, Zero_Key);
}

void MainWindow::on_zeroButton_released()
{
  stopRepeating();
}

void MainWindow::on_enterButton_pressed()
{
  startRepeating(currentKeyset, Enter_Key);
}

void MainWindow::on_enterButton_released()
{
  stopRepeating();
}

void MainWindow::on_clearButton_pressed()
{
  startRepeating(currentKeyset, Clear_Key);
}

void MainWindow::on_clearButton_released()
{
  stopRepeating();
}

void MainWindow::on_prevChannelButton_pressed()
{
  startRepeating(currentKeyset, PrevChannel_Key);
}

void MainWindow::on_prevChannelButton_released()
{
  stopRepeating();
}

void MainWindow::on_plusOneHundredButton_pressed()
{
  startRepeating(currentKeyset, PlusOneHundred_Key);
}

void MainWindow::on_plusOneHundredButton_released()
{
  stopRepeating();
}

void MainWindow::on_dashButton_pressed()
{
  startRepeating(currentKeyset, Dash_Key);
}

void MainWindow::on_dashButton_released()
{
  stopRepeating();
}

void MainWindow::on_doubleDigitButton_pressed()
{
  startRepeating(currentKeyset, DoubleDigit_Key);
}

void MainWindow::on_doubleDigitButton_released()
{
  stopRepeating();
}


// Menu tab buttons:

void MainWindow::on_upButton_pressed()
{
  startRepeating(currentKeyset, Up_Key);
}

void MainWindow::on_upButton_released()
{
  stopRepeating();
}

void MainWindow::on_leftButton_pressed()
{
  startRepeating(currentKeyset, Left_Key);
}

void MainWindow::on_leftButton_released()
{
  stopRepeating();
}

void MainWindow::on_rightButton_pressed()
{
  startRepeating(currentKeyset, Right_Key);
}

void MainWindow::on_rightButton_released()
{
  stopRepeating();
}

void MainWindow::on_downButton_pressed()
{
  startRepeating(currentKeyset, Down_Key);
}

void MainWindow::on_downButton_released()
{
  stopRepeating();
}

void MainWindow::on_selectButton_pressed()
{
  startRepeating(currentKeyset, Select_Key);
}

void MainWindow::on_selectButton_released()
{
  stopRepeating();
}

void MainWindow::on_menuButton_pressed()
{
  startRepeating(currentKeyset, Menu_Key);
}

void MainWindow::on_menuButton_released()
{
  stopRepeating();
}

void MainWindow::on_exitButton_pressed()
{
  startRepeating(currentKeyset, Exit_Key);
}

void MainWindow::on_exitButton_released()
{
  stopRepeating();
}



// Media tab buttons:

void MainWindow::on_mediaPreviousButton_pressed()
{
  startRepeating(currentKeyset, Previous_Key);
}

void MainWindow::on_mediaPreviousButton_released()
{
  stopRepeating();
}

void MainWindow::on_mediaNextButton_pressed()
{
  startRepeating(currentKeyset, Next_Key);
}

void MainWindow::on_mediaNextButton_released()
{
  stopRepeating();
}

void MainWindow::on_replayButton_pressed()
{
  startRepeating(currentKeyset, Replay_Key);
}

void MainWindow::on_replayButton_released()
{
  stopRepeating();
}

void MainWindow::on_advanceButton_pressed()
{
  startRepeating(currentKeyset, Advance_Key);
}

void MainWindow::on_advanceButton_released()
{
  stopRepeating();
}

void MainWindow::on_stepBackButton_pressed()
{
  startRepeating(currentKeyset, StepBack_Key);
}

void MainWindow::on_stepBackButton_released()
{
  stopRepeating();
}

void MainWindow::on_stepForwardButton_pressed()
{
  startRepeating(currentKeyset, StepForward_Key);
}

void MainWindow::on_stepForwardButton_released()
{
  stopRepeating();
}

void MainWindow::on_reverseButton_pressed()
{
  startRepeating(currentKeyset, Rewind_Key);
}

void MainWindow::on_reverseButton_released()
{
  stopRepeating();
}

void MainWindow::on_fastForwardButton_pressed()
{
  startRepeating(currentKeyset, FastForward_Key);
}

void MainWindow::on_fastForwardButton_released()
{
  stopRepeating();
}

void MainWindow::on_playButton_pressed()
{
  startRepeating(currentKeyset, Play_Key);
}

void MainWindow::on_playButton_released()
{
  stopRepeating();
}

void MainWindow::on_pauseButton_pressed()
{
  startRepeating(currentKeyset, Pause_Key);
}

void MainWindow::on_pauseButton_released()
{
  stopRepeating();
}

void MainWindow::on_stopButton_pressed()
{
  startRepeating(currentKeyset, Stop_Key);
}

void MainWindow::on_stopButton_released()
{
  stopRepeating();
}

void MainWindow::on_ejectButton_pressed()
{
  startRepeating(currentKeyset, Eject_Key);
}

void MainWindow::on_ejectButton_released()
{
  stopRepeating();
}


// Misc tab slots:

void MainWindow::on_pipOnOffButton_pressed()
{
  startRepeating(currentKeyset, PIP_Key);
}

void MainWindow::on_pipOnOffButton_released()
{
  stopRepeating();
}

void MainWindow::on_pipSwapButton_pressed()
{
  startRepeating(currentKeyset, PIPSwap_Key);
}

void MainWindow::on_pipSwapButton_released()
{
  stopRepeating();
}

void MainWindow::on_pipPositionButton_pressed()
{
  startRepeating(currentKeyset, PIPMove_Key);
}

void MainWindow::on_pipPositionButton_released()
{
  stopRepeating();
}

void MainWindow::on_pipSourceButton_pressed()
{
  startRepeating(currentKeyset, PIPSource_Key);
}

void MainWindow::on_pipSourceButton_released()
{
  stopRepeating();
}

void MainWindow::on_scanButton_pressed()
{
  startRepeating(currentKeyset, Scan_Key);
}

void MainWindow::on_scanButton_released()
{
  stopRepeating();
}

void MainWindow::on_programButton_pressed()
{
  startRepeating(currentKeyset, Program_Key);
}

void MainWindow::on_programButton_released()
{
  stopRepeating();
}

void MainWindow::on_pictureModeButton_pressed()
{
  startRepeating(currentKeyset, PictureMode_Key);
}

void MainWindow::on_pictureModeButton_released()
{
  stopRepeating();
}

void MainWindow::on_soundModeButton_pressed()
{
  startRepeating(currentKeyset, SoundMode_Key);
}

void MainWindow::on_soundModeButton_released()
{
  stopRepeating();
}

void MainWindow::on_discTitleButton_pressed()
{
  startRepeating(currentKeyset, DiscTitle_Key);
}

void MainWindow::on_discTitleButton_released()
{
  stopRepeating();
}

void MainWindow::on_discMenuButton_pressed()
{
  startRepeating(currentKeyset, DiscMenu_Key);
}

void MainWindow::on_discMenuButton_released()
{
  stopRepeating();
}

void MainWindow::on_discSelectButton_pressed()
{
  startRepeating(currentKeyset, DiscSelect_Key);
}

void MainWindow::on_discSelectButton_released()
{
  stopRepeating();
}

void MainWindow::on_trackingPlusButton_pressed()
{
  startRepeating(currentKeyset, TrackingPlus_Key);
}

void MainWindow::on_trackingPlusButton_released()
{
  stopRepeating();
}

void MainWindow::on_trackingMinusButton_pressed()
{
  startRepeating(currentKeyset, TrackingMinus_Key);
}

void MainWindow::on_trackingMinusButton_released()
{
  stopRepeating();
}

void MainWindow::on_autoTrackingButton_pressed()
{
  startRepeating(currentKeyset, AutoTracking_Key);
}

void MainWindow::on_autoTrackingButton_released()
{
  stopRepeating();
}

void MainWindow::on_vhsSpeedButton_pressed()
{
  startRepeating(currentKeyset, VHSSpeed_Key);
}

void MainWindow::on_vhsSpeedButton_released()
{
  stopRepeating();
}

void MainWindow::on_recordButton_pressed()
{
  startRepeating(currentKeyset, Record_Key);
}

void MainWindow::on_recordButton_released()
{
  stopRepeating();
}


// Menu actions:

void MainWindow::on_actionSelectKeyset_triggered()
{
  selectKeysetForm->show();
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
  if (!item) return;  // Should probably say something here!

  PIRKeysetWidgetItem *kwi = dynamic_cast<PIRKeysetWidgetItem *>(item);

  if (!kwi) return; // Also need to say something here
  
  currentKeyset = kwi->getID();

  QSettings settings("pietrzak.org", "Pierogi");
  settings.setValue("currentKeyset", currentKeyset);

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
  settings.setValue("keysetID", currentKeyset);
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
  PIRKeysetWidgetItem *kwi = NULL;
  settings.beginWriteArray("favorites");
  while (index < count)
  {
    kwi = dynamic_cast<PIRKeysetWidgetItem *>(
      ui->favoriteKeysetsWidget->item(index));

    settings.setArrayIndex(index);
    settings.setValue("keysetID", kwi->getID());
    ++index;
  }
  settings.endArray();
}

void MainWindow::populateFavorites()
{
  QSettings settings("pietrzak.org", "Pierogi");

  int size = settings.beginReadArray("favorites");
  int index = 0;
  PIRMakeName make;
  QString name;
  unsigned int id;
//  PIRKeysetWidgetItem *kwi;

  while (index < size)
  {
    settings.setArrayIndex(index);
    id = settings.value("keysetID").toInt();

    // Sanity check: Does this keyset even exist?
    if (myKeysets->keysetExists(id))
    {
      // Keyset does exist, so continue:
      make = myKeysets->getMake(id);
      name = makeManager.getMakeString(make);
      name.append(" ");
      name.append(myKeysets->getDisplayName(id));
//    kwi = new PIRKeysetWidgetItem(name, id, make);
//    myKeysets->populateDeviceTypes(kwi, id);
      ui->favoriteKeysetsWidget->addItem(new PIRKeysetWidgetItem(name, id, make));
    }

    ++index;
  }

  settings.endArray();
}


void MainWindow::startRepeating(
  unsigned int id,
  PIRKeyName name)
{
  QMutexLocker locker(&commandIFMutex);
  if (!commandInFlight)
  {
    commandInFlight = true;
    emit buttonPressed(id, name);
  }
}


void MainWindow::stopRepeating()
{
  QMutexLocker locker(&stopRepeatingMutex);
  stopRepeatingFlag = true;
}
