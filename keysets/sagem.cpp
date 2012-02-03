#include "sagem.h"
#include "protocols/necprotocol.h"

SagemTVBox1::SagemTVBox1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVB-T/Cable Box Keyset 1",
      Sagem_Make,
      index)
{
  threadableProtocol = new NECProtocol(guiObject, index, true, true);

//  setPreData(0xE17A, 16);
  setPreData(0x5E87, 16);

  addKey("0", Zero_Key, 0x00, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("EXIT", Exit_Key, 0x0A, 8); // "Key"
  addKey("Up", Up_Key, 0x0B, 8);
  addKey("Down", Down_Key, 0x0C, 8);
  addKey("Vol+", VolumeUp_Key, 0x0D, 8);
  addKey("Vol-", VolumeDown_Key, 0x0E, 8);
  addKey("Mute", Mute_Key, 0x0F, 8);
  addKey("P+", ChannelUp_Key, 0x10, 8);
  addKey("MENU", Menu_Key, 0x11, 8); // "Q"
  addKey("Power", Power_Key, 0x12, 8);
  addKey("Head", Unmapped_Key, 0x13, 8); // "FREEZE", "satdtt"
  addKey("BACK", PrevChannel_Key, 0x14, 8); // "R"
  addKey("OK", Select_Key, 0x15, 8);
  addKey("Red_A", Red_Key, 0x16, 8);
  addKey("Green_B", Green_Key, 0x17, 8);
  addKey("Yellow_C", Yellow_Key, 0x18, 8);
  addKey("Blue_D", Blue_Key, 0x19, 8);
  addKey("P-", ChannelDown_Key, 0x1A, 8);
  addKey("Left", Left_Key, 0x1B, 8);
  addKey("Right", Right_Key, 0x1C, 8);
  addKey("Text", Teletext_Key, 0x1D, 8); // "TELETEXT"
  addKey("INFO", Info_Key, 0x1E, 8); // "Menu"
  addKey("SUBTITLE", Captions_Key, 0x1F, 8); // "swap"
  addKey("Interface", Audio_Key, 0x20, 8); // "AUDIO"
  addKey("Tone", SoundMode_Key, 0x21, 8); // "SOUND"
  addKey("INPUT", Input_Key, 0x24, 8); // "i"
  addKey("EPG", Guide_Key, 0x25, 8); // "Navigator"
  addKey("RightArr", Unmapped_Key, 0x26, 8); // "LIST", "hd"
  addKey("LeftArr", Unmapped_Key, 0x28, 8);
}


SagemTVBox1a::SagemTVBox1a(
  QObject *guiObject,
  unsigned int index)
  : SagemTVBox1(guiObject, index)
{
  setKeysetName("DVB-T/Cable Box Keyset 1a");

  addKey("tria2", Unmapped_Key, 0x0F, 8);
  addKey("epg", Guide_Key, 0x11, 8);
  addKey("v-", VolumeDown_Key, 0x16, 8);
  addKey("mute", Mute_Key, 0x17, 8);
  addKey("p-", ChannelDown_Key, 0x18, 8);
  addKey("menu", Menu_Key, 0x19, 8);
  addKey("v+", VolumeUp_Key, 0x1D, 8);
  addKey("teletext6", Unmapped_Key, 0x20, 8);
  addKey("note", Unmapped_Key, 0x21, 8);
  addKey("ext", Unmapped_Key, 0x24, 8);
  addKey("p+", ChannelUp_Key, 0x25, 8);
}
