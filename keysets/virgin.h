#ifndef VIRGIN_H
#define VIRGIN_H

#include "pirkeysetmetadata.h"

class QObject;

class VirginSTB1: public PIRKeysetMetaData
{
public:
  VirginSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // VIRGIN_H
