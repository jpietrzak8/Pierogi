#ifndef AIWA_H
#define AIWA_H

#include "pirkeysetmetadata.h"

class QObject;

class AiwaVCR1: public PIRKeysetMetaData
{
public:
  AiwaVCR1(
    QObject *guiObject,
    unsigned int index);
};

class AiwaVCR2: public PIRKeysetMetaData
{
public:
  AiwaVCR2(
    QObject *guiObject,
    unsigned int index);
};

class AiwaVCR3: public PIRKeysetMetaData
{
public:
  AiwaVCR3(
    QObject *guiObject,
    unsigned int index);
};

class AiwaAudio1: public PIRKeysetMetaData
{
public:
  AiwaAudio1(
    QObject *guiObject,
    unsigned int index);
};

class AiwaAudio1a: public AiwaAudio1
{
public:
  AiwaAudio1a(
    QObject *guiObject,
    unsigned int index);
};

class AiwaAudio2: public PIRKeysetMetaData
{
public:
  AiwaAudio2(
    QObject *guiObject,
    unsigned int index);
};

class AiwaAudio2a: public AiwaAudio2
{
public:
  AiwaAudio2a(
    QObject *guiObject,
    unsigned int index);
};

class AiwaAudio2b: public AiwaAudio2
{
public:
  AiwaAudio2b(
    QObject *guiObject,
    unsigned int index);
};

class AiwaAudio2c: public AiwaAudio2
{
public:
  AiwaAudio2c(
    QObject *guiObject,
    unsigned int index);
};

class AiwaAudio3: public PIRKeysetMetaData
{
public:
  AiwaAudio3(
    QObject *guiObject,
    unsigned int index);
};

class AiwaAudio4: public PIRKeysetMetaData
{
public:
  AiwaAudio4(
    QObject *guiObject,
    unsigned int index);
};

class AiwaAudio5: public PIRKeysetMetaData
{
public:
  AiwaAudio5(
    QObject *guiObject,
    unsigned int index);
};

class AiwaAudio6: public PIRKeysetMetaData
{
public:
  AiwaAudio6(
    QObject *guiObject,
    unsigned int index);
};

class AiwaCarStereo1: public PIRKeysetMetaData
{
public:
  AiwaCarStereo1(
    QObject *guiObject,
    unsigned int index);
};

class AiwaDVD1: public PIRKeysetMetaData
{
public:
  AiwaDVD1(
    QObject *guiObject,
    unsigned int index);
};

#endif // AIWA_H
