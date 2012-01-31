#ifndef TOSHIBA_H
#define TOSHIBA_H

#include "pirkeysetmetadata.h"
#include <QObject>

class ToshibaTV1: public PIRKeysetMetaData
{
public:
  ToshibaTV1(
    QObject *guiObject,
    unsigned int index);
};

class ToshibaTV1a: public ToshibaTV1
{
public:
  ToshibaTV1a(
    QObject *guiObject,
    unsigned int index);
};

class ToshibaTV1b: public ToshibaTV1
{
public:
  ToshibaTV1b(
    QObject *guiObject,
    unsigned int index);
};

class ToshibaTV1c: public ToshibaTV1
{
public:
  ToshibaTV1c(
    QObject *guiObject,
    unsigned int index);
};

class ToshibaTV1d: public ToshibaTV1
{
public:
  ToshibaTV1d(
    QObject *guiObject,
    unsigned int index);
};

class ToshibaTV1e: public ToshibaTV1
{
public:
  ToshibaTV1e(
    QObject *guiObject,
    unsigned int index);
};

class ToshibaTV1f: public ToshibaTV1
{
public:
  ToshibaTV1f(
    QObject *guiObject,
    unsigned int index);
};

class ToshibaTV1g: public ToshibaTV1
{
public:
  ToshibaTV1g(
    QObject *guiObject,
    unsigned int index);
};

class ToshibaVCR1: public PIRKeysetMetaData
{
public:
  ToshibaVCR1(
    QObject *guiObject,
    unsigned int index);
};

class ToshibaVCR1a: public ToshibaVCR1
{
public:
  ToshibaVCR1a(
    QObject *guiObject,
    unsigned int index);
};

class ToshibaDisc1: public PIRKeysetMetaData
{
public:
  ToshibaDisc1(
    QObject *guiObject,
    unsigned int index);
};

class ToshibaDisc1a: public ToshibaDisc1
{
public:
  ToshibaDisc1a(
    QObject *guiObject,
    unsigned int index);
};

class ToshibaDisc1b: public ToshibaDisc1
{
public:
  ToshibaDisc1b(
    QObject *guiObject,
    unsigned int index);
};

class ToshibaDisc1c: public ToshibaDisc1a
{
public:
  ToshibaDisc1c(
    QObject *guiObject,
    unsigned int index);
};

class ToshibaDisc1d: public ToshibaDisc1a
{
public:
  ToshibaDisc1d(
    QObject *guiObject,
    unsigned int index);
};

#endif // TOSHIBA_H
