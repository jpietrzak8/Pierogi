#ifndef KEYMAT_H
#define KEYMAT_H

#include "pirkeysetmetadata.h"

class QObject;

class KeymatTV1: public PIRKeysetMetaData
{
public:
  KeymatTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class KeymatTV2: public PIRKeysetMetaData
{
public:
  KeymatTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // KEYMAT_H
