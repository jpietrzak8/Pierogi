#ifndef PIRKEYSETWIDGETITEM_H
#define PIRKEYSETWIDGETITEM_H

#include <QListWidgetItem>

#include "pirmakenames.h"
#include "pirdevicetypenames.h"
#include "pirpanelnames.h"

class PIRKeysetWidgetItem: public QListWidgetItem
{
public:
  PIRKeysetWidgetItem(
    QString displayName,
    QString internalName,
    unsigned int id,
    PIRMakeName make);

  PIRKeysetWidgetItem(
    QString displayName,
    QString internalName,
    unsigned int id,
    PIRMakeName make,
    PIRDeviceTypeName dt);

  PIRKeysetWidgetItem(
    PIRKeysetWidgetItem *original);

  unsigned int getID();

  PIRMakeName getMake();

  PIRDeviceTypeName getDeviceType();

  void setFavorite(
    bool favorite);

  bool isFavorite();

  bool hasNickname();

  void setNickname(
    QString nn);

  QString getNickname();

  QString getInternalName();

  PIRTabBarName getTabBarName();
  int getPanelIndex();

  void setTabBarName(
    PIRTabBarName name);

  void setPanelIndex(
    int index);

private:
  unsigned int id;
  PIRMakeName make;
  PIRDeviceTypeName deviceType;
  bool favorite;
  bool nicknameNotEmpty;
  QString internalName;
  QString nickname;
  PIRTabBarName tabBarName;
  int panelIndex;
};


inline unsigned int PIRKeysetWidgetItem::getID()
{
  return id;
}


inline PIRMakeName PIRKeysetWidgetItem::getMake()
{
  return make;
}


inline PIRDeviceTypeName PIRKeysetWidgetItem::getDeviceType()
{
  return deviceType;
}


inline void PIRKeysetWidgetItem::setFavorite(
  bool f)
{
  favorite = f;
}


inline bool PIRKeysetWidgetItem::isFavorite()
{
  return favorite;
}


inline bool PIRKeysetWidgetItem::hasNickname()
{
  return nicknameNotEmpty;
}


inline QString PIRKeysetWidgetItem::getNickname()
{
  return nickname;
}


inline QString PIRKeysetWidgetItem::getInternalName()
{
  return internalName;
}


inline PIRTabBarName PIRKeysetWidgetItem::getTabBarName()
{
  return tabBarName;
}


inline int PIRKeysetWidgetItem::getPanelIndex()
{
  return panelIndex;
}


inline void PIRKeysetWidgetItem::setTabBarName(
  PIRTabBarName name)
{
  tabBarName = name;
}


inline void PIRKeysetWidgetItem::setPanelIndex(
  int index)
{
  panelIndex = index;
}

#endif // PIRKEYSETWIDGETITEM_H
