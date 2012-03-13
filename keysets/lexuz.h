#ifndef LEXUZ_H
#define LEXUZ_H

#include "pirkeysetmetadata.h"

class QObject;

class LexuzDVB1: public PIRKeysetMetaData
{
public:
  LexuzDVB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // LEXUZ_H
