#include "zenith.h"
#include "protocols/necprotocol.h"

// Based solely on LIRC Zenith_C32V37 config file
ZenithC32V37::ZenithC32V37(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "C32V37 TV",
      Zenith_Make,
      index)
{
  addControlledDevice(Zenith_Make, "C32V37", TV_Device);

  threadableProtocol = new NECProtocol(guiObject, index, false, true);

//  setPreData(0x20DF, 16);
  setPreData(0x04, 8);

  addKey("CH_UP", ChannelUp_Key, 0x00, 8);
  addKey("CH_DOWN", ChannelDown_Key, 0x01, 8);
  addKey("VOL_UP", VolumeUp_Key, 0x02, 8);
  addKey("VOL_DOWN", VolumeDown_Key, 0x03, 8);
  addKey("right", Right_Key, 0x06, 8);
  addKey("left", Left_Key, 0x07, 8);
  addKey("power", Power_Key, 0x08, 8);
  addKey("mute", Mute_Key, 0x09, 8);
  addKey("audio", Audio_Key, 0x0A, 8);
  addKey("tv/video", Input_Key, 0x0B, 8);
  addKey("timer", Sleep_Key, 0x0E, 8);
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
  addKey("flashbk", PrevChannel_Key, 0x1A, 8);
  addKey("surf", Unmapped_Key, 0x1E, 8);
  addKey("cc", Captions_Key, 0x39, 8);
  addKey("up", Up_Key, 0x40, 8);
  addKey("down", Down_Key, 0x41, 8);
  addKey("menu", Menu_Key, 0x43, 8);
  addKey("dash", Dash_Key, 0x4C, 8);
  addKey("video", PictureMode_Key, 0x4D, 8);
  addKey("front", Unmapped_Key, 0x51, 8);
  addKey("exit", Exit_Key, 0x5B, 8);
  addKey("pip", PIP_Key, 0x60, 8);
  addKey("pcin", PCInput_Key, 0x61, 8);
  addKey("swap", PIPSwap_Key, 0x63, 8);
  addKey("freeze", PIPPause_Key, 0x65, 8);
  addKey("pipch+", PIPChannelUp_Key, 0x71, 8);
  addKey("pipch-", PIPChannelDown_Key, 0x72, 8);
  addKey("ratio", AspectRatio_Key, 0x79, 8);
  addKey("signal", Unmapped_Key, 0x96, 8);
  addKey("comp/dvi", Unmapped_Key, 0x98, 8);
  addKey("info", Info_Key, 0xAA, 8);
}
