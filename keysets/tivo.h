#ifndef TIVO_H
#define TIVO_H

#include "pirkeysetmetadata.h"

class QObject;

class Tivo1: public PIRKeysetMetaData
{
public:
  Tivo1(
    QObject *guiObject,
    unsigned int index);
};

class Tivo1a: public Tivo1
{
public:
  Tivo1a(
    QObject *guiObject,
    unsigned int index);
};

class Tivo1b: public Tivo1
{
public:
  Tivo1b(
    QObject *guiObject,
    unsigned int index);
};

class Tivo1c: public Tivo1
{
public:
  Tivo1c(
    QObject *guiObject,
    unsigned int index);
};

class Tivo1d: public Tivo1
{
public:
  Tivo1d(
    QObject *guiObject,
    unsigned int index);
};

#endif // TIVO_H
