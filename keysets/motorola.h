#ifndef MOTOROLA_H
#define MOTOROLA_H

#include "pirkeysetmetadata.h"

class QObject;

class Motorola4DTV: public PIRKeysetMetaData
{
public:
  Motorola4DTV(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MotorolaSTB1: public PIRKeysetMetaData
{
public:
  MotorolaSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MotorolaSTB1a: public MotorolaSTB1
{
public:
  MotorolaSTB1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MotorolaSTB1b: public MotorolaSTB1
{
public:
  MotorolaSTB1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MotorolaSkyDigital: public PIRKeysetMetaData
{
public:
  MotorolaSkyDigital(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // MOTOROLA_H
