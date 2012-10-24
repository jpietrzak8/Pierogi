#ifndef NEC_H
#define NEC_H

#include "pirkeysetmetadata.h"

class QObject;

class NECTV1: public PIRKeysetMetaData
{
public:
  NECTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class NECVCR1: public PIRKeysetMetaData
{
public:
  NECVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class NECVCR2: public PIRKeysetMetaData
{
public:
  NECVCR2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class NECVCR3: public PIRKeysetMetaData
{
public:
  NECVCR3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class NECDVD1: public PIRKeysetMetaData
{
public:
  NECDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class NECProjector1: public PIRKeysetMetaData
{
public:
  NECProjector1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class NECProjector2: public PIRKeysetMetaData
{
public:
  NECProjector2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // NEC_H
