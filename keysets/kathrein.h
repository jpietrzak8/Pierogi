#ifndef KATHREIN_H
#define KATHREIN_H

#include "pirkeysetmetadata.h"

class QObject;

class KathreinSat1: public PIRKeysetMetaData
{
public:
  KathreinSat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class KathreinSat2: public PIRKeysetMetaData
{
public:
  KathreinSat2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class KathreinSat3: public PIRKeysetMetaData
{
public:
  KathreinSat3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // KATHREIN_H
