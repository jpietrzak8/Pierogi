#ifndef SAMSUNG_H
#define SAMSUNG_H

#include "pirkeysetmetadata.h"

class QObject;

class SamsungTV1: public PIRKeysetMetaData
{
public:
  SamsungTV1(
    QObject *guiObject,
    unsigned int index);
};


class SamsungTV1a: public SamsungTV1
{
public:
  SamsungTV1a(
    QObject *guiObject,
    unsigned int index);
};


class SamsungTV1b: public SamsungTV1
{
public:
  SamsungTV1b(
    QObject *guiObject,
    unsigned int index);
};


class SamsungTV1c: public SamsungTV1
{
public:
  SamsungTV1c(
    QObject *guiObject,
    unsigned int index);
};


class SamsungTV1d: public SamsungTV1
{
public:
  SamsungTV1d(
    QObject *guiObject,
    unsigned int index);
};


class SamsungTV1e: public SamsungTV1
{
public:
  SamsungTV1e(
    QObject *guiObject,
    unsigned int index);
};


class SamsungTV1f: public SamsungTV1
{
public:
  SamsungTV1f(
    QObject *guiObject,
    unsigned int index);
};


class SamsungTV2: public PIRKeysetMetaData
{
public:
  SamsungTV2(
    QObject *guiObject,
    unsigned int index);
};

class SamsungTV2a: public SamsungTV2
{
public:
  SamsungTV2a(
    QObject *guiObject,
    unsigned int index);
};

class SamsungVCR1: public PIRKeysetMetaData
{
public:
  SamsungVCR1(
    QObject *guiObject,
    unsigned int index);
};


class SamsungVCR1a: public SamsungVCR1
{
public:
  SamsungVCR1a(
    QObject *guiObject,
    unsigned int index);
};

class SamsungVCR1b: public SamsungVCR1
{
public:
  SamsungVCR1b(
    QObject *guiObject,
    unsigned int index);
};

class SamsungVCR1c: public SamsungVCR1a
{
public:
  SamsungVCR1c(
    QObject *guiObject,
    unsigned int index);
};

class SamsungVCR1d: public SamsungVCR1
{
public:
  SamsungVCR1d(
    QObject *guiObject,
    unsigned int index);
};

class SamsungVCR1e: public SamsungVCR1
{
public:
  SamsungVCR1e(
    QObject *guiObject,
    unsigned int index);
};

class SamsungDVD1: public PIRKeysetMetaData
{
public:
  SamsungDVD1(
    QObject *guiObject,
    unsigned int index);
};

class SamsungDVD1a: public SamsungDVD1
{
public:
  SamsungDVD1a(
    QObject *guiObject,
    unsigned int index);
};

class SamsungDVD1b: public SamsungDVD1
{
public:
  SamsungDVD1b(
    QObject *guiObject,
    unsigned int index);
};

class SamsungDVD2: public PIRKeysetMetaData
{
public:
  SamsungDVD2(
    QObject *guiObject,
    unsigned int index);
};

class SamsungAC1: public PIRKeysetMetaData
{
public:
  SamsungAC1(
    QObject *guiObject,
    unsigned int index);
};

#endif // SAMSUNG_H
