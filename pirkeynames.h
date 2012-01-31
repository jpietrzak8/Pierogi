#ifndef PIRKEYNAMES_H
#define PIRKEYNAMES_H

// I will need to eventually have a set of "universal" buttons, something that
// should be able to match a decent subset of the buttons on all the remotes
// out there.  The following list should give me a decent start...
enum PIRKeyName{
  // The "Unmapped" key is a placeholder for commands with no key mapping:
  Unmapped_Key,
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
  // Power control:
  Power_Key,
  PowerOn_Key,
  PowerOff_Key,
  // Volume control:
  VolumeUp_Key,
  VolumeDown_Key,
  Mute_Key,
  // Channel control:
  ChannelUp_Key,
  ChannelDown_Key,
  PrevChannel_Key,
  Input_Key,
  // Recorded media control:
  Play_Key,
  Pause_Key,
  Stop_Key,
  Record_Key,
  RecordPause_Key,
  RecordStop_Key,
  RecordMute_Key,
  FastForward_Key,
  Rewind_Key,
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
  DiscTitle_Key,
  DiscMenu_Key,
  DiscSelect_Key,
  Angle_Key,
  // VHS / Beta / etc. keys:
  VHSSpeed_Key,
  TrackingPlus_Key,
  TrackingMinus_Key,
  AutoTracking_Key,
  // Other keys:
  Captions_Key,
  Info_Key,
  Guide_Key,
  Sleep_Key,
  PictureMode_Key, // "PMODE"
  SoundMode_Key,
  Reset_Key,
  Program_Key,
  Surround_Key,
  AspectRatio_Key,
  Audio_Key,
  Favorites_Key,
  Scan_Key,
  Zoom_Key,
  LiveTV_Key,
  TunerBand_Key
};

#endif // PIRKEYNAMES_H
