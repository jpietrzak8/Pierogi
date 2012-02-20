#ifndef ADMIRAL_H
#define ADMIRAL_H

#include "pirkeysetmetadata.h"

class QObject;

class AdmiralTV1: public PIRKeysetMetaData
{
public:
  AdmiralTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AdmiralTV2: public PIRKeysetMetaData
{
public:
  AdmiralTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AdmiralVCR1: public PIRKeysetMetaData
{
public:
  AdmiralVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // ADMIRAL_H
