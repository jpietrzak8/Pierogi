#ifndef HAUPPAUGE_H
#define HAUPPAUGE_H

#include "pirkeysetmetadata.h"
#include <QObject>

class HauppaugePCTV1: public PIRKeysetMetaData
{
public:
  HauppaugePCTV1(
    QObject *guiObject,
    unsigned int index);
};

class HauppaugePCTV1a: public HauppaugePCTV1
{
public:
  HauppaugePCTV1a(
    QObject *guiObject,
    unsigned int index);
};

class HauppaugePCTV1b: public HauppaugePCTV1
{
public:
  HauppaugePCTV1b(
    QObject *guiObject,
    unsigned int index);
};

class HauppaugePCTV1c: public HauppaugePCTV1
{
public:
  HauppaugePCTV1c(
    QObject *guiObject,
    unsigned int index);
};

class HauppaugePCTV2: public PIRKeysetMetaData
{
public:
  HauppaugePCTV2(
    QObject *guiObject,
    unsigned int index);
};

#endif // HAUPPAUGE_H
