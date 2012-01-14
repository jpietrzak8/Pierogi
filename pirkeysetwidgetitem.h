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

  void addDeviceType(
    PIRDeviceTypeName dt);

  unsigned int getID();

  PIRMakeName getMake();

  bool supportsDeviceType(
    PIRDeviceTypeName dt);

private:
  unsigned int id;
  PIRMakeName make;
  PIRDeviceTypeCollection devices;
};

#endif // PIRKEYSETWIDGETITEM_H
