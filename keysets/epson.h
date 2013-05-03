#ifndef EPSON_H
#define EPSON_H

#include "pirkeysetmetadata.h"

class QObject;

class EpsonProjector1: public PIRKeysetMetaData
{
public:
  EpsonProjector1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class EpsonProjector1a: public EpsonProjector1
{
public:
  EpsonProjector1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // EPSON_H
