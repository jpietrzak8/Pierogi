#ifndef YAMAHA_H
#define YAMAHA_H

#include "pirkeysetmetadata.h"

class QObject;

class YamahaDVD1: public PIRKeysetMetaData
{
public:
  YamahaDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaDVD1a: public YamahaDVD1
{
public:
  YamahaDVD1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaAudio1: public PIRKeysetMetaData
{
public:
  YamahaAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaAudio1a: public YamahaAudio1
{
public:
  YamahaAudio1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaAudio2: public PIRKeysetMetaData
{
public:
  YamahaAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaAudio2a: public YamahaAudio2
{
public:
  YamahaAudio2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaAudio2b: public YamahaAudio2
{
public:
  YamahaAudio2b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaAudio2c: public YamahaAudio2
{
public:
  YamahaAudio2c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaAudio2d: public YamahaAudio2
{
public:
  YamahaAudio2d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaAudio3: public PIRKeysetMetaData
{
public:
  YamahaAudio3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaAudio4: public PIRKeysetMetaData
{
public:
  YamahaAudio4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaTV1: public PIRKeysetMetaData
{
public:
  YamahaTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class YamahaKaraoke1: public PIRKeysetMetaData
{
public:
  YamahaKaraoke1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // YAMAHA_H
