#ifndef VESTEL_H
#define VESTEL_H

#include "pirkeysetmetadata.h"

class QObject;

class VestelTV1: public PIRKeysetMetaData
{
public:
  VestelTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class VestelTV2: public PIRKeysetMetaData
{
public:
  VestelTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // VESTEL_H
