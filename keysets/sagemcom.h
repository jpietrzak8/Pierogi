#ifndef SAGEMCOM_H
#define SAGEMCOM_H

#include "pirkeysetmetadata.h"

class QObject;

class SagemcomSTB1: public PIRKeysetMetaData
{
public:
  SagemcomSTB1(unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class SagemcomSTB2: public PIRKeysetMetaData
{
public:
  SagemcomSTB2(unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // SAGEMCOM_H
