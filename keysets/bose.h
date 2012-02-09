#ifndef BOSE_H
#define BOSE_H

#include "pirkeysetmetadata.h"

class QObject;

class BoseRadio1: public PIRKeysetMetaData
{
public:
  BoseRadio1(
    QObject *guiObject,
    unsigned int index);
};

class BoseRadio2: public PIRKeysetMetaData
{
public:
  BoseRadio2(
    QObject *guiObject,
    unsigned int index);
};

class BoseRadio3: public PIRKeysetMetaData
{
public:
  BoseRadio3(
    QObject *guiObject,
    unsigned int index);
};

#endif // BOSE_H
