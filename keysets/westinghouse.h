#ifndef WESTINGHOUSE_H
#define WESTINGHOUSE_H

#include "pirkeysetmetadata.h"

#include <QObject>

class WestinghouseTV1: public PIRKeysetMetaData
{
public:
  WestinghouseTV1(
    QObject *guiObject,
    unsigned int index);
};

class WestinghouseTV2: public PIRKeysetMetaData
{
public:
  WestinghouseTV2(
    QObject *guiObject,
    unsigned int index);
};

#endif // WESTINGHOUSE_H
