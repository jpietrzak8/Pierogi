#include "rca.h"
#include "necprotocol.h"

RCATV1::RCATV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      RCA_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    500, 1000,
    500, 2000,
    64500, true,
    LIRC_NEC);

  threadableProtocol = np;

  np->setHeaderPair(4000, 4000);
  np->setTrailerPulse(500);

//  np->setMinimumRepetitions(1);

  setPreData(0xF, 4);

  addKey("vol-left", VolumeDown_Key, 0x2E0D1, 20);
  addKey("vol-right", VolumeUp_Key, 0x2F0D0, 20);
  addKey("mute", Mute_Key, 0x3F0C0, 20);
  addKey("tv-on-off", Power_Key, 0x2A0D5, 20);
  addKey("tv-who", Unmapped_Key, 0x6109E, 20);
  addKey("tv-fetch", Unmapped_Key, 0x9306C, 20);
  addKey("tv-go-back", PrevChannel_Key, 0x270D8, 20);
  addKey("tv-ch+", ChannelUp_Key, 0x2D0D2, 20);
  addKey("tv-ch-", ChannelDown_Key, 0x2C0D3, 20);
  addKey("tv-guide", Guide_Key, 0x1A0E5, 20);
  addKey("tv-info", Info_Key, 0x3C0C3, 20);
  addKey("tv-menu", Menu_Key, 0x080F7, 20);
  addKey("tv-clear", Clear_Key, 0x060F9, 20);
  addKey("tv-clear", Exit_Key, 0x060F9, 20);
  addKey("tv-ok", Select_Key, 0xF400B, 20);
  addKey("tv-up", Up_Key, 0x590A6, 20);
  addKey("tv-down", Down_Key, 0x580A7, 20);
  addKey("tv-left", Left_Key, 0x560A9, 20);
  addKey("tv-right", Right_Key, 0x570A8, 20);
  addKey("tv-1", One_Key, 0x310CE, 20);
  addKey("tv-2", Two_Key, 0x320CD, 20);
  addKey("tv-3", Three_Key, 0x330CC, 20);
  addKey("tv-4", Four_Key, 0x340CB, 20);
  addKey("tv-5", Five_Key, 0x350CA, 20);
  addKey("tv-6", Six_Key, 0x360C9, 20);
  addKey("tv-7", Seven_Key, 0x370C8, 20);
  addKey("tv-8", Eight_Key, 0x380C7, 20);
  addKey("tv-9", Nine_Key, 0x390C6, 20);
  addKey("tv-0", Zero_Key, 0x300CF, 20);
  addKey("tv-input", Input_Key, 0xA305C, 20);
  addKey("tv-antenna", Unmapped_Key, 0x050FA, 20);
  addKey("tv-reverse", Rewind_Key, 0x1D0E2, 20);
  addKey("tv-play", Play_Key, 0x150EA, 20);
  addKey("tv-forward", FastForward_Key, 0x1C0E3, 20);
  addKey("tv-record", Record_Key, 0x170E8, 20);
  addKey("tv-stop", Stop_Key, 0x1F0E0, 20);
  addKey("tv-pause", Pause_Key, 0x190E6, 20);
  addKey("skip", Advance_Key, 0x530AC, 20);
  addKey("pgm", Program_Key, 0xE101E, 20);
  addKey("Sleep", Sleep_Key, 0x070F8, 20);
  addKey("CC", Captions_Key, 0x8007F, 20);
  addKey("Presets", Unmapped_Key, 0x120ED, 20);
  addKey("Sound", SoundMode_Key, 0x5A0A5, 20);
  addKey("Fav", Favorites_Key, 0x000FF, 20);
  addKey("tv_again", Unmapped_Key, 0xBA045, 20);
  addKey("vport", Unmapped_Key, 0x99066, 20);
  addKey("tv", Unmapped_Key, 0x3A0C5, 20);
}


RCATV1a::RCATV1a(
  QObject *guiObject,
  unsigned int index)
  : RCATV1(guiObject, index)
{
  setKeysetName("TV Keyset 1a");

  addKey("repeat", Repeat_Key, 0x050FA, 20);
  addKey("pip", PIP_Key, 0x1B0E4, 20);
  addKey("swap", PIPSwap_Key, 0xC303C, 20);
  addKey("aspect", AspectRatio_Key, 0x9006F, 20);
}


RCATV2::RCATV2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      RCA_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    500, 1000,
    500, 2000,
    12390, false,
    LIRC_NEC);

  threadableProtocol = np;
  np->setHeaderPair(17355, 3978);
  np->setTrailerPulse(897);

  setPreData(0xF, 4);

  addKey("off", PowerOff_Key, 0x3B0C4, 20);
  addKey("on", PowerOn_Key, 0x3A0C5, 20);
  addKey("display", Info_Key, 0x3C0C3, 20);
  addKey("reset", Reset_Key, 0x120ED, 20);
  addKey("pc", PrevChannel_Key, 0x270D8, 20);
  addKey("1", One_Key, 0x310CE, 20);
  addKey("2", Two_Key, 0x320CD, 20);
  addKey("3", Three_Key, 0x330CC, 20);
  addKey("4", Four_Key, 0x340CB, 20);
  addKey("5", Five_Key, 0x350CA, 20);
  addKey("6", Six_Key, 0x360C9, 20);
  addKey("7", Seven_Key, 0x370C8, 20);
  addKey("8", Eight_Key, 0x380C7, 20);
  addKey("9", Nine_Key, 0x390C6, 20);
  addKey("0", Zero_Key, 0x300CF, 20);
  addKey("ch+", ChannelUp_Key, 0x2D0D2, 20);
  addKey("ch-", ChannelDown_Key, 0x2C0D3, 20);
  addKey("vol+", VolumeUp_Key, 0x2F0D0, 20);
  addKey("vol-", VolumeDown_Key, 0x2E0D1, 20);
  addKey("vid+", Unmapped_Key, 0x6409B, 20);
  addKey("vid-", Unmapped_Key, 0xE201D, 20);
  addKey("setup+", Unmapped_Key, 0x6509A, 20);
  addKey("setup-", Unmapped_Key, 0x180E7, 20);
  addKey("mute", Mute_Key, 0x3F0C0, 20);
}


RCAAux1::RCAAux1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Aux(?) Keyset 1",
      RCA_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    500, 1000,
    500, 2000,
    64500, true,
    LIRC_NEC);

  threadableProtocol = np;

  np->setHeaderPair(4000, 4000);
  np->setTrailerPulse(500);

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
  addKey("aux-antenna", Unmapped_Key, 0x05BFA, 20);
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
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    500, 1000,
    500, 2000,
    64500, true,
    LIRC_NEC);

  threadableProtocol = np;

  np->setHeaderPair(4000, 4000);
  np->setTrailerPulse(500);

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
  addKey("aux-antenna", Unmapped_Key, 0x053FA, 20);
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
  addKey("aux2_antenna", Unmapped_Key, 0x413BE, 20);
  addKey("aux2_whoinput", Input_Key, 0x283D7, 20);
}


RCAVCR1::RCAVCR1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      RCA_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    500, 1000,
    500, 2000,
    64500, true,
    LIRC_NEC);

  threadableProtocol = np;

  np->setHeaderPair(4000, 4000);
  np->setTrailerPulse(500);

//  np->setMinimumRepetitions(1);

  setPreData(0xE, 4);

  addKey("vcr1-on-off", Power_Key, 0x2A1D5, 20);
  addKey("vcr1-who", Unmapped_Key, 0x6119E, 20);
  addKey("vcr1-ch+", ChannelUp_Key, 0x2D1D2, 20);
  addKey("vcr1-ch-", ChannelDown_Key, 0x2C1D3, 20);
  addKey("vcr1-fetch", Unmapped_Key, 0x9316C, 20);
  addKey("vcr1-go-back", PrevChannel_Key, 0x271D8, 20);
  addKey("vcr1-guide", Guide_Key, 0x1A1E5, 20);
  addKey("vcr1-info", Info_Key, 0x3C1C3, 20);
  addKey("vcr1-ok", Select_Key, 0xF410B, 20);
  addKey("vcr1-up", Up_Key, 0x591A6, 20);
  addKey("vcr1-down", Down_Key, 0x581A7, 20);
  addKey("vcr1-left", Left_Key, 0x561A9, 20);
  addKey("vcr1-right", Right_Key, 0x571A8, 20);
  addKey("vcr1-menu", Menu_Key, 0x081F7, 20);
  addKey("vcr1-clear", Clear_Key, 0x061F9, 20);
  addKey("vcr1-clear", Exit_Key, 0x061F9, 20);
  addKey("vcr1-1", One_Key, 0x311CE, 20);
  addKey("vcr1-2", Two_Key, 0x321CD, 20);
  addKey("vcr1-3", Three_Key, 0x331CC, 20);
  addKey("vcr1-4", Four_Key, 0x341CB, 20);
  addKey("vcr1-5", Five_Key, 0x351CA, 20);
  addKey("vcr1-6", Six_Key, 0x361C9, 20);
  addKey("vcr1-7", Seven_Key, 0x371C8, 20);
  addKey("vcr1-8", Eight_Key, 0x381C7, 20);
  addKey("vcr1-9", Nine_Key, 0x391C6, 20);
  addKey("vcr1-0", Zero_Key, 0x301CF, 20);
  addKey("vcr1-input", Input_Key, 0x471B8, 20);
  addKey("vcr1-antenna", Unmapped_Key, 0x051FA, 20);
  addKey("vcr1-reverse", Rewind_Key, 0x1D1E2, 20);
  addKey("vcr1-play", Play_Key, 0x151EA, 20);
  addKey("vcr1-forward", FastForward_Key, 0x1C1E3, 20);
  addKey("vcr1-record", Record_Key, 0x171E8, 20);
  addKey("vcr1-stop", Stop_Key, 0x1F1E0, 20);
  addKey("vcr1-pause", Pause_Key, 0x191E6, 20);
  addKey("skip", Advance_Key, 0x531AC, 20);
  addKey("vcr", Unmapped_Key, 0x3A1C5, 20);
  addKey("vcr_again", Unmapped_Key, 0x461B9, 20);
  addKey("trackplus", TrackingPlus_Key, 0x0B1F4, 20);
  addKey("trackminus", TrackingMinus_Key, 0x0A1F5, 20);
}


RCAVCR2::RCAVCR2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR(alt?) Keyset 2",
      RCA_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    500, 1000,
    500, 2000,
    64500, true,
    LIRC_NEC);

  threadableProtocol = np;

  np->setHeaderPair(4000, 4000);
  np->setTrailerPulse(500);

  setPreData(0xD, 4);

  addKey("vcr2-on-off", Power_Key, 0x2A2D5, 20);
  addKey("vcr2-who", Unmapped_Key, 0x6129E, 20);
  addKey("vcr2-ch+", ChannelUp_Key, 0x2D2D2, 20);
  addKey("vcr2-ch-", ChannelDown_Key, 0x2C2D3, 20);
  addKey("vcr2-fetch", Unmapped_Key, 0x9326C, 20);
  addKey("vcr2-go-back", PrevChannel_Key, 0x272D8, 20);
  addKey("vcr2-guide", Guide_Key, 0x1A2E5, 20);
  addKey("vcr2-info", Info_Key, 0x3C2C3, 20);
  addKey("vcr2-ok", Select_Key, 0xF420B, 20);
  addKey("vcr2-up", Up_Key, 0x592A6, 20);
  addKey("vcr2-down", Down_Key, 0x582A7, 20);
  addKey("vcr2-left", Left_Key, 0x562A9, 20);
  addKey("vcr2-right", Right_Key, 0x572A8, 20);
  addKey("vcr2-menu", Menu_Key, 0x082F7, 20);
  addKey("vcr2-clear", Clear_Key, 0x062F9, 20);
  addKey("vcr2-clear", Exit_Key, 0x062F9, 20);
  addKey("vcr2-1", One_Key, 0x312CE, 20);
  addKey("vcr2-2", Two_Key, 0x322CD, 20);
  addKey("vcr2-3", Three_Key, 0x332CC, 20);
  addKey("vcr2-4", Four_Key, 0x342CB, 20);
  addKey("vcr2-5", Five_Key, 0x352CA, 20);
  addKey("vcr2-6", Six_Key, 0x362C9, 20);
  addKey("vcr2-7", Seven_Key, 0x372C8, 20);
  addKey("vcr2-8", Eight_Key, 0x382C7, 20);
  addKey("vcr2-9", Nine_Key, 0x392C6, 20);
  addKey("vcr2-0", Zero_Key, 0x302CF, 20);
  addKey("vcr2-input", Input_Key, 0x472B8, 20);
  addKey("vcr2-antenna", Unmapped_Key, 0x052FA, 20);
  addKey("vcr2-reverse", Rewind_Key, 0x1D2E2, 20);
  addKey("vcr2-play", Play_Key, 0x152EA, 20);
  addKey("vcr2-forward", FastForward_Key, 0x1C2E3, 20);
  addKey("vcr2-record", Record_Key, 0x172E8, 20);
  addKey("vcr2-stop", Stop_Key, 0x1F2E0, 20);
  addKey("vcr2-pause", Pause_Key, 0x192E6, 20);
  addKey("skip", Advance_Key, 0x532AC, 20);
}


RCADVD1::RCADVD1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      RCA_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    500, 1000,
    500, 2000,
    64500, true,
    LIRC_NEC);

  threadableProtocol = np;

  np->setHeaderPair(4000, 4000);
  np->setTrailerPulse(500);

  setPreData(0x5, 4);

  addKey("dvd-on-off", Power_Key, 0x2AAD5, 20);
  addKey("dvd-who", Unmapped_Key, 0x61A9E, 20);
  addKey("dvd-ch+", ChannelUp_Key, 0x2DAD2, 20);
  addKey("dvd-ch-", ChannelDown_Key, 0x2CAD3, 20);
  addKey("dvd-fetch", Unmapped_Key, 0x93A6C, 20);
  addKey("dvd-go-back", PrevChannel_Key, 0x27AD8, 20);
  addKey("dvd-guide", Guide_Key, 0x1AAE5, 20);
  addKey("dvd-info", Info_Key, 0x3CAC3, 20);
  addKey("dvd-ok", Select_Key, 0xF4A0B, 20);
  addKey("dvd-up", Up_Key, 0x59AA6, 20);
  addKey("dvd-down", Down_Key, 0x58AA7, 20);
  addKey("dvd-left", Left_Key, 0x56AA9, 20);
  addKey("dvd-right", Right_Key, 0x57AA8, 20);
  addKey("dvd-menu", Menu_Key, 0x08AF7, 20);
  addKey("dvd-clear", Clear_Key, 0x06AF9, 20);
  addKey("dvd-clear", Exit_Key, 0x06AF9, 20);
  addKey("dvd-1", One_Key, 0x31ACE, 20);
  addKey("dvd-2", Two_Key, 0x32ACD, 20);
  addKey("dvd-3", Three_Key, 0x33ACC, 20);
  addKey("dvd-4", Four_Key, 0x34ACB, 20);
  addKey("dvd-5", Five_Key, 0x35ACA, 20);
  addKey("dvd-6", Six_Key, 0x36AC9, 20);
  addKey("dvd-7", Seven_Key, 0x37AC8, 20);
  addKey("dvd-8", Eight_Key, 0x38AC7, 20);
  addKey("dvd-9", Nine_Key, 0x39AC6, 20);
  addKey("dvd-0", Zero_Key, 0x30ACF, 20);
  addKey("dvd-input", Input_Key, 0x47AB8, 20);
  addKey("dvd-antenna", Unmapped_Key, 0x05AFA, 20); // tv_vcr
  addKey("dvd-reverse", Rewind_Key, 0x1DAE2, 20);
  addKey("dvd-play", Play_Key, 0x15AEA, 20);
  addKey("dvd-forward", FastForward_Key, 0x1CAE3, 20);
  addKey("dvd-record", Record_Key, 0x17AE8, 20);
  addKey("dvd-stop", Stop_Key, 0x1FAE0, 20);
  addKey("dvd-pause", Pause_Key, 0x19AE6, 20);
  addKey("skip", Advance_Key, 0x53AAC, 20);
  addKey("dvd_again", Replay_Key, 0xBAA45, 20);
  addKey("dvd_open_close", Eject_Key, 0x40ABF, 20);
  addKey("dvd_zoom", Zoom_Key, 0x90A6F, 20);
  addKey("dvd_preset", Unmapped_Key, 0x12AED, 20);
  addKey("dvd", Unmapped_Key, 0x3AAC5, 20);
}


RCADVD1a::RCADVD1a(
  QObject *guiObject,
  unsigned int index)
  : RCADVD1(guiObject, index)
{
  setKeysetName("DVD Keyset 1a");

  addKey("dvd_ch+", ChannelUp_Key, 0x20ADF, 20);
  addKey("dvd_ch-", ChannelDown_Key, 0x22ADD, 20);
}


RCASat1::RCASat1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Satellite(DirecTV) Keyset 1",
      RCA_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    500, 1000,
    500, 2000,
    64500, true,
    LIRC_NEC);

  threadableProtocol = np;

  np->setHeaderPair(4000, 4000);
  np->setTrailerPulse(500);

  setPreData(0x7, 4);

  addKey("on-off", Power_Key, 0x2A8D5, 20);
  addKey("who", Unmapped_Key, 0x6189E, 20); // "cc", "-"
  addKey("ch+", ChannelUp_Key, 0x2D8D2, 20);
  addKey("ch-", ChannelDown_Key, 0x2C8D3, 20);
  addKey("fetch", Unmapped_Key, 0x9386C, 20);
  addKey("go-back", PrevChannel_Key, 0x278D8, 20);
  addKey("guide", Guide_Key, 0x1A8E5, 20);
  addKey("info", Info_Key, 0x3C8C3, 20);
  addKey("ok", Select_Key, 0xF480B, 20);
  addKey("ok", Enter_Key, 0xF480B, 20);
  addKey("up", Up_Key, 0x598A6, 20);
  addKey("down", Down_Key, 0x588A7, 20);
  addKey("left", Left_Key, 0x568A9, 20);
  addKey("right", Right_Key, 0x578A8, 20);
  addKey("menu", Menu_Key, 0x088F7, 20);
  addKey("clear", Clear_Key, 0x068F9, 20);
  addKey("clear", Exit_Key, 0x068F9, 20);
  addKey("1", One_Key, 0x318CE, 20);
  addKey("2", Two_Key, 0x328CD, 20);
  addKey("3", Three_Key, 0x338CC, 20);
  addKey("4", Four_Key, 0x348CB, 20);
  addKey("5", Five_Key, 0x358CA, 20);
  addKey("6", Six_Key, 0x368C9, 20);
  addKey("7", Seven_Key, 0x378C8, 20);
  addKey("8", Eight_Key, 0x388C7, 20);
  addKey("9", Nine_Key, 0x398C6, 20);
  addKey("0", Zero_Key, 0x308CF, 20);
  addKey("hd-input", Input_Key, 0x478B8, 20);
  addKey("antenna", Unmapped_Key, 0x058FA, 20); // "TV/VCR"
  addKey("hd-reverse", Rewind_Key, 0x1D8E2, 20);
  addKey("hd-play", Play_Key, 0x158EA, 20);
  addKey("hd-forward", FastForward_Key, 0x1C8E3, 20);
  addKey("hd-record", Record_Key, 0x178E8, 20);
  addKey("hd-stop", Stop_Key, 0x1F8E0, 20);
  addKey("hd-pause", Pause_Key, 0x198E6, 20);
  addKey("skip", Advance_Key, 0x538AC, 20);
  addKey("SAT", Unmapped_Key, 0x3A8C5, 20);
  addKey("PIP", PIP_Key, 0x1B8E4, 20);
  addKey("SWAP", PIPSwap_Key, 0xC383C, 20);
  addKey("INPUT", Unmapped_Key, 0x6189E, 20);
}


RCASat2::RCASat2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Satellite (Dish Network) Keyset 2",
      RCA_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    440, 2780,
    440, 1645,
    6115, false,
    LIRC_NEC);

  threadableProtocol = np;

  np->setHeaderPair(525, 6045);
  np->setTrailerPulse(450);

//  np->setMinimumRepetitions(6);
  np->setFullHeadlessRepeat(true);

  np->setCarrierFrequency(56000);
  np->setDutyCycle(32);

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
  addKey("sat", Unmapped_Key, 0x41, 6);
  addKey("dish_home", Unmapped_Key, 0x52, 6);
  addKey("sys_info2", Unmapped_Key, 0x54, 6);
  addKey("dish_home2", Unmapped_Key, 0x56, 6);
}
