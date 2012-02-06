#ifndef YAMAHA_H
#define YAMAHA_H

#include "pirkeysetmetadata.h"

class QObject;

class YamahaDVD1: public PIRKeysetMetaData
{
public:
  YamahaDVD1(
    QObject *guiObject,
    unsigned int index);
};

class YamahaDVD1a: public YamahaDVD1
{
public:
  YamahaDVD1a(
    QObject *guiObject,
    unsigned int index);
};

class YamahaAudio1: public PIRKeysetMetaData
{
public:
  YamahaAudio1(
    QObject *guiObject,
    unsigned int index);
};

class YamahaAudio1a: public YamahaAudio1
{
public:
  YamahaAudio1a(
    QObject *guiObject,
    unsigned int index);
};

class YamahaAudio2: public PIRKeysetMetaData
{
public:
  YamahaAudio2(
    QObject *guiObject,
    unsigned int index);
};

class YamahaAudio2a: public YamahaAudio2
{
public:
  YamahaAudio2a(
    QObject *guiObject,
    unsigned int index);
};

class YamahaAudio2b: public YamahaAudio2
{
public:
  YamahaAudio2b(
    QObject *guiObject,
    unsigned int index);
};

class YamahaAudio2c: public YamahaAudio2
{
public:
  YamahaAudio2c(
    QObject *guiObject,
    unsigned int index);
};

class YamahaAudio2d: public YamahaAudio2
{
public:
  YamahaAudio2d(
    QObject *guiObject,
    unsigned int index);
};

class YamahaAudio3: public PIRKeysetMetaData
{
public:
  YamahaAudio3(
    QObject *guiObject,
    unsigned int index);
};

class YamahaAudio4: public PIRKeysetMetaData
{
public:
  YamahaAudio4(
    QObject *guiObject,
    unsigned int index);
};

class YamahaTV1: public PIRKeysetMetaData
{
public:
  YamahaTV1(
    QObject *guiObject,
    unsigned int index);
};

class YamahaKaraoke1: public PIRKeysetMetaData
{
public:
  YamahaKaraoke1(
    QObject *guiObject,
    unsigned int index);
};

#endif // YAMAHA_H
