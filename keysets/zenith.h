#ifndef ZENITH_H
#define ZENITH_H

#include "pirkeysetmetadata.h"

class QObject;

class ZenithTV1: public PIRKeysetMetaData
{
public:
  ZenithTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ZenithConverterBox1: public PIRKeysetMetaData
{
public:
  ZenithConverterBox1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // ZENITH_H
