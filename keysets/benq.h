#ifndef BENQ_H
#define BENQ_H

#include "pirkeysetmetadata.h"

class QObject;

class BenQTV1: public PIRKeysetMetaData
{
public:
  BenQTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // BENQ_H
