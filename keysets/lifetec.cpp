#include "lifetec.h"
#include "protocols/sircprotocol.h"
#include "protocols/necprotocol.h"
#include "protocols/necxprotocol.h"
#include "protocols/rc5protocol.h"


LifetecTV1::LifetecTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Lifetec_Make,
      index)
{
}


void LifetecTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new SIRCProtocol(guiObject, index);

  addSIRC12Key("1", One_Key, 0x01, 0x00);
  addSIRC12Key("2", Two_Key, 0x01, 0x01);
  addSIRC12Key("3", Three_Key, 0x01, 0x02);
  addSIRC12Key("4", Four_Key, 0x01, 0x03);
  addSIRC12Key("5", Five_Key, 0x01, 0x04);
  addSIRC12Key("6", Six_Key, 0x01, 0x05);
  addSIRC12Key("7", Seven_Key, 0x01, 0x06);
  addSIRC12Key("8", Eight_Key, 0x01, 0x07);
  addSIRC12Key("9", Nine_Key, 0x01, 0x08);
  addSIRC12Key("0", Zero_Key, 0x01, 0x09);
  addSIRC12Key("power", Power_Key, 0x01, 0x15);
  addSIRC12Key("prog+", ChannelUp_Key, 0x01, 0x10);
  addSIRC12Key("prog-", ChannelDown_Key, 0x01, 0x11);
  addSIRC12Key("vol-", VolumeDown_Key, 0x01, 0x13);
  addSIRC12Key("vol+", VolumeUp_Key, 0x01, 0x12);
  addSIRC12Key("tonaus", Mute_Key, 0x01, 0x14);
  addSIRC12Key("menu", Menu_Key, 0x01, 0x60);
  addSIRC12Key("exit", Exit_Key, 0x01, 0x34);
  addSIRC12Key("links", Left_Key, 0x01, 0x62);
  addSIRC12Key("rechts", Right_Key, 0x01, 0x61);
  addSIRC12Key("hoch", Up_Key, 0x01, 0x74);
  addSIRC12Key("runter", Down_Key, 0x01, 0x75);
  addSIRC12Key("ok", Select_Key, 0x01, 0x65);
  addSIRC12Key("text", Unmapped_Key, 0x01, 0x3F);
  addSIRC12Key("textaus", Unmapped_Key, 0x01, 0x38);
  addSIRC12Key("texttransparent", Unmapped_Key, 0x01, 0x5B);
  addSIRC12Key("text+", Unmapped_Key, 0x01, 0x3A);
  addSIRC12Key("textseitenscrolling", Unmapped_Key, 0x03, 0x4A);
  addSIRC12Key("rew", Rewind_Key, 0x03, 0x4C);
  addSIRC12Key("play", Play_Key, 0x03, 0x4E);
  addSIRC12Key("f.f.", FastForward_Key, 0x03, 0x4F);
  addSIRC12Key("rec", Record_Key, 0x01, 0x5B);
  addSIRC12Key("stop", Stop_Key, 0x03, 0x4D);
  addSIRC12Key("pause", Pause_Key, 0x03, 0x48);
}


LifetecTV2::LifetecTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Lifetec_Make,
      index)
{
}


void LifetecTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

  addKey("POWER", Power_Key, 0x100C, 13);
  addKey("1", One_Key, 0x1001, 13);
  addKey("2", Two_Key, 0x1002, 13);
  addKey("3", Three_Key, 0x1003, 13);
  addKey("4", Four_Key, 0x1004, 13);
  addKey("5", Five_Key, 0x1005, 13);
  addKey("6", Six_Key, 0x1006, 13);
  addKey("7", Seven_Key, 0x1007, 13);
  addKey("8", Eight_Key, 0x1008, 13);
  addKey("9", Nine_Key, 0x1009, 13);
  addKey("0", Zero_Key, 0x1000, 13);
  addKey("MUTE", Mute_Key, 0x100D, 13);
  addKey("INFO", Info_Key, 0x100F, 13);
  addKey("UP", Up_Key, 0x1020, 13);
  addKey("DOWN", Down_Key, 0x1021, 13);
  addKey("LEFT", Left_Key, 0x1011, 13);
  addKey("RIGHT", Right_Key, 0x1010, 13);
  addKey("TV", Unmapped_Key, 0x103C, 13);
  addKey("OK", Select_Key, 0x1029, 13);
  addKey("RED", Red_Key, 0x1037, 13);
  addKey("GREEN", Green_Key, 0x1036, 13);
  addKey("YELLOW", Yellow_Key, 0x1032, 13);
  addKey("BLUE", Blue_Key, 0x1034, 13);
  addKey("F1", Unmapped_Key, 0x001C, 13);
  addKey("F2", Unmapped_Key, 0x001D, 13);
  addKey("F3", Unmapped_Key, 0x001E, 13);
  addKey("F4", Unmapped_Key, 0x001F, 13);
  addKey("REWIND", Rewind_Key, 0x1165, 13);
  addKey("STOP", Stop_Key, 0x1176, 13);
  addKey("PLAY", Play_Key, 0x1175, 13);
  addKey("FORWARD", FastForward_Key, 0x1166, 13);
}


LifetecVCR1::LifetecVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Lifetec_Make,
      index)
{
}


void LifetecVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, false);

  setPreData(0x7B80, 16);

  addKey("power", Power_Key, 0x13, 8);
  addKey("1", One_Key, 0x01, 8);
  addKey("2", Two_Key, 0x02, 8);
  addKey("3", Three_Key, 0x03, 8);
  addKey("4", Four_Key, 0x04, 8);
  addKey("5", Five_Key, 0x05, 8);
  addKey("6", Six_Key, 0x06, 8);
  addKey("7", Seven_Key, 0x07, 8);
  addKey("8", Eight_Key, 0x08, 8);
  addKey("9", Nine_Key, 0x09, 8);
  addKey("0", Zero_Key, 0x00, 8);
  addKey("CH-", ChannelDown_Key, 0x0B, 8);
  addKey("CH+", ChannelUp_Key, 0x0A, 8);
  addKey("REC/OTR", Record_Key, 0x15, 8);
  addKey("PAUSE/STILL", Pause_Key, 0x1A, 8);
  addKey("<<", Rewind_Key, 0x19, 8);
  addKey("PLAY/SLOW", Play_Key, 0x16, 8);
  addKey("PLAY/SLOW", Slow_Key, 0x16, 8);
  addKey(">>", FastForward_Key, 0x18, 8);
  addKey("stop", Stop_Key, 0x17, 8);
  addKey("ENTER", Select_Key, 0x45, 8);
  addKey("INDEX", IndexSearch_Key, 0x14, 8);
  addKey("CANCEL", Clear_Key, 0x4A, 8);
  addKey("MENU", Menu_Key, 0x50, 8);
  addKey("TIMER_REC", RecordTimed_Key, 0x0D, 8);
  addKey("SHOWVIEW", Unmapped_Key, 0x1D, 8); // vhsplus+, etc.
  addKey("CALL", Call_Key, 0x5F, 8);
  addKey("CLOCK/COUNTER", Unmapped_Key, 0x51, 8);
  addKey("COUNTER_RESET", Reset_Key, 0x4C, 8);
  addKey("ZERO_RETURN", Unmapped_Key, 0x4B, 8);
  addKey("SPEED_SP/LP", VHSSpeed_Key, 0x1E, 8);
  addKey("TV/VCR", Input_Key, 0x12, 8);
  addKey("AUDIO_SELECT", Audio_Key, 0x0E, 8);
  addKey("EJECT", Eject_Key, 0x4E, 8);
}


LifetecAudio1::LifetecAudio1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Audio Keyset 1",
      Lifetec_Make,
      index)
{
}


void LifetecAudio1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new NECXProtocol(guiObject, index, false);

  setPreData(0xA4A4, 16);

  addKey("power", Power_Key, 0x16, 8);
  addKey("play", Play_Key, 0x13, 8);
  addKey("rew", Rewind_Key, 0x04, 8);
  addKey("ff", FastForward_Key, 0x0C, 8);
  addKey("stop", Stop_Key, 0x1B, 8);
  addKey("mute", Mute_Key, 0x17, 8);
  addKey("vol+", VolumeUp_Key, 0x20, 8);
  addKey("vol-", VolumeDown_Key, 0x60, 8);
}
