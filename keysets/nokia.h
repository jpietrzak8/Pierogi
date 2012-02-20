#ifndef NOKIA_H
#define NOKIA_H

#include "pirkeysetmetadata.h"

class QObject;

class NokiaGenericVCR: public PIRKeysetMetaData
{
public:
  NokiaGenericVCR(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // NOKIA_H
