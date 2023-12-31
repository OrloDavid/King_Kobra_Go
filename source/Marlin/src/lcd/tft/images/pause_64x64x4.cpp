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

#include "../../../inc/MarlinConfigPre.h"

#if HAS_GRAPHICAL_TFT
#pragma pack(4)
//extern const uint8_t pause_64x64x4[2048] __attribute((aligned (4)))= {
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x77, 0x77, 0x77, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x87, 0x77, 0x77, 0x77, 0x77, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xD8, 0x78, 0x88, 0x88, 0x87, 0x8D, 0xFF, 0xFF, 0xFF, 0xFF, 0xF9, 0x78, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE8, 0x78, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF8, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0x67, 0x88, 0x88, 0x87, 0x8E, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x9F, 0xFF, 0xFF, 0xFF, 0xFF, 0xD7, 0x67, 0x88, 0x88, 0x87, 0x8D, 0xFF, 0xFF, 0xFF, 0xFF, 0xF7, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x77, 0x77, 0x77, 0x77, 0x76, 0x67, 0x88, 0x88, 0x88, 0x88, 0x77, 0x77, 0x77, 0x77, 0x76, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x66, 0x66, 0x66, 0x66, 0x66, 0x67, 0x88, 0x88, 0x88, 0x87, 0x66, 0x66, 0x66, 0x66, 0x66, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x66, 0x66, 0x66, 0x66, 0x66, 0x77, 0x88, 0x88, 0x88, 0x87, 0x76, 0x66, 0x66, 0x66, 0x66, 0x67, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x77, 0x77, 0x77, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x87, 0x77, 0x77, 0x77, 0x77, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
//  0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88
//};

extern const uint8_t pause_48x48x1[288] __attribute((aligned (4))){
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFF,0xFF,
0xFF,0x00,0x03,0xFF,0xFF,0xFF,0xFF,0xC0,0x06,0x00,0x00,0x00,0x00,0x60,0x0C,0x00,
0x00,0x00,0x00,0x30,0x0C,0x00,0x00,0x00,0x00,0x30,0x0C,0x00,0x00,0x00,0x00,0x30,
0x0C,0x00,0x00,0x00,0x00,0x30,0x0C,0x00,0x00,0x00,0x00,0x30,0x0C,0x00,0x00,0x00,
0x00,0x30,0x0C,0x00,0x00,0x00,0x00,0x30,0x0C,0x00,0x00,0x00,0x00,0x30,0x0C,0x04,
0x00,0xF1,0xE0,0x30,0x0C,0x06,0x00,0xF1,0xE0,0x30,0x0C,0x07,0x00,0xF1,0xE0,0x30,
0x0C,0x07,0x80,0xF1,0xE0,0x30,0x0C,0x07,0xC0,0xF1,0xE0,0x30,0x0C,0x07,0xE0,0xF1,
0xE0,0x30,0x0C,0x07,0xF0,0xF1,0xE0,0x30,0x0C,0x07,0xF8,0xF1,0xE0,0x30,0x0C,0x07,
0xFC,0xF1,0xE0,0x30,0x0C,0x07,0xFE,0xF1,0xE0,0x30,0x0C,0x07,0xFF,0xF1,0xE0,0x30,
0x0C,0x07,0xFE,0xF1,0xE0,0x30,0x0C,0x07,0xFC,0xF1,0xE0,0x30,0x0C,0x07,0xF8,0xF1,
0xE0,0x30,0x0C,0x07,0xF0,0xF1,0xE0,0x30,0x0C,0x07,0xE0,0xF1,0xE0,0x30,0x0C,0x07,
0xC0,0xF1,0xE0,0x30,0x0C,0x07,0x80,0xF1,0xE0,0x30,0x0C,0x07,0x00,0xF1,0xE0,0x30,
0x0C,0x06,0x00,0xF1,0xE0,0x30,0x0C,0x04,0x00,0xF1,0xE0,0x30,0x0C,0x00,0x00,0x00,
0x00,0x30,0x0C,0x00,0x00,0x00,0x00,0x30,0x0C,0x00,0x00,0x00,0x00,0x30,0x0C,0x00,
0x00,0x00,0x00,0x30,0x0C,0x00,0x00,0x00,0x00,0x30,0x0C,0x00,0x00,0x00,0x00,0x30,
0x0C,0x00,0x00,0x00,0x00,0x30,0x0C,0x00,0x00,0x00,0x00,0x30,0x0C,0x00,0x00,0x00,
0x00,0x30,0x06,0x00,0x00,0x00,0x00,0x60,0x03,0xFF,0xFF,0xFF,0xFF,0xC0,0x01,0xFF,
0xFF,0xFF,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};

extern const uint8_t STOP_48x48x1[288] __attribute((aligned (4))){
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xFF,0xFF,0xFF,
0xFF,0x00,0x03,0xFF,0xFF,0xFF,0xFF,0xC0,0x06,0x00,0x00,0x00,0x00,0x60,0x0C,0x00,
0x00,0x00,0x00,0x30,0x0C,0x00,0x00,0x00,0x00,0x30,0x0C,0x00,0x00,0x00,0x00,0x30,
0x0C,0x00,0x00,0x00,0x00,0x30,0x0C,0x00,0x00,0x00,0x00,0x30,0x0C,0x00,0x0F,0xF0,
0x00,0x30,0x0C,0x00,0x3F,0xFC,0x00,0x30,0x0C,0x00,0xFF,0xFE,0x00,0x30,0x0C,0x01,
0xFF,0xFF,0x00,0x30,0x0C,0x01,0xFF,0xFF,0x80,0x30,0x0C,0x07,0xFF,0xFF,0xC0,0x30,
0x0C,0x07,0xFF,0xFF,0xE0,0x30,0x0C,0x0F,0xFF,0xFF,0xF0,0x30,0x0C,0x0F,0xFF,0xFF,
0xF0,0x30,0x0C,0x1F,0xFF,0xFF,0xF8,0x30,0x0C,0x1F,0xFF,0xFF,0xF8,0x30,0x0C,0x1F,
0xFF,0xFF,0xF8,0x30,0x0C,0x1F,0xFF,0xFF,0xF8,0x30,0x0C,0x1F,0xFF,0xFF,0xF8,0x30,
0x0C,0x1F,0xFF,0xFF,0xF8,0x30,0x0C,0x1F,0xFF,0xFF,0xF8,0x30,0x0C,0x1F,0xFF,0xFF,
0xF8,0x30,0x0C,0x1F,0xFF,0xFF,0xF8,0x30,0x0C,0x0F,0xFF,0xFF,0xF0,0x30,0x0C,0x0F,
0xFF,0xFF,0xF0,0x30,0x0C,0x07,0xFF,0xFF,0xE0,0x30,0x0C,0x07,0xFF,0xFF,0xE0,0x30,
0x0C,0x03,0xFF,0xFF,0xC0,0x30,0x0C,0x03,0xFF,0xFF,0x80,0x30,0x0C,0x01,0xFF,0xFF,
0x00,0x30,0x0C,0x00,0xFF,0xFE,0x00,0x30,0x0C,0x00,0x1F,0xF0,0x00,0x30,0x0C,0x00,
0x00,0x00,0x00,0x30,0x0C,0x00,0x00,0x00,0x00,0x30,0x0C,0x00,0x00,0x00,0x00,0x30,
0x0C,0x00,0x00,0x00,0x00,0x30,0x0C,0x00,0x00,0x00,0x00,0x30,0x0C,0x00,0x00,0x00,
0x00,0x30,0x06,0x00,0x00,0x00,0x00,0x60,0x03,0xFF,0xFF,0xFF,0xFF,0xC0,0x01,0xFF,
0xFF,0xFF,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
};
#endif // HAS_GRAPHICAL_TFT



