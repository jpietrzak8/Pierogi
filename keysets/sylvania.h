#ifndef SYLVANIA_H
#define SYLVANIA_H

#include "pirkeysetmetadata.h"

class QObject;

class SylvaniaTV1: public PIRKeysetMetaData
{
public:
  SylvaniaTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // SYLVANIA_H
