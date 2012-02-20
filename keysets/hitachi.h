#ifndef HITACHI_H
#define HITACHI_H

#include "pirkeysetmetadata.h"

class QObject;

class HitachiTV1: public PIRKeysetMetaData
{
public:
  HitachiTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HitachiTV1a: public HitachiTV1
{
public:
  HitachiTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HitachiTV1b: public HitachiTV1a
{
public:
  HitachiTV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HitachiTV1c: public HitachiTV1
{
public:
  HitachiTV1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HitachiTV2: public PIRKeysetMetaData
{
public:
  HitachiTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HitachiTV3: public PIRKeysetMetaData
{
public:
  HitachiTV3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HitachiProjector: public PIRKeysetMetaData
{
public:
  HitachiProjector(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HitachiDVD1: public PIRKeysetMetaData
{
public:
  HitachiDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HitachiAudio1: public PIRKeysetMetaData
{
public:
  HitachiAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HitachiVCR1: public PIRKeysetMetaData
{
public:
  HitachiVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // HITACHI_H
