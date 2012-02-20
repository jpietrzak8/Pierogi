#ifndef FORTEC_H
#define FORTEC_H

#include "pirkeysetmetadata.h"

class QObject;

class FortecReceiver1: public PIRKeysetMetaData
{
public:
  FortecReceiver1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class FortecReceiver2: public PIRKeysetMetaData
{
public:
  FortecReceiver2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // FORTEC_H
