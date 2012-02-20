#ifndef DENON_H
#define DENON_H

#include "pirkeysetmetadata.h"

class QObject;

class DenonDVD1: public PIRKeysetMetaData
{
public:
  DenonDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonDVD2: public PIRKeysetMetaData
{
public:
  DenonDVD2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonDVD3: public PIRKeysetMetaData
{
public:
  DenonDVD3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonReceiver1: public PIRKeysetMetaData
{
public:
  DenonReceiver1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonReceiver1a: public DenonReceiver1
{
public:
  DenonReceiver1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonReceiver1b: public DenonReceiver1
{
public:
  DenonReceiver1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonReceiver1c: public DenonReceiver1
{
public:
  DenonReceiver1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonReceiver1d: public DenonReceiver1c
{
public:
  DenonReceiver1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonReceiver1e: public DenonReceiver1d
{
public:
  DenonReceiver1e(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonReceiver1f: public DenonReceiver1c
{
public:
  DenonReceiver1f(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonReceiver2: public PIRKeysetMetaData
{
public:
  DenonReceiver2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonReceiver2a: public DenonReceiver2
{
public:
  DenonReceiver2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonReceiver3: public PIRKeysetMetaData
{
public:
  DenonReceiver3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonAudio1: public PIRKeysetMetaData
{
public:
  DenonAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonAudio1a: public DenonAudio1
{
public:
  DenonAudio1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonAudio1b: public DenonAudio1
{
public:
  DenonAudio1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonAudio1c: public DenonAudio1b
{
public:
  DenonAudio1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonAudio1d: public DenonAudio1
{
public:
  DenonAudio1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonAudio2: public PIRKeysetMetaData
{
public:
  DenonAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonAudio3: public PIRKeysetMetaData
{
public:
  DenonAudio3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DenonAudio4: public PIRKeysetMetaData
{
public:
  DenonAudio4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // DENON_H
