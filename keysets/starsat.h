#ifndef STARSAT
#define STARSAT

#include "pirkeysetmetadata.h"

class QObject;

class StarsatSat1: public PIRKeysetMetaData
{
public:
  StarsatSat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // STARSAT
