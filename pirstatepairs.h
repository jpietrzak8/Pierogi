#ifndef PIRSTATEPAIRS_H
#define PIRSTATEPAIRS_H

// For air conditioner remotes that maintain state information, we need
// to set up a panel with all the options available to the user.  To do
// this, the "PIRStatePair" structure will contain a list of state names
// and corresponding code values; the keyset object will populate these
// lists of pairs, the AC Panel will display the lists of pairs, and the
// protocol object will retrieve the chosen code values to construct the
// full IR command.

#include <list>
#include <QString>

class PIRStatePair
{
public:
  PIRStatePair(
    QString n,
    unsigned int c);

  QString getName();

  unsigned int getCode();

private:
  QString name;
  unsigned int code;
};

typedef std::list<PIRStatePair *> PIRStatePairs;

// -------- inline method definitions:

inline PIRStatePair::PIRStatePair(
  QString n,
  unsigned int c)
  : name(n),
    code(c)
{
}

inline QString PIRStatePair::getName()
{
  return name;
}

inline unsigned int PIRStatePair::getCode()
{
  return code;
}

#endif // PIRSTATEPAIRS_H
