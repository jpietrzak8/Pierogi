#ifndef CANON_H
#define CANON_H

#include "pirkeysetmetadata.h"

class QObject;

class CanonDSLR1: public PIRKeysetMetaData
{
public:
  CanonDSLR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class CanonCamcorder1: public PIRKeysetMetaData
{
public:
  CanonCamcorder1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class CanonPowershot1: public PIRKeysetMetaData
{
public:
  CanonPowershot1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // CANON_H
