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
// DISABLED: PA_14 USB connect control prevents USB enumeration
// Let USB enumerate normally without software control
//#define USB_CONNECT_PIN                     PA_14

/**
 *            SKR Mini E3 V2.0
 *                 ------
 * (BEEPER)  PB5  | 1  2 | PA15 (BTN_ENC)
 * (BTN_EN1) PA9  | 3  4 | RESET
 * (BTN_EN2) PA10   5  6 | PB9  (LCD_D4)
 * (LCD_RS)  PB8  | 7  8 | PB15 (LCD_EN)
 *            GND | 9 10 | 5V
 *                 ------
 *                  EXP1
 */
#define EXP1_01_PIN                         PB_5
#define EXP1_02_PIN                         PA_15
#define EXP1_03_PIN                         PA_9
#define EXP1_04_PIN                         -1    // RESET
#define EXP1_05_PIN                         PA_10
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

#if HAS_TMC_UART
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
#define UART1_TX_PIN                        PA_9   // default usage LCD connector
#define UART1_RX_PIN                        PA_10  // default usage LCD connector
#define UART2_TX_PIN                        PA_2   // default usage TFT connector
#define UART2_RX_PIN                        PA_3   // default usage TFT connector
#define UART3_TX_PIN                        PB_10  // default usage Y_STEP_PIN
#define UART3_RX_PIN                        PB_11  // default usage Y_ENABLE_PIN
#define UART4_TX_PIN                        PC_10  // default usage TMC UART
#define UART4_RX_PIN                        PC_11  // default usage TMC UART
#define UART5_TX_PIN                        PC_12  // default usage POWER_LOSS_PIN
#define UART5_RX_PIN                        PD_2   // default usage E0_ENABLE_PIN

//
// Touch Screen pins - NOT NEEDED for TFTGLCD_PANEL_SPI
// TFTGLCD handles touch through main SPI connection (PA_5/6/7)
// No separate touch pins required
//

//
// SD Auto-Detection - RESTORED to original pin
// No jumper wire needed - uses standard SD detect pin PC_4
//

//
// Custom Hardware SPI Configuration for TFTGLCD_PANEL_SPI
// Uses available pins mapped to hardware SPI peripheral
//
#if ENABLED(TFTGLCD_PANEL_SPI)
  // Use Hardware SPI but map to available pins
  // STM32F103RE has multiple SPI peripherals - we'll use SPI2 on PB13/PB14/PB15
  
  // Override default TFTGLCD_CS to prevent pin conflicts
  #undef TFTGLCD_CS
  
  // Map TFTGLCD pins to available hardware SPI pins
  #define TFTGLCD_SCK_PIN                   PB_13  // SPI2_SCK (Hardware SPI)
  #define TFTGLCD_MOSI_PIN                  PB_15  // SPI2_MOSI (Hardware SPI)
  #define TFTGLCD_MISO_PIN                  PB_14  // SPI2_MISO (Hardware SPI)
  #define TFTGLCD_CS_PIN                    PA_15  // EXP1-2 (Display Chip Select)
  
  // Create alias for existing TFTGLCD code
  #define TFTGLCD_CS                        TFTGLCD_CS_PIN
  
  // SD Card CS pin (separate from display CS)
  #define TFTGLCD_SD_CS_PIN                 PB_12  // SPI2_NSS (Hardware SPI)
  
  // Display control pins (already connected)
  #define TFTGLCD_DC_PIN                    PA_3   // TFT TX2 (Data/Command)
  #define TFTGLCD_RST_PIN                   PA_2   // TFT RX2 (Reset)
  
  // Power pins (already connected)
  #define TFTGLCD_VCC_PIN                   -1     // 3.3V from SWD area
  #define TFTGLCD_GND_PIN                   -1     // GND from SWD area
#endif


