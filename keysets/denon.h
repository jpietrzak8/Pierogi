#ifndef DENON_H
#define DENON_H

#include "pirkeysetmetadata.h"

class QObject;

class DenonDVD1: public PIRKeysetMetaData
{
public:
  DenonDVD1(
    QObject *guiObject,
    unsigned int index);
};

class DenonDVD2: public PIRKeysetMetaData
{
public:
  DenonDVD2(
    QObject *guiObject,
    unsigned int index);
};

class DenonDVD3: public PIRKeysetMetaData
{
public:
  DenonDVD3(
    QObject *guiObject,
    unsigned int index);
};

class DenonReceiver1: public PIRKeysetMetaData
{
public:
  DenonReceiver1(
    QObject *guiObject,
    unsigned int index);
};

class DenonReceiver1a: public DenonReceiver1
{
public:
  DenonReceiver1a(
    QObject *guiObject,
    unsigned int index);
};

class DenonReceiver1b: public DenonReceiver1
{
public:
  DenonReceiver1b(
    QObject *guiObject,
    unsigned int index);
};

class DenonReceiver1c: public DenonReceiver1
{
public:
  DenonReceiver1c(
    QObject *guiObject,
    unsigned int index);
};

class DenonReceiver1d: public DenonReceiver1c
{
public:
  DenonReceiver1d(
    QObject *guiObject,
    unsigned int index);
};

class DenonReceiver1e: public DenonReceiver1d
{
public:
  DenonReceiver1e(
    QObject *guiObject,
    unsigned int index);
};

class DenonReceiver1f: public DenonReceiver1c
{
public:
  DenonReceiver1f(
    QObject *guiObject,
    unsigned int index);
};

class DenonReceiver2: public PIRKeysetMetaData
{
public:
  DenonReceiver2(
    QObject *guiObject,
    unsigned int index);
};

class DenonReceiver2a: public DenonReceiver2
{
public:
  DenonReceiver2a(
    QObject *guiObject,
    unsigned int index);
};

class DenonReceiver3: public PIRKeysetMetaData
{
public:
  DenonReceiver3(
    QObject *guiObject,
    unsigned int index);
};

class DenonAudio1: public PIRKeysetMetaData
{
public:
  DenonAudio1(
    QObject *guiObject,
    unsigned int index);
};

class DenonAudio1a: public DenonAudio1
{
public:
  DenonAudio1a(
    QObject *guiObject,
    unsigned int index);
};

class DenonAudio1b: public DenonAudio1
{
public:
  DenonAudio1b(
    QObject *guiObject,
    unsigned int index);
};

class DenonAudio1c: public DenonAudio1b
{
public:
  DenonAudio1c(
    QObject *guiObject,
    unsigned int index);
};

class DenonAudio1d: public DenonAudio1
{
public:
  DenonAudio1d(
    QObject *guiObject,
    unsigned int index);
};

class DenonAudio2: public PIRKeysetMetaData
{
public:
  DenonAudio2(
    QObject *guiObject,
    unsigned int index);
};

class DenonAudio3: public PIRKeysetMetaData
{
public:
  DenonAudio3(
    QObject *guiObject,
    unsigned int index);
};

class DenonAudio4: public PIRKeysetMetaData
{
public:
  DenonAudio4(
    QObject *guiObject,
    unsigned int index);
};

#endif // DENON_H
