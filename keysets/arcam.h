#ifndef ARCAM_H
#define ARCAM_H

#include "pirkeysetmetadata.h"

class QObject;

class ArcamReceiver1: public PIRKeysetMetaData
{
public:
  ArcamReceiver1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // ARCAM_H
