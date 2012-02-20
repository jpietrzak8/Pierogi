#ifndef RCA_H
#define RCA_H

#include "pirkeysetmetadata.h"

class QObject;

class RCATV1: public PIRKeysetMetaData
{
public:
  RCATV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class RCATV1a: public RCATV1
{
public:
  RCATV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class RCATV1b: public RCATV1
{
public:
  RCATV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

/*
class RCAAux1: public PIRKeysetMetaData
{
public:
  RCAAux1(
    QObject *guiObject,
    unsigned int index);
};

class RCAAux2: public PIRKeysetMetaData
{
public:
  RCAAux2(
    QObject *guiObject,
    unsigned int index);
};

class RCAAux2a: public RCAAux2
{
public:
  RCAAux2a(
    QObject *guiObject,
    unsigned int index);
};
*/

class RCAVCR1: public PIRKeysetMetaData
{
public:
  RCAVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class RCAVCR1a: public RCAVCR1
{
public:
  RCAVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class RCADVD1: public PIRKeysetMetaData
{
public:
  RCADVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class RCADVD1a: public RCADVD1
{
public:
  RCADVD1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class RCASat1: public PIRKeysetMetaData
{
public:
  RCASat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class RCASat2: public PIRKeysetMetaData
{
public:
  RCASat2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // RCA_H
