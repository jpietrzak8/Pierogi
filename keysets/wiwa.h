#ifndef WIWA_H
#define WIWA_H

#include "pirkeysetmetadata.h"

class QObject;

class WiwaSTB1: public PIRKeysetMetaData
{
public:
  WiwaSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // WIWA_H
