#ifndef SANYO_H
#define SANYO_H

#include "pirkeysetmetadata.h"

#include <QObject>

class SanyoVCR1: public PIRKeysetMetaData
{
public:
  SanyoVCR1(
    QObject *guiObject,
    unsigned int index);
};

class SanyoTV1: public PIRKeysetMetaData
{
public:
  SanyoTV1(
    QObject *guiObject,
    unsigned int index);
};

class SanyoTV2: public PIRKeysetMetaData
{
public:
  SanyoTV2(
    QObject *guiObject,
    unsigned int index);
};

#endif // SANYO_H
