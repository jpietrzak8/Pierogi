#ifndef ZENITH_H
#define ZENITH_H

#include "pirkeysetmetadata.h"

class QObject;

class ZenithC32V37: public PIRKeysetMetaData
{
public:
  ZenithC32V37(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // ZENITH_H
