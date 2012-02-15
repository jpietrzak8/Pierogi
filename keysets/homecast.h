#ifndef HOMECAST_H
#define HOMECAST_H

#include "pirkeysetmetadata.h"

class QObject;

class HomecastReceiver1: public PIRKeysetMetaData
{
public:
  HomecastReceiver1(
    QObject *guiObject,
    unsigned int index);
};

class HomecastReceiver2: public PIRKeysetMetaData
{
public:
  HomecastReceiver2(
    QObject *guiObject,
    unsigned int index);
};

#endif // HOMECAST_H
