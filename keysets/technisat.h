#ifndef TECHNISAT_H
#define TECHNISAT_H

#include "pirkeysetmetadata.h"

class QObject;

class TechnisatSTB1: public PIRKeysetMetaData
{
public:
  TechnisatSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TechnisatSTB1a: public TechnisatSTB1
{
public:
  TechnisatSTB1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TechnisatSTB2: public PIRKeysetMetaData
{
public:
  TechnisatSTB2(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TechnisatSTB2a: public TechnisatSTB2
{
public:
  TechnisatSTB2a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TechnisatSTB3: public PIRKeysetMetaData
{
public:
  TechnisatSTB3(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class TechnisatSTB3a: public TechnisatSTB3
{
public:
  TechnisatSTB3a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // TECHNISAT_H
