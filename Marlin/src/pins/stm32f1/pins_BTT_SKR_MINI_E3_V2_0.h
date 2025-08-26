/**
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
#pragma once

#ifndef BOARD_INFO_NAME
  #define BOARD_INFO_NAME "BTT SKR Mini E3 V2.0"
#endif

#define BOARD_CUSTOM_BUILD_FLAGS -DTONE_CHANNEL=4 -DTONE_TIMER=4 -DTIMER_TONE=4

// Onboard I2C EEPROM
#if NO_EEPROM_SELECTED
  #define I2C_EEPROM
  #define SOFT_I2C_EEPROM
  #define MARLIN_EEPROM_SIZE              0x1000  // 4K
  #define I2C_SDA_PIN                       PB_7
  #define I2C_SCL_PIN                       PB_6
  #undef NO_EEPROM_SELECTED
#endif

#define FAN0_PIN                            PC_6

//
// USB connect control
//
// DISABLED: USB connect control prevents USB enumeration
// Let USB enumerate normally without software control
#undef USB_CONNECT_PIN

/**
 *            SKR Mini E3 V2.0
 *                 ------
 * (BEEPER)  PB5  | 1  2 | PA15 (BTN_ENC)
 * (BTN_EN1) PC_14| 3  4 | RESET  // MOVED from PA9 to free up USB pin
 * (BTN_EN2) PC_15| 5  6 | PB9  (LCD_D4)  // MOVED from PA10 to free up USB pin
 * (LCD_RS)  PB8  | 7  8 | PB15 (LCD_EN)
 *            GND | 9 10 | 5V
 *                 ------
 *                  EXP1
 */
#define EXP1_01_PIN                         PB_5
#define EXP1_02_PIN                         PA_15
#define EXP1_03_PIN                         PC_14  // MOVED from PA9 to free up USB pin
#define EXP1_04_PIN                         -1    // RESET
#define EXP1_05_PIN                         PC_15  // MOVED from PA10 to free up USB pin
#define EXP1_06_PIN                         PB_9
#define EXP1_07_PIN                         PB_8
#define EXP1_08_PIN                         PB_15

#include "pins_BTT_SKR_MINI_E3_common.h"

// Release PA13/PA14 (led, usb control) from SWD pins
#define DISABLE_DEBUG

#ifndef BOARD_NEOPIXEL_PIN
  #define BOARD_NEOPIXEL_PIN                PA_8   // LED driving pin
#endif

#ifndef PS_ON_PIN
  #define PS_ON_PIN                         PC_13  // Power Supply Control
#endif

#define FAN1_PIN                            PC_7

#ifndef CONTROLLER_FAN_PIN
  #define CONTROLLER_FAN_PIN            FAN1_PIN
#endif

// TMC UART DISABLED to free up PC10/PC11 for USB functionality
// Using A4988 drivers instead of TMC2209 to avoid pin conflicts
#if 0 // HAS_TMC_UART - DISABLED
  /**
   * TMC220x stepper drivers
   * Hardware serial communication ports
   */
  #define X_HARDWARE_SERIAL  MSerial4
  #define Y_HARDWARE_SERIAL  MSerial4
  #define Z_HARDWARE_SERIAL  MSerial4
  #define E0_HARDWARE_SERIAL MSerial4

  // Default TMC slave addresses
  #ifndef X_SLAVE_ADDRESS
    #define X_SLAVE_ADDRESS                    0
  #endif
  #ifndef Y_SLAVE_ADDRESS
    #define Y_SLAVE_ADDRESS                    2
  #endif
  #ifndef Z_SLAVE_ADDRESS
    #define Z_SLAVE_ADDRESS                    1
  #endif
  #ifndef E0_SLAVE_ADDRESS
    #define E0_SLAVE_ADDRESS                   3
  #endif
  static_assert(X_SLAVE_ADDRESS == 0, "X_SLAVE_ADDRESS must be 0 for BOARD_SKR_MINI_E3_V2_0.");
  static_assert(Y_SLAVE_ADDRESS == 2, "Y_SLAVE_ADDRESS must be 2 for BOARD_SKR_MINI_E3_V2_0.");
  static_assert(Z_SLAVE_ADDRESS == 1, "Z_SLAVE_ADDRESS must be 1 for BOARD_SKR_MINI_E3_V2_0.");
  static_assert(E0_SLAVE_ADDRESS == 3, "E0_SLAVE_ADDRESS must be 3 for BOARD_SKR_MINI_E3_V2_0.");
#endif

// Pins for documentation and sanity checks only.
// Changing these will not change the pin they are on.

// Hardware UART pins
// UART1 pins freed up for USB functionality (button inputs moved to PC14/PC15)
// #define UART1_TX_PIN                        PA_9   // default usage LCD connector
// #define UART1_RX_PIN                        PA_10  // default usage LCD connector
#define UART2_TX_PIN                        PA_2   // default usage TFT connector
#define UART2_RX_PIN                        PA_3   // default usage TFT connector
#define UART3_TX_PIN                        PB_10  // default usage Y_STEP_PIN
#define UART3_RX_PIN                        PB_11  // default usage Y_ENABLE_PIN
// UART4 pins freed up for USB functionality (TMC UART disabled)
// #define UART4_TX_PIN                        PC_10  // default usage TMC UART
// #define UART4_RX_PIN                        PC_11  // default usage TMC UART
#define UART5_TX_PIN                        PC_12  // default usage POWER_LOSS_PIN
#define UART5_RX_PIN                        PD_2   // default usage E0_ENABLE_PIN

//
// Touch Screen pins - NOT NEEDED for TFTGLCD_PANEL_SPI
// TFTGLCD handles touch through main SPI connection (Software SPI)
// No separate touch pins required
//

//
// SD Auto-Detection - RESTORED to original pin
// No jumper wire needed - uses standard SD detect pin PC_4
//

//
// Software SPI Configuration for TFTGLCD_PANEL_SPI
// Uses available EXP1 connector pins since hardwired SPI pins are not accessible
//
#if ENABLED(TFTGLCD_PANEL_SPI)
  // Use Software SPI with available EXP1 connector pins
  // Since PA4-PA7 are not accessible on TFT connector, we use Software SPI
  
  // Override default TFTGLCD_CS to prevent pin conflicts
  #undef TFTGLCD_CS
  
  // Map TFTGLCD pins to available EXP1 connector pins (Software SPI)
  #define TFTGLCD_SCK_PIN                   PB_9   // EXP1-6 (Software SPI Clock)
  #define TFTGLCD_MOSI_PIN                  PB_8   // EXP1-7 (Software SPI Data In)
  #define TFTGLCD_MISO_PIN                  PB_5   // EXP1-1 (Software SPI Data Out)
  #define TFTGLCD_CS_PIN                    PA_15  // EXP1-2 (Display Chip Select)
  
  // Create alias for existing TFTGLCD code
  #define TFTGLCD_CS                        TFTGLCD_CS_PIN
  
  // SD Card CS pin (separate from display CS)
  #define TFTGLCD_SD_CS_PIN                 PB_15  // EXP1-8 (SD Card CS)
  
  // Display control pins (already connected)
  #define TFTGLCD_DC_PIN                    PA_3   // TFT TX2 (Data/Command)
  #define TFTGLCD_RST_PIN                   PA_2   // TFT RX2 (Reset)
  
  // Power pins (already connected)
  #define TFTGLCD_VCC_PIN                   -1     // 3.3V from SWD area
  #define TFTGLCD_GND_PIN                   -1     // GND from SWD area
  
  // Force Software SPI since we're not using hardware SPI pins
  #define FORCE_SOFT_SPI
#endif


