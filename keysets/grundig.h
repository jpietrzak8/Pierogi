#ifndef GRUNDIG_H
#define GRUNDIG_H

#include "pirkeysetmetadata.h"

class QObject;

class GrundigSat1: public PIRKeysetMetaData
{
public:
  GrundigSat1(
    QObject *guiObject,
    unsigned int index);
};

class GrundigSat2: public PIRKeysetMetaData
{
public:
  GrundigSat2(
    QObject *guiObject,
    unsigned int index);
};

class GrundigAmp1: public PIRKeysetMetaData
{
public:
  GrundigAmp1(
    QObject *guiObject,
    unsigned int index);
};

class GrundigAudio1: public PIRKeysetMetaData
{
public:
  GrundigAudio1(
    QObject *guiObject,
    unsigned int index);
};

class GrundigAudio2: public PIRKeysetMetaData
{
public:
  GrundigAudio2(
    QObject *guiObject,
    unsigned int index);
};

class GrundigVCR1: public PIRKeysetMetaData
{
public:
  GrundigVCR1(
    QObject *guiObject,
    unsigned int index);
};

class GrundigVCR1a: public GrundigVCR1
{
public:
  GrundigVCR1a(
    QObject *guiObject,
    unsigned int index);
};

class GrundigTV1: public PIRKeysetMetaData
{
public:
  GrundigTV1(
    QObject *guiObject,
    unsigned int index);
};

class GrundigTV2: public PIRKeysetMetaData
{
public:
  GrundigTV2(
    QObject *guiObject,
    unsigned int index);
};

class GrundigTV3: public PIRKeysetMetaData
{
public:
  GrundigTV3(
    QObject *guiObject,
    unsigned int index);
};

class GrundigDVD1: public PIRKeysetMetaData
{
public:
  GrundigDVD1(
    QObject *guiObject,
    unsigned int index);
};

#endif // GRUNDIG_H
