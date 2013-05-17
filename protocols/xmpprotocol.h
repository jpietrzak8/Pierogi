#ifndef XMPPROTOCOL_H
#define XMPPROTOCOL_H

#include "pirprotocol.h"

class PIRInfraredLED;

//
// The XMP protocol is a large, fairly complex protocol, but seems to be
// gaining popularity in a variety of modern devices.
//

class XMPProtocol: public PIRProtocol
{
public:
  XMPProtocol(
    QObject *guiObject,
    unsigned int index,
    unsigned int sd1,
    unsigned int sd2,
    unsigned int oem,
    unsigned int d,
    bool hasFF);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  int generateStandardCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);

  int generateRepeatCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);

  int generateFinalCommand(
    const PIRKeyBits &bits,
    PIRInfraredLED &led);

  unsigned int calculateChecksumOne();

  unsigned int calculateChecksumTwo(
    unsigned int toggle,
    const CommandSequence &firstCode,
    const CommandSequence &secondCode);

  int pushHalfByte(
    unsigned int halfByte,
    PIRInfraredLED &led);

  int pushFullByte(
    unsigned int fullByte,
    PIRInfraredLED &led);

  int pushBits(
    const CommandSequence &bits,
    PIRInfraredLED &led);

  unsigned int subDeviceOne;
  unsigned int subDeviceTwo;
  unsigned int oemCode;
  unsigned int deviceCode;
  bool hasFinalFrame;
};

#endif // XMPPROTOCOL_H
