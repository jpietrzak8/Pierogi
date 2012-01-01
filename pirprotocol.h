#ifndef PIRPROTOCOL_H
#define PIRPROTOCOL_H

// The generic remote controller.

#include <QObject>
//#include <QMutex>
#include "pirkeynames.h"
//#include "pirdevice.h"

#include <map>
#include <deque>

// We'll define a maximum number of repetitions, regardless of how long the
// user presses the button.  (This is just in case we miss the point at which
// he stops pressing it...)  500 should be plenty.
#define MAX_REPEAT_COUNT 500

typedef std::deque<bool> CommandSequence;

// I'll go ahead and use associative arrays to build up lists of keycodes.
typedef std::map<int, CommandSequence> KeycodeCollection;


// Right now, the only reason for this object to inherit from QObject is
// so it can participate in Qt-style threading.  Note that it has no
// event loop, and no access to the GUI, so don't go trying to communicate
// with the user here...
class PIRProtocol: public QObject
{
  Q_OBJECT

public:
  PIRProtocol(
    QObject *guiObject,
    unsigned int index,
    unsigned int gSpace,
    bool iclflag);

  void addKey(
    PIRKeyName key,
    unsigned long data,
    unsigned int bits);

//  void setIndex(
//    unsigned int index);

  void setCarrierFrequency(
    unsigned int freq);

  void setDutyCycle(
    unsigned int dc);

  void setMinimumRepetitions(
    unsigned int minrep);

public slots:
  virtual void startSendingCommand(
    unsigned int threadableID,
    PIRKeyName command) = 0;

signals:
  void commandFailed(
    const char *errString);

protected:
  bool isCommandSupported(
    PIRKeyName command);

  void clearRepeatFlag();
  bool checkRepeatFlag();

  unsigned int carrierFrequency;
  unsigned int dutyCycle;

  // "appendToBitSeq" really doesn't belong in this class...
  void appendToBitSeq(
    CommandSequence &sequence,
    unsigned int bits,
    int significantBits);

  KeycodeCollection keycodes;

  // A sleep function for all protocols:
  void sleepUntilRepeat(
    int commandDuration);

  // The "gap" parameter from LIRC.  If the commands are "variable-length",
  // this indicates the amount of time between the last pulse of one
  // command and the first pulse of the next.  If "constant-length", it is
  // the time between the _first_ pulse of one command and the first pulse
  // of the next.

  bool isConstantLength;
  int gap;

  // Some remotes require a minimum number of repetitions:
  int minimumRepetitions;

  unsigned int id;
};

#endif // PIRPROTOCOL_H
