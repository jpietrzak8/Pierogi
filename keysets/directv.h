#ifndef DIRECTV_H
#define DIRECTV_H

#include "pirkeysetmetadata.h"
#include "protocols/directvprotocol.h"

class QObject;

class DirectvReceiver1: public PIRKeysetMetaData
{
public:
  DirectvReceiver1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);

protected:
  void dtvPopulateProtocol(
    QObject *guiObject,
    DirectvGapSize gap,
    DirectvFreq freq);
};

class DirectvReceiver1a: public DirectvReceiver1
{
public:
  DirectvReceiver1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DirectvReceiver1b: public DirectvReceiver1
{
public:
  DirectvReceiver1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DirectvReceiver1c: public DirectvReceiver1
{
public:
  DirectvReceiver1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DirectvReceiver1d: public DirectvReceiver1
{
public:
  DirectvReceiver1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DirectvReceiver1e: public DirectvReceiver1
{
public:
  DirectvReceiver1e(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // DIRECTV_H
