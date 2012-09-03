#include "blaupunkt.h"
#include "protocols/kaseikyoprotocol.h"

BlaupunktVCR1::BlaupunktVCR1(
  unsigned int index)
  : PIRKeysetMetaData(
      "VCR Keyset 1",
      Blaupunkt_Make,
      index)
{
}


void BlaupunktVCR1::populateProtocol(
   QObject *guiObject)
{
  if (threadableProtocol)
  {
    // Keyset already populated.
    return;
  }

  threadableProtocol = new KaseikyoProtocol(guiObject, index);

  setPreData(0x2002, 16);

  addKaseikyoKey("ok", Select_Key, 0x009, 0x58);
  addKaseikyoKey("up", Up_Key, 0x009, 0x02);
  addKaseikyoKey("down", Down_Key, 0x009, 0x03);
  addKaseikyoKey("left", Left_Key, 0x009, 0x05);
  addKaseikyoKey("right", Right_Key, 0x009, 0x04);
  addKaseikyoKey("menu", Menu_Key, 0x009, 0x56);
  addKaseikyoKey("exit", Exit_Key, 0x009, 0x66);
  addKaseikyoKey("power", Power_Key, 0x009, 0x3D);
  addKaseikyoKey("prog+", ChannelUp_Key, 0x009, 0x34);
  addKaseikyoKey("prog-", ChannelDown_Key, 0x009, 0x35);
  addKaseikyoKey("vt_hold", TeletextHold_Key, 0x009, 0x66);
  addKaseikyoKey("vt_mix", TeletextMix_Key, 0x009, 0x58);
  addKaseikyoKey("vt_off", TeletextOff_Key, 0x009, 0x66);
  addKaseikyoKey("vt_on", Teletext_Key, 0x009, 0x56);
  addKaseikyoKey("adjust", Unmapped_Key, 0x009, 0x57);
  addKaseikyoKey("stop", Stop_Key, 0x009, 0x00);
  addKaseikyoKey("play", Play_Key, 0x009, 0x0A);
  addKaseikyoKey("rew", Rewind_Key, 0x009, 0x02);
  addKaseikyoKey("ffwd", FastForward_Key, 0x009, 0x03);
  addKaseikyoKey("rec", Record_Key, 0x009, 0x08);
  addKaseikyoKey("pause", Pause_Key, 0x009, 0x06);
  addKaseikyoKey("1", One_Key, 0x009, 0x10);
  addKaseikyoKey("2", Two_Key, 0x009, 0x11);
  addKaseikyoKey("3", Three_Key, 0x009, 0x12);
  addKaseikyoKey("4", Four_Key, 0x009, 0x13);
  addKaseikyoKey("5", Five_Key, 0x009, 0x14);
  addKaseikyoKey("6", Six_Key, 0x009, 0x15);
  addKaseikyoKey("7", Seven_Key, 0x009, 0x16);
  addKaseikyoKey("8", Eight_Key, 0x009, 0x17);
  addKaseikyoKey("9", Nine_Key, 0x009, 0x18);
  addKaseikyoKey("0", Zero_Key, 0x009, 0x19);
  addKaseikyoKey("av", Input_Key, 0x009, 0xC0);
  addKaseikyoKey("n/nm", Unmapped_Key, 0x009, 0x3B);
}
