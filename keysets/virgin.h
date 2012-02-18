#ifndef VIRGIN_H
#define VIRGIN_H

#include "pirkeysetmetadata.h"

class QObject;

class VirginSTB1: public PIRKeysetMetaData
{
public:
  VirginSTB1(
    QObject *guiObject,
    unsigned int index);
};

#endif // VIRGIN_H
