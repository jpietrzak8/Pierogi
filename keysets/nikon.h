#ifndef NIKON_H
#define NIKON_H

#include "pirkeysetmetadata.h"

class QObject;

class NikonDSLR1: public PIRKeysetMetaData
{
public:
  NikonDSLR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // NIKON_H
