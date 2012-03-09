#ifndef XCRUISER_H
#define XCRUISER_H

#include "pirkeysetmetadata.h"

class QObject;

class XcruiserSat1: public PIRKeysetMetaData
{
public:
  XcruiserSat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // XCRUISER_H
