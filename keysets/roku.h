#ifndef ROKU_H
#define ROKU_H

#include "pirkeysetmetadata.h"

class QObject;

class RokuBox1: public PIRKeysetMetaData
{
public:
  RokuBox1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class RokuBox2: public PIRKeysetMetaData
{
public:
  RokuBox2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // ROKU_H
