#ifndef WESTINGHOUSE_H
#define WESTINGHOUSE_H

#include "pirkeysetmetadata.h"

class QObject;

class WestinghouseTV1: public PIRKeysetMetaData
{
public:
  WestinghouseTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class WestinghouseTV2: public PIRKeysetMetaData
{
public:
  WestinghouseTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // WESTINGHOUSE_H
