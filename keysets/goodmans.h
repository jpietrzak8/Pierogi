#ifndef GOODMANS_H
#define GOODMANS_H

#include "pirkeysetmetadata.h"

class QObject;

class GoodmansSTB1: public PIRKeysetMetaData
{
public:
  GoodmansSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GoodmansVCR1: public PIRKeysetMetaData
{
public:
  GoodmansVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GoodmansDVD1: public PIRKeysetMetaData
{
public:
  GoodmansDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class GoodmansAudio1: public PIRKeysetMetaData
{
public:
  GoodmansAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // GOODMANS_H
