#ifndef GENIUS_H
#define GENIUS_H

#include "pirkeysetmetadata.h"

class QObject;

class GeniusSpeakers1: public PIRKeysetMetaData
{
public:
  GeniusSpeakers1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // GENIUS_H
