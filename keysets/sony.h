#ifndef SONY_H
#define SONY_H

#include "pirkeysetmetadata.h"

class QObject;

class SonyTV1: public PIRKeysetMetaData
{
public:
  SonyTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyTV1a: public SonyTV1
{
public:
  SonyTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyTV1b: public SonyTV1a
{
public:
  SonyTV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyTV1c: public SonyTV1
{
public:
  SonyTV1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyTV2: public PIRKeysetMetaData
{
public:
  SonyTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyAmp1: public PIRKeysetMetaData
{
public:
  SonyAmp1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyAmp2: public PIRKeysetMetaData
{
public:
  SonyAmp2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyAudio1: public PIRKeysetMetaData
{
public:
  SonyAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyAudio1a: public SonyAudio1
{
public:
  SonyAudio1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyDAT1: public PIRKeysetMetaData
{
public:
  SonyDAT1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyDVD1: public PIRKeysetMetaData
{
public:
  SonyDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyDVD1a: public SonyDVD1
{
public:
  SonyDVD1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyDVD1b: public SonyDVD1
{
public:
  SonyDVD1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyDVD2: public PIRKeysetMetaData
{
public:
  SonyDVD2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyDVD2a: public SonyDVD2
{
public:
  SonyDVD2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyVCR1: public PIRKeysetMetaData
{
public:
  SonyVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyVCR1a: public SonyVCR1
{
public:
  SonyVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyVCR1b: public SonyVCR1a
{
public:
  SonyVCR1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyReceiver1: public PIRKeysetMetaData
{
public:
  SonyReceiver1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class SonyCD1: public PIRKeysetMetaData
{
public:
  SonyCD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SonyCD1a: public SonyCD1
{
public:
  SonyCD1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SonyCD1b: public SonyCD1
{
public:
  SonyCD1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SonyProjector1: public PIRKeysetMetaData
{
public:
  SonyProjector1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SonyProjector1a: public SonyProjector1
{
public:
  SonyProjector1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SonyPlaystation1: public SonyDVD1
{
public:
  SonyPlaystation1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // SONY_H
