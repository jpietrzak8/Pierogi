#ifndef GOLDSTAR_H
#define GOLDSTAR_H

#include "pirkeysetmetadata.h"

class QObject;

class GoldStarTV1: public PIRKeysetMetaData
{
public:
  GoldStarTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class GoldStarTV2: public PIRKeysetMetaData
{
public:
  GoldStarTV2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class GoldStarVCR1: public PIRKeysetMetaData
{
public:
  GoldStarVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class GoldStarVCR1a: public GoldStarVCR1
{
public:
  GoldStarVCR1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class GoldStarVCR1b: public GoldStarVCR1
{
public:
  GoldStarVCR1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class GoldStarVCR1c: public GoldStarVCR1
{
public:
  GoldStarVCR1c(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class GoldStarCD1: public PIRKeysetMetaData
{
public:
  GoldStarCD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // GOLDSTAR_H
