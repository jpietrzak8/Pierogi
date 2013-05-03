#ifndef STRONG_H
#define STRONG_H

#include "pirkeysetmetadata.h"

class QObject;

class StrongSat1: public PIRKeysetMetaData
{
public:
  StrongSat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class StrongSat2: public PIRKeysetMetaData
{
public:
  StrongSat2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class StrongSat3: public PIRKeysetMetaData
{
public:
  StrongSat3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class StrongSat4: public PIRKeysetMetaData
{
public:
  StrongSat4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class StrongDVBT1: public PIRKeysetMetaData
{
public:
  StrongDVBT1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // STRONG_H
