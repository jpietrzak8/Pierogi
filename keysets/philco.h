#ifndef PHILCO_H
#define PHILCO_H

#include "pirkeysetmetadata.h"

class QObject;

class PhilcoTV: public PIRKeysetMetaData
{
public:
  PhilcoTV(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // PHILCO_H
