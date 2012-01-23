#ifndef PIRMAKENAMES_H
#define PIRMAKENAMES_H

#include <QComboBox>
#include <map>

// The list of brands currently known by Pierogi:
enum PIRMakeName{
  Any_Make,
  Apple_Make,
  Denon_Make,
  Ei_Make,
  GoldStar_Make,
  Hauppauge_Make,
  Hitachi_Make,
  JVC_Make,
  LG_Make,
  Mitsubishi_Make,
  Nokia_Make,
  Panasonic_Make,
  Philips_Make,
  Pinnacle_Make,
  Raite_Make,
  RCA_Make,
  Sagem_Make,
  Samsung_Make,
  Sanyo_Make,
  Sharp_Make,
  Sony_Make,
  Toshiba_Make,
  Westinghouse_Make,
  Yamaha_Make,
  Zenith_Make
};


// An object of convenience:

typedef std::map<PIRMakeName, const char *> MakeCollection;

class PIRMakeMgr
{
public:
  PIRMakeMgr();

  const char *getMakeString(
    PIRMakeName n);

  void populateComboBox(
    QComboBox *cb);

private:
  MakeCollection makes;
};

#endif // PIRMAKENAMES_H
