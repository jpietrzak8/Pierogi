#include "pirmakenames.h"

PIRMakeMgr::PIRMakeMgr()
{
  makes[Any_Make] = "Any";
  makes[Apple_Make] = "Apple";
  makes[Denon_Make] = "Denon";
  makes[Ei_Make] = "Ei";
  makes[GoldStar_Make] = "GoldStar";
  makes[Hauppauge_Make] = "Hauppauge";
  makes[Hitachi_Make] = "Hitachi";
  makes[JVC_Make] = "JVC";
  makes[LG_Make] = "LG";
  makes[Mitsubishi_Make] = "Mitsubishi";
  makes[Nokia_Make] = "Nokia";
  makes[Panasonic_Make] = "Panasonic";
  makes[Philips_Make] = "Philips";
  makes[Pinnacle_Make] = "Pinnacle Systems";
  makes[Raite_Make] = "Raite";
  makes[RCA_Make] = "RCA";
  makes[Sagem_Make] = "Sagem";
  makes[Samsung_Make] = "Samsung";
  makes[Sanyo_Make] = "Sanyo";
  makes[Sharp_Make] = "Sharp";
  makes[Sony_Make] = "Sony";
  makes[Toshiba_Make] = "Toshiba";
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
