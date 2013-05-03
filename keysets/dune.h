#ifndef DUNE_H
#define DUNE_H

#include "pirkeysetmetadata.h"

class QObject;

class DuneSTB1: public PIRKeysetMetaData
{
public:
  DuneSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // DUNE_H
