#ifndef JVC_H
#define JVC_H

#include "pirkeysetmetadata.h"

class QObject;

class JVCSat1: public PIRKeysetMetaData
{
public:
  JVCSat1(
    QObject *guiObject,
    unsigned int index);
};

class JVCSat2: public PIRKeysetMetaData
{
public:
  JVCSat2(
    QObject *guiObject,
    unsigned int index);
};

class JVCVCR1: public PIRKeysetMetaData
{
public:
  JVCVCR1(
    QObject *guiObject,
    unsigned int index);
};

class JVCVCR1a: public JVCVCR1
{
public:
  JVCVCR1a(
    QObject *guiObject,
    unsigned int index);
};

class JVCVCRBmode1: public JVCVCR1
{
public:
  JVCVCRBmode1(
    QObject *guiObject,
    unsigned int index);
};

class JVCVCRBmode1a: public JVCVCR1a
{
public:
  JVCVCRBmode1a(
    QObject *guiObject,
    unsigned int index);
};

class JVCTV1: public PIRKeysetMetaData
{
public:
  JVCTV1(
    QObject *guiObject,
    unsigned int index);
};

class JVCTV1a: public JVCTV1
{
public:
  JVCTV1a(
    QObject *guiObject,
    unsigned int index);
};

class JVCTV1b: public JVCTV1
{
public:
  JVCTV1b(
    QObject *guiObject,
    unsigned int index);
};

class JVCTV1c: public JVCTV1
{
public:
  JVCTV1c(
    QObject *guiObject,
    unsigned int index);
};

class JVCTV1d: public JVCTV1
{
public:
  JVCTV1d(
    QObject *guiObject,
    unsigned int index);
};

class JVCDAT1: public PIRKeysetMetaData
{
public:
  JVCDAT1(
    QObject *guiObject,
    unsigned int index);
};

class JVCCarDeck1: public PIRKeysetMetaData
{
public:
  JVCCarDeck1(
    QObject *guiObject,
    unsigned int index);
};

class JVCAudio1: public PIRKeysetMetaData
{
public:
  JVCAudio1(
    QObject *guiObject,
    unsigned int index);
};

class JVCAudio1a: public JVCAudio1
{
public:
  JVCAudio1a(
    QObject *guiObject,
    unsigned int index);
};

class JVCAudio1b: public JVCAudio1
{
public:
  JVCAudio1b(
    QObject *guiObject,
    unsigned int index);
};

class JVCAudio2: public PIRKeysetMetaData
{
public:
  JVCAudio2(
    QObject *guiObject,
    unsigned int index);
};

class JVCDVD1: public PIRKeysetMetaData
{
public:
  JVCDVD1(
    QObject *guiObject,
    unsigned int index);
};

#endif // JVC_H
