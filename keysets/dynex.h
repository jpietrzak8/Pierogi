#ifndef DYNEX_H
#define DYNEX_H

#include "pirkeysetmetadata.h"

class QObject;

class DynexTV1: public PIRKeysetMetaData
{
public:
  DynexTV1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // DYNEX_H
