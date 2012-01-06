#ifndef PIRMODPROBE_H
#define PIRMODPROBE_H

class PIRModprobe
{
public:
  PIRModprobe();

  ~PIRModprobe();

  int loadRX51Module();

private:
  int unloadRX51Module();

  int modprobeRX51Module(
    bool unloadModule);

  bool successfullyLoadedModule;
};


inline int PIRModprobe::loadRX51Module()
{
  return modprobeRX51Module(false);
}

inline int PIRModprobe::unloadRX51Module()
{
  return modprobeRX51Module(true);
}

#endif // PIRMODPROBE_H
