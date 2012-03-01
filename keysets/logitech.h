#ifndef LOGITECH_H
#define LOGITECH_H

#include "pirkeysetmetadata.h"

class QObject;

class LogitechSpeakers: public PIRKeysetMetaData
{
public:
  LogitechSpeakers(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class LogitechSqueezebox: public PIRKeysetMetaData
{
public:
  LogitechSqueezebox(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // LOGITECH_H
