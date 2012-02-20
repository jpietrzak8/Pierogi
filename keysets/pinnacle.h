#ifndef PINNACLE_H
#define PINNACLE_H

#include "pirkeysetmetadata.h"

class QObject;

class PinnaclePCTV1: public PIRKeysetMetaData
{
public:
  PinnaclePCTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PinnaclePCTV2: public PIRKeysetMetaData
{
public:
  PinnaclePCTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PinnaclePCTV3: public PIRKeysetMetaData
{
public:
  PinnaclePCTV3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // PINNACLE_H
