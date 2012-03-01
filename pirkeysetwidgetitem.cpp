#include "pirkeysetwidgetitem.h"

PIRKeysetWidgetItem::PIRKeysetWidgetItem(
  QString name,
  unsigned int i,
  PIRMakeName m)
  : QListWidgetItem(name),
    id(i),
    make(m)
{
}


PIRKeysetWidgetItem::PIRKeysetWidgetItem(
  QString name,
  unsigned int i,
  PIRMakeName m,
  PIRDeviceTypeName t)
  : QListWidgetItem(name),
    id(i),
    make(m),
    deviceType(t)
{
}


unsigned int PIRKeysetWidgetItem::getID()
{
  return id;
}


PIRMakeName PIRKeysetWidgetItem::getMake()
{
  return make;
}


PIRDeviceTypeName PIRKeysetWidgetItem::getDeviceType()
{
  return deviceType;
}
