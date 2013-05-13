#ifndef SANYO_H
#define SANYO_H

#include "pirkeysetmetadata.h"

class QObject;

class SanyoVCR1: public PIRKeysetMetaData
{
public:
  SanyoVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SanyoDVD1: public PIRKeysetMetaData
{
public:
  SanyoDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SanyoTV1: public PIRKeysetMetaData
{
public:
  SanyoTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SanyoTV1a: public SanyoTV1
{
public:
  SanyoTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SanyoTV1b: public SanyoTV1
{
public:
  SanyoTV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SanyoTV1c: public SanyoTV1a
{
public:
  SanyoTV1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SanyoTV1d: public SanyoTV1
{
public:
  SanyoTV1d(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SanyoProjector1: public PIRKeysetMetaData
{
public:
  SanyoProjector1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SanyoProjector1a: public SanyoProjector1
{
public:
  SanyoProjector1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SanyoProjector1b: public SanyoProjector1
{
public:
  SanyoProjector1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SanyoProjector1c: public SanyoProjector1
{
public:
  SanyoProjector1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // SANYO_H
