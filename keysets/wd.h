#ifndef WD_H
#define WD_H

#include "pirkeysetmetadata.h"

class QObject;

class WDMediaPlayer1: public PIRKeysetMetaData
{
public:
  WDMediaPlayer1(
    QObject *guiObject,
    unsigned int index);
};

class WDMediaPlayer1a: public WDMediaPlayer1
{
public:
  WDMediaPlayer1a(
    QObject *guiObject,
    unsigned int index);
};

#endif // WD_H
