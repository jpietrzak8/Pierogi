#ifndef OLYMPUS_H
#define OLYMPUS_H

#include "pirkeysetmetadata.h"

class QObject;

class OlympusCamera1: public PIRKeysetMetaData
{
public:
  OlympusCamera1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // OLYMPUS_H
