#ifndef EI_H
#define EI_H

#include "pirkeysetmetadata.h"

class QObject;

class EiTV1: public PIRKeysetMetaData
{
public:
  EiTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // EI_H
