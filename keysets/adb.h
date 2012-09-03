#ifndef ADB_H
#define ADB_H

#include "pirkeysetmetadata.h"

class QObject;

class ADBSTB1: public PIRKeysetMetaData
{
public:
  ADBSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class ADBSTB2: public PIRKeysetMetaData
{
public:
  ADBSTB2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class ADBSTB3: public PIRKeysetMetaData
{
public:
  ADBSTB3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class ADBSTB4: public PIRKeysetMetaData
{
public:
  ADBSTB4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // ADB_H
