#ifndef VIZIO_H
#define VIZIO_H

#include "pirkeysetmetadata.h"

class QObject;

class VizioTV1: public PIRKeysetMetaData
{
public:
  VizioTV1(
    QObject *guiObject,
    unsigned int index);
};

#endif // VIZIO_H
