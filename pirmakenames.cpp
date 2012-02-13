#include "pirmakenames.h"

#include <QComboBox>

PIRMakeMgr::PIRMakeMgr()
{
  makes[Any_Make] = "Any";
  makes[Acer_Make] = "Acer";
  makes[Admiral_Make] = "Admiral";
  makes[Aiwa_Make] = "Aiwa";
  makes[Apple_Make] = "Apple";
  makes[Bose_Make] = "Bose";
  makes[Daewoo_Make] = "Daewoo";
  makes[Denon_Make] = "Denon";
  makes[Ei_Make] = "Ei";
  makes[Elgato_Make] = "Elgato";
  makes[GoldStar_Make] = "GoldStar";
  makes[Grundig_Make] = "Grundig";
  makes[Hauppauge_Make] = "Hauppauge";
  makes[Hitachi_Make] = "Hitachi";
  makes[JVC_Make] = "JVC";
  makes[LG_Make] = "LG";
  makes[Logitech_Make] = "Logitech";
  makes[Magnavox_Make] = "Magnavox";
  makes[Microsoft_Make] = "Microsoft";
  makes[Mitsubishi_Make] = "Mitsubishi";
  makes[Nokia_Make] = "Nokia";
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
  makes[Tivo_Make] = "TiVo";
  makes[Topfield_Make] = "Topfield";
  makes[Toshiba_Make] = "Toshiba";
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
