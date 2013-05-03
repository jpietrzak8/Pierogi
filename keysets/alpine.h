#ifndef ALPINE_H
#define ALPINE_H

#include "pirkeysetmetadata.h"

class QObject;

class AlpineAudio1: public PIRKeysetMetaData
{
public:
  AlpineAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // ALPINE_H
