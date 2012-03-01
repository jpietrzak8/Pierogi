#ifndef DELL_H
#define DELL_H

#include "pirkeysetmetadata.h"

class QObject;

class DellRemote1: public PIRKeysetMetaData
{
public:
  DellRemote1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // DELL_H
