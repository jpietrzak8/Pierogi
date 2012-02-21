#ifndef HUMAX_H
#define HUMAX_H

#include "pirkeysetmetadata.h"

class QObject;

class HumaxReceiver1: public PIRKeysetMetaData
{
public:
  HumaxReceiver1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class HumaxReceiver2: public PIRKeysetMetaData
{
public:
  HumaxReceiver2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class HumaxReceiver3: public PIRKeysetMetaData
{
public:
  HumaxReceiver3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // HUMAX_H
