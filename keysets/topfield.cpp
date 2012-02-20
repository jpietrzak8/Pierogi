#include "topfield.h"
#include "protocols/necprotocol.h"

TopfieldPVR1::TopfieldPVR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "PVR Keyset 1",
      Topfield_Make,
      index)
{
  addControlledDevice(Topfield_Make, "PVR 4000", Other_Device);
  addControlledDevice(Topfield_Make, "PVR 5000", Other_Device);
}


void TopfieldPVR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

  setPreData(0x20, 8);

  addKey("Up", Up_Key, 0x00, 8); // "P+"
  addKey("Up", ChannelUp_Key, 0x00, 8); // "P+"
  addKey("Down", Down_Key, 0x01, 8); // "P-"
  addKey("Down", ChannelDown_Key, 0x01, 8); // "P-"
  addKey("Right", Right_Key, 0x02, 8); // "VOL+"
  addKey("Right", VolumeUp_Key, 0x02, 8); // "VOL+"
  addKey("Left", Left_Key, 0x03, 8); // "VOL-"
  addKey("Left", VolumeDown_Key, 0x03, 8); // "VOL-"
  addKey("Tv", Input_Key, 0x04, 8);
  addKey("Audio", Audio_Key, 0x05, 8);
  addKey("Pause", Pause_Key, 0x06, 8);
  addKey("Subtitles", Captions_Key, 0x07, 8);
  addKey("Sat", SatInput_Key, 0x08, 8);
  addKey("Fav", Favorites_Key, 0x09, 8);
  addKey("Power", Power_Key, 0x0A, 8);
  addKey("Mute", Mute_Key, 0x0C, 8);
  addKey("Green", Green_Key, 0x0D, 8);
  addKey("Yellow", Yellow_Key, 0x0E, 8);
  addKey("Blue", Blue_Key, 0x0F, 8);

  addKey("0", Zero_Key, 0x10, 8);
  addKey("1", One_Key, 0x11, 8);
  addKey("2", Two_Key, 0x12, 8);
  addKey("3", Three_Key, 0x13, 8);
  addKey("4", Four_Key, 0x14, 8);
  addKey("5", Five_Key, 0x15, 8);
  addKey("6", Six_Key, 0x16, 8);
  addKey("7", Seven_Key, 0x17, 8);
  addKey("8", Eight_Key, 0x18, 8);
  addKey("9", Nine_Key, 0x19, 8);
  addKey("Menu", Menu_Key, 0x1A, 8);
  addKey("Scheudle", Guide_Key, 0x1B, 8); // "GUIDE"
  addKey("Back", Exit_Key, 0x1C, 8); // "EXIT"
  addKey("Info", Info_Key, 0x1D, 8);
  addKey("Prev", PrevChannel_Key, 0x1E, 8); // "BACK"
  addKey("Ok", Select_Key, 0x1F, 8);

  addKey("UHF", AntennaInput_Key, 0x43, 8);
  addKey("Timer", Timer_Key, 0x44, 8);
  addKey("FastRew", Rewind_Key, 0x45, 8);
  addKey("Play", Play_Key, 0x46, 8);
  addKey("Teletext", Teletext_Key, 0x47, 8);
  addKey("FastFwd", FastForward_Key, 0x48, 8);
  addKey("Skip", Unmapped_Key, 0x49, 8);
  addKey("Stop", Stop_Key, 0x4A, 8);
  addKey("Rec", Record_Key, 0x4B, 8);
  addKey("White", Unmapped_Key, 0x4C, 8);
  addKey("Red", Red_Key, 0x4D, 8);

  addKey("SkipLeft", Replay_Key, 0x50, 8);
  addKey("Records", Unmapped_Key, 0x51, 8); // "LIST"
  addKey("SkipRight", Advance_Key, 0x52,8);
  addKey("Gray", Unmapped_Key, 0x5E, 8);
}


TopfieldSat1::TopfieldSat1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sat Keyset 1",
      Topfield_Make,
      index)
{
  addControlledDevice(Topfield_Make, "TF4000Fi", Sat_Device);
}


void TopfieldSat1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0xFF04, 16);

  addKey("P+", ChannelUp_Key, 0x00, 8);
  addKey("P-", ChannelDown_Key, 0x01, 8);
  addKey("V+", VolumeUp_Key, 0x02, 8);
  addKey("V-", VolumeDown_Key, 0x03, 8);
  addKey("TV/Radio", TunerInput_Key, 0x04, 8);
  addKey("Sound", Audio_Key, 0x05, 8);
  addKey("Pause", Pause_Key, 0x06, 8);
  addKey("Subtitle", Captions_Key, 0x07, 8);
  addKey("TV/STB", Input_Key, 0x08, 8);
  addKey("FAV", Favorites_Key, 0x09, 8);
  addKey("Power", Power_Key, 0x0A, 8);
  addKey("Red", Red_Key, 0x0B, 8);
  addKey("Mute", Mute_Key, 0x0C, 8);
  addKey("Green", Green_Key, 0x0D, 8);
  addKey("Yellow", Yellow_Key, 0x0E, 8);
  addKey("Blue", Blue_Key, 0x0F, 8);

  addKey("0", Zero_Key, 0x10, 8);
  addKey("1", One_Key, 0x11, 8);
  addKey("2", Two_Key, 0x12, 8);
  addKey("3", Three_Key, 0x13, 8);
  addKey("4", Four_Key, 0x14, 8);
  addKey("5", Five_Key, 0x15, 8);
  addKey("6", Six_Key, 0x16, 8);
  addKey("7", Seven_Key, 0x17, 8);
  addKey("8", Eight_Key, 0x18, 8);
  addKey("9", Nine_Key, 0x19, 8);
  addKey("Menu", Menu_Key, 0x1A, 8);
  addKey("Guide", Guide_Key, 0x1B, 8);
  addKey("Exit", Exit_Key, 0x1C, 8);
  addKey("Info", Info_Key, 0x1D, 8);
  addKey("Recall", PrevChannel_Key, 0x1E, 8);
  addKey("Ok", Select_Key, 0x1F, 8);

  addKey("M1", Unmapped_Key, 0x40, 8);
  addKey("M2", Unmapped_Key, 0x41, 8);
  addKey("M3", Unmapped_Key, 0x42, 8);
  addKey("UHF", AntennaInput_Key, 0x43, 8);
  addKey("Sleep", Sleep_Key, 0x44, 8);
  addKey("Teletext", Teletext_Key, 0x47, 8);

  addKey("SAT", SatInput_Key, 0x5E, 8);
}
