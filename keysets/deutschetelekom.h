#ifndef DEUTSCHETELEKOM_H
#define DEUTSCHETELEKOM_H

#include "pirkeysetmetadata.h"

class QObject;

class DeutscheTelekomSTB1: public PIRKeysetMetaData
{
public:
  DeutscheTelekomSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // DEUTSCHETELEKOM_H
