#include "sagem.h"
#include "necprotocol.h"

SagemTVBox1::SagemTVBox1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVB-T/Cable Box Keyset 1",
      Sagem_Make,
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
  np->setRepeatPair(9000, 2250);

//  np->setMinimumRepetitions(1);

  np->setPreData(0xE17A, 16);

  addKey("Power", Power_Key, 0x48B7, 16);
  addKey("P+", ChannelUp_Key, 0x08F7, 16);
  addKey("P-", ChannelDown_Key, 0x58A7, 16);
  addKey("Vol+", VolumeUp_Key, 0xB04F, 16);
  addKey("Vol-", VolumeDown_Key, 0x708F, 16);
  addKey("Red_A", Red_Key, 0x6897, 16);
  addKey("Green_B", Green_Key, 0xE817, 16);
  addKey("Yellow_C", Yellow_Key, 0x18E7, 16);
  addKey("Blue_D", Blue_Key, 0x9867, 16);
  addKey("Up", Up_Key, 0xD02F, 16);
  addKey("Right", Right_Key, 0x38C7, 16);
  addKey("Down", Down_Key, 0x30CF, 16);
  addKey("Left", Left_Key, 0xD827, 16);
  addKey("OK", Select_Key, 0xA857, 16);
  addKey("INFO", Info_Key, 0x7887, 16); // "Menu"
  addKey("MENU", Menu_Key, 0x8877, 16);
  addKey("Head", Unmapped_Key, 0xC837, 16); // "FREEZE", "satdtt"
  addKey("Q", Unmapped_Key, 0x8877, 16);
  addKey("LeftArr", Unmapped_Key, 0x14AB, 16);
  addKey("RightArr", Unmapped_Key, 0x649B, 16); // "LIST", "hd"
  addKey("EPG", Guide_Key, 0xA45B, 16); // "Navigator"
  addKey("INPUT", Input_Key, 0x24DB, 16); // "i"
  addKey("Tone", SoundMode_Key, 0x847B, 16); // "SOUND"
  addKey("Text", Unmapped_Key, 0xB847, 16); // "TELETEXT"
  addKey("SUBTITLE", Captions_Key, 0xF807, 16); // "swap"
  addKey("Interface", Language_Key, 0x04FB, 16); // "AUDIO"
  addKey("Mute", Mute_Key, 0xF00F, 16);
  addKey("1", One_Key, 0x807F, 16);
  addKey("2", Two_Key, 0x40BF, 16);
  addKey("3", Three_Key, 0xC03F, 16);
  addKey("4", Four_Key, 0x20DF, 16);
  addKey("5", Five_Key, 0xA05F, 16);
  addKey("6", Six_Key, 0x609F, 16);
  addKey("7", Seven_Key, 0xE01F, 16);
  addKey("8", Eight_Key, 0x10EF, 16);
  addKey("9", Nine_Key, 0x906F, 16);
  addKey("0", Zero_Key, 0x00FF, 16);
  addKey("EXIT", Exit_Key, 0x50AF, 16); // "Key"
  addKey("BACK", PrevChannel_Key, 0x28D7, 16); // "R"
}


SagemTVBox1a::SagemTVBox1a(
  QObject *guiObject,
  unsigned int index)
  : SagemTVBox1(guiObject, index)
{
  setKeysetName("DVB-T/Cable Box Keyset 1a");

  addKey("epg", Guide_Key, 0x8877, 16);
  addKey("menu", Menu_Key, 0x9867, 16);
  addKey("v-", VolumeDown_Key, 0x6897, 16);
  addKey("v+", VolumeUp_Key, 0xB847, 16);
  addKey("mute", Mute_Key, 0xE817, 16);
  addKey("p+", ChannelUp_Key, 0xA45B, 16);
  addKey("p-", ChannelDown_Key, 0x18E7, 16);
  addKey("note", Unmapped_Key, 0x847B, 16);
  addKey("teletext6", Unmapped_Key, 0x04FB, 16);
  addKey("tria2", Unmapped_Key, 0xF00F, 16);
  addKey("ext", Unmapped_Key, 0x24DB, 16);
}
