#include "pirtabswidgetitem.h"

PIRTabsWidgetItem::PIRTabsWidgetItem(
  QString displayName,
  PIRTabBarName internalName)
  : QListWidgetItem(displayName),
    tabBarName(internalName)
{
}


PIRTabBarName PIRTabsWidgetItem::getTabBarName()
{
  return tabBarName;
}
