#ifndef HYUNDAI_H
#define HYUNDAI_H

#include "pirkeysetmetadata.h"

class QObject;

class HyundaiDVD1: public PIRKeysetMetaData
{
public:
  HyundaiDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HyundaiAudio1: public PIRKeysetMetaData
{
public:
  HyundaiAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HyundaiTV1: public PIRKeysetMetaData
{
public:
  HyundaiTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // HYUNDAI_H
