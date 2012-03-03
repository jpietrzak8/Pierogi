#ifndef COMPRO_H
#define COMPRO_H

#include "pirkeysetmetadata.h"

class QObject;

class ComproTVCard1: public PIRKeysetMetaData
{
public:
  ComproTVCard1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // COMPRO_H
