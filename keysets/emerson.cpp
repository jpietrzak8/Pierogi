#include "emerson.h"
#include "protocols/necprotocol.h"

EmersonTV1::EmersonTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Emerson_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x0586, 16);

  addKey("1", One_Key, 0x00, 8);
  addKey("2", Two_Key, 0x01, 8);
  addKey("3", Three_Key, 0x02, 8);
  addKey("4", Four_Key, 0x03, 8);
  addKey("5", Five_Key, 0x04, 8);
  addKey("6", Six_Key, 0x05, 8);
  addKey("7", Seven_Key, 0x06, 8);
  addKey("8", Eight_Key, 0x07, 8);
  addKey("9", Nine_Key, 0x08, 8);
  addKey("0", Zero_Key, 0x09, 8);
  addKey("CHUp", ChannelUp_Key, 0x0A, 8);
  addKey("CHDown", ChannelDown_Key, 0x0B, 8);
  addKey("VolUp", VolumeUp_Key, 0x0C, 8);
  addKey("VolDown", VolumeDown_Key, 0x0D, 8);
  addKey("Mute", Mute_Key, 0x0E, 8);
  addKey("Power", Power_Key, 0x0F, 8);

  addKey("QuickView", Unmapped_Key, 0x10, 8);
  addKey("Sleep", Sleep_Key, 0x13, 8);
  addKey("Menu", Menu_Key, 0x14, 8);
  addKey("SetUp", Up_Key, 0x15, 8);
  addKey("SetDown", Down_Key, 0x16, 8);
  addKey("Call", Call_Key, 0x17, 8);
  addKey("Enter", Select_Key, 0x18, 8);
  addKey("Reset", Reset_Key, 0x19, 8);
  addKey("Caption", Captions_Key, 0x1C, 8);
  addKey("CapChan", Unmapped_Key, 0x1D, 8);
}


EmersonDVD1::EmersonDVD1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Emerson_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x2287, 16);

  addKey("KEY_POWER", Power_Key, 0x41, 8);
  addKey("KEY_AB", RepeatAB_Key, 0x43, 8);
  addKey("KEY_OPENCLOSE", Eject_Key, 0x44, 8);
  addKey("KEY_1", One_Key, 0x45, 8);
  addKey("KEY_2", Two_Key, 0x46, 8);
  addKey("KEY_3", Three_Key, 0x47, 8);
  addKey("KEY_4", Four_Key, 0x48, 8);
  addKey("KEY_5", Five_Key, 0x49, 8);
  addKey("KEY_6", Six_Key, 0x4A, 8);
  addKey("KEY_7", Seven_Key, 0x4B, 8);
  addKey("KEY_8", Eight_Key, 0x4C, 8);
  addKey("KEY_9", Nine_Key, 0x4D, 8);
  addKey("KEY_0", Zero_Key, 0x4E, 8);

  addKey("KEY_REPEAT", Repeat_Key, 0x50, 8);
  addKey("KEY_PLUSTEN", DoubleDigit_Key, 0x51, 8);
  addKey("KEY_REWIND", Rewind_Key, 0x52, 8);
  addKey("KEY_FASTFORWARD", FastForward_Key, 0x53, 8);
  addKey("KEY_DISPLAY", Info_Key, 0x55, 8);
  addKey("KEY_SEARCHMODE", Unmapped_Key, 0x57, 8);
  addKey("KEY_CLEAR", Clear_Key, 0x58, 8);
  addKey("KEY_PAUSE", Pause_Key, 0x5B, 8);
  addKey("KEY_MODE", Mode_Key, 0x5C, 8);
  addKey("KEY_PREVIOUS", Previous_Key, 0x5D, 8);
  addKey("KEY_PLAY", Play_Key, 0x5E, 8);
  addKey("KEY_NEXT", Next_Key, 0x5F, 8);

  addKey("KEY_STOP", Stop_Key, 0x60, 8);
  addKey("KEY_TOPMENU", DiscTitle_Key, 0x70, 8);
  addKey("KEY_MENU", DiscMenu_Key, 0x71, 8);
  addKey("KEY_ENTER", Select_Key, 0x72, 8);
  addKey("KEY_RETURN", Exit_Key, 0x73, 8);
  addKey("KEY_SETUP", Menu_Key, 0x74, 8);
  addKey("KEY_LEFTARROW", Left_Key, 0x75, 8);
  addKey("KEY_RIGHTARROW", Right_Key, 0x76, 8);
  addKey("KEY_UPARROW", Up_Key, 0x77, 8);
  addKey("KEY_DOWNARROW", Down_Key, 0x78, 8);
  addKey("KEY_ANGLE", Angle_Key, 0x79, 8);
  addKey("KEY_SUBTITLE", Captions_Key, 0x7A, 8);
  addKey("KEY_AUDIO", Audio_Key, 0x7B, 8);

  addKey("KEY_VSURR", Surround_Key, 0x81, 8);
}
