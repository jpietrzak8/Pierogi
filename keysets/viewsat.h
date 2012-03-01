#ifndef VIEWSAT_H
#define VIEWSAT_H

#include "pirkeysetmetadata.h"

class QObject;

class ViewsatSat1: public PIRKeysetMetaData
{
public:
  ViewsatSat1(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

class ViewsatSat1a: public ViewsatSat1
{
public:
  ViewsatSat1a(
    unsigned int index);

  virtual void populateProtocol(
    QObject *guiObject);
};

#endif // VIEWSAT_H
