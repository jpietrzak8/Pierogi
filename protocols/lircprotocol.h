#ifndef LIRCPROTOCOL_H
#define LIRCPROTOCOL_H

#include "spaceprotocol.h"

class PIRRX51Hardware;

//
// LIRC does not itself have an actual protocol; what it does do is attempt
// to capture IR pulses in more-or-less the most general method possible.
// I'm attempting to push all my keysets into using code paths specific to
// their actual protocols, but I still don't know all the protocols myself.
// Where I don't have that information, I'll use LIRC's system.  The following
// pretty much follows LIRC's system for space-based encoding patterns.
//

class LIRCProtocol: public SpaceProtocol
{
public:
  LIRCProtocol(
    QObject *guiObject,
    unsigned int index,
    unsigned int zPulse,
    unsigned int zSpace,
    unsigned int oPulse,
    unsigned int oSpace,
    unsigned int gapSpace,
    bool iclflag);

  void setHeaderPair(
    unsigned int pulse,
    unsigned int space);

  void setTrailerPulse(
    unsigned int pulse);

  void setRepeatPair(
    unsigned int pulse,
    unsigned int space);

  void setRepeatNeedsHeader(
    bool flag);

  void setFullHeadlessRepeat(
    bool flag);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  bool hasHeaderPair;

  bool hasTrailerPulse;

  unsigned int repeatPulse;
  unsigned int repeatSpace;
  bool hasRepeatPair;
  bool repeatNeedsHeader; // Put the header ahead of the repeat pulse
  bool fullHeadlessRepeat; // Repeat full command but without header

  int generateStandardCommand(
    const PIRKeyBits &bits,
    PIRRX51Hardware &device);

  int generateHeadlessCommand(
    const PIRKeyBits &bits,
    PIRRX51Hardware &device);

  int generateRepeatCommand(
    PIRRX51Hardware &device);
};

#endif // LIRCPROTOCOL_H
