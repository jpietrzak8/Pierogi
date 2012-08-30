#ifndef GADMEI_H
#define GADMEI_H

#include "pirkeysetmetadata.h"

class QObject;

class GadmeiTuner1: public PIRKeysetMetaData
{
public:
  GadmeiTuner1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // GADMEI_H
