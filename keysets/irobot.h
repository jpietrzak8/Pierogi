#ifndef IROBOT_H
#define IROBOT_H

#include "pirkeysetmetadata.h"

class QObject;

class IRobotRoomba1: public PIRKeysetMetaData
{
public:
  IRobotRoomba1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // IROBOT_H
