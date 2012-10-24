#ifndef PIRKEYNAMES_H
#define PIRKEYNAMES_H

// I will need to eventually have a set of "universal" buttons, something that
// should be able to match a decent subset of the buttons on all the remotes
// out there.  The following list should give me a decent start...
enum PIRKeyName{
  // The "Unmapped" key is a placeholder for commands with no key mapping:
  Unmapped_Key,

  // Power control:
  Power_Key,
  PowerOn_Key,
  PowerOff_Key,

  // Menu control:
  Menu_Key,
  Up_Key,
  Down_Key,
  Left_Key,
  Right_Key,
  Select_Key,
  Exit_Key,
  PageUp_Key,
  PageDown_Key,
  Guide_Key,

  // Number keys:
  Zero_Key,
  One_Key,
  Two_Key,
  Three_Key,
  Four_Key,
  Five_Key,
  Six_Key,
  Seven_Key,
  Eight_Key,
  Nine_Key,

  // Other keypad commands:
  Enter_Key,
  Clear_Key,
  PlusOneHundred_Key,
  Dash_Key,
  DoubleDigit_Key,

  // Volume control:
  VolumeUp_Key,
  VolumeDown_Key,
  Mute_Key,
  Surround_Key,
  RearVolumeUp_Key,
  RearVolumeDown_Key,
  CenterVolumeUp_Key,
  CenterVolumeDown_Key,
  WooferUp_Key,
  WooferDown_Key,

  // Channel control:
  ChannelUp_Key,
  ChannelDown_Key,
  PrevChannel_Key,

  // Recorded media control:
  Play_Key,
  Pause_Key,
  Stop_Key,
  FastForward_Key,
  Rewind_Key,
  PlayX2_Key,
  Next_Key,
  Previous_Key,
  StepForward_Key,
  StepBack_Key,
  Advance_Key,
  Replay_Key,
  Eject_Key,
  Random_Key,
  Repeat_Key,
  RepeatAB_Key,
  Slow_Key,
  SlowPlus_Key,
  SlowMinus_Key,
  Timer_Key,
  Clock_Key,
  Record_Key,
  RecordPause_Key,
  RecordStop_Key,
  RecordMute_Key,
  RecordTimed_Key,
  RecordPDC_Key,

  // Color buttons:
  Red_Key,
  Green_Key,
  Yellow_Key,
  Blue_Key,

  // Teletext buttons:
  Teletext_Key,
  TeletextReveal_Key,
  TeletextHold_Key,
  TeletextSize_Key,
  TeletextSelect_Key,
  TeletextTime_Key,
  TeletextAndTV_Key,
  TeletextMix_Key, // same as "AndTV"?
  TeletextDown_Key,
  TeletextUp_Key,
  TeletextBackgroundTV_Key,
  TeletextStore_Key,
  TeletextIndex_Key,
  TeletextOff_Key,

  // Picture-in-picture stuff:
  PIP_Key,
  PIPSwap_Key,
  PIPMove_Key,
  PIPSource_Key,
  PIPChannelUp_Key,
  PIPChannelDown_Key,
  PIPPause_Key,
  PIPSize_Key,
  PIPScan_Key,

  // DVD / Blue-ray / etc. keys:
  NextDisc_Key,
  PrevDisc_Key,
  DiscTitle_Key,
  DiscMenu_Key,
  DiscOne_Key,
  DiscTwo_Key,
  DiscThree_Key,
  Angle_Key,

  // VHS / Beta / etc. keys:
  VHSSpeed_Key,
  TrackingPlus_Key,
  TrackingMinus_Key,
  AutoTracking_Key,
  IndexSearch_Key, // also known as VISS
  IndexMark_Key,
  IndexErase_Key,
  OneTouchPlayBack_Key,

  // Audio/Video Adjustment Controls:
  PictureMode_Key,
  SoundMode_Key,
  NoiseReduction_Key,
  EnhancedBass_Key,
  BassUp_Key,
  BassDown_Key,
  TrebleUp_Key,
  TrebleDown_Key,
  BrightnessUp_Key,
  BrightnessDown_Key,
  ColorUp_Key,
  ColorDown_Key,
  ContrastUp_Key,
  ContrastDown_Key,
  BalanceRight_Key,
  BalanceLeft_Key,
  Keystone_Key,
  PictureMute_Key,
  Focus_Key,

  // Input Controls:
  Input_Key,
  CDInput_Key,
  PhonoInput_Key,
  TunerInput_Key,
  LineInput_Key,
  TapeInput_Key,
  AntennaInput_Key,
  Antenna2Input_Key,
  PCInput_Key,
  CompositeInput_Key,
  Composite2Input_Key,
  SVideoInput_Key,
  SVideo2Input_Key,
  ComponentInput_Key,
  Component2Input_Key,
  HDMIInput_Key,
  HDMI2Input_Key,
  HDMI3Input_Key,
  ScartInput_Key,
  AuxInput_Key,
  MDInput_Key,
  LDInput_Key,
  DVDInput_Key,
  VCRInput_Key,
  HDDInput_Key,
  CableInput_Key,
  SatInput_Key,
  DVRInput_Key,
  OpticalInput_Key,
  DigitalCoaxInput_Key,
  USBInput_Key,

  // "Program" Controls:
  Program_Key,
  Memory_Key,
  Call_Key,
  NextPreset_Key,
  PrevPreset_Key,

  // Audio controls:
//  TunerBand_Key,
  FMMode_Key,
  FM_Key,
  AM_Key, // also "MW"
  LW_Key,

  // Air Conditioner controls:
  TempUp_Key,
  TempDown_Key,
  Fan_Key,
  Cool_Key,
  Heat_Key,
  Oscillate_Key,
  FanFaster_Key,
  FanSlower_Key,
  EnergySave_Key,

  // iRobot controls:
  RobotForward_Key,
  RobotCW_Key,
  RobotCCW_Key,
  RobotSpot_Key,
  RobotMax_Key,
  RobotClean_Key,

  // Camera controls:
  OpenShutter_Key,
  DelayedOpenShutter_Key,

  // Other keys:
  Captions_Key,
  Info_Key,
  Sleep_Key,
  Reset_Key,
  AspectRatio_Key,
  Audio_Key,
  Favorites_Key,
  Scan_Key,
  Zoom_Key,
  LiveTV_Key,
  Mode_Key
};


// Need to make the key names visible to users now:
#include <map>
#include <QString>
typedef std::map<PIRKeyName, QString> KeynameCollection;
typedef std::map<QString, PIRKeyName> ReverseKeynameCollection;

class QComboBox;

class PIRKeynameMgr
{
public:
  PIRKeynameMgr();

  QString getKeynameString(
    PIRKeyName keyname);

  PIRKeyName getKeynameID(
    QString keynameString);

  void populateComboBox(
    QComboBox *cb);

private:
  KeynameCollection keynameStrings;
  ReverseKeynameCollection keynameIDs;
};

#endif // PIRKEYNAMES_H
