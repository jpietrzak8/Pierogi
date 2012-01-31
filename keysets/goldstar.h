#ifndef GOLDSTAR_H
#define GOLDSTAR_H

#include "pirkeysetmetadata.h"

#include <QObject>

class GoldStarTV1: public PIRKeysetMetaData
{
public:
  GoldStarTV1(
    QObject *guiObject,
    unsigned int index);
};


class GoldStarTV2: public PIRKeysetMetaData
{
public:
  GoldStarTV2(
    QObject *guiObject,
    unsigned int index);
};


class GoldStarVCR1: public PIRKeysetMetaData
{
public:
  GoldStarVCR1(
    QObject *guiObject,
    unsigned int index);
};


class GoldStarVCR1a: public GoldStarVCR1
{
public:
  GoldStarVCR1a(
    QObject *guiObject,
    unsigned int index);
};


class GoldStarVCR1b: public GoldStarVCR1
{
public:
  GoldStarVCR1b(
    QObject *guiObject,
    unsigned int index);
};


class GoldStarVCR1c: public GoldStarVCR1
{
public:
  GoldStarVCR1c(
    QObject *guiObject,
    unsigned int index);
};


class GoldStarCD1: public PIRKeysetMetaData
{
public:
  GoldStarCD1(
    QObject *guiObject,
    unsigned int index);
};

#endif // GOLDSTAR_H
