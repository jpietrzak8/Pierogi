#ifndef SHARP_H
#define SHARP_H

#include "pirkeysetmetadata.h"

class QObject;

class SharpTV1: public PIRKeysetMetaData
{
public:
  SharpTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SharpTV1a: public SharpTV1
{
public:
  SharpTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SharpTV1b: public SharpTV1
{
public:
  SharpTV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SharpTV1c: public SharpTV1
{
public:
  SharpTV1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SharpTV1d: public SharpTV1
{
public:
  SharpTV1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SharpTV1e: public SharpTV1
{
public:
  SharpTV1e(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SharpVCR1: public PIRKeysetMetaData
{
public:
  SharpVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SharpReceiver1: public PIRKeysetMetaData
{
public:
  SharpReceiver1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SharpAC1: public PIRKeysetMetaData
{
public:
  SharpAC1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // SHARP_H
