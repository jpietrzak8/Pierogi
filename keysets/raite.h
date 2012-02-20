#ifndef RAITE_H
#define RAITE_H

#include "pirkeysetmetadata.h"

class QObject;

class RaiteDVD1: public PIRKeysetMetaData
{
public:
  RaiteDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // RAITE_H
