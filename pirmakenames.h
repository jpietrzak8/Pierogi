//
// pirmakenames.h
//
// Copyright 2012 - 2014 by John Pietrzak  (jpietrzak8@gmail.com)
//
// This file is part of Pierogi.
//
// Pierogi is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either version 2
// of the License, or (at your option) any later version.
//
// Pierogi is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Pierogi; if not, write to the Free Software Foundation,
// Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//

#ifndef PIRMAKENAMES_H
#define PIRMAKENAMES_H

class QComboBox;

// The list of brands currently known by Pierogi:
enum PIRMakeName{
  Any_Make,
  Acer_Make,
  ADB_Make,
  Admiral_Make,
  Airtech_Make,
  Aiwa_Make,
  Alpine_Make,
  Anitech_Make,
  AOC_Make,
  Apex_Make,
  Apple_Make,
  Arcam_Make,
  Astro_Make,
  BangAndOlufsen_Make,
  Beko_Make,
  BenQ_Make,
  Blaupunkt_Make,
  Bose_Make,
  Bush_Make,
  Cambridge_Make,
  Canon_Make,
  Changhong_Make,
  Cisco_Make,
  Comag_Make,
  Compro_Make,
  Creative_Make,
  Crown_Make,
  CrownMustang_Make,
  Daewoo_Make,
  Dell_Make,
  Denon_Make,
  DeutscheTelekom_Make,
  DigitalStream_Make,
  Directv_Make,
  Dish_Make,
  Dreambox_Make,
  DSE_Make,
  Dune_Make,
  Dynex_Make,
  Ei_Make,
  Elgato_Make,
  Emerson_Make,
  Emtec_Make,
  Epson_Make,
  Fortec_Make,
  Foxtel_Make,
  Frontech_Make,
  Gadmei_Make,
  GeneralElectric_Make,
  Genius_Make,
  GoldStar_Make,
  Goodmans_Make,
  Grundig_Make,
  Haier_Make,
  Hantarex_Make,
  HarmanKardon_Make,
  Hauppauge_Make,
  Hitachi_Make,
  Homecast_Make,
  HP_Make,
  Huawei_Make,
  Humax_Make,
  Hyundai_Make,
  ILO_Make,
  Insignia_Make,
  IRobot_Make,
  JVC_Make,
  Kaon_Make,
  Kathrein_Make,
  Kenwood_Make,
  Keymat_Make,
  Konka_Make,
  Lasko_Make,
  Lexuz_Make,
  LG_Make,
  Lifetec_Make,
  Loewe_Make,
  Logitech_Make,
  Magnavox_Make,
  Magnum_Make,
  Majestic_Make,
  Manta_Make,
  Medialink_Make,
  Medion_Make,
  Microsoft_Make,
  Minolta_Make,
  Mitsubishi_Make,
  Motorola_Make,
  MTLogic_Make,
  Multichoice_Make,
  NAD_Make,
  NEC_Make,
  Nikon_Make,
  Nokia_Make,
  Octagon_Make,
  Olympus_Make,
  Onida_Make,
  Onkyo_Make,
  OpenBox_Make,
  Orion_Make,
  Panasonic_Make,
  Pentax_Make,
  Philco_Make,
  Philips_Make,
  Pinnacle_Make,
  Pioneer_Make,
  Proview_Make,
  QNAP_Make,
  Raite_Make,
  RCA_Make,
  Roku_Make,
  RussellHobbs_Make,
  Saba_Make,
  Sagem_Make,
  Sagemcom_Make,
  Samsung_Make,
  Sanyo_Make,
  Sharp_Make,
  SilverCrest_Make,
  Sinotec_Make,
  Sky_Make,
  Sony_Make,
  Starhub_Make,
  Starsat_Make,
  Strong_Make,
  Sylvania_Make,
  Technics_Make,
  Technisat_Make,
  Telefunken_Make,
  Telenet_Make,
  Thomson_Make,
  Tivo_Make,
  Topfield_Make,
  Toshiba_Make,
  Triax_Make,
  United_Make,
  Universum_Make,
  Venturer_Make,
  Vestel_Make,
  Viewsat_Make,
  Viewsonic_Make,
  Virgin_Make,
  Vizio_Make,
  WD_Make,
  Westinghouse_Make,
  Wharfedale_Make,
  Wiwa_Make,
  Xcruiser_Make,
  Xoro_Make,
  Yamaha_Make,
  Zenith_Make
};


// An object of convenience:

#include <map>
#include <QString>
typedef std::map<PIRMakeName, const char *> MakeCollection;
typedef std::map<QString, PIRMakeName> ReverseMakeCollection;

class PIRMakeMgr
{
public:
  PIRMakeMgr();

  const char *getMakeString(
    PIRMakeName n);

  PIRMakeName getMakeID(
    QString name);

  void populateComboBox(
    QComboBox *cb);

private:
  MakeCollection makes;
  ReverseMakeCollection makeIDs;
};

#endif // PIRMAKENAMES_H
