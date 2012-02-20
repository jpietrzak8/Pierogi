#ifndef DIGITALSTREAM_H
#define DIGITALSTREAM_H

#include "pirkeysetmetadata.h"

class QObject;

class DigitalStreamReceiver: public PIRKeysetMetaData
{
public:
  DigitalStreamReceiver(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // DIGITALSTREAM_H
