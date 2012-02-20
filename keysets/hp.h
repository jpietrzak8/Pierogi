#ifndef HP_H
#define HP_H

#include "pirkeysetmetadata.h"

class QObject;

class HPRemote1: public PIRKeysetMetaData
{
public:
  HPRemote1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // HP_H
