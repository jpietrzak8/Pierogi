#ifndef NOKIA_H
#define NOKIA_H

#include "pirkeysetmetadata.h"

#include <QObject>

class NokiaGenericVCR: public PIRKeysetMetaData
{
public:
  NokiaGenericVCR(
    QObject *guiObject,
    unsigned int index);
};

#endif // NOKIA_H
