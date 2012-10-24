#ifndef MEDIALINK_H
#define MEDIALINK_H

#include "pirkeysetmetadata.h"

class QObject;

class MedialinkSTB1: public PIRKeysetMetaData
{
public:
  MedialinkSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // MEDIALINK_H
