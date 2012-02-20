#ifndef HAUPPAUGE_H
#define HAUPPAUGE_H

#include "pirkeysetmetadata.h"

class QObject;

class HauppaugePCTV1: public PIRKeysetMetaData
{
public:
  HauppaugePCTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HauppaugePCTV1a: public HauppaugePCTV1
{
public:
  HauppaugePCTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HauppaugePCTV1b: public HauppaugePCTV1
{
public:
  HauppaugePCTV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HauppaugePCTV1c: public HauppaugePCTV1
{
public:
  HauppaugePCTV1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HauppaugePCTV2: public PIRKeysetMetaData
{
public:
  HauppaugePCTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // HAUPPAUGE_H
