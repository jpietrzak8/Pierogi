#ifndef NECPROTOCOL_H
#define NECPROTOCOL_H

#include "pirprotocol.h"
#include "pirrx51hardware.h"

//
// The "NEC" Protocol is, more or less, followed by the majority of
// remotes defined in the LIRC config files, which means it is probably
// followed by most of the remotes out there.
//
// Remotes using this protocol seem to use a frequency of 38000 Hz, lead off
// each command with a signal that should be unique to the manufacturer,
// and mostly define 0s and 1s by the length of time between pulses...
//

//
// There exist two well-defined NEC protocols: "standard" and "extended".
// Some remotes might not fit into either format; LIRC has given up and
// simply recorded the exact set of IR pulses as bits, rather than attempt
// to follow the standard encodings.  I'll use the following enum to
// describe which mechanism the key data follows:
//

enum NECKeyFormat
{
  Standard_NEC,
  Extended_NEC,
  LIRC_NEC
};

class NECProtocol: public PIRProtocol
{
public:
  // An NEC protocol will always have differing times for "zero" and "one".
  // Also, all protocols have some space set between commands.  However,
  // some protocols specify a fixed delay between the end of one
  // command and the start of the next, and others specify each command be
  // started at a precise interval (so the spacing between the end of one
  // and the start of another may vary).

  // Constructor for standard NEC:
  NECProtocol(
    QObject *guiObject,
    unsigned int index,
    NECKeyFormat type);

  // Constructor for non-standard NEC:
  NECProtocol(
    QObject *guiObject,
    unsigned int index,
    unsigned int zPulse,
    unsigned int zSpace,
    unsigned int oPulse,
    unsigned int oSpace,
    unsigned int gapSpace,
    bool iclflag,
    NECKeyFormat type);

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

  void setElevenBitToggle(
    bool flag);

public slots:
  void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command);

private:
  // First, define what is used to represent 0 and 1:
  unsigned int zeroPulse;
  unsigned int zeroSpace;
  unsigned int onePulse;
  unsigned int oneSpace;

  // Some administrative data that most NEC Protocol remotes have:
  unsigned int headerPulse;
  unsigned int headerSpace;
  bool hasHeaderPair;

  // A tailing on-request, not followed by a specific off time:
  unsigned int trailerPulse;
  bool hasTrailerPulse;

  // A pulse that means "repeat the last command":
  unsigned int repeatPulse;
  unsigned int repeatSpace;
  bool hasRepeatPair;
  bool repeatNeedsHeader; // Put the header ahead of the repeat pulse
  bool fullHeadlessRepeat; // Repeat full command but without header
  bool elevenBitToggle; // A few remotes toggle the last eleven bits on repeat

  // A flag used to determine how to encode the bits:
  NECKeyFormat encodingFormat;

  int generateStandardCommand(
    const CommandSequence &bits,
    PIRRX51Hardware &device);

  int generateHeadlessCommand(
    const CommandSequence &bits,
    PIRRX51Hardware &device);

  int generateRepeatCommand(
    PIRRX51Hardware &device);

  int generateToggledCommand(
    const CommandSequence &bits,
    PIRRX51Hardware &device);

  int pushBits(
    const CommandSequence &bits,
    PIRRX51Hardware &device);

  int pushReverseBits(
    const CommandSequence &bits,
    PIRRX51Hardware &device);

  int pushInvertedReverseBits(
    const CommandSequence &bits,
    PIRRX51Hardware &device);
};

#endif // NECPROTOCOL_H
