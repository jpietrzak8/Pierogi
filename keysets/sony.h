#ifndef SONY_H
#define SONY_H

#include "pirkeysetmetadata.h"

#include <QObject>

class SonyTV1: public PIRKeysetMetaData
{
public:
  SonyTV1(
    QObject *guiObject,
    unsigned int index);
};


class SonyTV1a: public SonyTV1
{
public:
  SonyTV1a(
    QObject *guiObject,
    unsigned int index);
};


class SonyTV1b: public SonyTV1
{
public:
  SonyTV1b(
    QObject *guiObject,
    unsigned int index);
};


class SonyTV1d: public SonyTV1a
{
public:
  SonyTV1d(
    QObject *guiObject,
    unsigned int index);
};


class SonyAmp1: public PIRKeysetMetaData
{
public:
  SonyAmp1(
    QObject *guiObject,
    unsigned int index);
};


class SonyAmp2: public PIRKeysetMetaData
{
public:
  SonyAmp2(
    QObject *guiObject,
    unsigned int index);
};


class SonyCD1: public PIRKeysetMetaData
{
public:
  SonyCD1(
    QObject *guiObject,
    unsigned int index);
};


class SonyCD1a: public SonyCD1
{
public:
  SonyCD1a(
    QObject *guiObject,
    unsigned int index);
};


class SonyCD2: public PIRKeysetMetaData
{
public:
  SonyCD2(
    QObject *guiObject,
    unsigned int index);
};


class SonyCD3: public PIRKeysetMetaData
{
public:
  SonyCD3(
    QObject *guiObject,
    unsigned int index);
};


class SonyDAT1: public PIRKeysetMetaData
{
public:
  SonyDAT1(
    QObject *guiObject,
    unsigned int index);
};


class SonyDVD1: public PIRKeysetMetaData
{
public:
  SonyDVD1(
    QObject *guiObject,
    unsigned int index);
};


class SonyDVD1a: public SonyDVD1
{
public:
  SonyDVD1a(
    QObject *guiObject,
    unsigned int index);
};


class SonyDVD1b: public SonyDVD1
{
public:
  SonyDVD1b(
    QObject *guiObject,
    unsigned int index);
};


class SonyDVD1c: public SonyDVD1
{
public:
  SonyDVD1c(
    QObject *guiObject,
    unsigned int index);
};


class SonyVCR1: public PIRKeysetMetaData
{
public:
  SonyVCR1(
    QObject *guiObject,
    unsigned int index);
};


class SonyVCR1a: public SonyVCR1
{
public:
  SonyVCR1a(
    QObject *guiObject,
    unsigned int index);
};


class SonyReceiver1: public PIRKeysetMetaData
{
public:
  SonyReceiver1(
    QObject *guiObject,
    unsigned int index);
};

#endif // SONY_H
