#include "samsung.h"
#include "protocols/samsungprotocol.h"
#include "protocols/lircprotocol.h"
#include "protocols/rc5protocol.h"

SamsungTV1::SamsungTV1(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 1",
      Samsung_Make,
      index)
{
  addControlledDevice(Samsung_Make, "SyncMaster 192MP", TV_Device);
  addControlledDevice(Samsung_Make, "SyncMaster 225MW", TV_Device);
  addControlledDevice(Samsung_Make, "LN32C530F1FXZA", TV_Device);
  addControlledDevice(Samsung_Make, "UE46B6000VPXZG", TV_Device); // ?
  addControlledDevice(Samsung_Make, "LE22B470C9M", TV_Device);
}


void SamsungTV1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new SamsungProtocol(guiObject, index);

//  setPreData(0xE0E0, 16);
  setPreData(0x0707, 16);

  addKey("mts", Audio_Key, 0x00, 8); // "dual"
  addKey("TV/Video", Input_Key, 0x01, 8);
  addKey("Power", Power_Key, 0x02, 8);
  addKey("Sleep", Sleep_Key, 0x03, 8);
  addKey("1", One_Key, 0x04, 8);
  addKey("2", Two_Key, 0x05, 8);
  addKey("3", Three_Key, 0x06, 8);
  addKey("Volume Up", VolumeUp_Key, 0x07, 8);
  addKey("4", Four_Key, 0x08, 8);
  addKey("5", Five_Key, 0x09, 8);
  addKey("6", Six_Key, 0x0A, 8);
  addKey("Volume Down", VolumeDown_Key, 0x0B, 8);
  addKey("7", Seven_Key, 0x0C, 8);
  addKey("8", Eight_Key, 0x0D, 8);
  addKey("9", Nine_Key, 0x0E, 8);
  addKey("Mute", Mute_Key, 0x0F, 8);
  addKey("Channel Down", ChannelDown_Key, 0x10, 8);
  addKey("0", Zero_Key, 0x11, 8);
  addKey("Channel Up", ChannelUp_Key, 0x12, 8);
  addKey("PrevCh", PrevChannel_Key, 0x13, 8);
  addKey("Green", Green_Key, 0x14, 8);
  addKey("Yellow", Yellow_Key, 0x15, 8);
  addKey("Blue", Blue_Key, 0x16, 8);
  addKey("Menu", Menu_Key, 0x1A, 8);
  addKey("tv", Unmapped_Key, 0x1B, 8);
  addKey("Display", Info_Key, 0x1F, 8);
  addKey("PIP", PIP_Key, 0x20, 8);
  addKey("Swap", PIPSwap_Key, 0x21, 8);
  addKey("position", PIPMove_Key, 0x22, 8);
  addKey("-/--", DoubleDigit_Key, 0x23, 8);
  addKey("+100", PlusOneHundred_Key, 0x23, 8);
  addKey("DASH", Dash_Key, 0x23, 8);
  addKey("PIP.SOURCE", PIPSource_Key, 0x24, 8);
  addKey("Closed Captions", Captions_Key, 0x25, 8); // "SUBTITLE"
  addKey("AD", Unmapped_Key, 0x27, 8);
  addKey("PMode", PictureMode_Key, 0x28, 8); // "p.std"
  addKey("SMode", SoundMode_Key, 0x2B, 8);
  addKey("ttx/mix", Teletext_Key, 0x2C, 8); // "teletext"
  addKey("Exit", Exit_Key, 0x2D, 8);
  addKey("size", AspectRatio_Key, 0x2F, 8);
  addKey("ch.scan", PIPScan_Key, 0x31, 8);  // "h.scan"
  addKey("PIP.chan+", PIPChannelUp_Key, 0x32, 8); // "AUDCH_UP"
  addKey("PIP.chan-", PIPChannelDown_Key, 0x33, 8); // "AUDCH_DOWN"
  addKey("ANTENNA", AntennaInput_Key, 0x36, 8);
  addKey("surf", Unmapped_Key, 0x3D, 8); // "r.surf"
  addKey("PSize", PIPSize_Key, 0x3E, 8);
  addKey("STILL", PIPPause_Key, 0x42, 8);
  addKey("TV-DTV", Unmapped_Key, 0x43, 8);
  addKey("FAV-CH", Favorites_Key, 0x44, 8);
  addKey("Rewind", Rewind_Key, 0x45, 8);
  addKey("Stop", Stop_Key, 0x46, 8);
  addKey("Play/Pause", Play_Key, 0x47, 8);
  addKey("Play/Pause", Pause_Key, 0x47, 8);
  addKey("Fast Forward", FastForward_Key, 0x48, 8);
  addKey("Record", Record_Key, 0x49, 8);
  addKey("Tools", Unmapped_Key, 0x4B, 8);
  addKey("Guide", Guide_Key, 0x4F, 8);
  addKey("RETURN", Unmapped_Key, 0x58, 8);
  addKey("Up", Up_Key, 0x60, 8);
  addKey("Down", Down_Key, 0x61, 8);
  addKey("Right", Right_Key, 0x62, 8);
  addKey("Left", Left_Key, 0x65, 8);
  addKey("Enter", Select_Key, 0x68, 8);
  addKey("pc", PCInput_Key, 0x69, 8);
  addKey("ch-mgr", Unmapped_Key, 0x6B, 8); // "CH_LIST"
  addKey("Red", Red_Key, 0x6C, 8);
  addKey("srs", Surround_Key, 0x6E, 8);
  addKey("E.SAVING", Unmapped_Key, 0x77, 8);
  addKey("Content", Unmapped_Key, 0x79, 8);
  addKey("HDMI", HDMIInput_Key, 0x8B, 8);
  addKey("WISELINK", Unmapped_Key, 0x8C, 8); // "W.Link", "Media.P"
  addKey("D.MENU", DiscMenu_Key, 0x8E, 8);
  addKey("Internet", Unmapped_Key, 0x93, 8);
  addKey("E.Mode", Unmapped_Key, 0x94, 8);
  addKey("ANYNET", Unmapped_Key, 0x97, 8);

//  addKey("turbo", Unmapped_Key, 0xA659, 16);
}


SamsungTV1a::SamsungTV1a(
  unsigned int index)
  : SamsungTV1(index)
{
  setKeysetName("TV Keyset 1a");
}


void SamsungTV1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungTV1::populateProtocol(guiObject);

  addKey("turbo", Unmapped_Key, 0x13, 8);
  addKey("s.menu", SoundMode_Key, 0x14, 8);
  addKey("s.std", Unmapped_Key, 0x15, 8);
  addKey("p.std", Unmapped_Key, 0x16, 8);
}


SamsungTV1b::SamsungTV1b(
  unsigned int index)
  : SamsungTV1(index)
{
  setKeysetName("TV Keyset 1b");

  addControlledDevice(Samsung_Make, "LE46M51B (R)", TV_Device); // ?
}


void SamsungTV1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungTV1::populateProtocol(guiObject);

  addKey("Red", Red_Key, 0x21, 8);
  addKey("Exit", Exit_Key, 0x2C, 8);
}


SamsungTV1c::SamsungTV1c(
  unsigned int index)
  : SamsungTV1(index)
{
  setKeysetName("TV Keyset 1c");
}


void SamsungTV1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungTV1::populateProtocol(guiObject);

  // Some remotes apparently use channel and volume keys for navigation:
  addKey("right", Right_Key, 0x07, 8);
  addKey("left", Left_Key, 0x0B, 8);
  addKey("down", Down_Key, 0x10, 8);
  addKey("up", Up_Key, 0x12, 8);
  addKey("center", Unmapped_Key, 0x1A, 8);
}


SamsungTV1d::SamsungTV1d(
  unsigned int index)
  : SamsungTV1(index)
{
  setKeysetName("TV Keyset 1d");
}


void SamsungTV1d::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungTV1::populateProtocol(guiObject);

  addKey("turbo", Unmapped_Key, 0x64, 8);
}


SamsungTV1e::SamsungTV1e(
  unsigned int index)
  : SamsungTV1(index)
{
  setKeysetName("TV Keyset 1e");
}


void SamsungTV1e::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungTV1::populateProtocol(guiObject);

  addKey("p.mode", PictureMode_Key, 0x16, 8);
}


// This one overrides the color keys:
SamsungTV1f::SamsungTV1f(
  unsigned int index)
  : SamsungTV1(index)
{
  setKeysetName("TV Keyset 1f");
}


void SamsungTV1f::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungTV1::populateProtocol(guiObject);

  addKey("p-mode", PictureMode_Key, 0x6C, 8);
  addKey("s-mode", SoundMode_Key, 0x14, 8);
  addKey("still", PIPPause_Key, 0x15, 8);
  addKey("p-size", PIPSize_Key, 0x16, 8);
}


// Not sure that this even is a Samsung TV...
SamsungTV2::SamsungTV2(
  unsigned int index)
  : PIRKeysetMetaData(
      "TV Keyset 2",
      Samsung_Make,
      index)
{
}


void SamsungTV2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new RC5Protocol(guiObject, index);

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
  addKey("TTX/MIX", Teletext_Key, 0x103C, 13);
  addKey("Red", Red_Key, 0x002B, 13);
  addKey("Green", Green_Key, 0x002C, 13);
  addKey("Yellow", Yellow_Key, 0x002D, 13);
  addKey("Blue", Blue_Key, 0x002E, 13);
  addKey(">>", FastForward_Key, 0x101E, 13);
  addKey("colour+", ColorUp_Key, 0x1014, 13);
  addKey("colour-", ColorDown_Key, 0x1015, 13);
  addKey("brightness+", BrightnessUp_Key, 0x1012, 13);
  addKey("brightness-", BrightnessDown_Key, 0x1013, 13);
  addKey("contrast+", ContrastUp_Key, 0x101C, 13);
  addKey("contrast-", ContrastDown_Key, 0x101D, 13);
}


SamsungTV2a::SamsungTV2a(
  unsigned int index)
  : SamsungTV2(index)
{
  setKeysetName("TV Keyset 2a");
}


void SamsungTV2a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungTV2::populateProtocol(guiObject);

  addKey("volume+", VolumeUp_Key, 0x1010, 13);
  addKey("volume-", VolumeDown_Key, 0x1011, 13);
  addKey("prog+", ChannelUp_Key, 0x1020, 13);
  addKey("prog-", ChannelDown_Key, 0x1021, 13);
}


SamsungVCR1::SamsungVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR(DVD) Keyset 1",
      Samsung_Make,
      index)
{
}


void SamsungVCR1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new SamsungProtocol(guiObject, index);

//  setPreData(0xA0A0, 16);
  setPreData(0x0505, 16);

  addKey("TV/Video", Input_Key, 0x01, 8);
  addKey("Power", Power_Key, 0x02, 8);
  addKey("A.REP", Unmapped_Key, 0x03, 8);
  addKey("One", One_Key, 0x04, 8);
  addKey("Two", Two_Key, 0x05, 8);
  addKey("Three", Three_Key, 0x06, 8);
  addKey("Four", Four_Key, 0x08, 8);
  addKey("Five", Five_Key, 0x09, 8);
  addKey("Six", Six_Key, 0x0A, 8);
  addKey("Seven", Seven_Key, 0x0C, 8);
  addKey("Eight", Eight_Key, 0x0D, 8);
  addKey("Nine", Nine_Key, 0x0E, 8);

  addKey("ChannelDown", ChannelDown_Key, 0x10, 8);
  addKey("Zero", Zero_Key, 0x11, 8);
  addKey("ChannelUp", ChannelUp_Key, 0x12, 8);
  addKey("SLOW_UP", SlowPlus_Key, 0x13, 8);
  addKey("Record", Record_Key, 0x14, 8);
  addKey("Stop", Stop_Key, 0x15, 8);
  addKey("Rewind", Rewind_Key, 0x18, 8);
  addKey("SLOW_DOWN", SlowMinus_Key, 0x17, 8);
  addKey("Play/Pause", Play_Key, 0x19, 8);
  addKey("Play/Pause", Pause_Key, 0x19, 8);
  addKey("FastForward", FastForward_Key, 0x1A, 8);
  addKey("Memory", Memory_Key, 0x1C, 8);
  addKey("Clear", Reset_Key, 0x1D, 8); // "CNT.RESET", "CLR_RST", "reset"
//  addKey("Exit", Exit_Key, 0x1D, 8);
  addKey("Info", Info_Key, 0x1E, 8); // "display"
  addKey("Menu", Menu_Key, 0x1F, 8);

  addKey("Eject", Eject_Key, 0x20, 8);
  addKey("auto_track", AutoTracking_Key, 0x21, 8); // "A.TRK"
  addKey("Captions", Captions_Key, 0x22, 8);
  addKey("BAND", TunerInput_Key, 0x23, 8);
  addKey("input", Unmapped_Key, 0x24, 8);
  addKey("shift", Unmapped_Key, 0x25, 8);
  addKey("100+", PlusOneHundred_Key, 0x26, 8);
  addKey("Down", Down_Key, 0x29, 8); // "erase"
  addKey("mark/search", IndexSearch_Key, 0x2B, 8); // "index"
  addKey("trk_up", TrackingPlus_Key, 0x2C, 8); // "FINE_UP"
  addKey("trk_down", TrackingMinus_Key, 0x2D, 8); // "FINE_DOWN"
  addKey("dub", Unmapped_Key, 0x2E, 8);
  addKey("Up", Up_Key, 0x2F, 8); // "mark"

  addKey("timer", Unmapped_Key, 0x30, 8); // "MONITOR", "showview", "SHOWVIEW"
  addKey("SEARCH", Unmapped_Key, 0x31, 8);
  addKey("SYSTEM", Unmapped_Key, 0x32, 8);
  addKey("CLK_COUNT", Unmapped_Key, 0x33, 8); // "clk/cnt"
  addKey("PRESET", Unmapped_Key, 0x35, 8);
  addKey("VPS", RecordPDC_Key, 0x38, 8);
  addKey("progressive/speed", VHSSpeed_Key, 0x3A, 8); // "SP-LP"
  addKey("Q_PRO", Unmapped_Key, 0x3D, 8);

  addKey("Enter", Select_Key, 0x5C, 8); // "ok"
  addKey("Dma", Unmapped_Key, 0x63, 8);

  addKey("ipc", PictureMode_Key, 0x75, 8); // "PICTURE"
  addKey("Left", Left_Key, 0x7D, 8); // "shuttle<"
  addKey("Right", Right_Key, 0x7E, 8); // "shuttle>"
}


SamsungVCR1a::SamsungVCR1a(
  unsigned int index)
  : SamsungVCR1(index)
{
  setKeysetName("VCR(DVD) Keyset 1a");
}


void SamsungVCR1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungVCR1::populateProtocol(guiObject);

  addKey("right", Right_Key, 0x13, 8);
  addKey("left", Left_Key, 0x17, 8);
  addKey("vcr", Unmapped_Key, 0x28, 8);
  addKey("up", Up_Key, 0x2C, 8);
  addKey("down", Down_Key, 0x2D, 8);
  addKey("clear", Clear_Key, 0x31, 8);
  addKey("audio", Audio_Key, 0x3D, 8);
  addKey("enter", Select_Key, 0x43, 8); // "ok"
  addKey("angle/timer", Unmapped_Key, 0x45, 8);
  addKey("power", Power_Key, 0x48, 8);
  addKey("dvd", Unmapped_Key, 0x55, 8);
  addKey("input_sel", Input_Key, 0x59, 8);
  addKey("disc_menu", DiscMenu_Key, 0x60, 8);
  addKey("mode/repeat", Unmapped_Key, 0x66, 8);
  addKey("menu", Menu_Key, 0x68, 8);
}


SamsungVCR1b::SamsungVCR1b(
  unsigned int index)
  : SamsungVCR1(index)
{
  setKeysetName("VCR(DVD) Keyset 1b");
}


void SamsungVCR1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungVCR1::populateProtocol(guiObject);

  addKey("audio", Audio_Key, 0x22, 8); // "output"
  addKey("+", Unmapped_Key, 0x26, 8);
  addKey("-", Unmapped_Key, 0x28, 8);
  addKey("pause", Pause_Key, 0x16, 8); // "P/S"
  addKey("prog", Program_Key, 0x1F, 8);
  addKey("aft", Unmapped_Key, 0x74, 8);
  addKey("SYSTEM", Menu_Key, 0x69, 8);
  addKey("OK_UP", Up_Key, 0x52, 8);
  addKey("OK_DOWN", Down_Key, 0x50, 8);
  addKey("OK_LEFT", Left_Key, 0x73, 8);
  addKey("OK_RIGHT", Right_Key, 0x77, 8);
}


SamsungVCR1c::SamsungVCR1c(
  unsigned int index)
  : SamsungVCR1a(index)
{
  setKeysetName("VCR(DVD) Keyset 1c");

  addControlledDevice(Samsung_Make, "DVD-V1000", DVD_Device);
}


void SamsungVCR1c::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungVCR1a::populateProtocol(guiObject);

  addKey("right", Right_Key, 0x00, 8);
  addKey("up", Up_Key, 0x1E, 8);
  addKey("timer", Sleep_Key, 0x22, 8);
  addKey("speed", VHSSpeed_Key, 0x30, 8);
  addKey("down", Down_Key, 0x31, 8);
  addKey("eject", Eject_Key, 0x32, 8);
  addKey("return", Exit_Key, 0x3D, 8);
  addKey("vol_down", VolumeDown_Key, 0x40, 8);
  addKey("prev_ch", PrevChannel_Key, 0x54, 8);
  addKey("vol_up", VolumeUp_Key, 0x63, 8);
  addKey("left", Left_Key, 0x66, 8);
}


SamsungVCR1d::SamsungVCR1d(
  unsigned int index)
  : SamsungVCR1(index)
{
  // Combo VCR/TV:
  addControlledDevice(Samsung_Make, "CXD1342", TV_Device);
  addControlledDevice(Samsung_Make, "CXD1342", VCR_Device);

  setKeysetName("VCR/TV Combo Keyset 1d");
}


void SamsungVCR1d::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungVCR1::populateProtocol(guiObject);

  addKey("VOL+", VolumeUp_Key, 0x07, 8);
  addKey("VOL-", VolumeDown_Key, 0x0B, 8);
  addKey("MUTE", Mute_Key, 0x0F, 8);
  addKey("P./STILL", Pause_Key, 0x16, 8);
  addKey("PRE-CH", PrevChannel_Key, 0x2A, 8);
  addKey("eject", Eject_Key, 0x32, 8);
  addKey("REPEAT", Repeat_Key, 0x37, 8);
  addKey("P-STD", Unmapped_Key, 0x6F, 8); // Picture mode?
}


SamsungVCR1e::SamsungVCR1e(
  unsigned int index)
  : SamsungVCR1(index)
{
  setKeysetName("VCR(DVD) Keyset 1e");
}


void SamsungVCR1e::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungVCR1::populateProtocol(guiObject);

  addKey("DIGEST", Unmapped_Key, 0x00, 8);
  addKey("RIGHT", Right_Key, 0x13, 8);
  addKey("LEFT", Left_Key, 0x17, 8);
  addKey("DISC_MENU", DiscMenu_Key, 0x1F, 8);
  addKey("3D_SOUND", Surround_Key, 0x26, 8);
  addKey("VCR", Unmapped_Key, 0x28, 8);
  addKey("UP", Up_Key, 0x2C, 8);
  addKey("DOWN", Down_Key, 0x2D, 8);
  addKey("CLOCK/COUNTER", Clock_Key, 0x31, 8);
  addKey("OPEN/CLOSE", Eject_Key, 0x32, 8);
  addKey("ZOOM", Zoom_Key, 0x3A, 8);
  addKey("RETURN", Exit_Key, 0x3D, 8);
  addKey("TRK_DOWN", TrackingMinus_Key, 0x40, 8);
  addKey("SETUP/ENTER", Menu_Key, 0x43, 8);
  addKey("SETUP/ENTER", Select_Key, 0x43, 8);
  addKey("ANGLE", Angle_Key, 0x54, 8);
  addKey("DVD", Unmapped_Key, 0x55, 8);
  addKey("INPUT_SEL", Input_Key, 0x59, 8);
  addKey("TITLE", DiscTitle_Key, 0x60, 8);
  addKey("TRK_UP", TrackingPlus_Key, 0x63, 8);
  addKey("MODE/REPEAT", Repeat_Key, 0x66, 8);
  addKey("AUDIO", Audio_Key, 0x68, 8);
}


SamsungDVD1::SamsungDVD1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 1",
      Samsung_Make,
      index)
{
}


void SamsungDVD1::populateProtocol(
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
    600, 500,
    600, 1600,
    108000, true);

  threadableProtocol = lp;

  lp->setHeaderPair(9000, 4500);
  lp->setTrailerPulse(600);
  lp->setRepeatPair(9000, 4500);

  setPreData(0x198133F, 26);

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
  addKey("audio", Audio_Key, 0x718E, 16);
  addKey("angle", Angle_Key, 0x49B6, 16);
  addKey("repeat", Repeat_Key, 0xB946, 16);
  addKey("repeat_A-B", RepeatAB_Key, 0x15EA, 16);
  addKey("step_r", StepForward_Key, 0xEB14, 16);
  addKey("step_l", StepBack_Key, 0x1BE4, 16);
  addKey("jog_r", Unmapped_Key, 0x936C, 16);
  addKey("jog_l", Unmapped_Key, 0x53AC, 16);
  addKey("sacd/cd", Unmapped_Key, 0x6E91, 16);
  addKey("bookmark", Unmapped_Key, 0x956A, 16);
  addKey("index_pre", Unmapped_Key, 0x837C, 16);
  addKey("index_next", Unmapped_Key, 0x639C, 16);
  addKey("page_pre", PageUp_Key, 0x23DC, 16);
  addKey("page_next", PageDown_Key, 0x639C, 16);
  addKey("zoom", Zoom_Key, 0x35CA, 16);
  addKey("hdmi_sel", Unmapped_Key, 0xE41B, 16);
  addKey("video_sel", Unmapped_Key, 0x44BB, 16);
  addKey("3D_Sound", Surround_Key, 0xD52A, 16);
  addKey("TopMenu", DiscTitle_Key, 0xC936, 16);
}


SamsungDVD1a::SamsungDVD1a(
  unsigned int index)
  : SamsungDVD1(index)
{
  setKeysetName("DVD Keyset 1a");
}


void SamsungDVD1a::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungDVD1::populateProtocol(guiObject);

  addKey("hdmi_sel", Unmapped_Key, 0x15EA, 16);
}


SamsungDVD1b::SamsungDVD1b(
  unsigned int index)
  : SamsungDVD1(index)
{
  setKeysetName("DVD Keyset 1b");
}


void SamsungDVD1b::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  SamsungDVD1::populateProtocol(guiObject);

  addKey("Zoom", Zoom_Key, 0x55AA, 16);
  addKey("i.replay", Replay_Key, 0xB54A, 16);
  addKey("Volume_Con", Unmapped_Key, 0x35CA, 16);
}


SamsungDVD2::SamsungDVD2(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVD Keyset 2",
      Samsung_Make,
      index)
{
  addControlledDevice(Samsung_Make, "HT-P1200", DVD_Device);
}


void SamsungDVD2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol= new SamsungProtocol(guiObject, index);

//  setPreData(0xC2CA, 16);
  setPreData(0x5343, 16);

  addKey("remain", Unmapped_Key, 0x00, 8);
  addKey("play", Play_Key, 0x03, 8);
  addKey("PLII-MODE", Unmapped_Key, 0x04, 8);
  addKey("ENTER", Select_Key, 0x05, 8);
  addKey("AUDIO", Audio_Key, 0x06, 8);
  addKey("EZ-VIEW", Unmapped_Key, 0x07, 8);
  addKey("TUNER", TunerInput_Key, 0x09, 8);
  addKey("stop", Stop_Key, 0x0B, 8);
  addKey("PLII-EFFECT", Unmapped_Key, 0x0C, 8);
  addKey("UP", Up_Key, 0x0D, 8);
  addKey("SUBTITLE", Captions_Key, 0x0E, 8);
  addKey("ZOOM", Zoom_Key, 0x0F, 8);
  addKey("AUX", AuxInput_Key, 0x11, 8);
  addKey("next", Next_Key, 0x13, 8);
  addKey("SOUND-EDIT", SoundMode_Key, 0x14, 8);
  addKey("DOWN", Down_Key, 0x15, 8);
  addKey("cancel", Unmapped_Key, 0x17, 8);
//  addKey("MODE", Program_Key, 0x18, 8); // Might be wrong
  addKey("TV-VIDEO", Input_Key, 0x18, 8);
  addKey("DVD", DVDInput_Key, 0x19, 8);
  addKey("prev", Previous_Key, 0x1B, 8);
  addKey("RETURN", Exit_Key, 0x1C, 8);
  addKey("RIGHT", Right_Key, 0x1D, 8);
  addKey("SLEEP", Sleep_Key, 0x21, 8);
  addKey("ch+", ChannelUp_Key, 0x23, 8);
  addKey("MUSIC", Unmapped_Key, 0x24, 8);
  addKey("LEFT", Left_Key, 0x25, 8);
  addKey("INFO", Info_Key, 0x26, 8);
  addKey("ch-", ChannelDown_Key, 0x2B, 8);
  addKey("TUNER-MEMORY", Memory_Key, 0x2D, 8);
  addKey("0", Zero_Key, 0x2F, 8);
  addKey("VOL+", VolumeUp_Key, 0x33, 8);
  addKey("TEST-TONE", Unmapped_Key, 0x34, 8);
  addKey("SLOW", Slow_Key, 0x35, 8);
  addKey("MENU", Menu_Key, 0x36, 8);
  addKey("9", Nine_Key, 0x37, 8);
  addKey("LOGO", Unmapped_Key, 0x38, 8);
  addKey("MUTE", Mute_Key, 0x39, 8);
  addKey("VOL-", VolumeDown_Key, 0x3B, 8);
  addKey("STEP", StepForward_Key, 0x3D, 8);
  addKey("8", Eight_Key, 0x3F, 8);
  addKey("1", One_Key, 0x41, 8);
  addKey("2", Two_Key, 0x42, 8);
  addKey("3", Three_Key, 0x43, 8);
  addKey("4", Four_Key, 0x44, 8);
  addKey("5", Five_Key, 0x45, 8);
  addKey("6", Six_Key, 0x46, 8);
  addKey("7", Seven_Key, 0x47, 8);
  addKey("SD-HD", AspectRatio_Key, 0x59, 8);
  addKey("REPEAT", Repeat_Key, 0x66, 8);
  addKey("super5.1", Surround_Key, 0x67, 8);
  addKey("MOVIE", Unmapped_Key, 0x68, 8);
  addKey("ASC", Unmapped_Key, 0x69, 8);
  addKey("HDMI-AUDIO", Unmapped_Key, 0x70, 8);
}


SamsungAC1::SamsungAC1(
  unsigned int index)
  : PIRKeysetMetaData(
      "Air Conditioner 1",
      Samsung_Make,
      index)
{
}


void SamsungAC1::populateProtocol(
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
    600, 500,
    600, 1600,
    60000, true);

  threadableProtocol = lp;

  lp->setHeaderPair(4500, 4500);
  lp->setTrailerPulse(600);

  setPreData(0x804, 12);

//  np->setMinimumRepetitions(1);

  addKey("TIMER", Timer_Key, 0xA4, 8);
  addKey("SLEEP", Sleep_Key, 0xE4, 8);
  addKey("TEMP+", TempUp_Key, 0x4C, 8);
  addKey("TEMP-", TempDown_Key, 0x8C, 8);
  addKey("FAN", Fan_Key, 0x9C, 8);
  addKey("COOL", Cool_Key, 0x3C, 8);
  addKey("HEAT", Heat_Key, 0x5C, 8);
  addKey("FAN_HIGH", FanFaster_Key, 0xEC, 8);
  addKey("FAN_MED", Unmapped_Key, 0x6C, 8);
  addKey("FAN_LOW", FanSlower_Key, 0xAC, 8);
  addKey("SWING", Oscillate_Key, 0x94, 8);
  addKey("POWER", Power_Key, 0xFC, 8);
}


/*
SamsungAC2::SamsungAC2(
  unsigned int index)
  : PIRKeysetMetaData(
      "AC Keyset 2",
      Samsung_Make,
      index)
{
}


void SamsungAC2::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new ACProtocol(guiObject, index);

  addKey("Power Off", PowerOff_Subkey, 0xC, 4);
  addKey("Power On", PowerOn_Subkey, 0x0, 4);

  addKey("Cool Mode - Normal", CoolModeNormal_Subkey, 0x7, 3);
  addKey("Cool Mode - Turbo", CoolModeTurbo_Subkey, 0x1, 3);
  addKey("Cool Mode - Far", CoolModeFar_Subkey, 0x2, 3);

  addKey("Deflector L/R Off", DeflectorLROff_Subkey, 0x0, 1);
  addKey("Deflector L/R On", DeflectorLROn_Subkey, 0x1, 1);
  addKey("Deflector U/D Off", DeflectorUDOff_Subkey, 0x0, 1);
  addKey("Deflector U/D On", DeflectorUDOn_Subkey, 0x1, 1);
}
*/


SamsungDVBT1::SamsungDVBT1(
  unsigned int index)
  : PIRKeysetMetaData(
      "DVB-T Receiver Keyset 1",
      Samsung_Make,
      index)
{
  addControlledDevice(Samsung_Make, "SMT-1000T", TV_Device);
  addControlledDevice(Samsung_Make, "SMT-1100T", TV_Device);
}


void SamsungDVBT1::populateProtocol(
  QObject *guiObject)
{
  if (threadableProtocol)
  {
    // If the pointer is not null, the keyset must already be populated.
    return;
  }

  threadableProtocol = new NECProtocol(guiObject, index, true, true);

  setPreData(0x4040, 16);

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
  addKey("power", Power_Key, 0x0A, 8);
  addKey("up", Up_Key, 0x0B, 8);
  addKey("mute", Mute_Key, 0x0C, 8);
  addKey("ok", Select_Key, 0x0D, 8);
  addKey("down", Down_Key, 0x0E, 8);
  addKey("tv/stb", Input_Key, 0x0F, 8);

  addKey("left", Left_Key, 0x10, 8);
  addKey("right", Right_Key, 0x11, 8);
  addKey("clock", Unmapped_Key, 0x12, 8);
  addKey("vol+", VolumeUp_Key, 0x15, 8);
  addKey("red", Red_Key, 0x16, 8);
  addKey("green", Green_Key, 0x17, 8);
  addKey("yellow", Yellow_Key, 0x18, 8);
  addKey("blue", Blue_Key, 0x19, 8);
  addKey("epg", Guide_Key, 0x1A, 8);
  addKey("vol-", VolumeDown_Key, 0x1C, 8);
  addKey("radio", TunerInput_Key, 0x1D, 8);
  addKey("chan-", ChannelDown_Key, 0x1E, 8);
  addKey("chan+", ChannelUp_Key, 0x1F, 8);

  addKey("fav", Favorites_Key, 0x27, 8);

  addKey("menu", Menu_Key, 0x40, 8);
  addKey("exit", Exit_Key, 0x41, 8);
  addKey("i", Info_Key, 0x42, 8);
  addKey("rcl", PrevChannel_Key, 0x43, 8);
  addKey("txt", Teletext_Key, 0x45, 8); // might be wrong
  addKey("a-z", Unmapped_Key, 0x46, 8);
}
