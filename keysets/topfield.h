#ifndef TOPFIELD_H
#define TOPFIELD_H

#include "pirkeysetmetadata.h"

class QObject;

class TopfieldPVR1: public PIRKeysetMetaData
{
public:
  TopfieldPVR1(
    QObject *guiObject,
    unsigned int index);
};

class TopfieldSat1: public PIRKeysetMetaData
{
public:
  TopfieldSat1(
    QObject *guiObject,
    unsigned int index);
};

#endif // TOPFIELD_H
