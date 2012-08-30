#ifndef ONKYO_H
#define ONKYO_H

#include "pirkeysetmetadata.h"

class QObject;

class OnkyoAudio1: public PIRKeysetMetaData
{
public:
  OnkyoAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OnkyoAudio2: public PIRKeysetMetaData
{
public:
  OnkyoAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OnkyoAudio2a: public OnkyoAudio2
{
public:
  OnkyoAudio2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OnkyoAudio3: public PIRKeysetMetaData
{
public:
  OnkyoAudio3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OnkyoAudio4: public PIRKeysetMetaData
{
public:
  OnkyoAudio4(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OnkyoAudio5: public PIRKeysetMetaData
{
public:
  OnkyoAudio5(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OnkyoDVD1: public PIRKeysetMetaData
{
public:
  OnkyoDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class OnkyoDVD2: public PIRKeysetMetaData
{
public:
  OnkyoDVD2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // ONKYO_H
