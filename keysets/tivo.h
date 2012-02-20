#ifndef TIVO_H
#define TIVO_H

#include "pirkeysetmetadata.h"

class QObject;

class Tivo1: public PIRKeysetMetaData
{
public:
  Tivo1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class Tivo1a: public Tivo1
{
public:
  Tivo1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class Tivo1b: public Tivo1
{
public:
  Tivo1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class Tivo1c: public Tivo1
{
public:
  Tivo1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class Tivo1d: public Tivo1
{
public:
  Tivo1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // TIVO_H
