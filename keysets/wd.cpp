#include "wd.h"
#include "protocols/necprotocol.h"

WDMediaPlayer1::WDMediaPlayer1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Media Player Keyset 1",
      WD_Make,
      index)
{
  addControlledDevice(WD_Make, "WDTV", Other_Device);
  addControlledDevice(WD_Make, "WDTV Live PLUS", Other_Device);
}


void WDMediaPlayer1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x7984, 16);

  addKey("KEY_DOWN", Down_Key, 0x00, 8); // "down arrow"
  addKey("KEY_NEXT", Next_Key, 0x01, 8); // "next"
  addKey("KEY_NEXT", PageDown_Key, 0x01, 8);
  addKey("KEY_PREVIOUS", Previous_Key, 0x02, 8); // "prev"
  addKey("KEY_PREVIOUS", PageUp_Key, 0x02, 8);
  addKey("KEY_STOP", Stop_Key, 0x04, 8); // "stop"
  addKey("KEY_UP", Up_Key, 0x05, 8); // "up arrow"
  addKey("KEY_HOME", Menu_Key, 0x06, 8); // "home"
  addKey("KEY_LEFT", Left_Key, 0x07, 8); // "left arrow"
  addKey("KEY_ENTER", Select_Key, 0x08, 8); // "enter"
  addKey("KEY_ENTER", Info_Key, 0x08, 8);
  addKey("KEY_RIGHT", Right_Key, 0x09, 8); // "right arrow"
  addKey("KEY_PLAYPAUSE", Play_Key, 0x0A, 8); // "pause/play"
  addKey("KEY_PLAYPAUSE", Pause_Key, 0x0A, 8);
  addKey("KEY_SEARCH", Scan_Key, 0x0F, 8); // "search"
  addKey("KEY_EJECTCD", Eject_Key, 0x10, 8);
  addKey("KEY_POWER", Power_Key, 0x12, 8); // "power"
  addKey("KEY_OPTION", Unmapped_Key, 0x1A, 8); // "option"
  addKey("KEY_BACK", Exit_Key, 0x1B, 8); // "back"
  addKey("KEY_FASTFORWARD", FastForward_Key, 0x1E, 8); // "fast fwd"
  addKey("KEY_REWIND", Rewind_Key, 0x1F, 8); // "rewind"
}


WDMediaPlayer1a::WDMediaPlayer1a(
  unsigned int index)
  : WDMediaPlayer1(index)
{
  setKeysetName("Media Player Keyset 1a");
}


void WDMediaPlayer1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  WDMediaPlayer1::populateProtocol(guiObject);

  addKey("next page", PageDown_Key, 0x03, 8);
  addKey("subtitle", Captions_Key, 0x0C, 8);
  addKey("audio", Audio_Key, 0x0D, 8);
  addKey("3", Three_Key, 0x0E, 8);
  addKey("mute", Mute_Key, 0x28, 8);
  addKey("prev page", PageUp_Key, 0x2C, 8);
  addKey("setup", Guide_Key, 0x2E, 8);
  addKey("8", Eight_Key, 0x5C, 8);
  addKey("7", Seven_Key, 0x5D, 8);
  addKey("6", Six_Key, 0x5E, 8);
  addKey("9", Nine_Key, 0x5F, 8);
  addKey("eject", Eject_Key, 0xE0, 8);
  addKey("2", Two_Key, 0xE6, 8);
  addKey("1", One_Key, 0xE7, 8);
  addKey("B (red)", Red_Key, 0xE5, 8);
  addKey("D (blue)", Blue_Key, 0xE8, 8);
  addKey("C (yellow)", Yellow_Key, 0xE9, 8);
  addKey("A (green)", Green_Key, 0xEB, 8);
  addKey("4", Four_Key, 0xEC, 8);
  addKey("5", Five_Key, 0xED, 8);
  addKey("0", Zero_Key, 0xEE, 8);
}


WDMediaPlayer1b::WDMediaPlayer1b(
  unsigned int index)
  : WDMediaPlayer1a(index)
{
  setKeysetName("Media Player Keyset 1b");
}


void WDMediaPlayer1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  WDMediaPlayer1a::populateProtocol(guiObject);

  addKey("0", Zero_Key, 0x11, 8);
  addKey("1", One_Key, 0x18, 8);
  addKey("2", Two_Key, 0x19, 8);
  addKey("4", Four_Key, 0x1C, 8);
  addKey("5", Five_Key, 0x1D, 8);
}
