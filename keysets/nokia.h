#ifndef NOKIA_H
#define NOKIA_H

#include "pirkeysetmetadata.h"

class QObject;

class NokiaGenericVCR: public PIRKeysetMetaData
{
public:
  NokiaGenericVCR(
    QObject *guiObject,
    unsigned int index);
};

#endif // NOKIA_H
