#ifndef MAGNAVOX_H
#define MAGNAVOX_H

#include "pirkeysetmetadata.h"
#include <QObject>

class MagnavoxDVD1: public PIRKeysetMetaData
{
public:
  MagnavoxDVD1(
    QObject *guiObject,
    unsigned int index);
};

class MagnavoxVCR1: public PIRKeysetMetaData
{
public:
  MagnavoxVCR1(
    QObject *guiObject,
    unsigned int index);
};

class MagnavoxConverterBox1: public PIRKeysetMetaData
{
public:
  MagnavoxConverterBox1(
    QObject *guiObject,
    unsigned int index);
};

class MagnavoxTV1: public PIRKeysetMetaData
{
public:
  MagnavoxTV1(
    QObject *guiObject,
    unsigned int index);
};

#endif // MAGNAVOX_H
