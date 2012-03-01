#include "pirmakenames.h"

#include <QComboBox>

PIRMakeMgr::PIRMakeMgr()
{
  makes[Any_Make] = "Any";
  makes[Acer_Make] = "Acer";
  makes[Admiral_Make] = "Admiral";
  makes[Aiwa_Make] = "Aiwa";
  makes[AOC_Make] = "AOC";
  makes[Apple_Make] = "Apple";
  makes[Arcam_Make] = "Arcam";
  makes[Beko_Make] = "Beko";
  makes[Bose_Make] = "Bose";
  makes[Bush_Make] = "Bush";
  makes[Cambridge_Make] = "Cambridge Audio";
  makes[Canon_Make] = "Canon";
  makes[Daewoo_Make] = "Daewoo";
  makes[Dell_Make] = "Dell";
  makes[Denon_Make] = "Denon";
  makes[DigitalStream_Make] = "Digital Stream";
  makes[Directv_Make] = "DirecTV";
  makes[Dish_Make] = "Dish";
  makes[DSE_Make] = "DSE (Dick Smith)";
  makes[Dynex_Make] = "Dynex";
  makes[Ei_Make] = "Ei";
  makes[Elgato_Make] = "Elgato";
  makes[Emerson_Make] = "Emerson";
  makes[Epson_Make] = "Epson";
  makes[Fortec_Make] = "Fortec Star";
  makes[Foxtel_Make] = "Foxtel";
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
  makes[Kathrein_Make] = "Kathrein";
  makes[Kenwood_Make] = "Kenwood";
  makes[LG_Make] = "LG";
  makes[Logitech_Make] = "Logitech";
  makes[Magnavox_Make] = "Magnavox";
  makes[Microsoft_Make] = "Microsoft";
  makes[Mitsubishi_Make] = "Mitsubishi";
  makes[Motorola_Make] = "Motorola";
  makes[NAD_Make] = "NAD";
  makes[Nokia_Make] = "Nokia";
  makes[Onida_Make] = "Onida";
  makes[Panasonic_Make] = "Panasonic";
  makes[Philco_Make] = "Philco";
  makes[Philips_Make] = "Philips";
  makes[Pinnacle_Make] = "Pinnacle Systems";
  makes[Pioneer_Make] = "Pioneer";
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
  makes[Technics_Make] = "Technics";
  makes[Tivo_Make] = "TiVo";
  makes[Topfield_Make] = "Topfield";
  makes[Toshiba_Make] = "Toshiba";
  makes[United_Make] = "United";
  makes[Universum_Make] = "Universum";
  makes[Vestel_Make] = "Vestel";
  makes[Viewsat_Make] = "Viewsat";
  makes[Virgin_Make] = "Virgin Media";
  makes[Vizio_Make] = "Vizio";
  makes[WD_Make] = "Western Digital";
  makes[Westinghouse_Make] = "Westinghouse";
  makes[Yamaha_Make] = "Yamaha";
  makes[Zenith_Make] = "Zenith";
}

const char *PIRMakeMgr::getMakeString(
  PIRMakeName n)
{
  return makes[n];
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
