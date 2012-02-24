#ifndef PIRMAKENAMES_H
#define PIRMAKENAMES_H

class QComboBox;

// The list of brands currently known by Pierogi:
enum PIRMakeName{
  Any_Make,
  Acer_Make,
  Admiral_Make,
  Aiwa_Make,
  Apple_Make,
  Beko_Make,
  Bose_Make,
  Bush_Make,
  Cambridge_Make,
  Canon_Make,
  Daewoo_Make,
  Denon_Make,
  DigitalStream_Make,
  Directv_Make,
  Dish_Make,
  Ei_Make,
  Elgato_Make,
  Emerson_Make,
  Epson_Make,
  Fortec_Make,
  Foxtel_Make,
  GoldStar_Make,
  Grundig_Make,
  Haier_Make,
  Hauppauge_Make,
  Hitachi_Make,
  Homecast_Make,
  HP_Make,
  Huawei_Make,
  Humax_Make,
  Hyundai_Make,
  JVC_Make,
  Kenwood_Make,
  LG_Make,
  Logitech_Make,
  Magnavox_Make,
  Microsoft_Make,
  Mitsubishi_Make,
  Motorola_Make,
  NAD_Make,
  Nokia_Make,
  Onida_Make,
  Panasonic_Make,
  Philco_Make,
  Philips_Make,
  Pinnacle_Make,
  Pioneer_Make,
  Raite_Make,
  RCA_Make,
  Roku_Make,
  Saba_Make,
  Sagem_Make,
  Samsung_Make,
  Sanyo_Make,
  Sharp_Make,
  Sky_Make,
  Sony_Make,
  Technics_Make,
  Tivo_Make,
  Topfield_Make,
  Toshiba_Make,
  United_Make,
  Universum_Make,
  Vestel_Make,
  Virgin_Make,
  Vizio_Make,
  WD_Make,
  Westinghouse_Make,
  Yamaha_Make,
  Zenith_Make
};


// An object of convenience:

#include <map>
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
