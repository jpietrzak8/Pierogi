#ifndef PIRKEYSETWIDGETITEM_H
#define PIRKEYSETWIDGETITEM_H

#include <QListWidgetItem>

#include "pirmakenames.h"

class PIRKeysetWidgetItem: public QListWidgetItem
{
public:
  PIRKeysetWidgetItem(
    QString name,
    unsigned int id,
    PIRMakeName make);

  unsigned int getID();

  PIRMakeName getMake();

private:
  unsigned int id;
  PIRMakeName make;
};

#endif // PIRKEYSETWIDGETITEM_H
