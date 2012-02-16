#ifndef KENWOOD_H
#define KENWOOD_H

#include "pirkeysetmetadata.h"

class QObject;

class KenwoodAudio1: public PIRKeysetMetaData
{
public:
  KenwoodAudio1(
    QObject *guiObject,
    unsigned int index);
};

class KenwoodComponent1: public PIRKeysetMetaData
{
public:
  KenwoodComponent1(
    QObject *guiObject,
    unsigned int index);
};

class KenwoodComponent2: public PIRKeysetMetaData
{
public:
  KenwoodComponent2(
    QObject *guiObject,
    unsigned int index);
};

class KenwoodComponent3: public PIRKeysetMetaData
{
public:
  KenwoodComponent3(
    QObject *guiObject,
    unsigned int index);
};

class KenwoodCD1: public PIRKeysetMetaData
{
public:
  KenwoodCD1(
    QObject *guiObject,
    unsigned int index);
};

class KenwoodDVD1: public PIRKeysetMetaData
{
public:
  KenwoodDVD1(
    QObject *guiObject,
    unsigned int index);
};

class KenwoodTV1: public PIRKeysetMetaData
{
public:
  KenwoodTV1(
    QObject *guiObject,
    unsigned int index);
};

#endif // KENWOOD_H
