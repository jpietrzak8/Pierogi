#ifndef LOEWE_H
#define LOEWE_H

#include "pirkeysetmetadata.h"

class QObject;

class LoeweTV1: public PIRKeysetMetaData
{
public:
  LoeweTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LoeweVCR1: public PIRKeysetMetaData
{
public:
  LoeweVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LoeweDVD1: public PIRKeysetMetaData
{
public:
  LoeweDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // LOEWE_H
