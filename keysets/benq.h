#ifndef BENQ_H
#define BENQ_H

#include "pirkeysetmetadata.h"

class QObject;

class BenQTV1: public PIRKeysetMetaData
{
public:
  BenQTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class BenQProjector1: public PIRKeysetMetaData
{
public:
  BenQProjector1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class BenQProjector1a: public BenQProjector1
{
public:
  BenQProjector1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class BenQProjector2: public PIRKeysetMetaData
{
public:
  BenQProjector2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class BenQProjector3: public PIRKeysetMetaData
{
public:
  BenQProjector3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class BenQProjector4: public PIRKeysetMetaData
{
public:
  BenQProjector4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class BenQProjector5: public PIRKeysetMetaData
{
public:
  BenQProjector5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // BENQ_H
