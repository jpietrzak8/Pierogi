#ifndef LG_H
#define LG_H

#include "pirkeysetmetadata.h"

#include <QObject>

class LGTV1: public PIRKeysetMetaData
{
public:
  LGTV1(
    QObject *guiObject,
    unsigned int index);
};

class LGTV1a: public LGTV1
{
public:
  LGTV1a(
    QObject *guiObject,
    unsigned int index);
};

class LGTV1b: public LGTV1
{
public:
  LGTV1b(
    QObject *guiObject,
    unsigned int index);
};

class LGTV1c: public LGTV1
{
public:
  LGTV1c(
    QObject *guiObject,
    unsigned int index);
};

class LGTV2: public PIRKeysetMetaData
{
public:
  LGTV2(
    QObject *guiObject,
    unsigned int index);
};

class LGTV2a: public LGTV2
{
public:
  LGTV2a(
    QObject *guiObject,
    unsigned int index);
};

class LGTV2b: public LGTV2
{
public:
  LGTV2b(
    QObject *guiObject,
    unsigned int index);
};

class LGDisc1: public PIRKeysetMetaData
{
public:
  LGDisc1(
    QObject *guiObject,
    unsigned int index);
};

class LGDisc2: public PIRKeysetMetaData
{
public:
  LGDisc2(
    QObject *guiObject,
    unsigned int index);
};

class LGDisc2a: public LGDisc2
{
public:
  LGDisc2a(
    QObject *guiObject,
    unsigned int index);
};

class LGVCR1: public PIRKeysetMetaData
{
public:
  LGVCR1(
    QObject *guiObject,
    unsigned int index);
};

class LGVCR1a: public LGVCR1
{
public:
  LGVCR1a(
    QObject *guiObject,
    unsigned int index);
};

class LGVCR1b: public LGVCR1
{
public:
  LGVCR1b(
    QObject *guiObject,
    unsigned int index);
};

#endif // LG_H
