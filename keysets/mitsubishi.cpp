#include "mitsubishi.h"
#include "necprotocol.h"

MitsubishiTV1::MitsubishiTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Mitsubishi_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    300, 900,
    300, 2100,
    53715, true);

  threadableProtocol = np;

  np->setTrailerPulse(300);

  np->setPreData(0xE2, 8);

//  np->setMinimumRepetitions(1);

  addKey("POWER", Power_Key, 0x40, 8);
  addKey("0", Zero_Key, 0x90, 8);
  addKey("1", One_Key, 0x00, 8);
  addKey("2", Two_Key, 0x10, 8);
  addKey("3", Three_Key, 0x08, 8);
  addKey("4", Four_Key, 0x18, 8);
  addKey("5", Five_Key, 0x04, 8);
  addKey("6", Six_Key, 0x14, 8);
  addKey("7", Seven_Key, 0x0C, 8);
  addKey("8", Eight_Key, 0x1C, 8);
  addKey("9", Nine_Key, 0x80, 8);
  addKey("-/--", DoubleDigit_Key, 0x88, 8); // "1-"
  addKey("2-", Unmapped_Key, 0x98, 8);
  addKey("VOL_UP", VolumeUp_Key, 0x44, 8);
  addKey("VOL_DOWN", VolumeDown_Key, 0x54, 8);
  addKey("MUTE", Mute_Key, 0x4C, 8);
  addKey("OFF_TIMER", Sleep_Key, 0xE8, 8);
  addKey("ENTER", Enter_Key, 0xAC, 8);
  addKey("ENTER", Select_Key, 0xAC, 8);
  addKey("TV/EXT", Input_Key, 0x5C, 8); // "tv/av", "INPUT"
  addKey("CHANNEL_UP", ChannelUp_Key, 0x50, 8);
  addKey("CHANNEL_DOWN", ChannelDown_Key, 0x48, 8);
  addKey("VIDEO", Unmapped_Key, 0x02, 8);
  addKey("ADJ_LEFT", Unmapped_Key, 0x92, 8);
  addKey("ADJ_RIGHT", Unmapped_Key, 0x82, 8);
  addKey("LAST", PrevChannel_Key, 0xF0, 8); // "Q.V."
  addKey("display", Info_Key, 0xF8, 8); // "clear"
  addKey("menu", Menu_Key, 0x4A, 8); // "MODE"
  addKey("up", Up_Key, 0x26, 8);
  addKey("down", Down_Key, 0x36, 8);
  addKey("right", Right_Key, 0x82, 8);
  addKey("left", Left_Key, 0x92, 8);
  addKey("TEXT", Unmapped_Key, 0x30, 8);
  addKey("HOLD", Unmapped_Key, 0xA8, 8);
  addKey("INDEX", Unmapped_Key, 0x64, 8);
  addKey("CANCEL/TIME", Unmapped_Key, 0xB8, 8);
  addKey("RED", Red_Key, 0xF4, 8);
  addKey("GREEN", Green_Key, 0xEC, 8);
  addKey("YELLOW", Yellow_Key, 0xFC, 8);
  addKey("BLUE", Blue_Key, 0xE4, 8);
  addKey("SIZE", Unmapped_Key, 0x34, 8);
  addKey("S****", Unmapped_Key, 0x74, 8);
  addKey("REVEAL", Unmapped_Key, 0x7C, 8);
  addKey("MODE", Unmapped_Key, 0xA4, 8);
  addKey("STORE", Unmapped_Key, 0x78, 8);
  addKey("STATUS", Unmapped_Key, 0xB0, 8);
  addKey("BROWSE", Unmapped_Key, 0x6C, 8);
  addKey("PIP", PIP_Key, 0xEE, 8);
  addKey("SOURCE", PIPSource_Key, 0xFA, 8);
  addKey("POSITION", PIPMove_Key, 0x76, 8);
  addKey("EXCHANGE", PIPSwap_Key, 0xFE, 8);
  addKey("STILL", Unmapped_Key, 0xE6, 8);
  addKey("PREVMENU", Exit_Key, 0xD2, 8);
  addKey("ENTER", Select_Key, 0xDE, 8);
  addKey("VIDEO", Unmapped_Key, 0xCC, 8);
  addKey("AUDIO", Unmapped_Key, 0xDC, 8);
  addKey("ST/MONO", Unmapped_Key, 0xC0, 8);
  addKey("DEGAUSS", Unmapped_Key, 0xCE, 8);
  addKey("DEMO", Unmapped_Key, 0x62, 8);
  addKey("PRESET", Unmapped_Key, 0xA2, 8);
  addKey("BAND", Unmapped_Key, 0xAE, 8);
  addKey("AFT", Unmapped_Key, 0xA6, 8);
  addKey("SKIP", Unmapped_Key, 0xB6, 8);
  addKey("REALNAME", Unmapped_Key, 0xDA, 8);
}


MitsubishiTV1a::MitsubishiTV1a(
  QObject *guiObject,
  unsigned int index)
  : MitsubishiTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1a");

  addKey("TURNLEFT", Unmapped_Key, 0xAC, 8);
  addKey("TURNRIGHT", Unmapped_Key, 0xB4, 8);
  addKey("COLOUR-SELECT", PictureMode_Key, 0x30, 8);
  addKey("AUDIO-SELECT", SoundMode_Key, 0xC8, 8);
}


MitsubishiVCR1::MitsubishiVCR1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Mitsubishi_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    300, 900,
    300, 2100,
    53815, true);

  threadableProtocol = np;

  np->setTrailerPulse(300);

  np->setPreData(0xEA, 8);

//  np->setMinimumRepetitions(1);

  addKey("POWER", Power_Key, 0x40, 8);
  addKey("CH-", ChannelDown_Key, 0x48, 8);
  addKey("CH+", ChannelUp_Key, 0x50, 8);
  addKey("PROG_ON-OFF", Unmapped_Key, 0xD8, 8); // "SHOWVIEW"
  addKey("PROG_REC", Unmapped_Key, 0xF8, 8);
  addKey("PROG_NBR", Unmapped_Key, 0xD4, 8);
  addKey("SELECT", Select_Key, 0xCC, 8); // "OKPROG", "quick_program"
  addKey("SET", Enter_Key, 0xC8, 8);
  addKey("CLEAR", Clear_Key, 0xD0, 8);
  addKey("INDEX_ENTER", Unmapped_Key, 0xF0, 8);
  addKey("FAST_PLAY", Unmapped_Key, 0xA4, 8);
  addKey("COUNTER_RESET", Unmapped_Key, 0xA8, 8);
  addKey("COUNTER_MEMORY", Unmapped_Key, 0xB0, 8);
  addKey("REC", Record_Key, 0x30, 8);
  addKey("PAUSE", Pause_Key, 0x38, 8);
  addKey("STOP", Stop_Key, 0x28, 8);
  addKey("SLOW", Unmapped_Key, 0x2C, 8); // "UP"
  addKey("REW", Rewind_Key, 0x34, 8);
  addKey("PLAY", Play_Key, 0x20, 8);
  addKey("FF", FastForward_Key, 0x24, 8);
  addKey("REPEAT", Unmapped_Key, 0xE8, 8);
  addKey("SKIP_SEARCH", Advance_Key, 0xBC, 8);
  addKey("INDEX_SEARCH-", Previous_Key, 0x68, 8);
  addKey("INDEX_SEARCH+", Next_Key, 0x70, 8);
  addKey("EJECT", Eject_Key, 0x6C, 8);
  addKey("MENU", Menu_Key, 0x4A, 8);
  addKey("123MENU", Unmapped_Key, 0x0A, 8);
  addKey("AV", Unmapped_Key, 0x58, 8);
  addKey("0", Zero_Key, 0x90, 8);
  addKey("1", One_Key, 0x00, 8);
  addKey("2", Two_Key, 0x10, 8);
  addKey("3", Three_Key, 0x08, 8);
  addKey("4", Four_Key, 0x18, 8);
  addKey("5", Five_Key, 0x04, 8);
  addKey("6", Six_Key, 0x14, 8);
  addKey("7", Seven_Key, 0x0C, 8);
  addKey("8", Eight_Key, 0x1C, 8);
  addKey("9", Nine_Key, 0x80, 8);
  addKey("10-60", DoubleDigit_Key, 0x88, 8);
  addKey("MONITOR", Unmapped_Key, 0xC0, 8);
  addKey("CANCEL", Unmapped_Key, 0x60, 8);
  addKey("SP/LP", VHSSpeed_Key, 0x7C, 8);
  addKey("DAILY/WEEKLY", Unmapped_Key, 0xF2, 8);
  addKey("COUNT_RES", Unmapped_Key, 0xDC, 8);
  addKey("display", Info_Key, 0xE4, 8); // "DATA_SCRN"
  addKey("x2", Unmapped_Key, 0x5C, 8);
  addKey("audio/video", Unmapped_Key, 0x02, 8);
  addKey("adjust+", Right_Key, 0x82, 8);
  addKey("cancel", Exit_Key, 0xD0, 8);
  addKey("enter", Select_Key, 0xAC, 8);
  addKey("adjust-", Left_Key, 0x92, 8);
  addKey("vcr/tv", Input_Key, 0xA0, 8);
//  addKey("ENCORE", Unmapped_Key, 0xA0, 8);
}


MitsubishiVCR1a::MitsubishiVCR1a(
  QObject *guiObject,
  unsigned int index)
  : MitsubishiVCR1(guiObject, index)
{
  setKeysetName("VCR Keyset 1a");

  addKey("->", Unmapped_Key, 0xAC, 8); // Shuttle right
  addKey("<-", Unmapped_Key, 0xD0, 8);  // Shuttle left
  addKey("UP", Up_Key, 0x2C, 8);
  addKey("JOG+", Unmapped_Key, 0x50, 8);
  addKey("JOG-", Unmapped_Key, 0x48, 8);
}
