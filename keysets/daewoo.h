#ifndef DAEWOO_H
#define DAEWOO_H

#include "pirkeysetmetadata.h"

class QObject;

class DaewooTV1: public PIRKeysetMetaData
{
public:
  DaewooTV1(
    QObject *guiObject,
    unsigned int index);
};

class DaewooTV2: public PIRKeysetMetaData
{
public:
  DaewooTV2(
    QObject *guiObject,
    unsigned int index);
};

class DaewooTV3: public PIRKeysetMetaData
{
public:
  DaewooTV3(
    QObject *guiObject,
    unsigned int index);
};

class DaewooTV4: public PIRKeysetMetaData
{
public:
  DaewooTV4(
    QObject *guiObject,
    unsigned int index);
};

class DaewooDVD1: public PIRKeysetMetaData
{
public:
  DaewooDVD1(
    QObject *guiObject,
    unsigned int index);
};

class DaewooVCR1: public PIRKeysetMetaData
{
public:
  DaewooVCR1(
    QObject *guiObject,
    unsigned int index);
};

class DaewooVCR2: public PIRKeysetMetaData
{
public:
  DaewooVCR2(
    QObject *guiObject,
    unsigned int index);
};

#endif // DAEWOO_H
