﻿/**
 * Marlin 3D Printer Firmware
 * Copyright (c) 2020 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (c) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 *
 */

//
// Temperature Menu
//

#include "../../inc/MarlinConfig.h"
#include "../tft/tft.h"

#if HAS_LCD_MENU && HAS_TEMPERATURE
#include "menu_item.h"
#include "../../module/temperature.h"

#if FAN_COUNT > 1 || ENABLED(SINGLENOZZLE)
#include "../../module/motion.h"
#endif

#if ENABLED(SINGLENOZZLE)
#include "../../module/tool_change.h"
#endif

//
// "Temperature" submenu items
//
void Temperature::lcd_preheat(const uint8_t e, const int8_t indh, const int8_t indb)

{
#if HAS_HOTEND
  if (indh >= 0 && ui.material_preset[indh].hotend_temp > 0)
    setTargetHotend(_MIN(thermalManager.heater_maxtemp[e] - HOTEND_OVERSHOOT, ui.material_preset[indh].hotend_temp), e);
#else
  UNUSED(e);
  UNUSED(indh);
#endif
#if HAS_HEATED_BED
  if (indb >= 0 && ui.material_preset[indb].bed_temp > 0)
    setTargetBed(ui.material_preset[indb].bed_temp);
#else
  UNUSED(indb);
#endif
#if HAS_FAN
  set_fan_speed((
#if FAN_COUNT > 1
                    active_extruder < FAN_COUNT ? active_extruder :
#endif
                                                0),
                ui.material_preset[indh].fan_speed);
#endif
  ui.return_to_status();
}

#if PREHEAT_COUNT

#if HAS_TEMP_HOTEND
inline void _preheat_end(const uint8_t m, const uint8_t e)
{
  thermalManager.lcd_preheat(e, m, -1);
}
#if HAS_HEATED_BED
inline void _preheat_both(const uint8_t m, const uint8_t e)
{
  thermalManager.lcd_preheat(e, m, m);
}
#endif
#endif
#if HAS_HEATED_BED
inline void _preheat_bed(const uint8_t m)
{
  thermalManager.lcd_preheat(-1, -1, m);
}
#endif

#if HAS_TEMP_HOTEND && HAS_HEATED_BED

// Indexed "Preheat ABC" and "Heat Bed" items
#define PREHEAT_ITEMS(M, E)                                                                                             \
  do                                                                                                                    \
  {                                                                                                                     \
    ACTION_ITEM_N_S(E, ui.get_preheat_label(M), MSG_PREHEAT_M_H, [] { _preheat_both(M, MenuItemBase::itemIndex); });    \
    ACTION_ITEM_N_S(E, ui.get_preheat_label(M), MSG_PREHEAT_M_END_E, [] { _preheat_end(M, MenuItemBase::itemIndex); }); \
  } while (0)

#elif HAS_MULTI_HOTEND

// No heated bed, so just indexed "Preheat ABC" items
#define PREHEAT_ITEMS(M, E) ACTION_ITEM_N_S(E, ui.get_preheat_label(M), MSG_PREHEAT_M_H, [] { _preheat_end(M, MenuItemBase::itemIndex); })

#endif

void do_preheat_end_m()
{
  _preheat_end(editable.int8, 0);
}
#if HAS_MULTI_HOTEND || HAS_HEATED_BED

// Set editable.int8 to the Material index before entering this menu
// because MenuItemBase::itemIndex will be re-used by PREHEAT_ITEMS
void menu_preheat_m()
{
  const uint8_t m = editable.int8; // Don't re-use 'editable' in this menu

  START_MENU();
  BACK_ITEM(MSG_BACK);

#if HOTENDS == 1

#if HAS_HEATED_BED
  ACTION_ITEM_S(ui.get_preheat_label(m), MSG_PREHEAT_M, []
                { _preheat_both(editable.int8, 0); });
  ACTION_ITEM_S(ui.get_preheat_label(m), MSG_PREHEAT_M_END, do_preheat_end_m);
#else
  ACTION_ITEM_S(ui.get_preheat_label(m), MSG_PREHEAT_M, do_preheat_end_m);
#endif

#elif HAS_MULTI_HOTEND

  HOTEND_LOOP()
  PREHEAT_ITEMS(editable.int8, e);
  ACTION_ITEM_S(ui.get_preheat_label(m), MSG_PREHEAT_M_ALL, []()
                {
        TERN_(HAS_HEATED_BED, [] { _preheat_bed(editable.int8); });
        HOTEND_LOOP() thermalManager.setTargetHotend(ui.material_preset[editable.int8].hotend_temp, e); });

#endif

#if HAS_HEATED_BED
  ACTION_ITEM_S(ui.get_preheat_label(m), MSG_PREHEAT_M_BEDONLY, []
                { _preheat_bed(editable.int8); });
#endif

  END_MENU();
}

#endif // HAS_MULTI_HOTEND || HAS_HEATED_BED

#endif // PREHEAT_COUNT

#if HAS_TEMP_HOTEND || HAS_HEATED_BED

void lcd_cooldown()
{
  thermalManager.zero_fan_speeds();
  thermalManager.disable_all_heaters();
  ui.return_to_status();
}

#endif // HAS_TEMP_HOTEND || HAS_HEATED_BED

void menu_temperature()
{
#if HAS_TEMP_HOTEND || HAS_HEATED_BED
  bool has_heat = false;
#if HAS_TEMP_HOTEND
  HOTEND_LOOP()
  if (thermalManager.temp_hotend[HOTEND_INDEX].target)
  {
    has_heat = true;
    break;
  }
#endif

#endif

  START_MENU();
  BACK_ITEM(MSG_BACK);

  //
  // Nozzle:
  // Nozzle [1-5]:
  //
#if HOTENDS == 1
  EDIT_ITEM_FAST(int3, MSG_NOZZLE, &thermalManager.temp_hotend[0].target, 0, HEATER_0_MAXTEMP - (HOTEND_OVERSHOOT), []
                 { thermalManager.start_watching_hotend(0); });
#elif HAS_MULTI_HOTEND
  HOTEND_LOOP()
  EDIT_ITEM_FAST_N(int3, e, MSG_NOZZLE_N, &thermalManager.temp_hotend[e].target, 0, thermalManager.heater_maxtemp[e] - (HOTEND_OVERSHOOT), []
                   { thermalManager.start_watching_hotend(MenuItemBase::itemIndex); });
#endif

#if ENABLED(SINGLENOZZLE_STANDBY_TEMP)
  LOOP_S_L_N(e, 1, EXTRUDERS)
  EDIT_ITEM_FAST_N(uint16_3, e, MSG_NOZZLE_STANDBY, &singlenozzle_temp[e], 0, thermalManager.heater_maxtemp[0] - (HOTEND_OVERSHOOT));
#endif

  //
  // Bed:
  //
#if HAS_HEATED_BED
  EDIT_ITEM_FAST(int3, MSG_BED, &thermalManager.temp_bed.target, 0, BED_MAX_TARGET, thermalManager.start_watching_bed);
#endif

  //
  // Chamber:
  //
#if HAS_HEATED_CHAMBER
  EDIT_ITEM_FAST(int3, MSG_CHAMBER, &thermalManager.temp_chamber.target, 0, CHAMBER_MAXTEMP - 10, thermalManager.start_watching_chamber);
#endif

  //
  // Fan Speed:
  //
#if HAS_FAN
  DEFINE_SINGLENOZZLE_ITEM();
#if HAS_FAN0
  _FAN_EDIT_ITEMS(0, FIRST_FAN_SPEED);
#endif
#if HAS_FAN1
  FAN_EDIT_ITEMS(1);
#elif SNFAN(1)
  singlenozzle_item(1);
#endif
#if HAS_FAN2
  FAN_EDIT_ITEMS(2);
#elif SNFAN(2)
  singlenozzle_item(2);
#endif
#if HAS_FAN3
  FAN_EDIT_ITEMS(3);
#elif SNFAN(3)
  singlenozzle_item(3);
#endif
#if HAS_FAN4
  FAN_EDIT_ITEMS(4);
#elif SNFAN(4)
  singlenozzle_item(4);
#endif
#if HAS_FAN5
  FAN_EDIT_ITEMS(5);
#elif SNFAN(5)
  singlenozzle_item(5);
#endif
#if HAS_FAN6
  FAN_EDIT_ITEMS(6);
#elif SNFAN(6)
  singlenozzle_item(6);
#endif
#if HAS_FAN7
  FAN_EDIT_ITEMS(7);
#elif SNFAN(7)
  singlenozzle_item(7);
#endif

#endif // HAS_FAN

#if PREHEAT_COUNT
  //
  // Preheat for Materials 1 to 5

  LOOP_L_N(m, PREHEAT_COUNT)
  {
    editable.int8 = m;
#if HOTENDS > 1 || HAS_HEATED_BED
    SUBMENU_S(ui.get_preheat_label(m), MSG_PREHEAT_M, menu_preheat_m);
#else
    ACTION_ITEM_S(ui.get_preheat_label(m), MSG_PREHEAT_M, do_preheat_end_m);
#endif
  }
#endif
#if HAS_TEMP_HOTEND || HAS_HEATED_BED
  //
  // Cooldown
  //
  if (TERN0(HAS_HEATED_BED, thermalManager.temp_bed.target))
    has_heat = true;
  if (has_heat)
    ACTION_ITEM(MSG_COOLDOWN, lcd_cooldown);
#endif
  END_MENU();
}

#endif

void lcd_setTargetHotend()
{

  static int16_t fresh_data;
  static char fresh_flag;

  if (ui.use_click())
  {
    ui.AC_bar_control = false;
    ui.enable_encoder_multiplier(false);
    thermalManager.setTargetHotend(fresh_data, 0);
    fresh_flag = 0;
    return ui.goto_previous_screen_no_defer();
  }
  ui.defer_status_screen();
  if (fresh_flag == 0)
  {
    ui.AC_bar_control = true;
    ui.enable_encoder_multiplier(true);
    fresh_flag = 1;
    fresh_data = thermalManager.temp_hotend[0].target;
  }

  if (ui.encoderPosition)
  {
    fresh_data += ui.encoderPosition;
    ui.encoderPosition = 0;
    LIMIT(fresh_data, 0, thermalManager.hotend_max_target(0));
    ui.refresh(LCDVIEW_CALL_REDRAW_NEXT);
  }

  if (ui.should_draw())
  {

    char cmd[36];

    MenuEditItemBase::draw_edit_screen(GET_TEXT(MSG_NOZZLE), ui16tostr3rj(fresh_data));
#define SLIDER_LENGTH 224
#define SLIDER_Y_POSITION 140

    tft.canvas((TFT_WIDTH - SLIDER_LENGTH) / 2, SLIDER_Y_POSITION, SLIDER_LENGTH, 9);
    tft.set_background(COLOR_PROGRESS_BG);
    tft.add_rectangle(0, 0, SLIDER_LENGTH, 9, COLOR_PROGRESS_FRAME);
    tft.add_bar(1, 1, ((SLIDER_LENGTH - 2) * fresh_data) / thermalManager.hotend_max_target(0), 7, COLOR_PROGRESS_BAR);
  }
}
//////*****************edit  bed******************************
void lcd_setTargetBED()
{

  static int16_t fresh_data;
  static char fresh_flag;

  if (ui.use_click())
  {
    ui.AC_bar_control = false;
    ui.enable_encoder_multiplier(false);
    thermalManager.temp_bed.target = fresh_data;
    thermalManager.start_watching_bed();
    fresh_flag = 0;
    return ui.goto_previous_screen_no_defer();
  }
  ui.defer_status_screen();
  if (fresh_flag == 0)
  {
    ui.AC_bar_control = true;
    ui.enable_encoder_multiplier(true);
    fresh_flag = 1;
    fresh_data = thermalManager.temp_bed.target;
  }

  if (ui.encoderPosition)
  {
    fresh_data += ui.encoderPosition;
    ui.encoderPosition = 0;
    LIMIT(fresh_data, 0, BED_MAX_TARGET);
    ui.refresh(LCDVIEW_CALL_REDRAW_NEXT);
  }

  if (ui.should_draw())
  {

    MenuEditItemBase::draw_edit_screen(GET_TEXT(MSG_BED), ui16tostr3rj(fresh_data));
#define SLIDER_LENGTH 224
#define SLIDER_Y_POSITION 140

    tft.canvas((TFT_WIDTH - SLIDER_LENGTH) / 2, SLIDER_Y_POSITION, SLIDER_LENGTH, 9);
    tft.set_background(COLOR_PROGRESS_BG);
    tft.add_rectangle(0, 0, SLIDER_LENGTH, 9, COLOR_PROGRESS_FRAME);
    tft.add_bar(1, 1, ((SLIDER_LENGTH - 2) * fresh_data) / BED_MAX_TARGET, 7, COLOR_PROGRESS_BAR);
  }
}

//#endif // HAS_LCD_MENU && HAS_TEMPERATURE



