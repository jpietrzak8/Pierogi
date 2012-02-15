#ifndef PIRSECONDARYFORM_H
#define PIRSECONDARYFORM_H

#include <QWidget>

namespace Ui {
class PIRSecondaryForm;
}

class MainWindow;
class PIRKeysetManager;

class PIRSecondaryForm : public QWidget
{
  Q_OBJECT
  
public:
  explicit PIRSecondaryForm(QWidget *parent = 0);

  ~PIRSecondaryForm();

  void enableButtons(
    const PIRKeysetManager *keyset,
    unsigned int id);

signals:
  // TV Tab:
  void teletextEnabled(bool);
  void teletextSizeEnabled(bool);
  void favoritesEnabled(bool);
  void pageUpEnabled(bool);
  void teletextHoldEnabled(bool);
  void teletextRevealEnabled(bool);
  void liveTVEnabled(bool);
  void pageDownEnabled(bool);
  void pipEnabled(bool);
  void pipSwapEnabled(bool);
  void pipMoveEnabled(bool);
  void pipSourceEnabled(bool);
  void pipChannelUpEnabled(bool);
  void pipChannelDownEnabled(bool);
  void pipPauseEnabled(bool);
  void pipSizeEnabled(bool);

  // Media2 Tab
  void tunerBandEnabled(bool);
  void programEnabled(bool);
  void memoryEnabled(bool);
  void callEnabled(bool);
  void autoTrackingEnabled(bool);
  void trackingMinusEnabled(bool);
  void trackingPlusEnabled(bool);
  void vhsSpeedEnabled(bool);
  void slowEnabled(bool);
  void slowMinusEnabled(bool);
  void slowPlusEnabled(bool);
  void nextDiscEnabled(bool);
  void repeatEnabled(bool);
  void repeatABEnabled(bool);
  void randomEnabled(bool);
  void discTitleEnabled(bool);

  // Input Tab
  void cdInputEnabled(bool);
  void tapeInputEnabled(bool);
  void phonoInputEnabled(bool);
  void tunerInputEnabled(bool);
  void pcInputEnabled(bool);
  void hdmiInputEnabled(bool);
  void dvdInputEnabled(bool);
  void vcrInputEnabled(bool);
  void antennaInputEnabled(bool);
  void cableInputEnabled(bool);
  void satelliteInputEnabled(bool);
  void auxInputEnabled(bool);

  // Adjust Tab
  void bassUpEnabled(bool);
  void trebleUpEnabled(bool);
  void enhancedBassEnabled(bool);
  void noiseReductionEnabled(bool);
  void bassDownEnabled(bool);
  void trebleDownEnabled(bool);
  void balanceLeftEnabled(bool);
  void balanceRightEnabled(bool);
  void surroundEnabled(bool);
  void colorUpEnabled(bool);
  void brightnessUpEnabled(bool);
  void contrastUpEnabled(bool);
  void zoomEnabled(bool);
  void colorDownEnabled(bool);
  void brightnessDownEnabled(bool);
  void contrastDownEnabled(bool);
  
private slots:
  // TV Tab:
  void on_teletextButton_pressed();
  void on_teletextButton_released();
  void on_teletextSizeButton_pressed();
  void on_teletextSizeButton_released();
  void on_favoritesButton_pressed();
  void on_favoritesButton_released();
  void on_pageUpButton_pressed();
  void on_pageUpButton_released();
  void on_teletextHoldButton_pressed();
  void on_teletextHoldButton_released();
  void on_teletextRevealButton_pressed();
  void on_teletextRevealButton_released();
  void on_liveTVButton_pressed();
  void on_liveTVButton_released();
  void on_pageDownButton_pressed();
  void on_pageDownButton_released();
  void on_pipButton_pressed();
  void on_pipButton_released();
  void on_pipSwapButton_pressed();
  void on_pipSwapButton_released();
  void on_pipMoveButton_pressed();
  void on_pipMoveButton_released();
  void on_pipSourceButton_pressed();
  void on_pipSourceButton_released();
  void on_pipChannelUpButton_pressed();
  void on_pipChannelUpButton_released();
  void on_pipChannelDownButton_pressed();
  void on_pipChannelDownButton_released();
  void on_pipPauseButton_pressed();
  void on_pipPauseButton_released();
  void on_pipSizeButton_pressed();
  void on_pipSizeButton_released();

  // Media2 Tab
  void on_tunerBandButton_pressed();
  void on_tunerBandButton_released();
  void on_programButton_pressed();
  void on_programButton_released();
  void on_memoryButton_pressed();
  void on_memoryButton_released();
  void on_callButton_pressed();
  void on_callButton_released();
  void on_autoTrackingButton_pressed();
  void on_autoTrackingButton_released();
  void on_trackingMinusButton_pressed();
  void on_trackingMinusButton_released();
  void on_trackingPlusButton_pressed();
  void on_trackingPlusButton_released();
  void on_vhsSpeedButton_pressed();
  void on_vhsSpeedButton_released();
  void on_slowButton_pressed();
  void on_slowButton_released();
  void on_slowMinusButton_pressed();
  void on_slowMinusButton_released();
  void on_slowPlusButton_pressed();
  void on_slowPlusButton_released();
  void on_discSelectButton_pressed();
  void on_discSelectButton_released();
  void on_repeatButton_pressed();
  void on_repeatButton_released();
  void on_repeatABButton_pressed();
  void on_repeatABButton_released();
  void on_randomButton_pressed();
  void on_randomButton_released();
  void on_discTitleButton_pressed();
  void on_discTitleButton_released();

  // Input Tab
  void on_cdInputButton_pressed();
  void on_cdInputButton_released();
  void on_tapeInputButton_pressed();
  void on_tapeInputButton_released();
  void on_phonoInputButton_pressed();
  void on_phonoInputButton_released();
  void on_tunerInputButton_pressed();
  void on_tunerInputButton_released();
  void on_pcInputButton_pressed();
  void on_pcInputButton_released();
  void on_hdmiInputButton_pressed();
  void on_hdmiInputButton_released();
  void on_dvdInputButton_pressed();
  void on_dvdInputButton_released();
  void on_vcrInputButton_pressed();
  void on_vcrInputButton_released();
  void on_antennaInputButton_pressed();
  void on_antennaInputButton_released();
  void on_cableInputButton_pressed();
  void on_cableInputButton_released();
  void on_satelliteInputButton_pressed();
  void on_satelliteInputButton_released();
  void on_auxInputButton_pressed();
  void on_auxInputButton_released();

  // Adjust Tab
  void on_bassUpButton_pressed();
  void on_bassUpButton_released();
  void on_trebleUpButton_pressed();
  void on_trebleUpButton_released();
  void on_enhancedBassButton_pressed();
  void on_enhancedBassButton_released();
  void on_noiseReductionButton_pressed();
  void on_noiseReductionButton_released();
  void on_bassDownButton_pressed();
  void on_bassDownButton_released();
  void on_trebleDownButton_pressed();
  void on_trebleDownButton_released();
  void on_balanceLeftButton_pressed();
  void on_balanceLeftButton_released();
  void on_balanceRightButton_pressed();
  void on_balanceRightButton_released();
  void on_colorUpButton_pressed();
  void on_colorUpButton_released();
  void on_brightnessUpButton_pressed();
  void on_brightnessUpButton_released();
  void on_contrastUpButton_pressed();
  void on_contrastUpButton_released();
  void on_colorDownButton_pressed();
  void on_colorDownButton_released();
  void on_brightnessDownButton_pressed();
  void on_brightnessDownButton_released();
  void on_contrastDownButton_pressed();
  void on_contrastDownButton_released();
  void on_surroundButton_pressed();
  void on_surroundButton_released();
  void on_zoomButton_pressed();
  void on_zoomButton_released();

private:
  Ui::PIRSecondaryForm *ui;

  MainWindow *mainWindow;
};

#endif // PIRSECONDARYFORM_H
