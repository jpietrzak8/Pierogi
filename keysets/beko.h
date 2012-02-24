#ifndef BEKO_H
#define BEKO_H

#include "pirkeysetmetadata.h"

class QObject;

class BekoTV1: public PIRKeysetMetaData
{
public:
  BekoTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // BEKO_H