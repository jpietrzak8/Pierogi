#ifndef DIRECTV_H
#define DIRECTV_H

#include "pirkeysetmetadata.h"

class QObject;

class DirectvReceiver1: public PIRKeysetMetaData
{
public:
  DirectvReceiver1(
    QObject *guiObject,
    unsigned int index);
};

#endif // DIRECTV_H
