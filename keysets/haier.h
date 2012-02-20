#ifndef HAIER_H
#define HAIER_H

#include "pirkeysetmetadata.h"

class QObject;

class HaierTV1: public PIRKeysetMetaData
{
public:
  HaierTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // HAIER_H
