#ifndef PIRKEYSETWIDGETITEM_H
#define PIRKEYSETWIDGETITEM_H

#include <QListWidgetItem>

#include "pirmakenames.h"
#include "pirdevicetypenames.h"

class PIRKeysetWidgetItem: public QListWidgetItem
{
public:
  PIRKeysetWidgetItem(
    QString name,
    unsigned int id,
    PIRMakeName make);

  PIRKeysetWidgetItem(
    QString name,
    unsigned int id,
    PIRMakeName make,
    PIRDeviceTypeName dt);

  unsigned int getID();

  PIRMakeName getMake();

  PIRDeviceTypeName getDeviceType();

private:
  unsigned int id;
  PIRMakeName make;
  PIRDeviceTypeName deviceType;
};

#endif // PIRKEYSETWIDGETITEM_H
