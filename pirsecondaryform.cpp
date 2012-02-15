#include "pirsecondaryform.h"
#include "ui_pirsecondaryform.h"
#include "mainwindow.h"
#include "pirkeysetmanager.h"

PIRSecondaryForm::PIRSecondaryForm(QWidget *parent) :
  QWidget(parent),
  ui(new Ui::PIRSecondaryForm)
{
  ui->setupUi(this);

  mainWindow = dynamic_cast<MainWindow *>(parent);

  setAttribute(Qt::WA_Maemo5StackedWindow);
  setWindowFlags(windowFlags() | Qt::Window);
}

PIRSecondaryForm::~PIRSecondaryForm()
{
  delete ui;
}

void PIRSecondaryForm::enableButtons(
  const PIRKeysetManager *keyset,
  unsigned int id)
{
  // TV Tab
  emit teletextEnabled(keyset->hasKey(id, Teletext_Key));
  emit teletextSizeEnabled(keyset->hasKey(id, TeletextSize_Key));
  emit favoritesEnabled(keyset->hasKey(id, Favorites_Key));
  emit pageUpEnabled(keyset->hasKey(id, PageUp_Key));
  emit teletextHoldEnabled(keyset->hasKey(id, TeletextHold_Key));
  emit teletextRevealEnabled(keyset->hasKey(id, TeletextReveal_Key));
  emit liveTVEnabled(keyset->hasKey(id, LiveTV_Key));
  emit pageDownEnabled(keyset->hasKey(id, PageDown_Key));
  emit pipEnabled(keyset->hasKey(id, PIP_Key));
  emit pipSwapEnabled(keyset->hasKey(id, PIPSwap_Key));
  emit pipMoveEnabled(keyset->hasKey(id, PIPMove_Key));
  emit pipSourceEnabled(keyset->hasKey(id, PIPSource_Key));
  emit pipChannelUpEnabled(keyset->hasKey(id, PIPChannelUp_Key));
  emit pipChannelDownEnabled(keyset->hasKey(id, PIPChannelDown_Key));
  emit pipPauseEnabled(keyset->hasKey(id, PIPPause_Key));
  emit pipSizeEnabled(keyset->hasKey(id, PIPSize_Key));

  // Media2 Tab
  emit tunerBandEnabled(keyset->hasKey(id, TunerBand_Key));
  emit programEnabled(keyset->hasKey(id, Program_Key));
  emit memoryEnabled(keyset->hasKey(id, Memory_Key));
  emit callEnabled(keyset->hasKey(id, Call_Key));
  emit autoTrackingEnabled(keyset->hasKey(id, AutoTracking_Key));
  emit trackingMinusEnabled(keyset->hasKey(id, TrackingMinus_Key));
  emit trackingPlusEnabled(keyset->hasKey(id, TrackingPlus_Key));
  emit vhsSpeedEnabled(keyset->hasKey(id, VHSSpeed_Key));
  emit slowEnabled(keyset->hasKey(id, Slow_Key));
  emit slowMinusEnabled(keyset->hasKey(id, SlowMinus_Key));
  emit slowPlusEnabled(keyset->hasKey(id, SlowPlus_Key));
  emit nextDiscEnabled(keyset->hasKey(id, NextDisc_Key));
  emit repeatEnabled(keyset->hasKey(id, Repeat_Key));
  emit repeatABEnabled(keyset->hasKey(id, RepeatAB_Key));
  emit randomEnabled(keyset->hasKey(id, Random_Key));
  emit discTitleEnabled(keyset->hasKey(id, DiscTitle_Key));

  // Input Tab
  emit cdInputEnabled(keyset->hasKey(id, CDInput_Key));
  emit tapeInputEnabled(keyset->hasKey(id, TapeInput_Key));
  emit phonoInputEnabled(keyset->hasKey(id, PhonoInput_Key));
  emit tunerInputEnabled(keyset->hasKey(id, TunerInput_Key));
  emit pcInputEnabled(keyset->hasKey(id, PCInput_Key));
  emit hdmiInputEnabled(keyset->hasKey(id, HDMIInput_Key));
  emit dvdInputEnabled(keyset->hasKey(id, DVDInput_Key));
  emit vcrInputEnabled(keyset->hasKey(id, VCRInput_Key));
  emit antennaInputEnabled(keyset->hasKey(id, AntennaInput_Key));
  emit cableInputEnabled(keyset->hasKey(id, CableInput_Key));
  emit satelliteInputEnabled(keyset->hasKey(id, SatInput_Key));
  emit auxInputEnabled(keyset->hasKey(id, AuxInput_Key));

  // Adjust Tab
  emit bassUpEnabled(keyset->hasKey(id, BassUp_Key));
  emit trebleUpEnabled(keyset->hasKey(id, TrebleUp_Key));
  emit enhancedBassEnabled(keyset->hasKey(id, EnhancedBass_Key));
  emit noiseReductionEnabled(keyset->hasKey(id, NoiseReduction_Key));
  emit bassDownEnabled(keyset->hasKey(id, BassDown_Key));
  emit trebleDownEnabled(keyset->hasKey(id, TrebleDown_Key));
  emit balanceLeftEnabled(keyset->hasKey(id, BalanceLeft_Key));
  emit balanceRightEnabled(keyset->hasKey(id, BalanceRight_Key));
  emit surroundEnabled(keyset->hasKey(id, Surround_Key));
  emit colorUpEnabled(keyset->hasKey(id, ColorUp_Key));
  emit brightnessUpEnabled(keyset->hasKey(id, BrightnessUp_Key));
  emit contrastUpEnabled(keyset->hasKey(id, ContrastUp_Key));
  emit zoomEnabled(keyset->hasKey(id, Zoom_Key));
  emit colorDownEnabled(keyset->hasKey(id, ColorDown_Key));
  emit brightnessDownEnabled(keyset->hasKey(id, BrightnessDown_Key));
  emit contrastDownEnabled(keyset->hasKey(id, ContrastDown_Key));
}

// TV Tab

void PIRSecondaryForm::on_teletextButton_pressed()
{
  mainWindow->startRepeating(Teletext_Key);
}

void PIRSecondaryForm::on_teletextButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_teletextSizeButton_pressed()
{
  mainWindow->startRepeating(TeletextSize_Key);
}

void PIRSecondaryForm::on_teletextSizeButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_favoritesButton_pressed()
{
  mainWindow->startRepeating(Favorites_Key);
}

void PIRSecondaryForm::on_favoritesButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_pageUpButton_pressed()
{
  mainWindow->startRepeating(PageUp_Key);
}

void PIRSecondaryForm::on_pageUpButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_teletextHoldButton_pressed()
{
  mainWindow->startRepeating(TeletextHold_Key);
}

void PIRSecondaryForm::on_teletextHoldButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_teletextRevealButton_pressed()
{
  mainWindow->startRepeating(TeletextReveal_Key);
}

void PIRSecondaryForm::on_teletextRevealButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_liveTVButton_pressed()
{
  mainWindow->startRepeating(LiveTV_Key);
}

void PIRSecondaryForm::on_liveTVButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_pageDownButton_pressed()
{
  mainWindow->startRepeating(PageDown_Key);
}

void PIRSecondaryForm::on_pageDownButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_pipButton_pressed()
{
  mainWindow->startRepeating(PIP_Key);
}

void PIRSecondaryForm::on_pipButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_pipSwapButton_pressed()
{
  mainWindow->startRepeating(PIPSwap_Key);
}

void PIRSecondaryForm::on_pipSwapButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_pipMoveButton_pressed()
{
  mainWindow->startRepeating(PIPMove_Key);
}

void PIRSecondaryForm::on_pipMoveButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_pipSourceButton_pressed()
{
  mainWindow->startRepeating(PIPSource_Key);
}

void PIRSecondaryForm::on_pipSourceButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_pipChannelUpButton_pressed()
{
  mainWindow->startRepeating(PIPChannelUp_Key);
}

void PIRSecondaryForm::on_pipChannelUpButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_pipChannelDownButton_pressed()
{
  mainWindow->startRepeating(PIPChannelDown_Key);
}

void PIRSecondaryForm::on_pipChannelDownButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_pipPauseButton_pressed()
{
  mainWindow->startRepeating(PIPPause_Key);
}

void PIRSecondaryForm::on_pipPauseButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_pipSizeButton_pressed()
{
  mainWindow->startRepeating(PIPSize_Key);
}

void PIRSecondaryForm::on_pipSizeButton_released()
{
  mainWindow->stopRepeating();
}


// Media 2 Tab

void PIRSecondaryForm::on_tunerBandButton_pressed()
{
  mainWindow->startRepeating(TunerBand_Key);
}

void PIRSecondaryForm::on_tunerBandButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_programButton_pressed()
{
  mainWindow->startRepeating(Program_Key);
}

void PIRSecondaryForm::on_programButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_memoryButton_pressed()
{
  mainWindow->startRepeating(Memory_Key);
}

void PIRSecondaryForm::on_memoryButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_callButton_pressed()
{
  mainWindow->startRepeating(Call_Key);
}

void PIRSecondaryForm::on_callButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_autoTrackingButton_pressed()
{
  mainWindow->startRepeating(AutoTracking_Key);
}

void PIRSecondaryForm::on_autoTrackingButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_trackingMinusButton_pressed()
{
  mainWindow->startRepeating(TrackingMinus_Key);
}

void PIRSecondaryForm::on_trackingMinusButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_trackingPlusButton_pressed()
{
  mainWindow->startRepeating(TrackingPlus_Key);
}

void PIRSecondaryForm::on_trackingPlusButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_vhsSpeedButton_pressed()
{
  mainWindow->startRepeating(VHSSpeed_Key);
}

void PIRSecondaryForm::on_vhsSpeedButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_slowButton_pressed()
{
  mainWindow->startRepeating(Slow_Key);
}

void PIRSecondaryForm::on_slowButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_slowMinusButton_pressed()
{
  mainWindow->startRepeating(SlowMinus_Key);
}

void PIRSecondaryForm::on_slowMinusButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_slowPlusButton_pressed()
{
  mainWindow->startRepeating(SlowPlus_Key);
}

void PIRSecondaryForm::on_slowPlusButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_discSelectButton_pressed()
{
  mainWindow->startRepeating(NextDisc_Key);
}

void PIRSecondaryForm::on_discSelectButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_repeatButton_pressed()
{
  mainWindow->startRepeating(Repeat_Key);
}

void PIRSecondaryForm::on_repeatButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_repeatABButton_pressed()
{
  mainWindow->startRepeating(RepeatAB_Key);
}

void PIRSecondaryForm::on_repeatABButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_randomButton_pressed()
{
  mainWindow->startRepeating(Random_Key);
}

void PIRSecondaryForm::on_randomButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_discTitleButton_pressed()
{
  mainWindow->startRepeating(DiscTitle_Key);
}

void PIRSecondaryForm::on_discTitleButton_released()
{
  mainWindow->stopRepeating();
}


// Input Tab

void PIRSecondaryForm::on_cdInputButton_pressed()
{
  mainWindow->startRepeating(CDInput_Key);
}

void PIRSecondaryForm::on_cdInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_tapeInputButton_pressed()
{
  mainWindow->startRepeating(TapeInput_Key);
}

void PIRSecondaryForm::on_tapeInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_phonoInputButton_pressed()
{
  mainWindow->startRepeating(PhonoInput_Key);
}

void PIRSecondaryForm::on_phonoInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_tunerInputButton_pressed()
{
  mainWindow->startRepeating(TunerInput_Key);
}

void PIRSecondaryForm::on_tunerInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_pcInputButton_pressed()
{
  mainWindow->startRepeating(PCInput_Key);
}

void PIRSecondaryForm::on_pcInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_hdmiInputButton_pressed()
{
  mainWindow->startRepeating(HDMIInput_Key);
}

void PIRSecondaryForm::on_hdmiInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_dvdInputButton_pressed()
{
  mainWindow->startRepeating(DVDInput_Key);
}

void PIRSecondaryForm::on_dvdInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_vcrInputButton_pressed()
{
  mainWindow->startRepeating(VCRInput_Key);
}

void PIRSecondaryForm::on_vcrInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_antennaInputButton_pressed()
{
  mainWindow->startRepeating(AntennaInput_Key);
}

void PIRSecondaryForm::on_antennaInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_cableInputButton_pressed()
{
  mainWindow->startRepeating(CableInput_Key);
}

void PIRSecondaryForm::on_cableInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_satelliteInputButton_pressed()
{
  mainWindow->startRepeating(SatInput_Key);
}

void PIRSecondaryForm::on_satelliteInputButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_auxInputButton_pressed()
{
  mainWindow->startRepeating(AuxInput_Key);
}

void PIRSecondaryForm::on_auxInputButton_released()
{
  mainWindow->stopRepeating();
}


// Adjust Tab

void PIRSecondaryForm::on_bassUpButton_pressed()
{
  mainWindow->startRepeating(BassUp_Key);
}

void PIRSecondaryForm::on_bassUpButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_trebleUpButton_pressed()
{
  mainWindow->startRepeating(TrebleUp_Key);
}

void PIRSecondaryForm::on_trebleUpButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_enhancedBassButton_pressed()
{
  mainWindow->startRepeating(EnhancedBass_Key);
}

void PIRSecondaryForm::on_enhancedBassButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_noiseReductionButton_pressed()
{
  mainWindow->startRepeating(NoiseReduction_Key);
}

void PIRSecondaryForm::on_noiseReductionButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_bassDownButton_pressed()
{
  mainWindow->startRepeating(BassDown_Key);
}

void PIRSecondaryForm::on_bassDownButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_trebleDownButton_pressed()
{
  mainWindow->startRepeating(TrebleDown_Key);
}

void PIRSecondaryForm::on_trebleDownButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_balanceLeftButton_pressed()
{
  mainWindow->startRepeating(BalanceLeft_Key);
}

void PIRSecondaryForm::on_balanceLeftButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_balanceRightButton_pressed()
{
  mainWindow->startRepeating(BalanceRight_Key);
}

void PIRSecondaryForm::on_balanceRightButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_surroundButton_pressed()
{
  mainWindow->startRepeating(Surround_Key);
}

void PIRSecondaryForm::on_surroundButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_colorUpButton_pressed()
{
  mainWindow->startRepeating(ColorUp_Key);
}

void PIRSecondaryForm::on_colorUpButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_brightnessUpButton_pressed()
{
  mainWindow->startRepeating(BrightnessUp_Key);
}

void PIRSecondaryForm::on_brightnessUpButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_contrastUpButton_pressed()
{
  mainWindow->startRepeating(ContrastUp_Key);
}

void PIRSecondaryForm::on_contrastUpButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_zoomButton_pressed()
{
  mainWindow->startRepeating(Zoom_Key);
}

void PIRSecondaryForm::on_zoomButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_colorDownButton_pressed()
{
  mainWindow->startRepeating(ColorDown_Key);
}

void PIRSecondaryForm::on_colorDownButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_brightnessDownButton_pressed()
{
  mainWindow->startRepeating(BrightnessDown_Key);
}

void PIRSecondaryForm::on_brightnessDownButton_released()
{
  mainWindow->stopRepeating();
}

void PIRSecondaryForm::on_contrastDownButton_pressed()
{
  mainWindow->startRepeating(ContrastDown_Key);
}

void PIRSecondaryForm::on_contrastDownButton_released()
{
  mainWindow->stopRepeating();
}
