#include "motorola.h"
#include "protocols/lircprotocol.h"
#include "protocols/giprotocol.h"
#include "protocols/necprotocol.h"


Motorola4DTV::Motorola4DTV(
  unsigned int index)
  : PIRKeysetMetaData(
      "4DTV/StarChoice Keyset",
      Motorola_Make,
      index)
{
}


void Motorola4DTV::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  LIRCProtocol *lp = new LIRCProtocol(
    guiObject, index,
    1000, 1000,
    1000, 3000,
    100000, true);

  threadableProtocol = lp;

  lp->setHeaderPair(5000, 2000);
  lp->setTrailerPulse(1000);

  addKey("0", Zero_Key, 0x246, 12);
  addKey("1", One_Key, 0xF04, 12);
  addKey("2", Two_Key, 0x886, 12);
  addKey("3", Three_Key, 0x486, 12);
  addKey("4", Four_Key, 0xE83, 12);
  addKey("5", Five_Key, 0x98B, 12);
  addKey("6", Six_Key, 0xD8D, 12);
  addKey("7", Seven_Key, 0x50B, 12);
  addKey("8", Eight_Key, 0x901, 12);
  addKey("9", Nine_Key, 0x708, 12);
  addKey("Power", Power_Key, 0x605, 12);
  addKey("Source", Input_Key, 0xA4A, 12);
  addKey("Sat", SatInput_Key, 0xA85, 12);
  addKey("Up", Up_Key, 0xC4F, 12);
  addKey("Down", Down_Key, 0x045, 12);
  addKey("Right", Right_Key, 0x80C, 12);
  addKey("Left", Left_Key, 0xB88, 12);
  addKey("Enter", Enter_Key, 0x384, 12);
  addKey("GoBack", Unmapped_Key, 0x68F, 12);
  addKey("Exit", Exit_Key, 0xA0F, 12);
  addKey("Guide", Guide_Key, 0x782, 12);
  addKey("Interests", Unmapped_Key, 0x581, 12);
  addKey("Options", Unmapped_Key, 0x289, 12);
  addKey("Info", Info_Key, 0xE4C, 12);
  addKey("Browse", Unmapped_Key, 0x849, 12);
  addKey("Future", Unmapped_Key, 0x443, 12);
  addKey("Ch-UP", ChannelUp_Key, 0xD07, 12);
  addKey("Ch-DOWN", ChannelDown_Key, 0x08A, 12);
  addKey("LastCh", PrevChannel_Key, 0x187, 12);
  addKey("Help", Unmapped_Key, 0xF8E, 12);
}


MotorolaSTB1::MotorolaSTB1(
  unsigned int index)
  : PIRKeysetMetaData(
      "STB Keyset 1",
      Motorola_Make,
      index)
{
}


void MotorolaSTB1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new GIProtocol(guiObject, index);

  addKey("0", Zero_Key, 0x0000, 16);
  addKey("1", One_Key, 0xF001, 16);
  addKey("2", Two_Key, 0xE002, 16);
  addKey("3", Three_Key, 0xD003, 16);
  addKey("4", Four_Key, 0xC004, 16);
  addKey("5", Five_Key, 0xB005, 16);
  addKey("6", Six_Key, 0xA006, 16);
  addKey("7", Seven_Key, 0x9007, 16);
  addKey("8", Eight_Key, 0x8008, 16);
  addKey("9", Nine_Key, 0x7009, 16);
  addKey("power", Power_Key, 0x600A, 16);
  addKey("ch+", ChannelUp_Key, 0x500B, 16);
  addKey("ch-", ChannelDown_Key, 0x400C, 16);
  addKey("vol+", VolumeUp_Key, 0x300D, 16);
  addKey("vol-", VolumeDown_Key, 0x200E, 16);
  addKey("mute", Mute_Key, 0x100F, 16);

  addKey("MUSIC", Unmapped_Key, 0xF010, 16);
  addKey("select", Select_Key, 0xE011, 16);
  addKey("enter", Enter_Key, 0xE011, 16);
  addKey("exit", Exit_Key, 0xD012, 16);
  addKey("last", PrevChannel_Key, 0xC013, 16);
  addKey("input", Input_Key, 0xB014, 16); // "tv/vcr_input"
  addKey("fav", Favorites_Key, 0xA015, 16);
  addKey("ppv", Unmapped_Key, 0x9016, 16);
  addKey("a", Audio_Key, 0x8017, 16); // "lang"
  addKey("menu", Menu_Key, 0x6019, 16);
  addKey("ffwd", FastForward_Key, 0x201D, 16);
  addKey("rew", Rewind_Key, 0x101E, 16);
  addKey("pause", Pause_Key, 0x001F, 16);

//  addKey("pnp-swap", PIPSwap_Key, 0xB020, 16);
  addKey("pip_onoff", PIP_Key, 0xC022, 16);
  addKey("pip_swap", PIPSwap_Key, 0xB023, 16);
  addKey("pip_move", PIPMove_Key, 0xA024, 16);
  addKey("pip_chan_up", PIPChannelUp_Key, 0x9025, 16);
  addKey("pip_chan_down", PIPChannelDown_Key, 0x8026, 16);
  addKey("b", Unmapped_Key, 0x7027, 16);
  addKey("c", Unmapped_Key, 0x6028, 16);

  addKey("guide", Guide_Key, 0xD030, 16);
  addKey("record", Record_Key, 0xC031, 16);
  addKey("settings", Unmapped_Key, 0xB032, 16); // "help"
  addKey("info", Info_Key, 0xA033, 16);
  addKey("up", Up_Key, 0x9034, 16);
  addKey("down", Down_Key, 0x8035, 16);
  addKey("left", Left_Key, 0x7036, 16);
  addKey("right", Right_Key, 0x6037, 16);
  addKey("play", Play_Key, 0x5038, 16);
  addKey("stop", Stop_Key, 0x4039, 16);
  addKey("page+", PageUp_Key, 0x303A, 16);
  addKey("page+", StepForward_Key, 0x303A, 16); // for convenience
  addKey("page-", PageDown_Key, 0x203B, 16);
  addKey("page-", StepBack_Key, 0x203B, 16); // Also for convenience
  addKey("skipback", Replay_Key, 0x103C, 16);
  addKey("mydvr", HDDInput_Key, 0x003D, 16);
  addKey("live", LiveTV_Key, 0xF03E, 16);
  addKey("next", Advance_Key, 0xE03F, 16);

  addKey("hdzoom_enter", AspectRatio_Key, 0xC040, 16);

  addKey("red", Red_Key, 0xC06E, 16);
  addKey("green", Green_Key, 0xB06F, 16);
  addKey("yelow", Yellow_Key, 0x9070, 16);
  addKey("blue", Blue_Key, 0x8071, 16);
  addKey("grey", Unmapped_Key, 0x7072, 16);

  addKey("back", Unmapped_Key, 0x649D, 16);

  addKey("exit", Unmapped_Key, 0x60FB, 16); // separate keyset?
}


MotorolaSTB1a::MotorolaSTB1a(
  unsigned int index)
  : MotorolaSTB1(index)
{
  setKeysetName("STB Keyset 1a");
}


void MotorolaSTB1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Already populated.
    return;
  }

  MotorolaSTB1::populateProtocol(guiObject);

  addKey("a_lock", Unmapped_Key, 0x9016, 16);
  addKey("ppv", Unmapped_Key, 0x7018, 16);
  addKey("vod", Unmapped_Key, 0x501A, 16);
  addKey("play", Play_Key, 0x401B, 16);
  addKey("stop", Stop_Key, 0x301C, 16);

  addKey("c_day+", Unmapped_Key, 0x5038, 16);
  addKey("b_day-", Unmapped_Key, 0x4039, 16);
}


MotorolaSTB1b::MotorolaSTB1b(
  unsigned int index)
  : MotorolaSTB1(index)
{
  setKeysetName("STB Keyset 1b");
}


void MotorolaSTB1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Already populated.
    return;
  }

  MotorolaSTB1::populateProtocol(guiObject);

  addKey("yellow", Yellow_Key, 0x8017, 16);
  addKey("ondemand", Unmapped_Key, 0x501A, 16);
  addKey("stop", Stop_Key, 0x301C, 16);
  addKey("play-pause", Play_Key, 0x001F, 16);
  addKey("play-pause", Pause_Key, 0x001F, 16);
  addKey("blue", Blue_Key, 0x7027, 16);
  addKey("red", Red_Key, 0x6028, 16);
  addKey("green", Green_Key, 0x5029, 16);
  addKey("#", Unmapped_Key, 0xC040, 16);
  addKey("widgets", Unmapped_Key, 0x9043, 16);
  addKey("*", Unmapped_Key, 0x8044, 16);
}


MotorolaSkyDigital::MotorolaSkyDigital(
  unsigned int index)
  : PIRKeysetMetaData(
      "Sky Digital Keyset",
      Motorola_Make,
      index)
{
}


void MotorolaSkyDigital::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x2F86, 16);

  addKey("chandown", ChannelDown_Key, 0x01, 8);
  addKey("1", One_Key, 0x02, 8);
  addKey("yellow", Yellow_Key, 0x04, 8);
  addKey("chanup", ChannelUp_Key, 0x07, 8);
  addKey("blue", Blue_Key, 0x09, 8);
  addKey("mute", Mute_Key, 0x0A, 8);
  addKey("3", Three_Key, 0x0C, 8);
  addKey("8", Eight_Key, 0x0D, 8);
  addKey("0", Zero_Key, 0x0E, 8);

  addKey("ok", Select_Key, 0x10, 8);
  addKey("volup", VolumeUp_Key, 0x12, 8);
  addKey("2", Two_Key, 0x13, 8);
  addKey("5", Five_Key, 0x14, 8);
  addKey("plus", Unmapped_Key, 0x15, 8);
  addKey("4", Four_Key, 0x16, 8);
  addKey("6", Six_Key, 0x17, 8);
  addKey("7", Seven_Key, 0x18, 8);
  addKey("9", Nine_Key, 0x19, 8);
  addKey("power", Power_Key, 0x1A, 8);
  addKey("voldown", VolumeDown_Key, 0x1B, 8);
  addKey("green", Green_Key, 0x1E, 8);
  addKey("red", Red_Key, 0x1F, 8);

  addKey("tv", Input_Key, 0x82, 8);
  addKey("left", Left_Key, 0x88, 8);
  addKey("back", Exit_Key, 0x89, 8);
  addKey("up", Up_Key, 0x8B, 8);
  addKey("question", Unmapped_Key, 0x8F, 8);

  addKey("down", Down_Key, 0x91, 8);
  addKey("interactive", Unmapped_Key, 0x93, 8);
  addKey("guide", Guide_Key, 0x9C, 8);
  addKey("right", Right_Key, 0x9D, 8);
}
