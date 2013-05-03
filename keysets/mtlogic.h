#ifndef MTLOGIC_H
#define MTLOGIC_H

#include "pirkeysetmetadata.h"

class QObject;

class MTLogicTV1: public PIRKeysetMetaData
{
public:
  MTLogicTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // MTLOGIC_H
