#ifndef SILVERCREST_H
#define SILVERCREST_H

#include "pirkeysetmetadata.h"

class QObject;

class SilverCrestDVD1: public PIRKeysetMetaData
{
public:
  SilverCrestDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SilverCrestDVD2: public PIRKeysetMetaData
{
public:
  SilverCrestDVD2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SilverCrestDVD3: public PIRKeysetMetaData
{
public:
  SilverCrestDVD3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // SILVERCREST_H
