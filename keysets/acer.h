#ifndef ACER_H
#define ACER_H

#include "pirkeysetmetadata.h"

class QObject;

class AcerTV1: public PIRKeysetMetaData
{
public:
  AcerTV1(
    QObject *guiObject,
    unsigned int index);
};

class AcerPC1: public PIRKeysetMetaData
{
public:
  AcerPC1(
    QObject *guiObject,
    unsigned int index);
};

#endif // ACER_H
