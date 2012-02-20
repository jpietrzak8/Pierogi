#ifndef HUAWEI_H
#define HUAWEI_H

#include "pirkeysetmetadata.h"

class QObject;

class HuaweiSTB1: public PIRKeysetMetaData
{
public:
  HuaweiSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HuaweiSTB2: public PIRKeysetMetaData
{
public:
  HuaweiSTB2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // HUAWEI_H
