#ifndef WD_H
#define WD_H

#include "pirkeysetmetadata.h"

class QObject;

class WDMediaPlayer1: public PIRKeysetMetaData
{
public:
  WDMediaPlayer1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class WDMediaPlayer1a: public WDMediaPlayer1
{
public:
  WDMediaPlayer1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class WDMediaPlayer1b: public WDMediaPlayer1a
{
public:
  WDMediaPlayer1b(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // WD_H
