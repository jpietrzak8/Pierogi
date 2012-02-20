#ifndef ELGATO_H
#define ELGATO_H

#include "pirkeysetmetadata.h"

class QObject;

class ElgatoEyeTV1: public PIRKeysetMetaData
{
public:
  ElgatoEyeTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // ELGATO_H
