#include "westinghouse.h"
#include "necprotocol.h"

WestinghouseTV1::WestinghouseTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Westinghouse_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, Standard_NEC);

//  setPreData(0x807F, 16);
  setPreData(0x01, 8);

  addKey("INPUT", Input_Key, 0x00, 8);
  addKey("KEY_POWER", Power_Key, 0x01, 8);
  addKey("KEY_VOLUMEUP", VolumeUp_Key, 0x04, 8);
  addKey("KEY_VOLUMEDOWN", VolumeDown_Key, 0x05, 8);
  addKey("DVI", Unmapped_Key, 0x06, 8);
  addKey("ASPECT_RATIO", AspectRatio_Key, 0x07, 8);
  addKey("KEY_BACK", PrevChannel_Key, 0x08, 8);
  addKey("VGA", Unmapped_Key, 0x09, 8);
  addKey("YPbPr", Unmapped_Key, 0x0A, 8);
  addKey("AV", Unmapped_Key, 0x0B, 8);
  addKey("S-Video", Unmapped_Key, 0x0C, 8);
  addKey("KEY_MUTE", Mute_Key, 0x10, 8);
  addKey("KEY_1", One_Key, 0x11, 8);
  addKey("KEY_2", Two_Key, 0x12, 8);
  addKey("KEY_3", Three_Key, 0x13, 8);
  addKey("KEY_4", Four_Key, 0x14, 8);
  addKey("KEY_5", Five_Key, 0x15, 8);
  addKey("KEY_6", Six_Key, 0x16, 8);
  addKey("KEY_7", Seven_Key, 0x17, 8);
  addKey("KEY_8", Eight_Key, 0x18, 8);
  addKey("KEY_9", Nine_Key, 0x19, 8);
  addKey("KEY_0", Zero_Key, 0x1A, 8);
  addKey("KEY_INFO", Info_Key, 0x1B, 8);
  addKey("FREEZE", Pause_Key, 0x1C, 8);
  addKey("KEY_UP", Up_Key, 0x40, 8);
  addKey("KEY_LEFT", Left_Key, 0x41, 8);
  addKey("KEY_ENTER", Enter_Key, 0x42, 8);
  addKey("KEY_RIGHT", Right_Key, 0x43, 8);
  addKey("KEY_DOWN", Down_Key, 0x44, 8);
  addKey("KEY_MENU", Menu_Key, 0x46, 8);
}


WestinghouseTV2::WestinghouseTV2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Westinghouse_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 500,
    1200, 500,
    45000, true,
    LIRC_NEC);

  threadableProtocol = np;

  np->setHeaderPair(2400, 500);

//  np->setMinimumRepetitions(3);

  addKey("Power", Power_Key, 0xA90, 12);
  addKey("PIP", PIP_Key, 0xDB0, 12);
  addKey("PIPSwap", PIPSwap_Key, 0xFB0, 12);
  addKey("Mute", Mute_Key, 0x290, 12);
  addKey("Sleep", Sleep_Key, 0x6D0, 12);
  addKey("CC", Captions_Key, 0x310, 12);
  addKey("Backlight", Unmapped_Key, 0x190, 12);
  addKey("A", Unmapped_Key, 0x570, 12);
  addKey("B", Unmapped_Key, 0xD70, 12);
  addKey("C", Unmapped_Key, 0x370, 12);
  addKey("1", One_Key, 0x010, 12);
  addKey("2", Two_Key, 0x810, 12);
  addKey("3", Three_Key, 0x410, 12);
  addKey("4", Four_Key, 0xC10, 12);
  addKey("5", Five_Key, 0x210, 12);
  addKey("6", Six_Key, 0xA10, 12);
  addKey("7", Seven_Key, 0x610, 12);
  addKey("8", Eight_Key, 0xE10, 12);
  addKey("9", Nine_Key, 0x110, 12);
  addKey("0", Zero_Key, 0x910, 12);
  addKey(".", Unmapped_Key, 0x510, 12);
  addKey("EnterNumPad", Enter_Key, 0xD10, 12);
  addKey("Input", Input_Key, 0xA50, 12);
  addKey("Zoom", Zoom_Key, 0x390, 12);
  addKey("Vol+", VolumeUp_Key, 0x490, 12);
  addKey("Vol-", VolumeDown_Key, 0xC90, 12);
  addKey("Ch+", ChannelUp_Key, 0x090, 12);
  addKey("Ch-", ChannelDown_Key, 0x890, 12);
  addKey("Menu", Menu_Key, 0x070, 12);
  addKey("Info", Info_Key, 0x5D0, 12);
  addKey("Up", Up_Key, 0x2F0, 12);
  addKey("Down", Down_Key, 0xAF0, 12);
  addKey("Left", Left_Key, 0x2D0, 12);
  addKey("Right", Right_Key, 0xCD0, 12);
  addKey("EnterNavigation", Select_Key, 0xA70, 12);
  addKey("Retry", Unmapped_Key, 0xDD0, 12);
  addKey("EPG", Guide_Key, 0x710, 12);
  addKey("YPbPr1", Unmapped_Key, 0x130, 12);
  addKey("YPbPr2", Unmapped_Key, 0x930, 12);
  addKey("PC", Unmapped_Key, 0xC30, 12);
  addKey("Video", Unmapped_Key, 0x030, 12);
  addKey("HDMI", Unmapped_Key, 0x430, 12);
  addKey("SVideo", Unmapped_Key, 0xB30, 12);
  addKey("TV", Unmapped_Key, 0x250, 12);
  addKey("DVI", Unmapped_Key, 0x230, 12);
}
