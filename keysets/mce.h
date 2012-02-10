#ifndef MCE_H
#define MCE_H

#include "pirkeysetmetadata.h"

class QObject;

class MCERemote1: public PIRKeysetMetaData
{
public:
  MCERemote1(
    QObject *guiObject,
    unsigned int index);
};

class MCERemote1a: public MCERemote1
{
public:
  MCERemote1a(
    QObject *guiObject,
    unsigned int index);
};

class MCERemote1b: public MCERemote1
{
public:
  MCERemote1b(
    QObject *guiObject,
    unsigned int index);
};

class MCERemote1c: public MCERemote1
{
public:
  MCERemote1c(
    QObject *guiObject,
    unsigned int index);
};

class MCERemote1d: public MCERemote1
{
public:
  MCERemote1d(
    QObject *guiObject,
    unsigned int index);
};

class MCERemote1e: public MCERemote1
{
public:
  MCERemote1e(
    QObject *guiObject,
    unsigned int index);
};

class MCERemote1f: public MCERemote1
{
public:
  MCERemote1f(
    QObject *guiObject,
    unsigned int index);
};

class MCERemote1g: public MCERemote1
{
public:
  MCERemote1g(
    QObject *guiObject,
    unsigned int index);
};

#endif // MCE_H
