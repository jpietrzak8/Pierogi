#ifndef BOSE_H
#define BOSE_H

#include "pirkeysetmetadata.h"

class QObject;

class BoseRadio1: public PIRKeysetMetaData
{
public:
  BoseRadio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class BoseRadio2: public PIRKeysetMetaData
{
public:
  BoseRadio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class BoseRadio3: public PIRKeysetMetaData
{
public:
  BoseRadio3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class BoseHomeTheater1: public PIRKeysetMetaData
{
public:
  BoseHomeTheater1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // BOSE_H
