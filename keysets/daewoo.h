#ifndef DAEWOO_H
#define DAEWOO_H

#include "pirkeysetmetadata.h"

class QObject;

class DaewooTV1: public PIRKeysetMetaData
{
public:
  DaewooTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DaewooTV2: public PIRKeysetMetaData
{
public:
  DaewooTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DaewooTV3: public PIRKeysetMetaData
{
public:
  DaewooTV3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DaewooTV4: public PIRKeysetMetaData
{
public:
  DaewooTV4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DaewooTV5: public PIRKeysetMetaData
{
public:
  DaewooTV5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DaewooDVD1: public PIRKeysetMetaData
{
public:
  DaewooDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DaewooVCR1: public PIRKeysetMetaData
{
public:
  DaewooVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DaewooVCR2: public PIRKeysetMetaData
{
public:
  DaewooVCR2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // DAEWOO_H
