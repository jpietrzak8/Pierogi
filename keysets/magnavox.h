#ifndef MAGNAVOX_H
#define MAGNAVOX_H

#include "pirkeysetmetadata.h"

class QObject;

class MagnavoxDVD1: public PIRKeysetMetaData
{
public:
  MagnavoxDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MagnavoxVCR1: public PIRKeysetMetaData
{
public:
  MagnavoxVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MagnavoxConverterBox1: public PIRKeysetMetaData
{
public:
  MagnavoxConverterBox1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class MagnavoxTV1: public PIRKeysetMetaData
{
public:
  MagnavoxTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // MAGNAVOX_H
