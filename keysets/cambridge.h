#ifndef CAMBRIDGE_H
#define CAMBRIDGE_H

#include "pirkeysetmetadata.h"

class QObject;

class CambridgeCD1: public PIRKeysetMetaData
{
public:
  CambridgeCD1(
    QObject *guiObject,
    unsigned int index);
};

class CambridgeAudio1: public PIRKeysetMetaData
{
public:
  CambridgeAudio1(
    QObject *guiObject,
    unsigned int index);
};

class CambridgeAudio2: public PIRKeysetMetaData
{
public:
  CambridgeAudio2(
    QObject *guiObject,
    unsigned int index);
};

class CambridgeAudio3: public PIRKeysetMetaData
{
public:
  CambridgeAudio3(
    QObject *guiObject,
    unsigned int index);
};

class CambridgeDVD1: public PIRKeysetMetaData
{
public:
  CambridgeDVD1(
    QObject *guiObject,
    unsigned int index);
};

#endif // CAMBRIDGE_H
