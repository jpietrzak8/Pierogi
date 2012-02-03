#ifndef PIONEER_H
#define PIONEER_H

#include "pirkeysetmetadata.h"
#include <QObject>

class PioneerTV1: public PIRKeysetMetaData
{
public:
  PioneerTV1(
    QObject *guiObject,
    unsigned int index);
};

class PioneerTV2: public PIRKeysetMetaData
{
public:
  PioneerTV2(
    QObject *guiObject,
    unsigned int index);
};

class PioneerTV3: public PIRKeysetMetaData
{
public:
  PioneerTV3(
    QObject *guiObject,
    unsigned int index);
};

class PioneerAudio1: public PIRKeysetMetaData
{
public:
  PioneerAudio1(
    QObject *guiObject,
    unsigned int index);
};

class PioneerAudio1a: public PioneerAudio1
{
public:
  PioneerAudio1a(
    QObject *guiObject,
    unsigned int index);
};

class PioneerAudio2: public PIRKeysetMetaData
{
public:
  PioneerAudio2(
    QObject *guiObject,
    unsigned int index);
};

class PioneerAudio3: public PIRKeysetMetaData
{
public:
  PioneerAudio3(
    QObject *guiObject,
    unsigned int index);
};

class PioneerAudio4: public PIRKeysetMetaData
{
public:
  PioneerAudio4(
    QObject *guiObject,
    unsigned int index);
};

class PioneerAudio5: public PIRKeysetMetaData
{
public:
  PioneerAudio5(
    QObject *guiObject,
    unsigned int index);
};

class PioneerCD1: public PIRKeysetMetaData
{
public:
  PioneerCD1(
    QObject *guiObject,
    unsigned int index);
};

class PioneerLaserDisc1: public PIRKeysetMetaData
{
public:
  PioneerLaserDisc1(
    QObject *guiObject,
    unsigned int index);
};

class PioneerDVD1: public PIRKeysetMetaData
{
public:
  PioneerDVD1(
    QObject *guiObject,
    unsigned int index);
};

#endif // PIONEER_H
