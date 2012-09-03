#ifndef BLAUPUNKT_H
#define BLAUPUNKT_H

#include "pirkeysetmetadata.h"

class QObject;

class BlaupunktVCR1: public PIRKeysetMetaData
{
public:
  BlaupunktVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // BLAUPUNKT_H
