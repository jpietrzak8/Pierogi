#ifndef RAITE_H
#define RAITE_H

#include "pirkeysetmetadata.h"

class QObject;

class RaiteDVD1: public PIRKeysetMetaData
{
public:
  RaiteDVD1(
    QObject *guiObject,
    unsigned int index);
};

#endif // RAITE_H
