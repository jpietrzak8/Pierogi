#ifndef SKY_H
#define SKY_H

#include "pirkeysetmetadata.h"

class QObject;

class SkyReceiver1: public PIRKeysetMetaData
{
public:
  SkyReceiver1(
    QObject *guiObject,
    unsigned int index);
};

class SkyReceiver1a: public SkyReceiver1
{
public:
  SkyReceiver1a(
    QObject *guiObject,
    unsigned int index);
};

#endif // SKY_H
