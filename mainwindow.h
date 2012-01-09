#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
//#include <QThread>

#include "selectionwindow.h"
#include "pirdocumentationform.h"
#include "piraboutform.h"
#include "pirkeysetmanager.h"
#include "pirmodprobe.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
  Q_OBJECT

public:
  enum ScreenOrientation {
    ScreenOrientationLockPortrait,
    ScreenOrientationLockLandscape,
    ScreenOrientationAuto
  };

  explicit MainWindow(QWidget *parent = 0);
  virtual ~MainWindow();

  // Note that this will only have an effect on Symbian and Fremantle.
  void setOrientation(ScreenOrientation orientation);

  void showExpanded();

signals:
  // Main keys
  void powerEnabled(bool);
  void volumeUpEnabled(bool);
  void volumeDownEnabled(bool);
  void channelUpEnabled(bool);
  void channelDownEnabled(bool);

  // Utility keys:
  void redEnabled(bool);
  void greenEnabled(bool);
  void yellowEnabled(bool);
  void blueEnabled(bool);
  void aspectRatioEnabled(bool);
  void surroundEnabled(bool);
  void languageEnabled(bool);
  void favoritesEnabled(bool);
  void captionsEnabled(bool);
  void inputEnabled(bool);
  void muteEnabled(bool);
  void sleepEnabled(bool);

  // Keypad
  void zeroEnabled(bool);
  void oneEnabled(bool);
  void twoEnabled(bool);
  void threeEnabled(bool);
  void fourEnabled(bool);
  void fiveEnabled(bool);
  void sixEnabled(bool);
  void sevenEnabled(bool);
  void eightEnabled(bool);
  void nineEnabled(bool);
  void enterEnabled(bool);
  void clearEnabled(bool);
  void dashEnabled(bool);
  void plusOneHundredEnabled(bool);
  void doubleDigitEnabled(bool);
  void prevChannelEnabled(bool);

  // Menu Keys
  void menuEnabled(bool);
  void upEnabled(bool);
  void downEnabled(bool);
  void leftEnabled(bool);
  void rightEnabled(bool);
  void selectEnabled(bool);
  void exitEnabled(bool);
  void infoEnabled(bool);
  void guideEnabled(bool);

  // Media keys
  void playEnabled(bool);
  void pauseEnabled(bool);
  void stopEnabled(bool);
  void fastForwardEnabled(bool);
  void reverseEnabled(bool);
  void nextEnabled(bool);
  void previousEnabled(bool);
  void stepForwardEnabled(bool);
  void stepBackEnabled(bool);
  void advanceEnabled(bool);
  void replayEnabled(bool);
  void ejectEnabled(bool);

  // Other Keys
  void pipEnabled(bool);
  void pipSwapEnabled(bool);
  void pipMoveEnabled(bool);
  void pipSourceEnabled(bool);
  void scanEnabled(bool);
  void programEnabled(bool);
  void pictureModeEnabled(bool);
  void soundModeEnabled(bool);
  void discTitleEnabled(bool);
  void discMenuEnabled(bool);
  void discSelectEnabled(bool);
  void recordEnabled(bool);
  void trackingMinusEnabled(bool);
  void trackingPlusEnabled(bool);
  void autoTrackingEnabled(bool);
  void vhsSpeedEnabled(bool);

  void keysetMakeChanged(QString);
  void keysetNameChanged(QString);

  void buttonPressed(
    unsigned int keysetID,
    PIRKeyName name);

  void buttonReleased();

public slots:
  void receivedExternalWarning(
    const char *warning);

private slots:
  // Main tab slots:
  void on_powerButton_pressed();
  void on_powerButton_released();
  void on_mainChannelUpButton_pressed();
  void on_mainChannelUpButton_released();
  void on_mainChannelDownButton_pressed();
  void on_mainChannelDownButton_released();
  void on_mainVolumeUp_pressed();
  void on_mainVolumeUp_released();
  void on_mainVolumeDownButton_pressed();
  void on_mainVolumeDownButton_released();

  // Utility tab slots:
  void on_redButton_pressed();
  void on_redButton_released();
  void on_greenButton_pressed();
  void on_greenButton_released();
  void on_yellowButton_pressed();
  void on_yellowButton_released();
  void on_blueButton_pressed();
  void on_blueButton_released();
  void on_aspectRatioButton_pressed();
  void on_aspectRatioButton_released();
  void on_surroundButton_pressed();
  void on_surroundButton_released();
  void on_languageButton_pressed();
  void on_languageButton_released();
  void on_favoritesButton_pressed();
  void on_favoritesButton_released();
  void on_captionButton_pressed();
  void on_captionButton_released();
  void on_inputButton_pressed();
  void on_inputButton_released();
  void on_sleepButton_pressed();
  void on_sleepButton_released();
  void on_muteButton_pressed();
  void on_muteButton_released();

  // Keypad tab slots:
  void on_oneButton_pressed();
  void on_oneButton_released();
  void on_twoButton_pressed();
  void on_twoButton_released();
  void on_threeButton_pressed();
  void on_threeButton_released();
  void on_fourButton_pressed();
  void on_fourButton_released();
  void on_fiveButton_pressed();
  void on_fiveButton_released();
  void on_sixButton_pressed();
  void on_sixButton_released();
  void on_sevenButton_pressed();
  void on_sevenButton_released();
  void on_eightButton_pressed();
  void on_eightButton_released();
  void on_nineButton_pressed();
  void on_nineButton_released();
  void on_zeroButton_pressed();
  void on_zeroButton_released();
  void on_enterButton_pressed();
  void on_enterButton_released();
  void on_clearButton_pressed();
  void on_clearButton_released();
  void on_prevChannelButton_pressed();
  void on_prevChannelButton_released();
  void on_plusOneHundredButton_pressed();
  void on_plusOneHundredButton_released();
  void on_dashButton_pressed();
  void on_dashButton_released();
  void on_doubleDigitButton_pressed();
  void on_doubleDigitButton_released();

  // Menu tab slots:
  void on_upButton_pressed();
  void on_upButton_released();
  void on_leftButton_pressed();
  void on_leftButton_released();
  void on_rightButton_pressed();
  void on_rightButton_released();
  void on_downButton_pressed();
  void on_downButton_released();
  void on_selectButton_pressed();
  void on_selectButton_released();
  void on_menuButton_pressed();
  void on_menuButton_released();
  void on_exitButton_pressed();
  void on_exitButton_released();

  // Media tab slots:
  void on_mediaPreviousButton_pressed();
  void on_mediaPreviousButton_released();
  void on_mediaNextButton_pressed();
  void on_mediaNextButton_released();
  void on_replayButton_pressed();
  void on_replayButton_released();
  void on_advanceButton_pressed();
  void on_advanceButton_released();
  void on_stepBackButton_pressed();
  void on_stepBackButton_released();
  void on_stepForwardButton_pressed();
  void on_stepForwardButton_released();
  void on_reverseButton_pressed();
  void on_reverseButton_released();
  void on_fastForwardButton_pressed();
  void on_fastForwardButton_released();
  void on_playButton_pressed();
  void on_playButton_released();
  void on_pauseButton_pressed();
  void on_pauseButton_released();
  void on_stopButton_pressed();
  void on_stopButton_released();
  void on_ejectButton_pressed();
  void on_ejectButton_released();

  // Misc tab slots:
  void on_pipOnOffButton_pressed();
  void on_pipOnOffButton_released();
  void on_pipSwapButton_pressed();
  void on_pipSwapButton_released();
  void on_recordButton_pressed();
  void on_recordButton_released();
  void on_pipPositionButton_pressed();
  void on_pipPositionButton_released();
  void on_pipSourceButton_pressed();
  void on_pipSourceButton_released();
  void on_scanButton_pressed();
  void on_scanButton_released();
  void on_programButton_pressed();
  void on_programButton_released();
  void on_pictureModeButton_pressed();
  void on_pictureModeButton_released();
  void on_soundModeButton_pressed();
  void on_soundModeButton_released();
  void on_discTitleButton_pressed();
  void on_discTitleButton_released();
  void on_discMenuButton_pressed();
  void on_discMenuButton_released();
  void on_discSelectButton_pressed();
  void on_discSelectButton_released();
  void on_trackingPlusButton_pressed();
  void on_trackingPlusButton_released();
  void on_trackingMinusButton_pressed();
  void on_trackingMinusButton_released();
  void on_autoTrackingButton_pressed();
  void on_autoTrackingButton_released();
  void on_vhsSpeedButton_pressed();
  void on_vhsSpeedButton_released();

  // Favorites tab actions:
  void on_addKeysetButton_clicked();
  void on_removeKeysetButton_clicked();

  // Menu actions:
  void on_actionSelectKeyset_triggered();
  void on_actionAbout_triggered();
  void on_actionDocumentation_triggered();

  // Internal actions:
  void keysetSelectionChanged(
    QListWidgetItem *item);

private:
  void enableButtons();

  void stopRepeating();

  void populateFavorites();

  Ui::MainWindow *ui;

  SelectionWindow *mySelectionWindow;
  PIRDocumentationForm *documentationForm;
  PIRAboutForm *aboutForm;

  PIRKeysetManager *myKeysets;

  unsigned int currentKeyset;

  PIRModprobe modprobeObj;
};


inline void MainWindow::stopRepeating()
{
  myKeysets->stopRepeating();
}

#endif // MAINWINDOW_H
