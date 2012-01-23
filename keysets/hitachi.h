#ifndef HITACHI_H
#define HITACHI_H

#include "pirkeysetmetadata.h"
#include <QObject>

class HitachiTV1: public PIRKeysetMetaData
{
public:
  HitachiTV1(
    QObject *guiObject,
    unsigned int index);
};

class HitachiTV1a: public HitachiTV1
{
public:
  HitachiTV1a(
    QObject *guiObject,
    unsigned int index);
};

class HitachiTV1b: public HitachiTV1a
{
public:
  HitachiTV1b(
    QObject *guiObject,
    unsigned int index);
};

class HitachiTV1c: public HitachiTV1
{
public:
  HitachiTV1c(
    QObject *guiObject,
    unsigned int index);
};

class HitachiProjector: public PIRKeysetMetaData
{
public:
  HitachiProjector(
    QObject *guiObject,
    unsigned int index);
};

class HitachiDVD1: public PIRKeysetMetaData
{
public:
  HitachiDVD1(
    QObject *guiObject,
    unsigned int index);
};

class HitachiAudio1: public PIRKeysetMetaData
{
public:
  HitachiAudio1(
    QObject *guiObject,
    unsigned int index);
};

class HitachiVCR1: public PIRKeysetMetaData
{
public:
  HitachiVCR1(
    QObject *guiObject,
    unsigned int index);
};

#endif // HITACHI_H
