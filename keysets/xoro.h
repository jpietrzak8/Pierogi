#ifndef XORO_H
#define XORO_H

#include "pirkeysetmetadata.h"

class QObject;

class XoroSTB1: public PIRKeysetMetaData
{
public:
  XoroSTB1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // XORO_H
