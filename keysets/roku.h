#ifndef ROKU_H
#define ROKU_H

#include "pirkeysetmetadata.h"

class QObject;

class RokuBox1: public PIRKeysetMetaData
{
public:
  RokuBox1(
    QObject *guiObject,
    unsigned int index);
};

class RokuBox2: public PIRKeysetMetaData
{
public:
  RokuBox2(
    QObject *guiObject,
    unsigned int index);
};

#endif // ROKU_H
