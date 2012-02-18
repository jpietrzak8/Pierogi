#ifndef VESTEL_H
#define VESTEL_H

#include "pirkeysetmetadata.h"

class QObject;

class VestelTV1: public PIRKeysetMetaData
{
public:
  VestelTV1(
    QObject *guiObject,
    unsigned int index);
};

class VestelTV2: public PIRKeysetMetaData
{
public:
  VestelTV2(
    QObject *guiObject,
    unsigned int index);
};

#endif // VESTEL_H
