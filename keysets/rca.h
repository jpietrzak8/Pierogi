#ifndef RCA_H
#define RCA_H

#include "pirkeysetmetadata.h"

class QObject;

class RCATV1: public PIRKeysetMetaData
{
public:
  RCATV1(
    QObject *guiObject,
    unsigned int index);
};

class RCATV1a: public RCATV1
{
public:
  RCATV1a(
    QObject *guiObject,
    unsigned int index);
};

class RCATV1b: public RCATV1
{
public:
  RCATV1b(
    QObject *guiObject,
    unsigned int index);
};

/*
class RCAAux1: public PIRKeysetMetaData
{
public:
  RCAAux1(
    QObject *guiObject,
    unsigned int index);
};

class RCAAux2: public PIRKeysetMetaData
{
public:
  RCAAux2(
    QObject *guiObject,
    unsigned int index);
};

class RCAAux2a: public RCAAux2
{
public:
  RCAAux2a(
    QObject *guiObject,
    unsigned int index);
};
*/

class RCAVCR1: public PIRKeysetMetaData
{
public:
  RCAVCR1(
    QObject *guiObject,
    unsigned int index);
};

class RCAVCR1a: public RCAVCR1
{
public:
  RCAVCR1a(
    QObject *guiObject,
    unsigned int index);
};

class RCADVD1: public PIRKeysetMetaData
{
public:
  RCADVD1(
    QObject *guiObject,
    unsigned int index);
};

class RCADVD1a: public RCADVD1
{
public:
  RCADVD1a(
    QObject *guiObject,
    unsigned int index);
};

class RCASat1: public PIRKeysetMetaData
{
public:
  RCASat1(
    QObject *guiObject,
    unsigned int index);
};

class RCASat2: public PIRKeysetMetaData
{
public:
  RCASat2(
    QObject *guiObject,
    unsigned int index);
};

#endif // RCA_H
