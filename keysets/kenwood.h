#ifndef KENWOOD_H
#define KENWOOD_H

#include "pirkeysetmetadata.h"

class QObject;

class KenwoodAudio1: public PIRKeysetMetaData
{
public:
  KenwoodAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class KenwoodComponent1: public PIRKeysetMetaData
{
public:
  KenwoodComponent1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class KenwoodComponent2: public PIRKeysetMetaData
{
public:
  KenwoodComponent2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class KenwoodComponent3: public PIRKeysetMetaData
{
public:
  KenwoodComponent3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class KenwoodCD1: public PIRKeysetMetaData
{
public:
  KenwoodCD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class KenwoodDVD1: public PIRKeysetMetaData
{
public:
  KenwoodDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class KenwoodTV1: public PIRKeysetMetaData
{
public:
  KenwoodTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // KENWOOD_H
