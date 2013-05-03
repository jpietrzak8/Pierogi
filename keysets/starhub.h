#ifndef STARHUB_H
#define STARHUB_H

#include "pirkeysetmetadata.h"

class QObject;

class StarhubSTB1: public PIRKeysetMetaData
{
public:
  StarhubSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class StarhubSTB1a: public StarhubSTB1
{
public:
  StarhubSTB1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // STARHUB_H
