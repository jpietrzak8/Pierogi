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


unsigned int PIRKeysetWidgetItem::getID()
{
  return id;
}


PIRMakeName PIRKeysetWidgetItem::getMake()
{
  return make;
}
