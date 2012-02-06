#ifndef ELGATO_H
#define ELGATO_H

#include "pirkeysetmetadata.h"

class QObject;

class ElgatoEyeTV1: public PIRKeysetMetaData
{
public:
  ElgatoEyeTV1(
    QObject *guiObject,
    unsigned int index);
};

#endif // ELGATO_H
