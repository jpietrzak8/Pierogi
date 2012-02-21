#ifndef TECHNICS_H
#define TECHNICS_H

#include "pirkeysetmetadata.h"

class QObject;

class TechnicsAudio1: public PIRKeysetMetaData
{
public:
  TechnicsAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TechnicsAudio1a: public TechnicsAudio1
{
public:
  TechnicsAudio1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TechnicsAudio2: public PIRKeysetMetaData
{
public:
  TechnicsAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TechnicsAudio3: public PIRKeysetMetaData
{
public:
  TechnicsAudio3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TechnicsAudio3a: public TechnicsAudio3
{
public:
  TechnicsAudio3a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TechnicsDVD1: public PIRKeysetMetaData
{
public:
  TechnicsDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // TECHNICS_H
