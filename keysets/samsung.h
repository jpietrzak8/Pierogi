#ifndef SAMSUNG_H
#define SAMSUNG_H

#include "pirkeysetmetadata.h"

class QObject;

class SamsungTV1: public PIRKeysetMetaData
{
public:
  SamsungTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SamsungTV1a: public SamsungTV1
{
public:
  SamsungTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SamsungTV1b: public SamsungTV1
{
public:
  SamsungTV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SamsungTV1c: public SamsungTV1
{
public:
  SamsungTV1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SamsungTV1d: public SamsungTV1
{
public:
  SamsungTV1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SamsungTV1e: public SamsungTV1
{
public:
  SamsungTV1e(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SamsungTV1f: public SamsungTV1
{
public:
  SamsungTV1f(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SamsungTV2: public PIRKeysetMetaData
{
public:
  SamsungTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungTV2a: public SamsungTV2
{
public:
  SamsungTV2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungVCR1: public PIRKeysetMetaData
{
public:
  SamsungVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SamsungVCR1a: public SamsungVCR1
{
public:
  SamsungVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungVCR1b: public SamsungVCR1
{
public:
  SamsungVCR1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungVCR1c: public SamsungVCR1a
{
public:
  SamsungVCR1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungVCR1d: public SamsungVCR1
{
public:
  SamsungVCR1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungVCR1e: public SamsungVCR1
{
public:
  SamsungVCR1e(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungDVD1: public PIRKeysetMetaData
{
public:
  SamsungDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungDVD1a: public SamsungDVD1
{
public:
  SamsungDVD1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungDVD1b: public SamsungDVD1
{
public:
  SamsungDVD1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungDVD2: public PIRKeysetMetaData
{
public:
  SamsungDVD2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungAC1: public PIRKeysetMetaData
{
public:
  SamsungAC1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SamsungDVBT1: public PIRKeysetMetaData
{
public:
  SamsungDVBT1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // SAMSUNG_H
