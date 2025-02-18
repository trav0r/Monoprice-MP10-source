/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
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
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * MALYAN M200 pin assignments
 */

#define BOARD_NAME "MALYAN"


// Enable EEPROM Emulation for this board
// This setting should probably be in configuration.h
// but it is literally the only board which uses it.
#define FLASH_EEPROM_EMULATION

#define SDSS SS_PIN

#define BTN_ENC             PA9
#define BTN_EN1             PB6
#define BTN_EN2             PB7
#define BEEPER_PIN      -1
#define DOGLCD_A0       PA10
#define DOGLCD_CS       PA8
#define DOGLCD_SCK		PC10
#define DOGLCD_MOSI		PC9

//
// Limit Switches
//
/*#define X_MIN_PIN          PC13
#define Y_MIN_PIN          PC14
#define Z_MIN_PIN          PC15*/
#define X_STOP_PIN          PC2
#define Y_STOP_PIN          PC1
#define Z_STOP_PIN          PC0
//#define Z_STOP_PIN          PC15

//
// Steppers
//
// X & Y enable are the same
#define X_STEP_PIN         PB15
#define X_DIR_PIN          PC7
#define X_ENABLE_PIN       PC6

#define Y_STEP_PIN         PB12
#define Y_DIR_PIN          PB13
#define Y_ENABLE_PIN       PB14

#define Z_STEP_PIN         PB1
#define Z_DIR_PIN          PB2
#define Z_ENABLE_PIN       PB10

#define E0_STEP_PIN        PA5
#define E0_DIR_PIN         PC4
#define E0_ENABLE_PIN      PC5

#define MOTOR_CURRENT_PWM_XY_PIN PA7
#define MOTOR_CURRENT_PWM_Z_PIN -1
#define MOTOR_CURRENT_PWM_E_PIN PA6
//
// Temperature Sensors
//
#define TEMP_0_PIN         PA1   // Analog Input (HOTEND0 thermistor)
#define TEMP_BED_PIN       PA3   // Analog Input (BED thermistor)

//
// Heaters / Fans
//
#define HEATER_0_PIN       PC14 // HOTEND0 MOSFET
#define HEATER_BED_PIN     PC13 // BED MOSFET

// This board has only the controller fan and the extruder fan
// If someone hacks to put a direct power fan on the controller, PB3 could
// be used as a separate print cooling fan.
//#define ORIG_E0_AUTO_FAN_PIN PB8
//#define E0_AUTO_FAN_PIN     PA4
//#define CONTROLLER_FAN_PIN  PB3

// FAN_PIN is commented out here because the M200 example
// Configuration_adv.h does NOT override E0_AUTO_FAN_PIN.
#define FAN_PIN            PA0 // FAN1 header on board - PRINT FAN
#define FAN1_PIN           -1 // FAN2 header on board - CONTROLLER FAN
#define FAN2_PIN           -1 // FAN3 header on board - EXTRUDER0 FAN
