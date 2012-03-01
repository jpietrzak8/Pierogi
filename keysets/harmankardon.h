#ifndef HARMANKARDON_H
#define HARMANKARDON_H

#include "pirkeysetmetadata.h"

class QObject;

class HarmanKardonAmp1: public PIRKeysetMetaData
{
public:
  HarmanKardonAmp1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HarmanKardonAmp2: public PIRKeysetMetaData
{
public:
  HarmanKardonAmp2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HarmanKardonReceiver2: public PIRKeysetMetaData
{
public:
  HarmanKardonReceiver2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HarmanKardonTape1: public PIRKeysetMetaData
{
public:
  HarmanKardonTape1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HarmanKardonDVD1: public PIRKeysetMetaData
{
public:
  HarmanKardonDVD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HarmanKardonDVD1a: public HarmanKardonDVD1
{
public:
  HarmanKardonDVD1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HarmanKardonCD1: public PIRKeysetMetaData
{
public:
  HarmanKardonCD1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class HarmanKardonCD2: public PIRKeysetMetaData
{
public:
  HarmanKardonCD2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // HARMANKARDON_H
