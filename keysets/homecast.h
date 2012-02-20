#ifndef HOMECAST_H
#define HOMECAST_H

#include "pirkeysetmetadata.h"

class QObject;

class HomecastReceiver1: public PIRKeysetMetaData
{
public:
  HomecastReceiver1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HomecastReceiver2: public PIRKeysetMetaData
{
public:
  HomecastReceiver2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // HOMECAST_H
