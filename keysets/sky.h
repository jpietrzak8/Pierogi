#ifndef SKY_H
#define SKY_H

#include "pirkeysetmetadata.h"

class QObject;

class SkyReceiver1: public PIRKeysetMetaData
{
public:
  SkyReceiver1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SkyReceiver1a: public SkyReceiver1
{
public:
  SkyReceiver1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // SKY_H
