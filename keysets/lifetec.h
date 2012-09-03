#ifndef LIFETEC_H
#define LIFETEC_H

#include "pirkeysetmetadata.h"

class QObject;

class LifetecTV1: public PIRKeysetMetaData
{
public:
  LifetecTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class LifetecTV2: public PIRKeysetMetaData
{
public:
  LifetecTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class LifetecVCR1: public PIRKeysetMetaData
{
public:
  LifetecVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class LifetecAudio1: public PIRKeysetMetaData
{
public:
  LifetecAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // LIFETEC_H
