#ifndef PANASONIC_H
#define PANASONIC_H

#include "pirkeysetmetadata.h"

class QObject;

class PanasonicCarAudio: public PIRKeysetMetaData
{
public:
  PanasonicCarAudio(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicSat1: public PIRKeysetMetaData
{
public:
  PanasonicSat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicSat1a: public PanasonicSat1
{
public:
  PanasonicSat1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicTV1: public PIRKeysetMetaData
{
public:
  PanasonicTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicTV1a: public PanasonicTV1
{
public:
  PanasonicTV1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicTV1b: public PanasonicTV1
{
public:
  PanasonicTV1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicVCR1: public PIRKeysetMetaData
{
public:
  PanasonicVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicVCR1a: public PanasonicVCR1
{
public:
  PanasonicVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicVCR1b: public PanasonicVCR1
{
public:
  PanasonicVCR1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicVCR1c: public PanasonicVCR1
{
public:
  PanasonicVCR1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicDVD1: public PIRKeysetMetaData
{
public:
  PanasonicDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicDVD1a: public PanasonicDVD1
{
public:
  PanasonicDVD1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicAudio1: public PIRKeysetMetaData
{
public:
  PanasonicAudio1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicAudio2: public PIRKeysetMetaData
{
public:
  PanasonicAudio2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicAudio2a: public PanasonicAudio2
{
public:
  PanasonicAudio2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class PanasonicAC1: public PIRKeysetMetaData
{
public:
  PanasonicAC1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // PANASONIC_H
