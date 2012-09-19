#ifndef FRONTECH_H
#define FRONTECH_H

#include "pirkeysetmetadata.h"

class QObject;

class FrontechTV1: public PIRKeysetMetaData
{
public:
  FrontechTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class FrontechTV2: public PIRKeysetMetaData
{
public:
  FrontechTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // FRONTECH_H
