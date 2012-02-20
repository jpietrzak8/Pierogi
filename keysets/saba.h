#ifndef SABA_H
#define SABA_H

#include "pirkeysetmetadata.h"

class QObject;

class SabaTV1: public PIRKeysetMetaData
{
public:
  SabaTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SabaTV2: public PIRKeysetMetaData
{
public:
  SabaTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // SABA_H
