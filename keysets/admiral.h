#ifndef ADMIRAL_H
#define ADMIRAL_H

#include "pirkeysetmetadata.h"

class QObject;

class AdmiralTV1: public PIRKeysetMetaData
{
public:
  AdmiralTV1(
    QObject *guiObject,
    unsigned int index);
};

class AdmiralTV2: public PIRKeysetMetaData
{
public:
  AdmiralTV2(
    QObject *guiObject,
    unsigned int index);
};

class AdmiralVCR1: public PIRKeysetMetaData
{
public:
  AdmiralVCR1(
    QObject *guiObject,
    unsigned int index);
};

#endif // ADMIRAL_H
