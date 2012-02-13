#ifndef SABA_H
#define SABA_H

#include "pirkeysetmetadata.h"

class QObject;

class SabaTV1: public PIRKeysetMetaData
{
public:
  SabaTV1(
    QObject *guiObject,
    unsigned int index);
};

class SabaTV2: public PIRKeysetMetaData
{
public:
  SabaTV2(
    QObject *guiObject,
    unsigned int index);
};

#endif // SABA_H
