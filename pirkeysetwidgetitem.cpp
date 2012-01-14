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


void PIRKeysetWidgetItem::addDeviceType(
  PIRDeviceTypeName dt)
{
  devices.insert(dt);
}


unsigned int PIRKeysetWidgetItem::getID()
{
  return id;
}


PIRMakeName PIRKeysetWidgetItem::getMake()
{
  return make;
}


bool PIRKeysetWidgetItem::supportsDeviceType(
  PIRDeviceTypeName dt)
{
  return (devices.find(dt) != devices.end());
}
