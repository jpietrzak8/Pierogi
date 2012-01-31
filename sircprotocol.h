#ifndef SIRCPROTOCOL_H
#define SIRCPROTOCOL_H

#include "pirprotocol.h"
#include "pirrx51hardware.h"

//
// The SIRC protocol is Sony's system for transmitting information via
// infrared light.  As with the very popular "NEC" protocol, binary data is
// encoded by varying the amount of time each bit is held: a zero is held for
// a short span of time, a one lasts a little bit longer.
//
// Currently, there seem to be three types of SIRC commands; 12 bit, 15 bit,
// and 20 bit.  In each type, it appears the last seven bits specify the
// command, and the rest specify the device being addressed.  (The bits are
// passed in reverse order in the actual IR stream.)
//
// The marvelous thing about the Sony Infrared Remote Control protocol is just
// how simple and easy it is; just a header pulse, the command, the address,
// and a trailer pulse.  The terrible thing about the protocol is that Sony
// has given up on following their own rules.  Sony devices today regularly
// support commands from a variety of addresses, making the whole concept of
// the "address" kind of meaningless. :(  I can see why the LIRC guys would
// give up and just encode the raw IR bits, rather than wade into this mess...
//

class SIRCProtocol: public PIRProtocol
{
public:
  SIRCProtocol(
    QObject *guiObject,
    unsigned int index);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  unsigned int zeroPulse;
  unsigned int zeroSpace;
  unsigned int onePulse;
  unsigned int oneSpace;

  unsigned int headerPulse;
  unsigned int headerSpace;

  int generateStandardCommand(
    const CommandSequence &bits,
    PIRRX51Hardware &device);

  int pushReverseBits(
    const CommandSequence &bits,
    PIRRX51Hardware &device);
};

#endif // SIRCPROTOCOL_H
