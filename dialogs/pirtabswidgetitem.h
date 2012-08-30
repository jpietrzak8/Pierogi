#ifndef PIRTABSWIDGETITEM_H
#define PIRTABSWIDGETITEM_H

#include <QListWidgetItem>

#include "pirpanelnames.h"

class PIRTabsWidgetItem: public QListWidgetItem
{
public:
  PIRTabsWidgetItem(
    QString displayName,
    PIRTabBarName internalName);

  PIRTabBarName getTabBarName();

private:
  PIRTabBarName tabBarName;
};

#endif // PIRTABSWIDGETITEM_H
