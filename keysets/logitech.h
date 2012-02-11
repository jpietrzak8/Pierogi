#ifndef LOGITECH_H
#define LOGITECH_H

#include "pirkeysetmetadata.h"

class QObject;

class LogitechSpeakers: public PIRKeysetMetaData
{
public:
  LogitechSpeakers(
    QObject *guiObject,
    unsigned int index);
};

#endif // LOGITECH_H
