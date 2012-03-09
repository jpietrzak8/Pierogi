#ifndef OCTAGON_H
#define OCTAGON_H

#include "pirkeysetmetadata.h"

class QObject;

class OctagonSat1: public PIRKeysetMetaData
{
public:
  OctagonSat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OctagonSat1a: public OctagonSat1
{
public:
  OctagonSat1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OctagonSat2: public PIRKeysetMetaData
{
public:
  OctagonSat2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // OCTAGON_H
