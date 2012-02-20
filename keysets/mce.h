#ifndef MCE_H
#define MCE_H

#include "pirkeysetmetadata.h"

class QObject;

class MCERemote1: public PIRKeysetMetaData
{
public:
  MCERemote1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MCERemote1a: public MCERemote1
{
public:
  MCERemote1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MCERemote1b: public MCERemote1
{
public:
  MCERemote1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MCERemote1c: public MCERemote1
{
public:
  MCERemote1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MCERemote1d: public MCERemote1
{
public:
  MCERemote1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MCERemote1e: public MCERemote1
{
public:
  MCERemote1e(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MCERemote1f: public MCERemote1
{
public:
  MCERemote1f(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MCERemote1g: public MCERemote1
{
public:
  MCERemote1g(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // MCE_H
