#ifndef CREATIVE_H
#define CREATIVE_H

#include "pirkeysetmetadata.h"

class QObject;

class CreativeAudio1: public PIRKeysetMetaData
{
public:
  CreativeAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class CreativeAudio2: public PIRKeysetMetaData
{
public:
  CreativeAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class CreativeMisc1: public PIRKeysetMetaData
{
public:
  CreativeMisc1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // CREATIVE_H
