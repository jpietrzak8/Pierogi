#ifndef PIRFLASHLED_H
#define PIRFLASHLED_H

//
// Support for engaging the N900's camera flash LEDs; this is used in
// conjunction with the IR camera shutter controls, to allow the N900 to
// be used as a "remote flash".
//

class PIRFlashLED
{
public:
  PIRFlashLED();

  ~PIRFlashLED();

  void strobe();

private:
  void openFlashDevice();

  int fileDescriptor;

  int minFlash;
  int maxFlash;

//  int minTorch;
//  int maxTorch;

  int maxTime;
};

#endif // PIRFLASHLED_H
