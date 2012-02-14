#ifndef DIGITALSTREAM_H
#define DIGITALSTREAM_H

#include "pirkeysetmetadata.h"

class QObject;

class DigitalStreamReceiver: public PIRKeysetMetaData
{
public:
  DigitalStreamReceiver(
    QObject *guiObject,
    unsigned int index);
};

#endif // DIGITALSTREAM_H
