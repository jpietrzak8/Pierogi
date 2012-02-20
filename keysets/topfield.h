#ifndef TOPFIELD_H
#define TOPFIELD_H

#include "pirkeysetmetadata.h"

class QObject;

class TopfieldPVR1: public PIRKeysetMetaData
{
public:
  TopfieldPVR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TopfieldSat1: public PIRKeysetMetaData
{
public:
  TopfieldSat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // TOPFIELD_H
