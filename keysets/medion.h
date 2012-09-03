#ifndef MEDION_H
#define MEDION_H

#include "pirkeysetmetadata.h"

class QObject;

class MedionSTB1: public PIRKeysetMetaData
{
public:
  MedionSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class MedionDVD1: public PIRKeysetMetaData
{
public:
  MedionDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class MedionDVD2: public PIRKeysetMetaData
{
public:
  MedionDVD2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};


class MedionVCR1: public PIRKeysetMetaData
{
public:
  MedionVCR1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // MEDION_H
