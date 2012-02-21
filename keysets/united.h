#ifndef UNITED_H
#define UNITED_H

#include "pirkeysetmetadata.h"

class QObject;

class UnitedDVD1: public PIRKeysetMetaData
{
public:
  UnitedDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class UnitedDVBT1: public PIRKeysetMetaData
{
public:
  UnitedDVBT1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // UNITED_H
