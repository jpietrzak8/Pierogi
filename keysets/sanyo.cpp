#include "sanyo.h"

#include "necprotocol.h"

SanyoVCR1::SanyoVCR1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Sanyo_Make,
      index)
{
  addControlledDevice(Sanyo_Make, "DVW-5000", VCR_Device);
  addControlledDevice(Sanyo_Make, "DVW-5000", DVD_Device);

  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    627, 500,  // values for zero
    627, 1626, // values for one
    108754, true); // constant-length gap

  threadableProtocol = np;

  np->setHeaderPair(9000, 4500);
  np->setTrailerPulse(626);
  np->setRepeatPair(9000, 2250);

  np->setPreData(0x8C73, 16);

  // Add keys:
  addKey("Power", Power_Key, 0xDA25, 16);
  addKey("1", One_Key, 0x20DF, 16);
  addKey("2", Two_Key, 0xA05F, 16);
  addKey("3", Three_Key, 0x609F, 16);
  addKey("4", Four_Key, 0xE01F, 16);
  addKey("5", Five_Key, 0x30CF, 16);
  addKey("6", Six_Key, 0xB04F, 16);
  addKey("7", Seven_Key, 0x708F, 16);
  addKey("8", Eight_Key, 0xF00F, 16);
  addKey("9", Nine_Key, 0x38C7, 16);
  addKey("0", Zero_Key, 0xB847, 16);
  addKey("Cancel", Clear_Key, 0x52AD, 16);
  addKey("Ch Up", ChannelUp_Key, 0x807F, 16);
  addKey("Ch Down", ChannelDown_Key, 0x40BF, 16);
  addKey("Rew", Rewind_Key, 0x48B7, 16);
  addKey("Play", Play_Key, 0x28D7, 16);
  addKey("FF", FastForward_Key, 0xC837, 16);
  addKey("Rec", Record_Key, 0xA857, 16);
  addKey("Stop", Stop_Key, 0x08F7, 16);
  addKey("Pause", Pause_Key, 0x8877, 16);
  addKey("TV/VCR", Input_Key, 0x10EF, 16);
  addKey("Menu", Menu_Key, 0x53AC, 16);
  addKey("Up", Up_Key, 0xE916, 16);
  addKey("Down", Down_Key, 0x6996, 16);
  addKey("Left", Left_Key, 0xA956, 16);
  addKey("Right", Right_Key, 0x29D6, 16);
  addKey("Ok", Select_Key, 0xD22D, 16);
  addKey("Clock", Clock_Key, 0x6A95, 16);
  addKey("Reset", Reset_Key, 0x22DD, 16);
  addKey("Display", Info_Key, 0x32CD, 16);
  addKey("Memory", Unmapped_Key, 0xC23D, 16); // "->0<-"
  addKey("PROG", Program_Key, 0x629D, 16);
  addKey("BLANK", Unmapped_Key, 0x0BF4, 16);
  addKey("Monitor", Unmapped_Key, 0x8A75, 16);
  addKey("ShowView", Unmapped_Key, 0x31CE, 16);
  addKey("ATR", Unmapped_Key, 0xF807, 16);
  addKey("Slow", Unmapped_Key, 0x58A7, 16);
  addKey("SP/LP", VHSSpeed_Key, 0x7A85, 16);
  addKey("VPS", Unmapped_Key, 0xF20D, 16); // "vps/pdc", "dpc"
  addKey("Preset", Unmapped_Key, 0x7986, 16);
  addKey("Input", Unmapped_Key, 0x7887, 16);  // need a subclass for this?
  addKey("Audio", Language_Key, 0xC03F, 16);
  addKey("Index", Unmapped_Key, 0x9867, 16);
  addKey("+100", PlusOneHundred_Key, 0xD827, 16);
  addKey("x2", Unmapped_Key, 0xD02F, 16);
}


SanyoTV1::SanyoTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Sanyo_Make,
      index)
{
  addControlledDevice(Sanyo_Make, "DP32746", TV_Device);

  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 1600,  // zero
    600, 500,   // one
    40000, false);  // gap, not constant length

  threadableProtocol = np;

  np->setHeaderPair(9000, 4500);
  np->setTrailerPulse(600);
  np->setRepeatPair(9000, 2250);

  np->setPreData(0xE31C, 16);

  addKey("Power", Power_Key, 0xB748, 16);
//  addKey("audio_mode", Language_Key, 0xC738, 16);  // might be wrong
  addKey("1", One_Key, 0x7F80, 16);
  addKey("2", Two_Key, 0xBF40, 16);
  addKey("3", Three_Key, 0x3FC0, 16);
  addKey("4", Four_Key, 0xDF20, 16);
  addKey("5", Five_Key, 0x5FA0, 16);
  addKey("6", Six_Key, 0x9F60, 16);
  addKey("7", Seven_Key, 0x1FE0, 16);
  addKey("8", Eight_Key, 0xEF10, 16);
  addKey("9", Nine_Key, 0x6F90, 16);
  addKey("0", Zero_Key, 0xFF00, 16);
  addKey("Channel Up", ChannelUp_Key, 0xAF50, 16);
  addKey("Channel Down", ChannelDown_Key, 0x2FD0, 16);
  addKey("Volume Up", VolumeUp_Key, 0x8F70, 16);
  addKey("Volume Down", VolumeDown_Key, 0x0FF0, 16);
  addKey("Mute", Mute_Key, 0xE718, 16);
  addKey("Display", Info_Key, 0xCF30, 16);
  addKey("Menu", Menu_Key, 0x17E8, 16);
//  addKey("Enter", Enter_Key, 0xA758, 16);
  addKey("Enter", Select_Key, 0xA758, 16);
  addKey("Closed Captions", Captions_Key, 0x7788, 16);
  addKey("Video Mode", Input_Key, 0x37C8, 16);
  addKey("Sleep", Sleep_Key, 0x4FB0, 16);
  addKey("Recall", PrevChannel_Key, 0x6798, 16);
  addKey("PIP", PIP_Key, 0x25DA, 16);
  addKey("Swap", PIPSwap_Key, 0x45BA, 16);
  addKey("Red", Red_Key, 0x6D92, 16);
  addKey("Green", Green_Key, 0xAD52, 16);
  addKey("Yellow", Yellow_Key, 0x2DD2, 16);
  addKey("Blue", Blue_Key, 0xCD32, 16);
  addKey("Reset", Reset_Key, 0xC738, 16);
  addKey("Menu +", Up_Key, 0x8778, 16); // menu +
  addKey("Menu -", Down_Key, 0x07F8, 16); // menu - 
//  addKey("image", AspectRatio_Key, 0x7788, 16);
  addKey("Digicon", Guide_Key, 0x47B8, 16);
}


SanyoTV2::SanyoTV2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Sanyo_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 1600,
    600, 500,
    40000, false);

  threadableProtocol = np;

  np->setHeaderPair(9000, 4500);
  np->setTrailerPulse(600);
  np->setRepeatPair(9000, 2250);

  np->setPreData(0xE31C, 16);

  addKey("POWER", Power_Key, 0xC738, 16);
  addKey("TV", Unmapped_Key, 0xD728, 16);
  addKey("WIDE", AspectRatio_Key, 0x3DC2, 16);
  addKey("1", One_Key, 0x7F80, 16);
  addKey("2", Two_Key, 0xBF40, 16);
  addKey("3", Three_Key, 0x3FC0, 16);
  addKey("4", Four_Key, 0xDF20, 16);
  addKey("5", Five_Key, 0x5FA0, 16);
  addKey("6", Six_Key, 0x9F60, 16);
  addKey("7", Seven_Key, 0x1FE0, 16);
  addKey("8", Eight_Key, 0xEF10, 16);
  addKey("9", Nine_Key, 0x6F90, 16);
  addKey("0", Zero_Key, 0xFF00, 16);
  addKey("-/--", DoubleDigit_Key, 0xAF50, 16);
  addKey("CS", Unmapped_Key, 0x2FD0, 16);
  addKey("SYMBOL_1", Unmapped_Key, 0xE718, 16);
  addKey("SYMBOL_2", Unmapped_Key, 0x7788, 16);
  addKey("MUTE", Mute_Key, 0x57A8, 16);
  addKey("P--P", Unmapped_Key, 0x47B8, 16);
  addKey("F/OK", Unmapped_Key, 0xA758, 16);
  addKey("MENU", Menu_Key, 0x758A, 16);
  addKey("VOL-", VolumeDown_Key, 0x17E8, 16);
  addKey("VOL+", VolumeUp_Key, 0x9768, 16);
  addKey("P+", ChannelUp_Key, 0xCF30, 16);
  addKey("P-", ChannelDown_Key, 0x4FB0, 16);
  addKey("RED", Red_Key, 0x6D92, 16);
  addKey("GREEN", Green_Key, 0xAD52, 16);
  addKey("YELLOW", Yellow_Key, 0x2DD2, 16);
  addKey("BLUE", Blue_Key, 0xCD32, 16);
  addKey("SYMBOL_3", Unmapped_Key, 0x6798, 16);
  addKey("SYMBOL_4", Unmapped_Key, 0x956A, 16);
  addKey("SYMBOL_5", Unmapped_Key, 0x8D72, 16);
  addKey("TXT/TV", Unmapped_Key, 0x9D62, 16);
  addKey("A-B", Language_Key, 0xFD02, 16);
}
