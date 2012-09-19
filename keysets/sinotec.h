#ifndef SINOTEC_H
#define SINOTEC_H

#include "pirkeysetmetadata.h"

class QObject;

class SinotecTV1: public PIRKeysetMetaData
{
public:
  SinotecTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SinotecTV2: public PIRKeysetMetaData
{
public:
  SinotecTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // SINOTEC_H
