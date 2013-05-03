#ifndef PIRACSTATEINFO_H
#define PIRACSTATEINFO_H

// A very simple class for passing state info around:

class PIRACStateInfo
{
public:
  PIRACStateInfo();

  // Standard state info:
  int power;
  int temperature;
  int fan;
  int mode;
  int swing;
  int turbo;
  int airclean;

  // Timer state info:
  int timerOption;
  int timerHours;
};


// --------------- Inline methods:

inline PIRACStateInfo::PIRACStateInfo()
  : power(0),
    temperature(0),
    fan(0),
    mode(0),
    swing(0),
    turbo(0),
    airclean(0),
    timerOption(0),
    timerHours(0)
{
}

#endif // PIRACSTATEINFO_H
