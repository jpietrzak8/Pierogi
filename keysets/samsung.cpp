#include "samsung.h"
#include "necprotocol.h"
#include "rc5protocol.h"

SamsungTV1::SamsungTV1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Samsung_Make,
      index)
{
  addControlledDevice(Samsung_Make, "SyncMaster 192MP", TV_Device);
  addControlledDevice(Samsung_Make, "LN32C530F1FXZA", TV_Device);

  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 500,
    600, 1600,
    107500, true);

  threadableProtocol = np;

  np->setHeaderPair(4500, 4500);
  np->setTrailerPulse(600);

  np->setPreData(0xE0E0, 16);

  addKey("Power", Power_Key, 0x40BF, 16);
  addKey("Channel Up", ChannelUp_Key, 0x48B7, 16);
  addKey("Channel Down", ChannelDown_Key, 0x08F7, 16);
  addKey("Volume Up", VolumeUp_Key, 0xE01F, 16);
  addKey("Volume Down", VolumeDown_Key, 0xD02F, 16);
  addKey("TV/Video", Input_Key, 0x807F, 16);
  addKey("1", One_Key, 0x20DF, 16);
  addKey("2", Two_Key, 0xA05F, 16);
  addKey("3", Three_Key, 0x609F, 16);
  addKey("4", Four_Key, 0x10EF, 16);
  addKey("5", Five_Key, 0x906F, 16);
  addKey("6", Six_Key, 0x50AF, 16);
  addKey("7", Seven_Key, 0x30CF, 16);
  addKey("8", Eight_Key, 0xB04F, 16);
  addKey("9", Nine_Key, 0x708F, 16);
  addKey("0", Zero_Key, 0x8877, 16);
  addKey("-/--", DoubleDigit_Key, 0xC43B, 16);
  addKey("+100", PlusOneHundred_Key, 0xC43B, 16);
  addKey("DASH", Dash_Key, 0xC43B, 16);
  addKey("Sleep", Sleep_Key, 0xC03F, 16);
  addKey("PrevCh", PrevChannel_Key, 0xC837, 16);
  addKey("Mute", Mute_Key, 0xF00F, 16);
  addKey("Display", Info_Key, 0xF807, 16);
  addKey("Menu", Menu_Key, 0x58A7, 16);
  addKey("Red", Red_Key, 0x36C9, 16);
  addKey("Green", Green_Key, 0x28D7, 16);
  addKey("Yellow", Yellow_Key, 0xA857, 16);
  addKey("Blue", Blue_Key, 0x6897, 16);
  addKey("Up", Up_Key, 0x06F9, 16);
  addKey("Down", Down_Key, 0x8679, 16);
  addKey("Left", Left_Key, 0xA659, 16);
  addKey("Right", Right_Key, 0x46B9, 16);
//  addKey("Enter", Enter_Key, 0x16E9, 16);
  addKey("Enter", Select_Key, 0x16E9, 16);
  addKey("Exit", Exit_Key, 0xB44B, 16);
  addKey("PIP", PIP_Key, 0x04FB, 16);
  addKey("Swap", PIPSwap_Key, 0x847B, 16);
  addKey("Closed Captions", Captions_Key, 0xA45B, 16); // "SUBTITLE"
  addKey("Guide", Guide_Key, 0xF20D, 16);
  addKey("Play", Play_Key, 0xE21D, 16);
  addKey("PLAY-PAUSE", Pause_Key, 0xE21D, 16);
  addKey("Stop", Stop_Key, 0x629D, 16);
  addKey("Fast Forward", FastForward_Key, 0x12ED, 16);
  addKey("Rewind", Rewind_Key, 0xA25D, 16);
  addKey("Record", Record_Key, 0x926D, 16);
  addKey("PMode", PictureMode_Key, 0x14EB, 16); // "p.std"
  addKey("SMode", SoundMode_Key, 0xD42B, 16);
  addKey("PSize", AspectRatio_Key, 0x7C83, 16);
  addKey("ch.scan", Scan_Key, 0x8C73, 16);  // "h.scan"
  addKey("surf", Unmapped_Key, 0xBC43, 16); // "r.surf"
  addKey("turbo", Unmapped_Key, 0xA659, 16);
  addKey("ttx/mix", Unmapped_Key, 0x34CB, 16); // "teletext"
  addKey("tv", Unmapped_Key, 0xD827, 16);
  addKey("mts", Language_Key, 0x00FF, 16); // "dual"
  addKey("PIP.SOURCE", PIPSource_Key, 0x24DB, 16);
  addKey("ch-mgr", Unmapped_Key, 0xD629, 16); // "CH_LIST"
  addKey("srs", Surround_Key, 0x7689, 16);
  addKey("size", Unmapped_Key, 0xF40B, 16); // PIP size?
  addKey("PIP.chan+", Unmapped_Key, 0x4CB3, 16); // "AUDCH_UP"
  addKey("position", PIPMove_Key, 0x44BB, 16);
  addKey("PIP.chan-", Unmapped_Key, 0xCC33, 16); // "AUDCH_DOWN"
  addKey("pc", Unmapped_Key, 0x9669, 16);
  addKey("TV-DTV", Unmapped_Key, 0xC23D, 16);
  addKey("D.MENU", DiscMenu_Key, 0x718E, 16);
  addKey("STILL", Unmapped_Key, 0x42BD, 16);
  addKey("WISELINK", Unmapped_Key, 0x31CE, 16); // "W.Link", "Media.P"
  addKey("ANTENNA", Unmapped_Key, 0x6C93, 16);
  addKey("ANYNET", Unmapped_Key, 0xE916, 16);
  addKey("FAV-CH", Favorites_Key, 0x22DD, 16);
  addKey("RETURN", Unmapped_Key, 0x1AE5, 16);
  addKey("E.SAVING", Unmapped_Key, 0xEE11, 16);
  addKey("Tools", Unmapped_Key, 0xD22D, 16);
  addKey("E.Mode", Unmapped_Key, 0x29D6, 16);
  addKey("HDMI", Unmapped_Key, 0xD12E, 16);
  addKey("Content", Unmapped_Key, 0x9E61, 16);
  addKey("Internet", Unmapped_Key, 0xC936, 16);
  addKey("AD", Unmapped_Key, 0xE41B, 16);
}


SamsungTV1a::SamsungTV1a(
  QObject *guiObject,
  unsigned int index)
  : SamsungTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1a");

  addKey("turbo", Unmapped_Key, 0xC837, 16);
  addKey("s.menu", SoundMode_Key, 0x28D7, 16);
  addKey("s.std", Unmapped_Key, 0xA857, 16);
  addKey("p.std", Unmapped_Key, 0x6897, 16);
}


SamsungTV1b::SamsungTV1b(
  QObject *guiObject,
  unsigned int index)
  : SamsungTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1b");

  addKey("Red", Red_Key, 0x847B, 16);
  addKey("Exit", Exit_Key, 0x34CB, 16);
}


SamsungTV1c::SamsungTV1c(
  QObject *guiObject,
  unsigned int index)
  : SamsungTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1c");

  // Some remotes apparently use channel and volume keys for navigation:
  addKey("up", Up_Key, 0x48B7, 16);
  addKey("down", Down_Key, 0x08F7, 16);
  addKey("left", Left_Key, 0xD02F, 16);
  addKey("right", Right_Key, 0xE01F, 16);
  addKey("center", Unmapped_Key, 0x58A7, 16);
}


SamsungTV1d::SamsungTV1d(
  QObject *guiObject,
  unsigned int index)
  : SamsungTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1d");

  addKey("turbo", Unmapped_Key, 0x26D9, 16);
}


SamsungTV1e::SamsungTV1e(
  QObject *guiObject,
  unsigned int index)
  : SamsungTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1e");

  addKey("p.mode", PictureMode_Key, 0x6897, 16);
}


// This one overrides the color keys:
SamsungTV1f::SamsungTV1f(
  QObject *guiObject,
  unsigned int index)
  : SamsungTV1(guiObject, index)
{
  setKeysetName("TV Keyset 1f");

  addKey("p-mode", PictureMode_Key, 0x36C9, 16);
  addKey("s-mode", SoundMode_Key, 0x28D7, 16);
  addKey("still", Unmapped_Key, 0xA857, 16);
  addKey("p-size", AspectRatio_Key, 0x6897, 16);
}


// Not sure that this even is a Samsung TV...
SamsungTV2::SamsungTV2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2 (dubious)",
      Samsung_Make,
      index)
{
  RC5Protocol *rp = new RC5Protocol(
    guiObject,
    index,
    900, 850,
    900,
    110000, true);

  threadableProtocol = rp;

  rp->setToggleBit(2);

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
  addKey("TV", Unmapped_Key, 0x103F, 13);
  addKey("Power", Power_Key, 0x100C, 13);
  addKey("Video", Unmapped_Key, 0x1038, 13);
  addKey("Display", Info_Key, 0x100F, 13); // [+]
  addKey("Sleep", Sleep_Key, 0x1026, 13);
  addKey("-/--", DoubleDigit_Key, 0x100A, 13);
  addKey("P.STD", PictureMode_Key, 0x100E, 13); // "Colour"
  addKey("Mute", Mute_Key, 0x100D, 13);
  addKey("P.Size", AspectRatio_Key, 0x1016, 13);
  addKey("Vol-", VolumeDown_Key, 0x0015, 13);
  addKey("Vol+", VolumeUp_Key, 0x0016, 13);
  addKey("CH/P_UP", ChannelUp_Key, 0x0010, 13);
  addKey("CH/P_DOWN", ChannelDown_Key, 0x0011, 13);
  addKey("Menu", Menu_Key, 0x0012, 13);
  addKey("TTX/MIX", Unmapped_Key, 0x103C, 13);
  addKey("Red", Red_Key, 0x002B, 13);
  addKey("Green", Green_Key, 0x002C, 13);
  addKey("Yellow", Yellow_Key, 0x002D, 13);
  addKey("Blue", Blue_Key, 0x002E, 13);
  addKey(">>", FastForward_Key, 0x101E, 13);
  addKey("colour+", Unmapped_Key, 0x1014, 13);
  addKey("colour-", Unmapped_Key, 0x1015, 13);
  addKey("brightness+", Unmapped_Key, 0x1012, 13);
  addKey("brightness-", Unmapped_Key, 0x1013, 13);
  addKey("contrast+", Unmapped_Key, 0x101C, 13);
  addKey("contrast-", Unmapped_Key, 0x101D, 13);
}


SamsungTV2a::SamsungTV2a(
  QObject *guiObject,
  unsigned int index)
  : SamsungTV2(guiObject, index)
{
  setKeysetName("TV Keyset 2a");

  addKey("volume+", VolumeUp_Key, 0x1010, 13);
  addKey("volume-", VolumeDown_Key, 0x1011, 13);
  addKey("prog+", ChannelUp_Key, 0x1020, 13);
  addKey("prog-", ChannelDown_Key, 0x1021, 13);
}


SamsungVCR1::SamsungVCR1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR(DVD) Keyset 1",
      Samsung_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 500,
    600, 1650,
    113837, true);

  threadableProtocol = np;

  np->setHeaderPair(4500, 4500);
  np->setTrailerPulse(600);

  np->setPreData(0xA0A0, 16);

  addKey("Power", Power_Key, 0x40BF, 16);
  addKey("Eject", Eject_Key, 0x04FB, 16);
  addKey("TV/Video", Input_Key, 0x807F, 16); // TV/Video
  addKey("One", One_Key, 0x20DF, 16);
  addKey("Two", Two_Key, 0xA05F, 16);
  addKey("Three", Three_Key, 0x609F, 16);
  addKey("Four", Four_Key, 0x10EF, 16);
  addKey("Five", Five_Key, 0x906F, 16);
  addKey("Six", Six_Key, 0x50AF, 16);
  addKey("Seven", Seven_Key, 0x30CF, 16);
  addKey("Eight", Eight_Key, 0xB04F, 16);
  addKey("Nine", Nine_Key, 0x708F, 16);
  addKey("Zero", Zero_Key, 0x8877, 16);
  addKey("Clear", Clear_Key, 0xB847, 16); // "CNT.RESET"
  addKey("Rewind", Rewind_Key, 0x18E7, 16);
  addKey("Stop", Stop_Key, 0xA857, 16);
  addKey("Play", Play_Key, 0x9867, 16);
  addKey("play/pause", Pause_Key, 0x9867, 16);
  addKey("FastForward", FastForward_Key, 0x58A7, 16);
  addKey("Menu", Menu_Key, 0xF807, 16);
  addKey("Captions", Captions_Key, 0x44BB, 16);
  addKey("Info", Info_Key, 0x7887, 16); // "display"
  addKey("Exit", Exit_Key, 0xB847, 16);
  addKey("Up", Up_Key, 0xF40B, 16);
  addKey("Down", Down_Key, 0x946B, 16);
  addKey("Left", Left_Key, 0xBE41, 16);
  addKey("Right", Right_Key, 0x7E81, 16);
//  addKey("Enter", Enter_Key, 0x3AC5, 16);
  addKey("Enter", Select_Key, 0x3AC5, 16); // "ok"
  addKey("Record", Record_Key, 0x28D7, 16);
  addKey("ChannelUp", ChannelUp_Key, 0x48B7, 16);
  addKey("ChannelDown", ChannelDown_Key, 0x08F7, 16);
  addKey("mark/search", Unmapped_Key, 0xD42B, 16); // "index"
  addKey("auto_track", AutoTracking_Key, 0x847B, 16);
  addKey("ipc", Unmapped_Key, 0xAE51, 16);
  addKey("input", Unmapped_Key, 0x24DB, 16);
  addKey("trk_up", TrackingPlus_Key, 0x34CB, 16); // "FINE_UP"
  addKey("trk_down", TrackingMinus_Key, 0xB44B, 16); // "FINE_DOWN"
  addKey("progressive/speed", VHSSpeed_Key, 0x5CA3, 16); // "SP-LP"
  addKey("dub", Unmapped_Key, 0x748B, 16);
  addKey("timer", Sleep_Key, 0x0CF3, 16); // "MONITOR"
  addKey("100+", PlusOneHundred_Key, 0x649B, 16);
  addKey("shift", Unmapped_Key, 0xA45B, 16);
  addKey("Dma", Unmapped_Key, 0xC639, 16);
  addKey("A.REP", Unmapped_Key, 0xC03F, 16);
  addKey("SYSTEM", Unmapped_Key, 0x4CB3, 16);
  addKey("VPS", Unmapped_Key, 0x0E71, 16);
  addKey("BAND", Unmapped_Key, 0x621D, 16);
  addKey("Q_PRO", Unmapped_Key, 0x5E21, 16);
  addKey("SHOWVIEW", Unmapped_Key, 0x0679, 16);
  addKey("SLOW_DOWN", Unmapped_Key, 0x740B, 16);
  addKey("SLOW_UP", Unmapped_Key, 0x641B, 16);
  addKey("PRESET", Unmapped_Key, 0x5629, 16);
}


SamsungVCR1a::SamsungVCR1a(
  QObject *guiObject,
  unsigned int index)
  : SamsungVCR1(guiObject, index)
{
  setKeysetName("VCR(DVD) Keyset 1a");

  addKey("power", Power_Key, 0x12ED, 16);
  addKey("clear", Clear_Key, 0x8C73, 16);
  addKey("audio", Language_Key, 0xBC43, 16);
  addKey("dvd", Unmapped_Key, 0xAA55, 16);
  addKey("vcr", Unmapped_Key, 0x14EB, 16);
  addKey("input_sel", Unmapped_Key, 0x9A65, 16);
  addKey("menu", Menu_Key, 0x16E9, 16);
  addKey("up", Up_Key, 0x34CB, 16);
  addKey("down", Down_Key, 0xB44B, 16);
  addKey("left", Left_Key, 0xE817, 16);
  addKey("right", Right_Key, 0xC837, 16);
  addKey("enter", Select_Key, 0xC23D, 16); // "ok"
  addKey("disc_menu", DiscMenu_Key, 0x06F9, 16);
  addKey("mode/repeat", Unmapped_Key, 0x6699, 16);
  addKey("angle/timer", Unmapped_Key, 0xA25D, 16);
}


SamsungVCR1b::SamsungVCR1b(
  QObject *guiObject,
  unsigned int index)
  : SamsungVCR1(guiObject, index)
{
  setKeysetName("VCR(DVD) Keyset 1b");

  addKey("audio", Language_Key, 0x44BB, 16); // "output"
  addKey("Input", Input_Key, 0x24DB, 16);
  addKey("+", Unmapped_Key, 0x649B, 16);
  addKey("-", Unmapped_Key, 0x14EB, 16);
  addKey("slowup", Unmapped_Key, 0xC837, 16);
  addKey("slowdown", Unmapped_Key, 0xE817, 16);
  addKey("reset", Clear_Key, 0xB847, 16); // "CLR/RST"
  addKey("pause", Pause_Key, 0x6897, 16); // "P/S"
  addKey("shuttle<", Unmapped_Key, 0xBE41, 16);
  addKey("shuttle>", Unmapped_Key, 0x7E81, 16);
  addKey("showview", Unmapped_Key, 0x0CF3, 16);
  addKey("index", Unmapped_Key, 0xD42B, 16);
  addKey("mark", Unmapped_Key, 0xF40B, 16);
  addKey("erase", Unmapped_Key, 0x946B, 16);
  addKey("prog", Program_Key, 0xF807, 16);
  addKey("clk/cnt", Unmapped_Key, 0xCC33, 16);
  addKey("aft", Unmapped_Key, 0x2ED1, 16);
  addKey("SYSTEM", Menu_Key, 0x9669, 16);
  addKey("A.TRK", AutoTracking_Key, 0x847B, 16);
  addKey("Q-PRO", Unmapped_Key, 0xBC43, 16);
  addKey("PICTURE", PictureMode_Key, 0xAE51, 16);
  addKey("OK_UP", Up_Key, 0x4AB5, 16);
  addKey("OK_DOWN", Down_Key, 0x0AF5, 16);
  addKey("OK_LEFT", Left_Key, 0xCE31, 16);
  addKey("OK_RIGHT", Right_Key, 0xEE11, 16);
  addKey("Band", Unmapped_Key, 0xC43B, 16);
  addKey("Preset", Unmapped_Key, 0xAC53, 16);
  addKey("Search", Unmapped_Key, 0x8C73, 16);
  addKey("Memory", Unmapped_Key, 0x38C7, 16);
}


SamsungVCR1c::SamsungVCR1c(
  QObject *guiObject,
  unsigned int index)
  : SamsungVCR1a(guiObject, index)
{
  setKeysetName("VCR(DVD) Keyset 1c");

  addKey("eject", Eject_Key, 0x4CB3, 16);
  addKey("vol_up", VolumeUp_Key, 0xC639, 16);
  addKey("vol_down", VolumeDown_Key, 0x02FD, 16);
  addKey("prev_ch", PrevChannel_Key, 0x2AD5, 16);
  addKey("up", Up_Key, 0x7887, 16);
  addKey("down", Down_Key, 0x8C73, 16);
  addKey("left", Left_Key, 0x6699, 16);
  addKey("right", Right_Key, 0x00FF, 16);
  addKey("speed", VHSSpeed_Key, 0x06F9, 16);
  addKey("timer", Sleep_Key, 0x44BB, 16);
  addKey("return", Exit_Key, 0xBC43, 16);
}


// Combo VCR/TV:
SamsungVCR1d::SamsungVCR1d(
  QObject *guiObject,
  unsigned int index)
  : SamsungVCR1(guiObject, index)
{
  setKeysetName("VCR/TV Combo Keyset 1d");

  addKey("eject", Eject_Key, 0x4CB3, 16);
  addKey("P-STD", PictureMode_Key, 0xF609, 16);
  addKey("MUTE", Mute_Key, 0xF00F, 16);
  addKey("VOL+", VolumeUp_Key, 0xE01F, 16);
  addKey("VOL-", VolumeDown_Key, 0xD02F, 16);
  addKey("PRE-CH", PrevChannel_Key, 0x54AB, 16);
  addKey("P./STILL", Pause_Key, 0x6897, 16);
  addKey("REPEAT", Unmapped_Key, 0xEC13, 16);
  addKey("TRK+", TrackingPlus_Key, 0xB44B, 16);
  addKey("TRK-", TrackingMinus_Key, 0x34CB, 16);
}


SamsungVCR1e::SamsungVCR1e(
  QObject *guiObject,
  unsigned int index)
  : SamsungVCR1(guiObject, index)
{
  setKeysetName("VCR(DVD) Keyset 1e");

  addKey("OPEN/CLOSE", Eject_Key, 0x4CB3, 16);
  addKey("AUDIO", Unmapped_Key, 0x16E9, 16);
  addKey("MODE/REPEAT", Unmapped_Key, 0x6699, 16);
  addKey("ZOOM", Unmapped_Key, 0x5CA3, 16);
  addKey("CLOCK/COUNTER", Unmapped_Key, 0x8C73, 16);
  addKey("ANGLE", Unmapped_Key, 0x2AD5, 16);
  addKey("3D_SOUND", Surround_Key, 0x649B, 16);
  addKey("DVD", Unmapped_Key, 0xAA55, 16);
  addKey("VCR", Unmapped_Key, 0x14EB, 16);
  addKey("INPUT_SEL", Unmapped_Key, 0x9A65, 16);
  addKey("DIGEST", Unmapped_Key, 0x00FF, 16);
  addKey("TRK_UP", TrackingPlus_Key, 0xC639, 16);
  addKey("TRK_DOWN", TrackingMinus_Key, 0x02FD, 16);
  addKey("DISC_MENU", DiscMenu_Key, 0xF807, 16);
  addKey("UP", Up_Key, 0x34CB, 16);
  addKey("DOWN", Down_Key, 0xB44B, 16);
  addKey("RIGHT", Right_Key, 0xC837, 16);
  addKey("LEFT", Left_Key, 0xE817, 16);
  addKey("SETUP/ENTER", Menu_Key, 0xC23D, 16);
  addKey("SETUP/ENTER", Select_Key, 0xC23D, 16);
  addKey("RETURN", Exit_Key, 0xBC43, 16);
  addKey("TITLE", DiscTitle_Key, 0x06F9, 16);
}


SamsungDVD1::SamsungDVD1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Samsung_Make,
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
  np->setRepeatPair(9000, 4500);

  np->setPreData(0x198133F, 26);

  addKey("power", Power_Key, 0x8976, 16);
  addKey("open_close", Eject_Key, 0x31CE, 16);
  addKey("1", One_Key, 0x817E, 16);
  addKey("2", Two_Key, 0x41BE, 16);
  addKey("3", Three_Key, 0xC13E, 16);
  addKey("4", Four_Key, 0x21DE, 16);
  addKey("5", Five_Key, 0xA15E, 16);
  addKey("6", Six_Key, 0x619E, 16);
  addKey("7", Seven_Key, 0xE11E, 16);
  addKey("8", Eight_Key, 0x11EE, 16);
  addKey("9", Nine_Key, 0x916E, 16);
  addKey("0", Zero_Key, 0x01FE, 16);
  addKey("prog", Program_Key, 0xE51A, 16); // "Mode"
  addKey("clear", Clear_Key, 0x25DA, 16); // "cancel"
  addKey("step", StepForward_Key, 0x659A, 16);
  addKey("replay", Replay_Key, 0x55AA, 16);
  addKey("skip", Advance_Key, 0x758A, 16); // "digest"
  addKey("|<<", Previous_Key, 0xF906, 16); // "skip-"
  addKey(">>|", Next_Key, 0x857A, 16);
  addKey("<<", Rewind_Key, 0x39C6, 16);
  addKey(">>", FastForward_Key, 0x7986, 16);
  addKey("stop", Stop_Key, 0x45BA, 16);
  addKey("play", Play_Key, 0x05FA, 16);
  addKey("play/pause", Pause_Key, 0x05FA, 16);
  addKey("return", Exit_Key, 0xA956, 16);
  addKey("menu", Menu_Key, 0xD12E, 16); // "setup"
  addKey("info", Info_Key, 0xF10E, 16); // "display"
  addKey("disc_menu", DiscMenu_Key, 0x29D6, 16);
  addKey("left", Left_Key, 0x59A6, 16);
  addKey("up", Up_Key, 0xE916, 16);
  addKey("down", Down_Key, 0x19E6, 16);
  addKey("right", Right_Key, 0x9966, 16);
  addKey("enter", Select_Key, 0xD926, 16);
  addKey("ez_view", Unmapped_Key, 0xF50A, 16); // s.fit
  addKey("subtitle", Captions_Key, 0x09F6, 16);
  addKey("audio", Language_Key, 0x718E, 16);
  addKey("angle", Unmapped_Key, 0x49B6, 16);
  addKey("repeat", Unmapped_Key, 0xB946, 16);
  addKey("repeat_A-B", Unmapped_Key, 0x15EA, 16);
  addKey("step_r", StepForward_Key, 0xEB14, 16);
  addKey("step_l", StepBack_Key, 0x1BE4, 16);
  addKey("jog_r", Unmapped_Key, 0x936C, 16);
  addKey("jog_l", Unmapped_Key, 0x53AC, 16);
  addKey("sacd/cd", Unmapped_Key, 0x6E91, 16);
  addKey("bookmark", Unmapped_Key, 0x956A, 16);
  addKey("index_pre", Unmapped_Key, 0x837C, 16);
  addKey("index_next", Unmapped_Key, 0x639C, 16);
  addKey("page_pre", Unmapped_Key, 0x23DC, 16);
  addKey("page_next", Unmapped_Key, 0x639C, 16);
  addKey("zoom", Unmapped_Key, 0x35CA, 16);
  addKey("hdmi_sel", Unmapped_Key, 0xE41B, 16);
  addKey("video_sel", Unmapped_Key, 0x44BB, 16);
  addKey("3D_Sound", Unmapped_Key, 0xD52A, 16);
  addKey("TopMenu", DiscTitle_Key, 0xC936, 16);
}


SamsungDVD1a::SamsungDVD1a(
  QObject *guiObject,
  unsigned int index)
  : SamsungDVD1(guiObject, index)
{
  setKeysetName("DVD Keyset 1a");

  addKey("hdmi_sel", Unmapped_Key, 0x15EA, 16);
}


SamsungDVD1b::SamsungDVD1b(
  QObject *guiObject,
  unsigned int index)
  : SamsungDVD1(guiObject, index)
{
  setKeysetName("DVD Keyset 1b");

  addKey("Zoom", Unmapped_Key, 0x55AA, 16);
  addKey("i.replay", Replay_Key, 0xB54A, 16);
  addKey("Volume_Con", Unmapped_Key, 0x35CA, 16);
}


SamsungDVD2::SamsungDVD2(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 2",
      Samsung_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 500,
    600, 1600,
    108000, true);

  threadableProtocol = np;

  np->setHeaderPair(4500, 4500);
  np->setTrailerPulse(600);

  np->setPreData(0xC2CA, 16);

  addKey("1", One_Key, 0x827D, 16);
  addKey("2", Two_Key, 0x42BD, 16);
  addKey("3", Three_Key, 0xC23D, 16);
  addKey("4", Four_Key, 0x22DD, 16);
  addKey("5", Five_Key, 0xA25D, 16);
  addKey("6", Six_Key, 0x629D, 16);
  addKey("7", Seven_Key, 0xE21D, 16);
  addKey("8", Eight_Key, 0xFC03, 16);
  addKey("9", Nine_Key, 0xEC13, 16);
  addKey("0", Zero_Key, 0xF40B, 16);
  addKey("remain", Unmapped_Key, 0x00FF, 16);
  addKey("cancel", Unmapped_Key, 0xE817, 16);
  addKey("prev", Previous_Key, 0xD827, 16);
  addKey("stop", Stop_Key, 0xD02F, 16);
  addKey("play", Play_Key, 0xC03F, 16);
  addKey("next", Next_Key, 0xC837, 16);
  addKey("VOL+", VolumeUp_Key, 0xCC33, 16);
  addKey("VOL-", VolumeDown_Key, 0xDC23, 16);
  addKey("ch+", ChannelUp_Key, 0xC43B, 16);
  addKey("ch-", ChannelDown_Key, 0xD42B, 16);
  addKey("super5.1", Surround_Key, 0xE619, 16);
  addKey("UP", Up_Key, 0xB04F, 16);
  addKey("DOWN", Down_Key, 0xA857, 16);
  addKey("LEFT", Left_Key, 0xA45B, 16);
  addKey("RIGHT", Right_Key, 0xB847, 16);
  addKey("ENTER", Select_Key, 0xA05F, 16);
  addKey("SLEEP", Sleep_Key, 0x847B, 16);
//  addKey("MODE", Program_Key, 0x18E7, 16); // Might be wrong
  addKey("TV-VIDEO", Input_Key, 0x18E7, 16);
  addKey("DVD", Unmapped_Key, 0x9867, 16);
  addKey("TUNER", Unmapped_Key, 0x906F, 16);
  addKey("AUX", Unmapped_Key, 0x8877, 16);
  addKey("MUTE", Mute_Key, 0x9C63, 16);
  addKey("SUBTITLE", Captions_Key, 0x708F, 16);
  addKey("MENU", Menu_Key, 0x6C93, 16);
  addKey("INFO", Info_Key, 0x649B, 16);
  addKey("AUDIO", Language_Key, 0x609F, 16);
  addKey("RETURN", Exit_Key, 0x38C7, 16);
  addKey("ZOOM", Unmapped_Key, 0xF00F, 16);
  addKey("MUSIC", Unmapped_Key, 0x24DB, 16);
  addKey("MOVIE", Unmapped_Key, 0x16E9, 16);
  addKey("ASC", Unmapped_Key, 0x9669, 16);
  addKey("TEST-TONE", Unmapped_Key, 0x2CD3, 16);
  addKey("EZ-VIEW", Unmapped_Key, 0xE01F, 16);
  addKey("PLII-MODE", Unmapped_Key, 0x20DF, 16);
  addKey("PLII-EFFECT", Unmapped_Key, 0x30CF, 16);
  addKey("SOUND-EDIT", SoundMode_Key, 0x28D7, 16);
  addKey("STEP", Unmapped_Key, 0xBC43, 16);
  addKey("REPEAT", Unmapped_Key, 0x6699, 16);
  addKey("SLOW", Unmapped_Key, 0xAC53, 16);
  addKey("LOGO", Unmapped_Key, 0x1CE3, 16);
  addKey("HDMI-AUDIO", Unmapped_Key, 0x0EF1, 16);
  addKey("SD-HD", AspectRatio_Key, 0x9A65, 16);
  addKey("TUNER-MEMORY", Unmapped_Key, 0xB44B, 16);
}


SamsungAC1::SamsungAC1(
  QObject *guiObject,
  unsigned int index)
  : PIRKeysetMetaData(
      "Air Conditioner Keyset 1",
      Samsung_Make,
      index)
{
  NECProtocol *np = new NECProtocol(
    guiObject,
    index,
    600, 500,
    600, 1600,
    60000, true);

  threadableProtocol = np;

  np->setHeaderPair(4500, 4500);
  np->setTrailerPulse(600);

  np->setPreData(0x804, 12);

  np->setMinimumRepetitions(1);

  addKey("TIMER", Unmapped_Key, 0xA4, 8);
  addKey("SLEEP", Sleep_Key, 0xE4, 8);
  addKey("TEMP+", Unmapped_Key, 0x4C, 8);
  addKey("TEMP-", Unmapped_Key, 0x8C, 8);
  addKey("FAN", Unmapped_Key, 0x9C, 8);
  addKey("COOL", Unmapped_Key, 0x3C, 8);
  addKey("HEAT", Unmapped_Key, 0x5C, 8);
  addKey("FAN_HIGH", Unmapped_Key, 0xEC, 8);
  addKey("FAN_MED", Unmapped_Key, 0x6C, 8);
  addKey("FAN_LOW", Unmapped_Key, 0xAC, 8);
  addKey("SWING", Unmapped_Key, 0x94, 8);
  addKey("POWER", Power_Key, 0xFC, 8);
}
