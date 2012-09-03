#include "pirkeysetwidgetitem.h"

PIRKeysetWidgetItem::PIRKeysetWidgetItem(
  QString displayName,
  QString in,
  unsigned int i,
  PIRMakeName m)
  : QListWidgetItem(displayName),
    id(i),
    make(m),
    favorite(false),
    nicknameNotEmpty(false),
    internalName(in)
{
}


PIRKeysetWidgetItem::PIRKeysetWidgetItem(
  QString displayName,
  QString in,
  unsigned int i,
  PIRMakeName m,
  PIRDeviceTypeName t)
  : QListWidgetItem(displayName),
    id(i),
    make(m),
    deviceType(t),
    favorite(false),
    nicknameNotEmpty(false),
    internalName(in)
{
}


PIRKeysetWidgetItem::PIRKeysetWidgetItem(
  PIRKeysetWidgetItem *original)
  : QListWidgetItem(original->text()),
    id(original->getID()),
    make(original->getMake()),
    deviceType(original->getDeviceType()),
    favorite(original->isFavorite()),
    nicknameNotEmpty(original->hasNickname()),
    internalName(original->getInternalName())
{
  if (nicknameNotEmpty)
  {
    nickname = original->getNickname();
  }
}


void PIRKeysetWidgetItem::setNickname(
  QString nn)
{
  nickname = nn;

  nicknameNotEmpty = !nn.isEmpty();
}
