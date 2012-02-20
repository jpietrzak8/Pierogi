#ifndef DIRECTV_H
#define DIRECTV_H

#include "pirkeysetmetadata.h"

class QObject;

class DirectvReceiver1: public PIRKeysetMetaData
{
public:
  DirectvReceiver1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // DIRECTV_H
