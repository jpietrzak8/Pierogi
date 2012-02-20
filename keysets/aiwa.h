#ifndef AIWA_H
#define AIWA_H

#include "pirkeysetmetadata.h"

class QObject;

class AiwaVCR1: public PIRKeysetMetaData
{
public:
  AiwaVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaVCR2: public PIRKeysetMetaData
{
public:
  AiwaVCR2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaVCR3: public PIRKeysetMetaData
{
public:
  AiwaVCR3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaAudio1: public PIRKeysetMetaData
{
public:
  AiwaAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaAudio1a: public AiwaAudio1
{
public:
  AiwaAudio1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaAudio2: public PIRKeysetMetaData
{
public:
  AiwaAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaAudio2a: public AiwaAudio2
{
public:
  AiwaAudio2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaAudio2b: public AiwaAudio2
{
public:
  AiwaAudio2b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaAudio2c: public AiwaAudio2
{
public:
  AiwaAudio2c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaAudio3: public PIRKeysetMetaData
{
public:
  AiwaAudio3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaAudio4: public PIRKeysetMetaData
{
public:
  AiwaAudio4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaAudio5: public PIRKeysetMetaData
{
public:
  AiwaAudio5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaAudio6: public PIRKeysetMetaData
{
public:
  AiwaAudio6(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaCarStereo1: public PIRKeysetMetaData
{
public:
  AiwaCarStereo1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AiwaDVD1: public PIRKeysetMetaData
{
public:
  AiwaDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // AIWA_H
