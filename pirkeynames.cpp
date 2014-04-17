//
// pirkeynames.cpp
//
// Copyright 2012, 2013 by John Pietrzak (jpietrzak8@gmail.com)
//
// This file is part of Pierogi.
//
// Pierogi is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// Pierogi is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#include "pirkeynames.h"

#include <QComboBox>
#include <QVariant>

PIRKeynameMgr::PIRKeynameMgr()
{
  keynameStrings[Power_Key] = "Power";
  keynameStrings[PowerOn_Key] = "Power On";
  keynameStrings[PowerOff_Key] = "Power Off";
  keynameStrings[Menu_Key] = "Menu";
  keynameStrings[Up_Key] = "Up";
  keynameStrings[Down_Key] = "Down";
  keynameStrings[Left_Key] = "Left";
  keynameStrings[Right_Key] = "Right";
  keynameStrings[Select_Key] = "Select";
  keynameStrings[Exit_Key] = "Exit";
  keynameStrings[PageUp_Key] = "Page Up";
  keynameStrings[PageDown_Key] = "Page Down";
  keynameStrings[Guide_Key] = "Guide";
  keynameStrings[Zero_Key] = "0";
  keynameStrings[One_Key] = "1";
  keynameStrings[Two_Key] = "2";
  keynameStrings[Three_Key] = "3";
  keynameStrings[Four_Key] = "4";
  keynameStrings[Five_Key] = "5";
  keynameStrings[Six_Key] = "6";
  keynameStrings[Seven_Key] = "7";
  keynameStrings[Eight_Key] = "8";
  keynameStrings[Nine_Key] = "9";
  keynameStrings[Enter_Key] = "Enter";
  keynameStrings[Clear_Key] = "Clear";
  keynameStrings[PlusOneHundred_Key] = "+100";
  keynameStrings[Dash_Key] = "-";
  keynameStrings[DoubleDigit_Key] = "-/--";
  keynameStrings[VolumeUp_Key] = "Volume Up";
  keynameStrings[VolumeDown_Key] = "Volume Down";
  keynameStrings[Mute_Key] = "Mute";
  keynameStrings[Surround_Key] = "Surround Sound";
  keynameStrings[RearVolumeUp_Key] = "Rear Volume Up";
  keynameStrings[RearVolumeDown_Key] = "Rear Volume Down";
  keynameStrings[CenterVolumeUp_Key] = "Center Volume Up";
  keynameStrings[CenterVolumeDown_Key] = "Center Volume Down";
  keynameStrings[WooferUp_Key] = "Woofer Up";
  keynameStrings[WooferDown_Key] = "Woofer Down";
  keynameStrings[ChannelUp_Key] = "Channel Up";
  keynameStrings[ChannelDown_Key] = "Channel Down";
  keynameStrings[PrevChannel_Key] = "Previous Channel";
  keynameStrings[Play_Key] = "Play";
  keynameStrings[Pause_Key] = "Pause";
  keynameStrings[Stop_Key] = "Stop";
  keynameStrings[FastForward_Key] = "Fast Forward";
  keynameStrings[Rewind_Key] = "Rewind";
  keynameStrings[PlayX2_Key] = "Play X2";
  keynameStrings[Next_Key] = "Next";
  keynameStrings[Previous_Key] = "Previous";
  keynameStrings[StepForward_Key] = "Step Forward";
  keynameStrings[StepBack_Key] = "Step Back";
  keynameStrings[Advance_Key] = "Advance";
  keynameStrings[Replay_Key] = "Replay";
  keynameStrings[Eject_Key] = "Eject";
  keynameStrings[Random_Key] = "Random";
  keynameStrings[Repeat_Key] = "Repeat";
  keynameStrings[RepeatAB_Key] = "RepeatAB";
  keynameStrings[Slow_Key] = "Slow";
  keynameStrings[SlowPlus_Key] = "Slow +";
  keynameStrings[SlowMinus_Key] = "Slow -";
  keynameStrings[Timer_Key] = "Timer";
  keynameStrings[Clock_Key] = "Clock";
  keynameStrings[Record_Key] = "Record";
  keynameStrings[RecordPause_Key] = "Record Pause";
  keynameStrings[RecordStop_Key] = "Record Stop";
  keynameStrings[RecordMute_Key] = "Record Mute";
  keynameStrings[RecordTimed_Key] = "Record Timed";
  keynameStrings[RecordPDC_Key] = "Record PDC";
  keynameStrings[Red_Key] = "Red";
  keynameStrings[Green_Key] = "Green";
  keynameStrings[Yellow_Key] = "Yellow";
  keynameStrings[Blue_Key] = "Blue";
  keynameStrings[Teletext_Key] = "Teletext";
  keynameStrings[TeletextReveal_Key] = "Teletext Reveal";
  keynameStrings[TeletextHold_Key] = "Teletext Hold";
  keynameStrings[TeletextSize_Key] = "Teletext Size";
  keynameStrings[TeletextSelect_Key] = "Teletext Select";
  keynameStrings[TeletextTime_Key] = "Teletext Time";
  keynameStrings[TeletextAndTV_Key] = "Teletext and TV";
  keynameStrings[TeletextMix_Key] = "Teletext Mix";
  keynameStrings[TeletextDown_Key] = "Teletext Down";
  keynameStrings[TeletextUp_Key] = "Teletext Up";
  keynameStrings[TeletextBackgroundTV_Key] = "Teletext Background TV";
  keynameStrings[TeletextStore_Key] = "Teletext Store";
  keynameStrings[TeletextIndex_Key] = "Teletext Index";
  keynameStrings[TeletextOff_Key] = "Teletext Off";
  keynameStrings[PIP_Key] = "PIP";
  keynameStrings[PIPSwap_Key] = "PIP Swap";
  keynameStrings[PIPMove_Key] = "PIP Move";
  keynameStrings[PIPSource_Key] = "PIP Source";
  keynameStrings[PIPChannelUp_Key] = "PIP Channel Up";
  keynameStrings[PIPChannelDown_Key] = "PIP Channel Down";
  keynameStrings[PIPPause_Key] = "PIP Pause";
  keynameStrings[PIPSize_Key] = "PIP Size";
  keynameStrings[PIPScan_Key] = "PIP Scan";
  keynameStrings[NextDisc_Key] = "Next Disc";
  keynameStrings[PrevDisc_Key] = "Previous Disc";
  keynameStrings[DiscTitle_Key] = "Disc Title";
  keynameStrings[DiscMenu_Key] = "Disc Menu";
  keynameStrings[DiscOne_Key] = "Disc One";
  keynameStrings[DiscTwo_Key] = "Disc Two";
  keynameStrings[DiscThree_Key] = "Disc Three";
  keynameStrings[Angle_Key] = "Angle";
  keynameStrings[VHSSpeed_Key] = "VHS Speed";
  keynameStrings[TrackingPlus_Key] = "Tracking +";
  keynameStrings[TrackingMinus_Key] = "Tracking -";
  keynameStrings[AutoTracking_Key] = "Auto Tracking";
  keynameStrings[IndexSearch_Key] = "Index Search";
  keynameStrings[IndexMark_Key] = "Index Mark";
  keynameStrings[IndexErase_Key] = "Index Erase";
  keynameStrings[OneTouchPlayBack_Key] = "One Touch Playback";
  keynameStrings[PictureMode_Key] = "Picture Mode";
  keynameStrings[SoundMode_Key] = "Sound Mode";
  keynameStrings[NoiseReduction_Key] = "Noise Reduction";
  keynameStrings[EnhancedBass_Key] = "Enhanced Bass";
  keynameStrings[BassUp_Key] = "Bass Up";
  keynameStrings[BassDown_Key] = "Bass Down";
  keynameStrings[TrebleUp_Key] = "Treble Up";
  keynameStrings[TrebleDown_Key] = "Treble Down";
  keynameStrings[BrightnessUp_Key] = "Brightness Up";
  keynameStrings[BrightnessDown_Key] = "Brightness Down";
  keynameStrings[ColorUp_Key] = "Color Up";
  keynameStrings[ColorDown_Key] = "Color Down";
  keynameStrings[ContrastUp_Key] = "Contrast Up";
  keynameStrings[ContrastDown_Key] = "Contrast Down";
  keynameStrings[BalanceRight_Key] = "Balance Right";
  keynameStrings[BalanceLeft_Key] = "Balance Left";
  keynameStrings[Keystone_Key] = "Keystone";
  keynameStrings[PictureMute_Key] = "Picture Mute";
  keynameStrings[Focus_Key] = "Focus";
  keynameStrings[Input_Key] = "Input";
  keynameStrings[CDInput_Key] = "CD Input";
  keynameStrings[PhonoInput_Key] = "Phono Input";
  keynameStrings[TunerInput_Key] = "Tuner Input";
  keynameStrings[LineInput_Key] = "Line Input";
  keynameStrings[TapeInput_Key] = "Tape Input";
  keynameStrings[AntennaInput_Key] = "Antenna Input";
  keynameStrings[Antenna2Input_Key] = "Antenna Input 2";
  keynameStrings[PCInput_Key] = "PC Input";
  keynameStrings[CompositeInput_Key] = "Composite Input";
  keynameStrings[Composite2Input_Key] = "Composite Input 2";
  keynameStrings[SVideoInput_Key] = "S-Video Input";
  keynameStrings[SVideo2Input_Key] = "S-Video Input 2";
  keynameStrings[ComponentInput_Key] = "Component Input";
  keynameStrings[Component2Input_Key] = "Component Input 2";
  keynameStrings[HDMIInput_Key] = "HDMI Input";
  keynameStrings[HDMI2Input_Key] = "HDMI Input 2";
  keynameStrings[HDMI3Input_Key] = "HDMI Input 3";
  keynameStrings[ScartInput_Key] = "SCART Input";
  keynameStrings[AuxInput_Key] = "Aux Input";
  keynameStrings[MDInput_Key] = "MD Input";
  keynameStrings[LDInput_Key] = "LD Input";
  keynameStrings[DVDInput_Key] = "DVD Input";
  keynameStrings[VCRInput_Key] = "VCR Input";
  keynameStrings[HDDInput_Key] = "HDD Input";
  keynameStrings[CableInput_Key] = "Cable Input";
  keynameStrings[SatInput_Key] = "Satellite Input";
  keynameStrings[DVRInput_Key] = "DVR Input";
  keynameStrings[OpticalInput_Key] = "Optical Input";
  keynameStrings[DigitalCoaxInput_Key] = "Digital Coax Input";
  keynameStrings[USBInput_Key] = "USB Input";
  keynameStrings[ADTunerSwap_Key] = "A/D Tuner Swap"; 
  keynameStrings[SpeakerSwitch_Key] = "Switch Speaker Set";
  keynameStrings[Program_Key] = "Program";
  keynameStrings[Memory_Key] = "Memory";
  keynameStrings[Call_Key] = "Call";
  keynameStrings[NextPreset_Key] = "Next Preset";
  keynameStrings[PrevPreset_Key] = "Previous Preset";
  keynameStrings[ToggleBand_Key] = "Toggle Band";
  keynameStrings[FM_Key] = "FM";
  keynameStrings[AM_Key] = "AM";
  keynameStrings[LW_Key] = "LW";
  keynameStrings[FMMode_Key] = "FM Mode";
  keynameStrings[RDS_Key] = "RDS Mode";
  keynameStrings[TempUp_Key] = "Temperature Up";
  keynameStrings[TempDown_Key] = "Temperature Down";
  keynameStrings[Fan_Key] = "Fan";
  keynameStrings[Cool_Key] = "Cool";
  keynameStrings[Heat_Key] = "Heat";
  keynameStrings[Oscillate_Key] = "Oscillate";
  keynameStrings[FanFaster_Key] = "Fan Faster";
  keynameStrings[FanSlower_Key] = "Fan Slower";
  keynameStrings[EnergySave_Key] = "Energy Save Mode";
  keynameStrings[ACSendCommand_Key] = "Send Stateful AC Command";
  keynameStrings[ACSetTimer_Key] = "Set AC Timer";
  keynameStrings[RobotForward_Key] = "Robot Forward";
  keynameStrings[RobotCW_Key] = "Robot Clockwise";
  keynameStrings[RobotCCW_Key] = "Robot Counterclockwise";
  keynameStrings[RobotSpot_Key] = "Robot Spot";
  keynameStrings[RobotMax_Key] = "Robot Max";
  keynameStrings[RobotClean_Key] = "Robot Clean";
  keynameStrings[PSSelect_Key] = "PS Select";
  keynameStrings[PSStart_Key] = "PS Start";
  keynameStrings[PSL1_Key] = "PS Left 1";
  keynameStrings[PSL2_Key] = "PS Left 2";
  keynameStrings[PSL3_Key] = "PS Left 3";
  keynameStrings[PSR1_Key] = "PS Right 1";
  keynameStrings[PSR2_Key] = "PS Right 2";
  keynameStrings[PSR3_Key] = "PS Right 3";
  keynameStrings[PSUp_Key] = "PS Up";
  keynameStrings[PSDown_Key] = "PS Down";
  keynameStrings[PSLeft_Key] = "PS Left";
  keynameStrings[PSRight_Key] = "PS Right";
  keynameStrings[PSTriangle_Key] = "PS Triangle";
  keynameStrings[PSCircle_Key] = "PS Circle";
  keynameStrings[PSCross_Key] = "PS Cross";
  keynameStrings[PSSquare_Key] = "PS Square";
  keynameStrings[OpenShutter_Key] = "Open Shutter";
  keynameStrings[DelayedOpenShutter_Key] = "Open Shutter After Delay";
  keynameStrings[ServiceMenu_Key] = "Service Menu";
  keynameStrings[FactoryReset_Key] = "Factory Reset";
  keynameStrings[Captions_Key] = "Captions";
  keynameStrings[Info_Key] = "Info";
  keynameStrings[Sleep_Key] = "Sleep";
  keynameStrings[Reset_Key] = "Reset";
  keynameStrings[AspectRatio_Key] = "Aspect Ratio";
  keynameStrings[Audio_Key] = "I/II";
  keynameStrings[Favorites_Key] = "Favorites";
  keynameStrings[Scan_Key] = "Scan";
  keynameStrings[Zoom_Key] = "Zoom";
  keynameStrings[LiveTV_Key] = "Live TV";
  keynameStrings[Mode_Key] = "Mode";

  KeynameCollection::const_iterator i = keynameStrings.begin();
  while (i != keynameStrings.end())
  {
    keynameIDs[i->second] = i->first;
    ++i;
  }
}


QString PIRKeynameMgr::getKeynameString(
  PIRKeyName keyname)
{
  return keynameStrings[keyname];
}


PIRKeyName PIRKeynameMgr::getKeynameID(
  QString keynameString)
{
  ReverseKeynameCollection::const_iterator i = keynameIDs.find(keynameString);

  if (i != keynameIDs.end())
  {
    return i->second;
  }
  else
  {
    return Unmapped_Key;
  }
}


PIRKeyName PIRKeynameMgr::getKeynameID(
  QStringRef keynameString)
{
  QString tempString = keynameString.toString();

  return getKeynameID(tempString);
}


void PIRKeynameMgr::populateComboBox(
  QComboBox *cb)
{
  ReverseKeynameCollection::const_iterator i = keynameIDs.begin();
  while (i != keynameIDs.end())
  {
    cb->addItem(i->first, QVariant(i->second));
    ++i;
  }
}
