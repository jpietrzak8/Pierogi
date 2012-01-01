#ifndef HAUPPAUGE_H
#define HAUPPAUGE_H

#include "pirkeysetmetadata.h"

#include <QObject>

class HauppaugeGeneric: public PIRKeysetMetaData
{
public:
  HauppaugeGeneric(
    QObject *guiObject,
    unsigned int index);
};


class HauppaugeTV1: public PIRKeysetMetaData
{
public:
  HauppaugeTV1(
    QObject *guiObject,
    unsigned int index);
};

#endif // HAUPPAUGE_H
