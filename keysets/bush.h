#ifndef BUSH_H
#define BUSH_H

#include "pirkeysetmetadata.h"

class QObject;

class BushTV1: public PIRKeysetMetaData
{
public:
  BushTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class BushTV2: public PIRKeysetMetaData
{
public:
  BushTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class BushSTB1: public PIRKeysetMetaData
{
public:
  BushSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // BUSH_H
