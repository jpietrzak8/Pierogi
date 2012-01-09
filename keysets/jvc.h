#ifndef JVC_H
#define JVC_H

#include "pirkeysetmetadata.h"

#include <QObject>

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

class JVCVCR1b: public JVCVCR1
{
public:
  JVCVCR1b(
    QObject *guiObject,
    unsigned int index);
};

class JVCVCR1c: public JVCVCR1
{
public:
  JVCVCR1c(
    QObject *guiObject,
    unsigned int index);
};

class JVCVCR2: public PIRKeysetMetaData
{
public:
  JVCVCR2(
    QObject *guiObject,
    unsigned int index);
};

class JVCVCR2a: public JVCVCR2
{
public:
  JVCVCR2a(
    QObject *guiObject,
    unsigned int index);
};

class JVCVCR2b: public JVCVCR2
{
public:
  JVCVCR2b(
    QObject *guiObject,
    unsigned int index);
};

class JVCVCR2c: public JVCVCR2
{
public:
  JVCVCR2c(
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

class JVCTV2: public PIRKeysetMetaData
{
public:
  JVCTV2(
    QObject *guiObject,
    unsigned int index);
};

class JVCTV2a: public JVCTV2
{
public:
  JVCTV2a(
    QObject *guiObject,
    unsigned int index);
};

class JVCTV2b: public JVCTV2
{
public:
  JVCTV2b(
    QObject *guiObject,
    unsigned int index);
};

class JVCTV2c: public JVCTV2
{
public:
  JVCTV2c(
    QObject *guiObject,
    unsigned int index);
};

class JVCTV2d: public JVCTV2
{
public:
  JVCTV2d(
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

class JVCPortableAudio1: public PIRKeysetMetaData
{
public:
  JVCPortableAudio1(
    QObject *guiObject,
    unsigned int index);
};

class JVCPortableAudio1a: public JVCPortableAudio1
{
public:
  JVCPortableAudio1a(
    QObject *guiObject,
    unsigned int index);
};

class JVCPortableAudio1b: public JVCPortableAudio1
{
public:
  JVCPortableAudio1b(
    QObject *guiObject,
    unsigned int index);
};

class JVCPortableAudio2: public PIRKeysetMetaData
{
public:
  JVCPortableAudio2(
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
