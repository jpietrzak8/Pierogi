#ifndef AOC_H
#define AOC_H

#include "pirkeysetmetadata.h"

class QObject;

class AOCTV1: public PIRKeysetMetaData
{
public:
  AOCTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // AOC_H
