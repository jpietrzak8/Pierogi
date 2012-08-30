#include "telefunken.h"
#include "protocols/paceprotocol.h"


TelefunkenTV1::TelefunkenTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Telefunken_Make,
      index)
{
}


void TelefunkenTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new PaceProtocol(guiObject, index);

  setPreData(0x7, 3);

  addKey("KEY_1", One_Key, 0x00, 6);
  addKey("KEY_4", Four_Key, 0x01, 6);
  addKey("KEY_7", Seven_Key, 0x02, 6);
  addKey("COLOR+", ColorUp_Key, 0x03, 6);
  addKey("COLOR-", ColorDown_Key, 0x04, 6);
  addKey("MUTE", Mute_Key, 0x05, 6);
  addKey("CHANNEL", Info_Key, 0x06, 6);
  addKey("KEY_2", Two_Key, 0x08, 6);
  addKey("KEY_5", Five_Key, 0x09, 6);
  addKey("KEY_8", Eight_Key, 0x0A, 6);
  addKey("BRIGHTNESS+", BrightnessUp_Key, 0x0B, 6);
  addKey("BRIGHTNESS-", BrightnessDown_Key, 0x0C, 6);
  addKey("KEY_0", Zero_Key, 0x0E, 6);

  addKey("KEY_3", Three_Key, 0x10, 6);
  addKey("KEY_6", Six_Key, 0x11, 6);
  addKey("KEY_9", Nine_Key, 0x12, 6);
  addKey("BLUE/VT", Blue_Key, 0x15, 6);
  addKey("VTX", Unmapped_Key, 0x15, 6); // what is this?
  addKey("AV", Input_Key, 0x18, 6);
  addKey("KEY_POWER", Power_Key, 0x1D, 6);
  addKey("STD_VALUES", Unmapped_Key, 0x1E, 6); // "VIOLET/NORM", "TOP"
  addKey("KEY_CHANNELUP", ChannelUp_Key, 0x1F, 6);

  addKey("KEY_CHANNELDOWN", ChannelDown_Key, 0x20, 6);
  addKey("BASS", BassUp_Key, 0x21, 6);
  addKey("SIZE", Unmapped_Key, 0x22, 6); // txt
  addKey("CONTRAST", ContrastUp_Key, 0x23, 6);
  addKey("<-o->", Unmapped_Key, 0x24, 6); // txt
  addKey("BALANCE", BalanceLeft_Key, 0x25, 6);
  addKey("HIDDEN", Unmapped_Key, 0x28, 6); //txt
  addKey("VOL_UP", VolumeUp_Key, 0x29, 6);
  addKey("VOL_DOWN", VolumeDown_Key, 0x2A, 6);
  addKey("MIX", Unmapped_Key, 0x2B, 6); //txt

  addKey("INDEX", Unmapped_Key, 0x34, 6); //txt
  addKey("STOP", Unmapped_Key, 0x35, 6); //txt
  addKey("CLOCK", Unmapped_Key, 0x36, 6); //txt
  addKey("YELLOW/PR", Yellow_Key, 0x38, 6);
  addKey("PROGRAM", Program_Key, 0x38, 6);
  addKey("RED/TONE", Red_Key, 0x39, 6);
  addKey("AUDIO", SoundMode_Key, 0x39, 6);
  addKey("GREEN/PICTURE", Green_Key, 0x3B, 6);
  addKey("VIDEO", PictureMode_Key, 0x3B, 6);
  addKey("FORMAT+", Unmapped_Key, 0x3C, 6);
  addKey("FORMAT-", Unmapped_Key, 0x3D, 6);
  addKey("VIDEOTEXT", Teletext_Key, 0x3E, 6);
}


TelefunkenTV1a::TelefunkenTV1a(
  unsigned int index)
  : TelefunkenTV1(index)
{
  setKeysetName("TV Keyset 1a");
}


void TelefunkenTV1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  TelefunkenTV1::populateProtocol(guiObject);

  addKey("VOLUME+", VolumeUp_Key, 0x1B, 6);
  addKey("VOLUME-", VolumeDown_Key, 0x1C, 6);
  addKey("+", Right_Key, 0x29, 6);
  addKey("-", Left_Key, 0x2A, 6);
}
