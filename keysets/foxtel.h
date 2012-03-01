#ifndef FOXTEL_H
#define FOXTEL_H

#include "pirkeysetmetadata.h"

class QObject;

class FoxtelSTB1: public PIRKeysetMetaData
{
public:
  FoxtelSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class FoxtelSTB2: public PIRKeysetMetaData
{
public:
  FoxtelSTB2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // FOXTEL_H
