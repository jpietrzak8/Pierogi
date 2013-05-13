#ifndef COMAG_H
#define COMAG_H

#include "pirkeysetmetadata.h"

class QObject;

class ComagSTB1: public PIRKeysetMetaData
{
public:
  ComagSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ComagSTB2: public PIRKeysetMetaData
{
public:
  ComagSTB2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // COMAG_H
