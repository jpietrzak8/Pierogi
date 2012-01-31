#ifndef SANYO_H
#define SANYO_H

#include "pirkeysetmetadata.h"

#include <QObject>

class SanyoVCR1: public PIRKeysetMetaData
{
public:
  SanyoVCR1(
    QObject *guiObject,
    unsigned int index);
};

class SanyoDVD1: public PIRKeysetMetaData
{
public:
  SanyoDVD1(
    QObject *guiObject,
    unsigned int index);
};

class SanyoTV1: public PIRKeysetMetaData
{
public:
  SanyoTV1(
    QObject *guiObject,
    unsigned int index);
};

class SanyoTV1a: public SanyoTV1
{
public:
  SanyoTV1a(
    QObject *guiObject,
    unsigned int index);
};

class SanyoTV1b: public SanyoTV1
{
public:
  SanyoTV1b(
    QObject *guiObject,
    unsigned int index);
};

class SanyoTV1c: public SanyoTV1
{
public:
  SanyoTV1c(
    QObject *guiObject,
    unsigned int index);
};

class SanyoTV1d: public SanyoTV1a
{
public:
  SanyoTV1d(
    QObject *guiObject,
    unsigned int index);
};

class SanyoTV1e: public SanyoTV1
{
public:
  SanyoTV1e(
    QObject *guiObject,
    unsigned int index);
};

class SanyoProjector: public PIRKeysetMetaData
{
public:
  SanyoProjector(
    QObject *guiObject,
    unsigned int index);
};

#endif // SANYO_H
