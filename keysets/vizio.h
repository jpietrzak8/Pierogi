#ifndef VIZIO_H
#define VIZIO_H

#include "pirkeysetmetadata.h"

class QObject;

class VizioTV1: public PIRKeysetMetaData
{
public:
  VizioTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // VIZIO_H
