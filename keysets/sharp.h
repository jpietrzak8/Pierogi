#ifndef SHARP_H
#define SHARP_H

#include "pirkeysetmetadata.h"

#include <QObject>

class SharpTV1: public PIRKeysetMetaData
{
public:
  SharpTV1(
    QObject *guiObject,
    unsigned int index);
};

class SharpTV1a: public SharpTV1
{
public:
  SharpTV1a(
    QObject *guiObject,
    unsigned int index);
};

class SharpTV1b: public SharpTV1
{
public:
  SharpTV1b(
    QObject *guiObject,
    unsigned int index);
};

class SharpTV1c: public SharpTV1
{
public:
  SharpTV1c(
    QObject *guiObject,
    unsigned int index);
};

class SharpTV1d: public SharpTV1
{
public:
  SharpTV1d(
    QObject *guiObject,
    unsigned int index);
};

class SharpTV1e: public SharpTV1
{
public:
  SharpTV1e(
    QObject *guiObject,
    unsigned int index);
};

class SharpVCR1: public PIRKeysetMetaData
{
public:
  SharpVCR1(
    QObject *guiObject,
    unsigned int index);
};


class SharpReceiver1: public PIRKeysetMetaData
{
public:
  SharpReceiver1(
    QObject *guiObject,
    unsigned int index);
};

#endif // SHARP_H
