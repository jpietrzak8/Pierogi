#ifndef HANTAREX_H
#define HANTAREX_H

#include "pirkeysetmetadata.h"

class QObject;

class HantarexTV1: public PIRKeysetMetaData
{
public:
  HantarexTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HantarexTV2: public PIRKeysetMetaData
{
public:
  HantarexTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // HANTAREX_H
