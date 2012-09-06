#ifndef PENTAX_H
#define PENTAX_H

#include "pirkeysetmetadata.h"

class QObject;

class PentaxCamera1: public PIRKeysetMetaData
{
public:
  PentaxCamera1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // PENTAX_H
