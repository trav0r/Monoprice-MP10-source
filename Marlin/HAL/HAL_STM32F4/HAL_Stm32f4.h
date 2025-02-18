/**
 * Marlin 3D Printer Firmware
 *
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 * Copyright (c) 2016 Bob Cousins bobcousins42@googlemail.com
 * Copyright (c) 2015-2016 Nico Tonnhofer wurstnase.reprap@gmail.com
 * Copyright (c) 2017 Victor Perez
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
 * HAL for stm32duino.com based on Libmaple and compatible (STM32F1)
 */

#ifndef _HAL_STM32F4_H
#define _HAL_STM32F4_H

#undef DEBUG_NONE

#ifndef vsnprintf_P
  #define vsnprintf_P vsnprintf
#endif

// --------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------

#include <stdint.h>
//#include <Arduino.h>

// --------------------------------------------------------------------------
// Undefine DEBUG_ settings
// --------------------------------------------------------------------------


#undef DEBUG_NONE
#undef DEBUG_FAULT
#undef DEBUG_ALL

// --------------------------------------------------------------------------
// Includes
// --------------------------------------------------------------------------
#include "intrinsics.h"

#include "fastio_Stm32f4.h"
#include "HAL_timers_Stm32f4.h"

#include "io.h"
#include "usb_serial.h"
#define PROGMEM
#define byte uint8

// --------------------------------------------------------------------------
// Defines
// --------------------------------------------------------------------------

#define SERIAL_PORT -1
#define MYSERIAL0 SerialUSB
#define NUM_SERIAL 1

/**
 * TODO: review this to return 1 for pins that are not analog input
 */
#ifndef analogInputToDigitalPin
  #define analogInputToDigitalPin(p) (p)
#endif

#define CRITICAL_SECTION_START  __disable_interrupt();
#define CRITICAL_SECTION_END    __enable_interrupt();

// On AVR this is in math.h?
#define square(x) ((x)*(x))

#ifndef strncpy_P
  #define strncpy_P(dest, src, num) strncpy((dest), (src), (num))
#endif

// Fix bug in pgm_read_ptr
#undef pgm_read_ptr
#define pgm_read_ptr(addr) (*(addr))

#define RST_POWER_ON   1
#define RST_EXTERNAL   2
#define RST_BROWN_OUT  4
#define RST_WATCHDOG   8
#define RST_JTAG       16
#define RST_SOFTWARE   32
#define RST_BACKUP     64

// --------------------------------------------------------------------------
// Types
// --------------------------------------------------------------------------

typedef int8_t pin_t;

// --------------------------------------------------------------------------
// Public Variables
// --------------------------------------------------------------------------

/** result of last ADC conversion */
extern uint16_t HAL_adc_result;

// --------------------------------------------------------------------------
// Public functions
// --------------------------------------------------------------------------

// Disable interrupts
#define cli() __disable_interrupt()

// Enable interrupts
#define sei() __enable_interrupt()

// Memory related
#define __bss_end __bss_end__

/** clear reset reason */
void HAL_clear_reset_source (void);

/** reset reason */
uint8_t HAL_get_reset_source (void);

//extern void _delay_ms(int delay);
#define _delay_ms   delay
extern void delay(uint32_t ms);

/*
extern "C" {
  int freeMemory(void);
}
*/

//extern "C" char* _sbrk(int incr);
/*
static int freeMemory() {
  volatile int top;
  top = (int)((char*)&top - reinterpret_cast<char*>(_sbrk(0)));
  return top;
}
*/
/*static int freeMemory() {
  volatile char top;
  return &top - reinterpret_cast<char*>(_sbrk(0));
}*/

// SPI: Extended functions which take a channel number (hardware SPI only)
extern void spiBegin();
extern void spiInit(uint8_t spiRate);
extern void spiBeginTransaction(uint32_t spiClock, uint8_t bitOrder, uint8_t dataMode);
extern uint8_t spiRec();
extern void spiRead(uint8_t* buf, uint16_t nbyte);
extern void spiSend(uint8_t data);
extern void spiSendBlock(uint8_t token, const uint8_t* buf);
extern void digitalWrite(uint8 pin, uint8 value);
extern uint32 digitalRead(uint8 pin);


// EEPROM

/**
 * TODO: Write all this eeprom stuff. Can emulate eeprom in flash as last resort.
 * Wire library should work for i2c eeproms.
 */
void eeprom_write_byte(unsigned char *pos, unsigned char value);
unsigned char eeprom_read_byte(unsigned char *pos);
void eeprom_read_block (void *__dst, const void *__src, size_t __n);
void eeprom_update_block (const void *__src, void *__dst, size_t __n);

// ADC

#define HAL_ANALOG_SELECT(pin) pinMode(pin, INPUT_ANALOG);

void HAL_adc_init(void);

#define HAL_START_ADC(pin)  HAL_adc_start_conversion(pin)
#define HAL_READ_ADC        HAL_adc_result

void HAL_adc_start_conversion(const uint8_t adc_pin);

uint16_t HAL_adc_get_result(void);

/* Todo: Confirm none of this is needed.
uint16_t HAL_getAdcReading(uint8_t chan);

void HAL_startAdcConversion(uint8_t chan);
uint8_t HAL_pinToAdcChannel(int pin);

uint16_t HAL_getAdcFreerun(uint8_t chan, bool wait_for_conversion = false);
//uint16_t HAL_getAdcSuperSample(uint8_t chan);

void HAL_enable_AdcFreerun(void);
//void HAL_disable_AdcFreerun(uint8_t chan);

*/
extern int32_t map(int32_t value, int32_t fromStart, int32_t fromEnd,
     int32_t toStart, int32_t toEnd);
#define GET_PIN_MAP_PIN(index) index
#define GET_PIN_MAP_INDEX(pin) pin
#define PARSED_PIN_INDEX(code, dval) parser.intval(code, dval)

#endif // _HAL_STM32F1_H
