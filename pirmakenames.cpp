#include "pirmakenames.h"

PIRMakeMgr::PIRMakeMgr()
{
  makes[Any_Make] = "Any";
  makes[Apple_Make] = "Apple";
  makes[Ei_Make] = "Ei";
  makes[GoldStar_Make] = "GoldStar";
  makes[Hauppauge_Make] = "Hauppauge";
  makes[LG_Make] = "LG";
  makes[Nokia_Make] = "Nokia";
  makes[Panasonic_Make] = "Panasonic";
  makes[Samsung_Make] = "Samsung";
  makes[Sanyo_Make] = "Sanyo";
  makes[Sharp_Make] = "Sharp";
  makes[Sony_Make] = "Sony";
  makes[Toshiba_Make] = "Toshiba";
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
