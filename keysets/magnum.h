#ifndef MAGNUM_H
#define MAGNUM_H

#include "pirkeysetmetadata.h"

class QObject;

class MagnumTV1: public PIRKeysetMetaData
{
public:
  MagnumTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // MAGNUM_H
