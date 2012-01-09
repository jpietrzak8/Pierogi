#ifndef PIRMODPROBE_H
#define PIRMODPROBE_H

class PIRModprobe
{
public:
  PIRModprobe();

  ~PIRModprobe();

  int loadRX51Module();

  int unloadRX51Module();

private:
  bool successfullyLoadedModule;
};

#endif // PIRMODPROBE_H
