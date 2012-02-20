#include "rca.h"
#include "protocols/lircprotocol.h"
#include "protocols/rcaprotocol.h"

RCATV1::RCATV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      RCA_Make,
      index)
{
}


void RCATV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RCAProtocol(guiObject, index);

  setPreData(0xF, 4);

  addKey("Fav", Favorites_Key, 0x00, 8);
  addKey("tv-antenna", AntennaInput_Key, 0x05, 8);
  addKey("tv-clear", Clear_Key, 0x06, 8);
  addKey("tv-clear", Exit_Key, 0x06, 8);
  addKey("Sleep", Sleep_Key, 0x07, 8);
  addKey("tv-menu", Menu_Key, 0x08, 8);
  addKey("Presets", Unmapped_Key, 0x12, 8);
  addKey("tv-play", Play_Key, 0x15, 8);
  addKey("tv-record", Record_Key, 0x17, 8);
  addKey("setup-", Unmapped_Key, 0x18, 8);
  addKey("tv-pause", Pause_Key, 0x19, 8);
  addKey("tv-guide", Guide_Key, 0x1A, 8);
  addKey("pip", PIP_Key, 0x1B, 8);
  addKey("tv-forward", FastForward_Key, 0x1C, 8);
  addKey("tv-reverse", Rewind_Key, 0x1D, 8);
  addKey("tv-stop", Stop_Key, 0x1F, 8);
  addKey("tv-go-back", PrevChannel_Key, 0x27, 8); // "pc"
  addKey("tv-on-off", Power_Key, 0x2A, 8);
  addKey("tv-ch-", ChannelDown_Key, 0x2C, 8);
  addKey("tv-ch+", ChannelUp_Key, 0x2D, 8);
  addKey("vol-left", VolumeDown_Key, 0x2E, 8);
  addKey("vol-right", VolumeUp_Key, 0x2F, 8);
  addKey("tv-0", Zero_Key, 0x30, 8);
  addKey("tv-1", One_Key, 0x31, 8);
  addKey("tv-2", Two_Key, 0x32, 8);
  addKey("tv-3", Three_Key, 0x33, 8);
  addKey("tv-4", Four_Key, 0x34, 8);
  addKey("tv-5", Five_Key, 0x35, 8);
  addKey("tv-6", Six_Key, 0x36, 8);
  addKey("tv-7", Seven_Key, 0x37, 8);
  addKey("tv-8", Eight_Key, 0x38, 8);
  addKey("tv-9", Nine_Key, 0x39, 8);
  addKey("tv", PowerOn_Key, 0x3A, 8); // "on"
  addKey("off", PowerOff_Key, 0x3B, 8);
  addKey("tv-info", Info_Key, 0x3C, 8); // "display"
  addKey("mute", Mute_Key, 0x3F, 8);
  addKey("skip", Advance_Key, 0x53, 8);
  addKey("tv-right", Right_Key, 0x57, 8);
  addKey("tv-left", Left_Key, 0x56, 8);
  addKey("tv-down", Down_Key, 0x58, 8);
  addKey("tv-up", Up_Key, 0x59, 8);
  addKey("Sound", SoundMode_Key, 0x5A, 8);
  addKey("tv-who", Unmapped_Key, 0x61, 8);
  addKey("vid+", Unmapped_Key, 0x64, 8);
  addKey("setup+", Unmapped_Key, 0x65, 8);
  addKey("CC", Captions_Key, 0x80, 8);
  addKey("aspect", AspectRatio_Key, 0x90, 8);
  addKey("tv-fetch", Unmapped_Key, 0x93, 8);
  addKey("vport", Unmapped_Key, 0x99, 8);
  addKey("tv-input", Input_Key, 0xA3, 8);
  addKey("tv_again", Unmapped_Key, 0xBA, 8);
  addKey("swap", PIPSwap_Key, 0xC3, 8);
  addKey("pgm", Program_Key, 0xE1, 8);
  addKey("vid-", Unmapped_Key, 0xE2, 8);
  addKey("tv-ok", Select_Key, 0xF4, 8);
}


RCATV1a::RCATV1a(
  unsigned int index)
  : RCATV1(index)
{
  setKeysetName("TV Keyset 1a");
}


void RCATV1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  RCATV1::populateProtocol(guiObject);

  addKey("repeat", Repeat_Key, 0x05, 8);
}


RCATV1b::RCATV1b(
  unsigned int index)
  : RCATV1(index)
{
  setKeysetName("TV Keyset 1b");
}


void RCATV1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  RCATV1::populateProtocol(guiObject);

  addKey("reset", Reset_Key, 0x12, 8);
}


/*
RCAAux1::RCAAux1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Aux(?) Keyset 1",
      RCA_Make,
      index)
{
  LIRCProtocol *lp = new LIRCProtocol(
    guiObject,
    index,
    500, 1000,
    500, 2000,
    64500, true);

  threadableProtocol = lp;

  lp->setHeaderPair(4000, 4000);
  lp->setTrailerPulse(500);

  setPreData(0x4, 4);

  addKey("aux1_power", Power_Key, 0x2ABD5, 20);
  addKey("skip", Advance_Key, 0x53BAC, 20);
  addKey("aux-ch+", ChannelUp_Key, 0x2DBD2, 20);
  addKey("aux-ch-", ChannelDown_Key, 0x2CBD3, 20);
  addKey("aux-fetch", Unmapped_Key, 0x93B6C, 20);
  addKey("aux-go-back", PrevChannel_Key, 0x27BD8, 20);
  addKey("aux-guide", Guide_Key, 0x1ABE5, 20);
  addKey("aux-up", Up_Key, 0x59BA6, 20);
  addKey("aux-info", Info_Key, 0x3CBC3, 20);
  addKey("aux-left", Left_Key, 0x56BA9, 20);
  addKey("aux-ok", Select_Key, 0xF4B0B, 20);
  addKey("aux-right", Right_Key, 0x57BA8, 20);
  addKey("aux-menu", Menu_Key, 0x08BF7, 20);
  addKey("aux-down", Down_Key, 0x58BA7, 20);
  addKey("aux-clear", Clear_Key, 0x06BF9, 20);
  addKey("aux-clear", Exit_Key, 0x06BF9, 20);
  addKey("aux-1", One_Key, 0x31BCE, 20);
  addKey("aux-2", Two_Key, 0x32BCD, 20);
  addKey("aux-3", Three_Key, 0x33BCC, 20);
  addKey("aux-4", Four_Key, 0x34BCB, 20);
  addKey("aux-5", Five_Key, 0x35BCA, 20);
  addKey("aux-6", Six_Key, 0x36BC9, 20);
  addKey("aux-7", Seven_Key, 0x37BC8, 20);
  addKey("aux-8", Eight_Key, 0x38BC7, 20);
  addKey("aux-9", Nine_Key, 0x39BC6, 20);
  addKey("aux-0", Zero_Key, 0x30BCF, 20);
  addKey("aux-who", Unmapped_Key, 0x61B9E, 20);
  addKey("aux-antenna", AntennaInput_Key, 0x05BFA, 20);
  addKey("aux-reverse", Rewind_Key, 0x1DBE2, 20);
  addKey("aux-play", Play_Key, 0x15BEA, 20);
  addKey("aux-forward", FastForward_Key, 0x1CBE3, 20);
  addKey("aux-record", Record_Key, 0x17BE8, 20);
  addKey("aux-stop", Stop_Key, 0x1FBE0, 20);
  addKey("aux-pause", Pause_Key, 0x19BE6, 20);
//  addKey("aux-mute", Mute_Key, 0x3FBC0, 20);
//  addKey("aux-vol-left", VolumeDown_Key, 0x2EBD1, 20);
//  addKey("aux-vol-right", VolumeUp_Key, 0x2FBD0, 20);
}


RCAAux2::RCAAux2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Aux(?) Keyset 2",
      RCA_Make,
      index)
{
  LIRCProtocol *lp = new LIRCProtocol(
    guiObject,
    index,
    500, 1000,
    500, 2000,
    64500, true);

  threadableProtocol = lp;

  lp->setHeaderPair(4000, 4000);
  lp->setTrailerPulse(500);

  setPreData(0xC, 4);

  addKey("aux-on-off", Power_Key, 0x3B3C4, 20);
  addKey("aux-mute", Mute_Key, 0x3F3C0, 20);
  addKey("aux-who", Unmapped_Key, 0x6139E, 20);
  addKey("aux-ch+", ChannelUp_Key, 0x2D3D2, 20);
  addKey("aux-ch-", ChannelDown_Key, 0x2C3D3, 20);
  addKey("aux-vol-left", VolumeDown_Key, 0x2E3D1, 20);
  addKey("aux-vol-right", VolumeUp_Key, 0x2F3D0, 20);
  addKey("aux-fetch", Unmapped_Key, 0x9336C, 20);
  addKey("aux-go-back", PrevChannel_Key, 0x273D8, 20);
  addKey("aux-guide", Guide_Key, 0x1A3E5, 20);
  addKey("aux-info", Info_Key, 0x3C3C3, 20);
  addKey("aux-menu", Menu_Key, 0x083F7, 20);
  addKey("aux-clear", Clear_Key, 0x063F9, 20);
  addKey("aux-clear", Exit_Key, 0x063F9, 20);
  addKey("aux-up", Up_Key, 0x593A6, 20);
  addKey("aux-down", Down_Key, 0x583A7, 20);
  addKey("aux-right", Right_Key, 0x573A8, 20);
  addKey("aux-left", Left_Key, 0x563A9, 20);
  addKey("aux-ok", Select_Key, 0xF430B, 20);
  addKey("aux-1", One_Key, 0x313CE, 20);
  addKey("aux-2", Two_Key, 0x323CD, 20);
  addKey("aux-3", Three_Key, 0x333CC, 20);
  addKey("aux-4", Four_Key, 0x343CB, 20);
  addKey("aux-5", Five_Key, 0x353CA, 20);
  addKey("aux-6", Six_Key, 0x363C9, 20);
  addKey("aux-7", Seven_Key, 0x373C8, 20);
  addKey("aux-8", Eight_Key, 0x383C7, 20);
  addKey("aux-9", Nine_Key, 0x393C6, 20);
  addKey("aux-0", Zero_Key, 0x303CF, 20);
  addKey("aux-antenna", AntennaInput_Key, 0x053FA, 20);
  addKey("aux-reverse", Rewind_Key, 0x1D3E2, 20);
  addKey("aux-play", Play_Key, 0x153EA, 20);
  addKey("aux-forward", FastForward_Key, 0x1C3E3, 20);
  addKey("aux-record", Record_Key, 0x173E8, 20);
  addKey("aux-stop", Stop_Key, 0x1F3E0, 20);
  addKey("aux-pause", Pause_Key, 0x193E6, 20);
  addKey("skip", Advance_Key, 0x533AC, 20);
}


RCAAux2a::RCAAux2a(
  QObject *guiObject,
  unsigned int index)
  : RCAAux2(guiObject, index)
{
  setKeysetName("Aux(?) Keyset 2a");

  addKey("aux2_up", Up_Key, 0x6339C, 20);
  addKey("aux2_left", Left_Key, 0x6439B, 20);
  addKey("aux2_right", Right_Key, 0x6539A, 20);
  addKey("aux2_down", Down_Key, 0x6239D, 20);
  addKey("aux2_antenna", AntennaInput_Key, 0x413BE, 20);
  addKey("aux2_whoinput", Input_Key, 0x283D7, 20);
}
*/


RCAVCR1::RCAVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      RCA_Make,
      index)
{
}


void RCAVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RCAProtocol(guiObject, index);

  setPreData(0xE, 4);

  addKey("vcr1-antenna", AntennaInput_Key, 0x05, 8);
  addKey("vcr1-clear", Clear_Key, 0x06, 8);
  addKey("vcr1-clear", Exit_Key, 0x06, 8);
  addKey("vcr1-menu", Menu_Key, 0x08, 8);
  addKey("trackminus", TrackingMinus_Key, 0x0A, 8);
  addKey("trackplus", TrackingPlus_Key, 0x0B, 8);
  addKey("vcr1-play", Play_Key, 0x15, 8);
  addKey("vcr1-record", Record_Key, 0x17, 8);
  addKey("vcr1-pause", Pause_Key, 0x19, 8);
  addKey("vcr1-guide", Guide_Key, 0x1A, 8);
  addKey("vcr1-forward", FastForward_Key, 0x1C, 8);
  addKey("vcr1-reverse", Rewind_Key, 0x1D, 8);
  addKey("vcr1-stop", Stop_Key, 0x1F, 8);
  addKey("vcr1-go-back", PrevChannel_Key, 0x27, 8);
  addKey("vcr1-on-off", Power_Key, 0x2A, 8);
  addKey("vcr1-ch-", ChannelDown_Key, 0x2C, 8);
  addKey("vcr1-ch+", ChannelUp_Key, 0x2D, 8);
  addKey("vcr1-0", Zero_Key, 0x30, 8);
  addKey("vcr1-1", One_Key, 0x31, 8);
  addKey("vcr1-2", Two_Key, 0x32, 8);
  addKey("vcr1-3", Three_Key, 0x33, 8);
  addKey("vcr1-4", Four_Key, 0x34, 8);
  addKey("vcr1-5", Five_Key, 0x35, 8);
  addKey("vcr1-6", Six_Key, 0x36, 8);
  addKey("vcr1-7", Seven_Key, 0x37, 8);
  addKey("vcr1-8", Eight_Key, 0x38, 8);
  addKey("vcr1-9", Nine_Key, 0x39, 8);
  addKey("vcr", Unmapped_Key, 0x3A, 8);
  addKey("vcr1-info", Info_Key, 0x3C, 8);
  addKey("vcr_again", Unmapped_Key, 0x46, 8);
  addKey("vcr1-input", Input_Key, 0x47, 8);
  addKey("skip", Advance_Key, 0x53, 8);
  addKey("vcr1-left", Left_Key, 0x56, 8);
  addKey("vcr1-right", Right_Key, 0x57, 8);
  addKey("vcr1-down", Down_Key, 0x58, 8);
  addKey("vcr1-up", Up_Key, 0x59, 8);
  addKey("vcr1-who", Unmapped_Key, 0x61, 8);
  addKey("vcr1-fetch", Unmapped_Key, 0x93, 8);
  addKey("vcr1-ok", Select_Key, 0xF4, 8);
}


RCAVCR1a::RCAVCR1a(
  unsigned int index)
  : RCAVCR1(index)
{
  setKeysetName("VCR(alt) Keyset 1a");
}


void RCAVCR1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  RCAVCR1::populateProtocol(guiObject);

  setPreData(0xD, 4);
}


RCADVD1::RCADVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      RCA_Make,
      index)
{
}


void RCADVD1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RCAProtocol(guiObject, index);

  setPreData(0x5, 4);

  addKey("dvd-antenna", AntennaInput_Key, 0x05, 8); // tv_vcr
  addKey("dvd-clear", Clear_Key, 0x06, 8);
  addKey("dvd-clear", Exit_Key, 0x06, 8);
  addKey("dvd-menu", Menu_Key, 0x08, 8);
  addKey("dvd_preset", Unmapped_Key, 0x12, 8);
  addKey("dvd-play", Play_Key, 0x15, 8);
  addKey("dvd-record", Record_Key, 0x17, 8);
  addKey("dvd-pause", Pause_Key, 0x19, 8);
  addKey("dvd-guide", Guide_Key, 0x1A, 8);
  addKey("dvd-forward", FastForward_Key, 0x1C, 8);
  addKey("dvd-reverse", Rewind_Key, 0x1D, 8);
  addKey("dvd-stop", Stop_Key, 0x1F, 8);
  addKey("dvd-go-back", PrevChannel_Key, 0x27, 8);
  addKey("dvd-on-off", Power_Key, 0x2A, 8);
  addKey("dvd-ch-", ChannelDown_Key, 0x2C, 8);
  addKey("dvd-ch+", ChannelUp_Key, 0x2D, 8);
  addKey("dvd-0", Zero_Key, 0x30, 8);
  addKey("dvd-1", One_Key, 0x31, 8);
  addKey("dvd-2", Two_Key, 0x32, 8);
  addKey("dvd-3", Three_Key, 0x33, 8);
  addKey("dvd-4", Four_Key, 0x34, 8);
  addKey("dvd-5", Five_Key, 0x35, 8);
  addKey("dvd-6", Six_Key, 0x36, 8);
  addKey("dvd-7", Seven_Key, 0x37, 8);
  addKey("dvd-8", Eight_Key, 0x38, 8);
  addKey("dvd-9", Nine_Key, 0x39, 8);
  addKey("dvd", Unmapped_Key, 0x3A, 8);
  addKey("dvd-info", Info_Key, 0x3C, 8);
  addKey("dvd_open_close", Eject_Key, 0x40, 8);
  addKey("dvd-input", Input_Key, 0x47, 8);
  addKey("skip", Advance_Key, 0x53, 8);
  addKey("dvd-left", Left_Key, 0x56, 8);
  addKey("dvd-right", Right_Key, 0x57, 8);
  addKey("dvd-down", Down_Key, 0x58, 8);
  addKey("dvd-up", Up_Key, 0x59, 8);
  addKey("dvd-who", Unmapped_Key, 0x61, 8);
  addKey("dvd_zoom", Zoom_Key, 0x90, 8);
  addKey("dvd-fetch", Unmapped_Key, 0x93, 8);
  addKey("dvd_again", Replay_Key, 0xBA, 8);
  addKey("dvd-ok", Select_Key, 0xF4, 8);
}


RCADVD1a::RCADVD1a(
  unsigned int index)
  : RCADVD1(index)
{
  setKeysetName("DVD Keyset 1a");
}


void RCADVD1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  RCADVD1::populateProtocol(guiObject);

  addKey("dvd_ch+", ChannelUp_Key, 0x20, 8);
  addKey("dvd_ch-", ChannelDown_Key, 0x22, 8);
}


RCASat1::RCASat1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Satellite(DirecTV) Keyset 1",
      RCA_Make,
      index)
{
}


void RCASat1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RCAProtocol(guiObject, index);

  setPreData(0x7, 4);

  addKey("antenna", AntennaInput_Key, 0x05, 8); // "TV/VCR"
  addKey("clear", Clear_Key, 0x06, 8);
  addKey("clear", Exit_Key, 0x06, 8);
  addKey("menu", Menu_Key, 0x08, 8);
  addKey("hd-play", Play_Key, 0x15, 8);
  addKey("hd-record", Record_Key, 0x17, 8);
  addKey("hd-pause", Pause_Key, 0x19, 8);
  addKey("guide", Guide_Key, 0x1A, 8);
  addKey("PIP", PIP_Key, 0x1B, 8);
  addKey("hd-forward", FastForward_Key, 0x1C, 8);
  addKey("hd-reverse", Rewind_Key, 0x1D, 8);
  addKey("hd-stop", Stop_Key, 0x1F, 8);
  addKey("go-back", PrevChannel_Key, 0x27, 8);
  addKey("on-off", Power_Key, 0x2A, 8);
  addKey("ch-", ChannelDown_Key, 0x2C, 8);
  addKey("ch+", ChannelUp_Key, 0x2D, 8);
  addKey("0", Zero_Key, 0x30, 8);
  addKey("1", One_Key, 0x31, 8);
  addKey("2", Two_Key, 0x32, 8);
  addKey("3", Three_Key, 0x33, 8);
  addKey("4", Four_Key, 0x34, 8);
  addKey("5", Five_Key, 0x35, 8);
  addKey("6", Six_Key, 0x36, 8);
  addKey("7", Seven_Key, 0x37, 8);
  addKey("8", Eight_Key, 0x38, 8);
  addKey("9", Nine_Key, 0x39, 8);
  addKey("info", Info_Key, 0x3C, 8);
  addKey("SAT", Unmapped_Key, 0x3A, 8);
  addKey("hd-input", Input_Key, 0x47, 8);
  addKey("skip", Advance_Key, 0x53, 8);
  addKey("left", Left_Key, 0x56, 8);
  addKey("right", Right_Key, 0x57, 8);
  addKey("down", Down_Key, 0x58, 8);
  addKey("up", Up_Key, 0x59, 8);
  addKey("INPUT", Input_Key, 0x61, 8);
//  addKey("who", Unmapped_Key, 0x61, 8); // "cc", "-"
  addKey("fetch", Unmapped_Key, 0x93, 8);
  addKey("SWAP", PIPSwap_Key, 0xC3, 8);
  addKey("ok", Select_Key, 0xF4, 8);
  addKey("ok", Enter_Key, 0xF4, 8);
}


RCASat2::RCASat2(
  unsigned int index)
  : PIRKeysetMetaData(
      "Satellite (Dish Network) Keyset 2",
      RCA_Make,
      index)
{
}


void RCASat2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  LIRCProtocol *lp = new LIRCProtocol(
    guiObject,
    index,
    440, 2780,
    440, 1645,
    6115, false);

  threadableProtocol = lp;

  lp->setHeaderPair(525, 6045);
  lp->setTrailerPulse(450);

//  lp->setMinimumRepetitions(6);
  lp->setFullHeadlessRepeat(true);

  lp->setCarrierFrequency(56000);
  lp->setDutyCycle(32);

  setPostData(0x000, 10);

  addKey("info", Info_Key, 0x0, 6);
  addKey("power_on", PowerOn_Key, 0x1, 6);
  addKey("power", Power_Key, 0x2, 6);
  addKey("1", One_Key, 0x4, 6);
  addKey("2", Two_Key, 0x5, 6);
  addKey("3", Three_Key, 0x6, 6);
  addKey("4", Four_Key, 0x8, 6);
  addKey("5", Five_Key, 0x9, 6);
  addKey("6", Six_Key, 0x10, 6);
  addKey("7", Seven_Key, 0x12, 6);
  addKey("8", Eight_Key, 0x13, 6);
  addKey("9", Nine_Key, 0x14, 6);
  addKey("0", Zero_Key, 0x17, 6);
  addKey("menu", Menu_Key, 0x11, 6);
  addKey("select", Select_Key, 0x16, 6);
  addKey("cancel", Exit_Key, 0x18, 6);
  addKey("guide", Guide_Key, 0x20, 6);
  addKey("view", Unmapped_Key, 0x22, 6);
  addKey("tv_vcr", Input_Key, 0x23, 6);
  addKey("right", Right_Key, 0x24, 6);
  addKey("up", Up_Key, 0x26, 6);
  addKey("recall", PrevChannel_Key, 0x27, 6);
  addKey("left", Left_Key, 0x28, 6);
  addKey("down", Down_Key, 0x30, 6);
  addKey("record", Record_Key, 0x31, 6);
  addKey("pause", Pause_Key, 0x32, 6);
  addKey("stop", Stop_Key, 0x33, 6);
  addKey("sys_info", Info_Key, 0x36, 6);
  addKey("asterisk", Unmapped_Key, 0x37, 6);
  addKey("pound", Unmapped_Key, 0x38, 6);
  addKey("power_off", PowerOff_Key, 0x39, 6);
  addKey("sat", CableInput_Key, 0x41, 6);
  addKey("dish_home", Unmapped_Key, 0x52, 6);
  addKey("sys_info2", Unmapped_Key, 0x54, 6);
  addKey("dish_home2", Unmapped_Key, 0x56, 6);
}
