#ifndef PIREXCEPTION_H
#define PIREXCEPTION_H

#include <string>

class PIRException
{
public:
  PIRException(
    std::string s)
  : errStr(s)
  {}

  std::string getError();

  void display();

private:
  std::string errStr;
};


inline std::string PIRException::getError()
{
  return errStr;
}

#endif // PIREXCEPTION_H
