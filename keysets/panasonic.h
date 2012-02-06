#ifndef PANASONIC_H
#define PANASONIC_H

#include "pirkeysetmetadata.h"

class QObject;

class PanasonicAmp: public PIRKeysetMetaData
{
public:
  PanasonicAmp(
    QObject *guiObject,
    unsigned int index);
};

class PanasonicCarAudio: public PIRKeysetMetaData
{
public:
  PanasonicCarAudio(
    QObject *guiObject,
    unsigned int index);
};

class PanasonicSat1: public PIRKeysetMetaData
{
public:
  PanasonicSat1(
    QObject *guiObject,
    unsigned int index);
};

class PanasonicSat1a: public PanasonicSat1
{
public:
  PanasonicSat1a(
    QObject *guiObject,
    unsigned int index);
};

class PanasonicTV1: public PIRKeysetMetaData
{
public:
  PanasonicTV1(
    QObject *guiObject,
    unsigned int index);
};

class PanasonicTV1a: public PanasonicTV1
{
public:
  PanasonicTV1a(
    QObject *guiObject,
    unsigned int index);
};

class PanasonicTV1b: public PanasonicTV1
{
public:
  PanasonicTV1b(
    QObject *guiObject,
    unsigned int index);
};

class PanasonicVCR1: public PIRKeysetMetaData
{
public:
  PanasonicVCR1(
    QObject *guiObject,
    unsigned int index);
};

class PanasonicVCR1a: public PanasonicVCR1
{
public:
  PanasonicVCR1a(
    QObject *guiObject,
    unsigned int index);
};

class PanasonicVCR1b: public PanasonicVCR1
{
public:
  PanasonicVCR1b(
    QObject *guiObject,
    unsigned int index);
};

class PanasonicVCR1c: public PanasonicVCR1
{
public:
  PanasonicVCR1c(
    QObject *guiObject,
    unsigned int index);
};

class PanasonicDVD1: public PIRKeysetMetaData
{
public:
  PanasonicDVD1(
    QObject *guiObject,
    unsigned int index);
};

class PanasonicDVD1a: public PanasonicDVD1
{
public:
  PanasonicDVD1a(
    QObject *guiObject,
    unsigned int index);
};

class PanasonicAudio1: public PIRKeysetMetaData
{
public:
  PanasonicAudio1(
    QObject *guiObject,
    unsigned int index);
};

class PanasonicAudio1a: public PanasonicAudio1
{
public:
  PanasonicAudio1a(
    QObject *guiObject,
    unsigned int index);
};

#endif // PANASONIC_H
