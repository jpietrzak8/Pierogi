#ifndef PIONEER_H
#define PIONEER_H

#include "pirkeysetmetadata.h"

class QObject;

class PioneerTV1: public PIRKeysetMetaData
{
public:
  PioneerTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PioneerTV2: public PIRKeysetMetaData
{
public:
  PioneerTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PioneerTV3: public PIRKeysetMetaData
{
public:
  PioneerTV3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PioneerAudio1: public PIRKeysetMetaData
{
public:
  PioneerAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PioneerAudio1a: public PioneerAudio1
{
public:
  PioneerAudio1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PioneerAudio2: public PIRKeysetMetaData
{
public:
  PioneerAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PioneerAudio3: public PIRKeysetMetaData
{
public:
  PioneerAudio3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PioneerAudio4: public PIRKeysetMetaData
{
public:
  PioneerAudio4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PioneerAudio5: public PIRKeysetMetaData
{
public:
  PioneerAudio5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PioneerCD1: public PIRKeysetMetaData
{
public:
  PioneerCD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PioneerLaserDisc1: public PIRKeysetMetaData
{
public:
  PioneerLaserDisc1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PioneerDVD1: public PIRKeysetMetaData
{
public:
  PioneerDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PioneerCarStereo1: public PIRKeysetMetaData
{
public:
  PioneerCarStereo1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // PIONEER_H
