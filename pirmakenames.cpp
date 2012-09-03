#include "pirmakenames.h"

#include <QComboBox>

PIRMakeMgr::PIRMakeMgr()
{
  makes[Any_Make] = "Any";
  makes[Acer_Make] = "Acer";
  makes[ADB_Make] = "ADB";
  makes[Admiral_Make] = "Admiral";
  makes[Aiwa_Make] = "Aiwa";
  makes[Anitech_Make] = "Anitech";
  makes[AOC_Make] = "AOC";
  makes[Apple_Make] = "Apple";
  makes[Arcam_Make] = "Arcam";
  makes[Beko_Make] = "Beko";
  makes[BenQ_Make] = "BenQ";
  makes[Blaupunkt_Make] = "Blaupunkt";
  makes[Bose_Make] = "Bose";
  makes[Bush_Make] = "Bush";
  makes[Cambridge_Make] = "Cambridge Audio";
  makes[Canon_Make] = "Canon";
  makes[Cisco_Make] = "Cisco";
  makes[Compro_Make] = "Compro";
  makes[Daewoo_Make] = "Daewoo";
  makes[Dell_Make] = "Dell";
  makes[Denon_Make] = "Denon";
  makes[DigitalStream_Make] = "Digital Stream";
  makes[Directv_Make] = "DirecTV";
  makes[Dish_Make] = "Dish";
  makes[Dreambox_Make] = "Dream Multimedia";
  makes[DSE_Make] = "DSE (Dick Smith)";
  makes[Dynex_Make] = "Dynex";
  makes[Ei_Make] = "Ei";
  makes[Elgato_Make] = "Elgato";
  makes[Emerson_Make] = "Emerson";
  makes[Epson_Make] = "Epson";
  makes[Fortec_Make] = "Fortec Star";
  makes[Foxtel_Make] = "Foxtel";
  makes[Gadmei_Make] = "Gadmei";
  makes[Genius_Make] = "Genius";
  makes[GoldStar_Make] = "GoldStar";
  makes[Grundig_Make] = "Grundig";
  makes[Haier_Make] = "Haier";
  makes[HarmanKardon_Make] = "Harman/Kardon";
  makes[Hauppauge_Make] = "Hauppauge";
  makes[Hitachi_Make] = "Hitachi";
  makes[Homecast_Make] = "Homecast";
  makes[HP_Make] = "HP";
  makes[Huawei_Make] = "Huawei";
  makes[Humax_Make] = "Humax";
  makes[Hyundai_Make] = "Hyundai";
  makes[JVC_Make] = "JVC";
  makes[Kaon_Make] = "Kaon";
  makes[Kathrein_Make] = "Kathrein";
  makes[Kenwood_Make] = "Kenwood";
  makes[Lexuz_Make] = "Lexuz";
  makes[LG_Make] = "LG";
  makes[Lifetec_Make] = "Lifetec";
  makes[Loewe_Make] = "Loewe";
  makes[Logitech_Make] = "Logitech";
  makes[Magnavox_Make] = "Magnavox";
  makes[Magnum_Make] = "Magnum";
  makes[Medion_Make] = "Medion";
  makes[Microsoft_Make] = "Microsoft";
  makes[Mitsubishi_Make] = "Mitsubishi";
  makes[Motorola_Make] = "Motorola";
  makes[NAD_Make] = "NAD";
  makes[Nokia_Make] = "Nokia";
  makes[Octagon_Make] = "Octagon";
  makes[Onida_Make] = "Onida";
  makes[Onkyo_Make] = "Onkyo";
  makes[Orion_Make] = "Orion";
  makes[Panasonic_Make] = "Panasonic";
  makes[Philco_Make] = "Philco";
  makes[Philips_Make] = "Philips";
  makes[Pinnacle_Make] = "Pinnacle Systems";
  makes[Pioneer_Make] = "Pioneer";
  makes[Proview_Make] = "Proview";
  makes[QNAP_Make] = "QNAP";
  makes[Raite_Make] = "Raite";
  makes[RCA_Make] = "RCA";
  makes[Roku_Make] = "Roku";
  makes[Saba_Make] = "Saba";
  makes[Sagem_Make] = "Sagem";
  makes[Samsung_Make] = "Samsung";
  makes[Sanyo_Make] = "Sanyo";
  makes[Sharp_Make] = "Sharp";
  makes[Sky_Make] = "Sky";
  makes[Sony_Make] = "Sony";
  makes[Starsat_Make] = "Starsat";
  makes[Strong_Make] = "Strong";
  makes[Sylvania_Make] = "Sylvania";
  makes[Technics_Make] = "Technics";
  makes[Technisat_Make] = "Technisat";
  makes[Telefunken_Make] = "Telefunken";
  makes[Telenet_Make] = "Telenet";
  makes[Thomson_Make] = "Thomson";
  makes[Tivo_Make] = "TiVo";
  makes[Topfield_Make] = "Topfield";
  makes[Toshiba_Make] = "Toshiba";
  makes[Triax_Make] = "Triax";
  makes[United_Make] = "United";
  makes[Universum_Make] = "Universum";
  makes[Vestel_Make] = "Vestel";
  makes[Viewsat_Make] = "Viewsat";
  makes[Viewsonic_Make] = "Viewsonic";
  makes[Virgin_Make] = "Virgin Media";
  makes[Vizio_Make] = "Vizio";
  makes[WD_Make] = "Western Digital";
  makes[Westinghouse_Make] = "Westinghouse";
  makes[Xcruiser_Make] = "Xcruiser";
  makes[Yamaha_Make] = "Yamaha";
  makes[Zenith_Make] = "Zenith";

  MakeCollection::const_iterator i = makes.begin();
  while (i != makes.end())
  {
    makeIDs[i->second] = i->first;
    ++i;
  }
}

const char *PIRMakeMgr::getMakeString(
  PIRMakeName n)
{
  return makes[n];
}


PIRMakeName PIRMakeMgr::getMakeID(
  QString name)
{
  return makeIDs[name];
}


void PIRMakeMgr::populateComboBox(
  QComboBox *cb)
{
  MakeCollection::const_iterator i = makes.begin();
  while (i != makes.end())
  {
    cb->insertItem(i->first, QString(i->second));
    ++i;
  }
}
