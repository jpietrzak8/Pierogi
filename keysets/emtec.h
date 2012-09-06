#ifndef EMTEC_H
#define EMTEC_H

#include "pirkeysetmetadata.h"

class QObject;

class EmtecSTB1: public PIRKeysetMetaData
{
public:
  EmtecSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class EmtecSTB2: public PIRKeysetMetaData
{
public:
  EmtecSTB2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // EMTEC_H
