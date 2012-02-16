#include "beko.h"
#include "protocols/rc5protocol.h"


BekoTV1::BekoTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Beko_Make,
      index)
{
  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("MIX", TeletextAndTV_Key, 0x1004, 13);
  addKey("DOUBLE", TeletextSize_Key, 0x1007, 13);
  addKey("SUB", Unmapped_Key, 0x100A, 13);
  addKey("STOP", TeletextHold_Key, 0x100C, 13);
  addKey("REVEAL", TeletextReveal_Key, 0x100E, 13);
  addKey("UPDATE", Unmapped_Key, 0x100F, 13);

  addKey("0", Zero_Key, 0x1010, 13);
  addKey("1", One_Key, 0x1011, 13);
  addKey("2", Two_Key, 0x1012, 13);
  addKey("3", Three_Key, 0x1013, 13);
  addKey("4", Four_Key, 0x1014, 13);
  addKey("5", Five_Key, 0x1015, 13);
  addKey("6", Six_Key, 0x1016, 13);
  addKey("7", Seven_Key, 0x1017, 13);
  addKey("8", Eight_Key, 0x1018, 13);
  addKey("9", Nine_Key, 0x1019, 13);
  addKey("1_X_CHANNELS", DoubleDigit_Key, 0x101A, 13);
  addKey("PR_DOWN", ChannelDown_Key, 0x101B, 13);
  addKey("PR_DOWN", Down_Key, 0x101B, 13);
  addKey("PR_UP", ChannelUp_Key, 0x101C, 13);
  addKey("PR_UP", Up_Key, 0x101C, 13);

  addKey("POWER_OFF", PowerOff_Key, 0x1020, 13); // ?
  addKey("16:9", AspectRatio_Key, 0x1023, 13);
  addKey("VOL_UP", VolumeUp_Key, 0x1024, 13);
  addKey("VOL_UP", Right_Key, 0x1024, 13);
  addKey("VOL_LOW", VolumeDown_Key, 0x1025, 13);
  addKey("VOL_LOW", Left_Key, 0x1025, 13);
  addKey("RED", Red_Key, 0x1026, 13);
  addKey("SWAP", PrevChannel_Key, 0x1027, 13);
  addKey("OK", Select_Key, 0x1028, 13);
  addKey("MENU", Menu_Key, 0x1029, 13);
  addKey("AV/TV", Input_Key, 0x102A, 13);
  addKey("MUTE", Mute_Key, 0x102B, 13);
  addKey("GREEN", Green_Key, 0x102C, 13);
  addKey("YELLOW", Yellow_Key, 0x102E, 13);
  addKey("I", Info_Key, 0x102F, 13); // ?

  addKey("TXT", Teletext_Key, 0x1031, 13); // ?
  addKey("BLUE", Blue_Key, 0x1033, 13);
}
