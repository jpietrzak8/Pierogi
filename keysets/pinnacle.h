#ifndef PINNACLE_H
#define PINNACLE_H

#include "pirkeysetmetadata.h"

class QObject;

class PinnaclePCTV1: public PIRKeysetMetaData
{
public:
  PinnaclePCTV1(
    QObject *guiObject,
    unsigned int index);
};

class PinnaclePCTV2: public PIRKeysetMetaData
{
public:
  PinnaclePCTV2(
    QObject *guiObject,
    unsigned int index);
};

class PinnaclePCTV3: public PIRKeysetMetaData
{
public:
  PinnaclePCTV3(
    QObject *guiObject,
    unsigned int index);
};

#endif // PINNACLE_H
