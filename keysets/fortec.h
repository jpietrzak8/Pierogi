#ifndef FORTEC_H
#define FORTEC_H

#include "pirkeysetmetadata.h"

class QObject;

class FortecReceiver1: public PIRKeysetMetaData
{
public:
  FortecReceiver1(
    QObject *guiObject,
    unsigned int index);
};

class FortecReceiver2: public PIRKeysetMetaData
{
public:
  FortecReceiver2(
    QObject *guiObject,
    unsigned int index);
};

#endif // FORTEC_H
