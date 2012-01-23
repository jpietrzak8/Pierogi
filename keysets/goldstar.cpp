#include "goldstar.h"
#include "necprotocol.h"
#include "rc5protocol.h"

GoldStarTV1::GoldStarTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "105-210A TV",
      GoldStar_Make,
      index)
{
  addControlledDevice(GoldStar_Make, "105-210A", TV_Device);

  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x20DF, 16);

  addKey("power", Power_Key, 0x10EF, 16);
  addKey("mute", Mute_Key, 0x906F, 16);
  addKey("1", One_Key, 0x8877, 16);
  addKey("2", Two_Key, 0x48B7, 16);
  addKey("3", Three_Key, 0xC837, 16);
  addKey("4", Four_Key, 0x28D7, 16);
  addKey("5", Five_Key, 0xA857, 16);
  addKey("6", Six_Key, 0x6897, 16);
  addKey("7", Seven_Key, 0xE817, 16);
  addKey("8", Eight_Key, 0x18E7, 16);
  addKey("9", Nine_Key, 0x9867, 16);
  addKey("0", Zero_Key, 0x08F7, 16);
  addKey("lowhigh", DoubleDigit_Key, 0x38C7, 16);
  addKey("recall", PrevChannel_Key, 0xD827, 16);
  addKey("prup", ChannelUp_Key, 0x00FF, 16);
  addKey("prdown", ChannelDown_Key, 0x807F, 16);
  addKey("volup", VolumeUp_Key, 0x40BF, 16);
  addKey("voldown", VolumeDown_Key, 0xC03F, 16);
  addKey("ok", Select_Key, 0x22DD, 16);
  addKey("prup", Up_Key, 0x00FF, 16);
  addKey("voldown", Left_Key, 0xC03F, 16);
  addKey("volup", Right_Key, 0x40BF, 16);
  addKey("prdown", Down_Key, 0x807F, 16);
  addKey("tvav", Input_Key, 0xD02F, 16);
  addKey("menu", Menu_Key, 0xC23D, 16);
  addKey("psm", Unmapped_Key, 0xF20D, 16);
  addKey("sleep", Sleep_Key, 0x708F, 16);
  addKey("qview", Unmapped_Key, 0x58A7, 16);
  addKey("picture", PictureMode_Key, 0x30CF, 16);
}


GoldStarTV2::GoldStarTV2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      GoldStar_Make,
      index)
{
  RC5Protocol *rp = new RC5Protocol(
    guiObject,
    index,
    899, 783,
    962,
    107722, true);

  threadableProtocol = rp;

  setPreData(0x40, 7);

  rp->setToggleBit(2);

  addKey("0", Zero_Key, 0x00, 6);
  addKey("1", One_Key, 0x01, 6);
  addKey("2", Two_Key, 0x02, 6);
  addKey("3", Three_Key, 0x03, 6);
  addKey("4", Four_Key, 0x04, 6);
  addKey("5", Five_Key, 0x05, 6);
  addKey("6", Six_Key, 0x06, 6);
  addKey("7", Seven_Key, 0x07, 6);
  addKey("8", Eight_Key, 0x08, 6);
  addKey("9", Nine_Key, 0x09, 6);
  addKey("MUTE", Mute_Key, 0x0D, 6);
  addKey("POWER", Power_Key, 0x0C, 6);
  addKey("TV", Unmapped_Key, 0x3F, 6);
  addKey("AV", Unmapped_Key, 0x38, 6);
  addKey("LOOP", Unmapped_Key, 0x22, 6);
  addKey("-/--", DoubleDigit_Key, 0x0A, 6);
  addKey("PP", Unmapped_Key, 0x0E, 6);
  addKey("MENU", Menu_Key, 0x3B, 6);
  addKey("OK", Select_Key, 0x25, 6);
  addKey("OK", Enter_Key, 0x25, 6);
  addKey("VOL-", VolumeDown_Key, 0x11, 6);
  addKey("VOL+", VolumeUp_Key, 0x10, 6);
  addKey("PROG-", ChannelDown_Key, 0x21, 6);
  addKey("PROG+", ChannelUp_Key, 0x20, 6);
  addKey("<=", Unmapped_Key, 0x0B, 6);
  addKey("=", Unmapped_Key, 0x3C, 6);
  addKey("RED", Red_Key, 0x37, 6);
  addKey("GREEN", Green_Key, 0x36, 6);
  addKey("YELLOW", Yellow_Key, 0x32, 6);
  addKey("BLUE", Blue_Key, 0x34, 6);
  addKey("=/", Unmapped_Key, 0x2E, 6);
  addKey("=o", Unmapped_Key, 0x2A, 6);
  addKey("=?", Unmapped_Key, 0x2C, 6);
  addKey("=i", Unmapped_Key, 0x35, 6);
  addKey("=^", Unmapped_Key, 0x2B, 6);
  addKey(">=<", Unmapped_Key, 0x29, 6);
  addKey("=X", Unmapped_Key, 0x2D, 6);
  addKey("=M", Unmapped_Key, 0x3E, 6);
}


GoldStarVCR1::GoldStarVCR1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      GoldStar_Make,
      index)
{
  addControlledDevice(GoldStar_Make, "GSE-Q204P", VCR_Device);
  addControlledDevice(GoldStar_Make, "QUISY 500", VCR_Device);

  threadableProtocol = new NECProtocol(guiObject, index);

  setPreData(0x7689, 16);

  addKey("power", Power_Key, 0x28D7, 16);
  addKey("eject", Eject_Key, 0x00FF, 16);
  addKey("a_trk", AutoTracking_Key, 0xFA05, 16);
  addKey("tracking+", TrackingPlus_Key, 0x22DD, 16);
  addKey("tracking-", TrackingMinus_Key, 0xA25D, 16);
  addKey("prog+", ChannelUp_Key, 0x18E7, 16);
  addKey("prog-", ChannelDown_Key, 0x9867, 16);
  addKey("child_lock", Unmapped_Key, 0xFC03, 16);
  addKey("play", Play_Key, 0x10EF, 16);
  addKey("<rew", Rewind_Key, 0x40BF, 16);
  addKey("ff>", FastForward_Key, 0xC03F, 16);
  addKey("pause||", Pause_Key, 0xD02F, 16);
  addKey("stop", Stop_Key, 0x807F, 16);
  addKey("record", Record_Key, 0x906F, 16);
  addKey("reset", Reset_Key, 0xB24D, 16);
  addKey("clock_count", Unmapped_Key, 0x32CD, 16); // "memory"
  addKey("show_view", Unmapped_Key, 0xE21D, 16);
  addKey("menu", Menu_Key, 0x6897, 16);
  addKey("up", Up_Key, 0x41BE, 16);
  addKey("down", Down_Key, 0x916E, 16);
  addKey("right", Right_Key, 0x09F6, 16);
  addKey("left", Left_Key, 0xC13E, 16);
//  addKey("ok", Enter_Key, 0x718E, 16);
  addKey("ok", Select_Key, 0x718E, 16);
  addKey("clear", Clear_Key, 0xF807, 16);
  addKey("display", Info_Key, 0x7887, 16);
  addKey("1", One_Key, 0xA05F, 16);
  addKey("2", Two_Key, 0x609F, 16);
  addKey("3", Three_Key, 0xE01F, 16);
  addKey("4", Four_Key, 0x30CF, 16);
  addKey("5", Five_Key, 0xB04F, 16);
  addKey("6", Six_Key, 0x708F, 16);
  addKey("7", Seven_Key, 0xF00F, 16);
  addKey("8", Eight_Key, 0x38C7, 16);
  addKey("9", Nine_Key, 0xB847, 16);
  addKey("0", Zero_Key, 0x20DF, 16);
  addKey("preset", Unmapped_Key, 0x728D, 16);
  addKey("viss", Unmapped_Key, 0x827D, 16);
  addKey("vps", Unmapped_Key, 0x926D, 16);
  addKey("tv_vcr", Input_Key, 0xA857, 16);
  addKey("sp/lp", VHSSpeed_Key, 0x12ED, 16);
  addKey("length", Unmapped_Key, 0xD22D, 16);
  addKey("start", Unmapped_Key, 0x52AD, 16);
  addKey("f/a", Unmapped_Key, 0x08F7, 16);
}


GoldStarVCR1a::GoldStarVCR1a(
  QObject *guiObject,
  unsigned int index)
  : GoldStarVCR1(guiObject, index)
{
  setKeysetName("VCR Keyset 1a");

  addKey("slow", Unmapped_Key, 0xC837, 16);
  addKey("slow+", Unmapped_Key, 0x58A7, 16);
  addKey("slow-", Unmapped_Key, 0xD827, 16);
}


GoldStarVCR1b::GoldStarVCR1b(
  QObject *guiObject,
  unsigned int index)
  : GoldStarVCR1(guiObject, index)
{
  setKeysetName("VCR Keyset 1b");

  addKey("BACK", Exit_Key, 0x32CD, 16);
}


GoldStarVCR1c::GoldStarVCR1c(
  QObject *guiObject,
  unsigned int index)
  : GoldStarVCR1(guiObject, index)
{
  setKeysetName("VCR Keyset 1c");

  addKey("trk+", TrackingPlus_Key, 0x7788, 16);
  addKey("trk-", TrackingMinus_Key, 0xB748, 16);
  addKey("a.trk", AutoTracking_Key, 0x17E8, 16);
  addKey("a.repeart", Unmapped_Key, 0xAF50, 16);
}


GoldStarVCR1d::GoldStarVCR1d(
  QObject *guiObject,
  unsigned int index)
  : GoldStarVCR1(guiObject, index)
{
  setKeysetName("VCR Keyset 1d");
  
  addKey("TU_AV", Input_Key, 0x6A95, 16);
}


// Based on LIRC 6710S-6000A config file
GoldStarCD1::GoldStarCD1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "CD Player Keyset 1",
      GoldStar_Make,
      index)
{
  addControlledDevice(GoldStar_Make, "FFH-272A/L", Audio_Device);

  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 500,
    600, 1600,
    108000, true);

  threadableProtocol = np;

  np->setHeaderPair(4500, 4500);
  np->setTrailerPulse(600);
  np->setRepeatPair(600, 1600);
  np->setRepeatNeedsHeader(true);

  setPreData(0x0808, 16);
  setPostData(0x1, 1);

  addKey("power", Power_Key, 0x3C43, 15);
  addKey("mute", Mute_Key, 0x7C03, 15);
  addKey("cd", Unmapped_Key, 0x601F, 15);
  addKey("tape", Unmapped_Key, 0x0877, 15);
  addKey("aux", Unmapped_Key, 0x4837, 15);
  addKey("fm", Unmapped_Key, 0x007F, 15);
  addKey("mw", Unmapped_Key, 0x403F, 15);
  addKey("lw", Unmapped_Key, 0x205F, 15);
  addKey("pre-", ChannelDown_Key, 0x245B, 15);
  addKey("pre+", ChannelUp_Key, 0x641B, 15);
  addKey("ply/pau", Play_Key, 0x106F, 15);
  addKey("stop", Stop_Key, 0x502F, 15);
  addKey("prev", Previous_Key, 0x304F, 15);
  addKey("next", Next_Key, 0x700F, 15);
  addKey("prog", Unmapped_Key, 0x5926, 15);
  addKey("repeat", Replay_Key, 0x3946, 15);
  addKey("random", Unmapped_Key, 0x057A, 15);
  addKey("dskip", Unmapped_Key, 0x2956, 15);
  addKey("remain", Unmapped_Key, 0x453A, 15);
  addKey("eqpatt", Unmapped_Key, 0x017E, 15);
  addKey("vol-", VolumeDown_Key, 0x344B, 15);
  addKey("vol+", VolumeUp_Key, 0x740B, 15);
}
