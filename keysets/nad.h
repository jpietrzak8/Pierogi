#ifndef NAD_H
#define NAD_H

#include "pirkeysetmetadata.h"

class QObject;

class NADAudio1: public PIRKeysetMetaData
{
public:
  NADAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class NADTuner1: public PIRKeysetMetaData
{
public:
  NADTuner1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class NADDVD1: public PIRKeysetMetaData
{
public:
  NADDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class NADCD1: public PIRKeysetMetaData
{
public:
  NADCD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class NADCD2: public PIRKeysetMetaData
{
public:
  NADCD2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class NADTape1: public PIRKeysetMetaData
{
public:
  NADTape1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // NAD_H
