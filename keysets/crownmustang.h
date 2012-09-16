#ifndef CROWNMUSTANG_H
#define CROWNMUSTANG_H

#include "pirkeysetmetadata.h"

class QObject;

class CrownMustangTV1: public PIRKeysetMetaData
{
public:
  CrownMustangTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // CROWNMUSTANG_H
