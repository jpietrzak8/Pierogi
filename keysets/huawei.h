#ifndef HUAWEI_H
#define HUAWEI_H

#include "pirkeysetmetadata.h"

class QObject;

class HuaweiSTB1: public PIRKeysetMetaData
{
public:
  HuaweiSTB1(
    QObject *guiObject,
    unsigned int index);
};

class HuaweiSTB2: public PIRKeysetMetaData
{
public:
  HuaweiSTB2(
    QObject *guiObject,
    unsigned int index);
};

#endif // HUAWEI_H
