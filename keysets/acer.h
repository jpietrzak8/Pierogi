#ifndef ACER_H
#define ACER_H

#include "pirkeysetmetadata.h"

class QObject;

class AcerTV1: public PIRKeysetMetaData
{
public:
  AcerTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class AcerPC1: public PIRKeysetMetaData
{
public:
  AcerPC1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // ACER_H
