#ifndef TELENET_H
#define TELENET_H

#include "pirkeysetmetadata.h"

class QObject;

class TelenetSTB1: public PIRKeysetMetaData
{
public:
  TelenetSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // TELENET_H
