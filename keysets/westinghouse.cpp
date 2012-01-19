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
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 500,
    600, 1600,
    108000, true);

  threadableProtocol = np;

  np->setHeaderPair(9000, 4500);
  np->setTrailerPulse(600);

  np->setPreData(0x807F, 16);

  addKey("KEY_1", One_Key, 0x8877, 16);
  addKey("KEY_2", Two_Key, 0x48B7, 16);
  addKey("KEY_3", Three_Key, 0xC837, 16);
  addKey("KEY_4", Four_Key, 0x28D7, 16);
  addKey("KEY_5", Five_Key, 0xA857, 16);
  addKey("KEY_6", Six_Key, 0x6897, 16);
  addKey("KEY_7", Seven_Key, 0xE817, 16);
  addKey("KEY_8", Eight_Key, 0x18E7, 16);
  addKey("KEY_9", Nine_Key, 0x9867, 16);
  addKey("KEY_0", Zero_Key, 0x58A7, 16);
  addKey("KEY_BACK", PrevChannel_Key, 0x10EF, 16);
  addKey("KEY_MENU", Menu_Key, 0x629D, 16);
  addKey("KEY_POWER", Power_Key, 0x807F, 16);
  addKey("KEY_UP", Up_Key, 0x02FD, 16);
  addKey("KEY_DOWN", Down_Key, 0x22DD, 16);
  addKey("KEY_LEFT", Left_Key, 0x827D, 16);
  addKey("KEY_RIGHT", Right_Key, 0xC23D, 16);
  addKey("KEY_MUTE", Mute_Key, 0x08F7, 16);
  addKey("KEY_INFO", Info_Key, 0xD827, 16);
  addKey("KEY_VOLUMEUP", VolumeUp_Key, 0x20DF, 16);
  addKey("KEY_VOLUMEDOWN", VolumeDown_Key, 0xA05F, 16);
  addKey("INPUT", Input_Key, 0x00FF, 16);
  addKey("YPbPr", Unmapped_Key, 0x50AF, 16);
  addKey("FREEZE", Unmapped_Key, 0x38C7, 16);
  addKey("VGA", Unmapped_Key, 0x906F, 16);
  addKey("DVI", Unmapped_Key, 0x609F, 16);
  addKey("S-Video", Unmapped_Key, 0x30CF, 16);
  addKey("AV", Unmapped_Key, 0xD02F, 16);
  addKey("KEY_ENTER", Enter_Key, 0x42BD, 16);
  addKey("ASPECT_RATIO", AspectRatio_Key, 0xE01F, 16);
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
    45000, true);

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
  addKey("Zoom", Unmapped_Key, 0x390, 12);
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
