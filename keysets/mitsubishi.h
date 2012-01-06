#ifndef MITSUBISHI_H
#define MITSUBISHI_H

#include "pirkeysetmetadata.h"

#include <QObject>

class MitsubishiTV1: public PIRKeysetMetaData
{
public:
  MitsubishiTV1(
    QObject *guiObject,
    unsigned int index);
};

class MitsubishiTV1a: public MitsubishiTV1
{
public:
  MitsubishiTV1a(
    QObject *guiObject,
    unsigned int index);
};

class MitsubishiVCR1: public PIRKeysetMetaData
{
public:
  MitsubishiVCR1(
    QObject *guiObject,
    unsigned int index);
};

class MitsubishiVCR1a: public MitsubishiVCR1
{
public:
  MitsubishiVCR1a(
    QObject *guiObject,
    unsigned int index);
};

#endif // MITSUBISHI_H
