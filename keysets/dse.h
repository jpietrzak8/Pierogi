#ifndef DSE_H
#define DSE_H

#include "pirkeysetmetadata.h"

class QObject;

class DSEDVD1: public PIRKeysetMetaData
{
public:
  DSEDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class DSESat1: public PIRKeysetMetaData
{
public:
  DSESat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // DSE_H
