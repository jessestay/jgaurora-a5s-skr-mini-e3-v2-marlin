# 🚀 JGAurora A5S + SKR Mini E3 V2.0 + Touchscreen Firmware

Custom Marlin 2.1.2.5 firmware for JGAurora A5S 3D printer with BigTreeTech SKR Mini E3 V2.0 motherboard, featuring TFTGLCD touchscreen support, NeoPixel LEDs, filament runout sensor, and SD card auto-detection.

## ✨ Features

- **🎯 Custom Configuration**: Optimized for JGAurora A5S (310x310x330mm build volume)
- **🖥️ Touchscreen Support**: TFTGLCD_PANEL_SPI with integrated touch functionality
- **💡 NeoPixel LEDs**: Addressable RGB LED strips (temporarily disabled for compilation)
- **🔍 Filament Runout**: Automatic pause and filament change with M600
- **💾 SD Card**: Auto-detection and full SD card functionality
- **🔌 USB Serial**: Easy firmware updates and G-code control
- **🔧 Z-Probe Ready**: Future-proofed for BLTouch or similar probes

## 🗺️ **PIN LOCATION GUIDE - SKR Mini E3 V2.0**

### **📍 Quick Pin Finder:**

**TFT Connector (Top-Left, 8 pins):**
- **PA3 (DC)**: Pin 2 - Data/Command ← **Display RS pin**
- **PA2 (RST)**: Pin 1 - Reset
- **PA4 (CS)**: Pin 3 - Chip Select
- **PA5 (SCK)**: Pin 4 - Clock
- **PA6 (MISO)**: Pin 5 - Data Out
- **PA7 (MOSI)**: Pin 6 - Data In

**EXP1 Connector (Top-Right):**
- **PA15**: Pin 2 - Button Encoder (SD Card CS)
- **PB5**: Pin 1 - Beeper
- **PB8**: Pin 7 - LCD RS
- **PB9**: Pin 6 - LCD D4

**Power Headers (Right side):**
- **3.3V**: Display power
- **GND**: Ground connections

**For complete pin mapping, see [JGAURORA_A5S_SKR_MINI_E3_V2_0_SETUP.md](JGAURORA_A5S_SKR_MINI_E3_V2_0_SETUP.md)**

## 🚀 Quick Start

### Option 1: Online Marlin Builder (RECOMMENDED)
1. **Go to**: [Marlin Firmware Builder](https://marlinfw.org/tools/autobuild/)
2. **Upload**: `Marlin/Configuration.h` and `Marlin/Configuration_adv.h`
3. **Select Board**: "BigTreeTech SKR Mini E3 V2.0"
4. **Build Online** - Download the .bin file
5. **Flash via SD Card** to your SKR Mini E3 V2.0

### Option 2: Local Build
1. **Install Arduino IDE 1.8.x** (not 2.x)
2. **Install STM32duino board package**
3. **Select Board**: "Generic STM32F103R series" → "Generic STM32F103RE"
4. **Open**: `Marlin/Marlin.ino`
5. **Build and Upload**

## 🔌 Wiring Diagram

> **📖 For complete wiring details, pin-by-pin instructions, and troubleshooting, see [JGAURORA_A5S_SKR_MINI_E3_V2_0_SETUP.md](JGAURORA_A5S_SKR_MINI_E3_V2_0_SETUP.md)**

### **📍 Essential Display Connections (TFTGLCD_PANEL_SPI)**

**34-Pin Ribbon Connector - Required Pins:**
| JGAurora A5S Pin | SKR Mini E3 V2.0 Pin | Function | Wire Color | Location |
|------------------|----------------------|----------|------------|----------|
| **Pin 1 (SCK)** | **PA5** | SPI Clock | **YELLOW** | TFT Connector Pin 4 |
| **Pin 2 (TCS)** | **PA4** | Display CS | **BLUE** | TFT Connector Pin 3 |
| **Pin 5 (MOSI)** | **PA7** | Data In | **ORANGE** | TFT Connector Pin 6 |
| **Pin 6 (MISO)** | **PA6** | Data Out | **RED** | TFT Connector Pin 5 |
| **Pin 8 (GND)** | **GND** | Ground | **BLACK** | Power Header |
| **Pin 10 (VCC)** | **3.3V** | Power | **RED** | Power Header |
| **Pin 30 (RST)** | **PA2** | Reset | **BROWN** | TFT Connector Pin 1 |
| **Pin 33 (RS)** | **PA3** | Data/Command | **PURPLE** | TFT Connector Pin 2 |

**Optional SD Card Connection:**
| JGAurora A5S Pin | SKR Mini E3 V2.0 Pin | Function | Wire Color | Location |
|------------------|----------------------|----------|------------|----------|
| **Pin 3 (FCS)** | **PA15** | SD Card CS | **GRAY** | EXP1 Connector Pin 2 |

### **📍 What NOT to Connect:**
- **10-pin connector** on top of LCD panel - **DO NOT TOUCH** (internal connection)
- **Any unused pins** - Leave disconnected
- **5V power** - Display needs 3.3V only

### **📍 Touch Interface:**
Touch functionality is **integrated** with the display SPI connection - no separate wiring needed!

## 🔧 Configuration Details

### **Hardware SPI (Default):**
- Uses hardwired SPI pins (PA4, PA5, PA6, PA7)
- Better performance and compatibility
- Standard Marlin TFTGLCD configuration

### **Software SPI (Alternative):**
- Uses available pins (PB9, PB8, PB5, PA15, PB15)
- For when hardwired pins are inaccessible
- Same functionality, slightly lower performance

### **NeoPixel LEDs:**
- **Pin**: PA8 (NeoPixel LED driving pin)
- **Status**: Temporarily disabled for compilation
- **Future**: Will be re-enabled once library issues are resolved

### **Filament Runout Sensor:**
- **Pin**: PC15 (E0-STOP)
- **Feature**: Automatic pause with M600 command
- **Configuration**: `FILAMENT_RUNOUT_SENSOR` enabled

### **SD Card:**
- **Auto-detection**: PC4 (built-in, no jumper needed)
- **SPI**: Hardware SPI2 on PB13/PB14/PB15
- **CS**: Separate from display CS for independent operation

## 🐛 Troubleshooting

### **Common Issues:**
1. **Display not powering on**: Check 3.3V power and ground connections
2. **Touch not working**: Touch is integrated - no separate wiring needed
3. **SD card not detected**: Verify PC4 connection and card formatting
4. **USB not connecting**: Check USB_CONNECT_PIN configuration

### **Getting Help:**
- **Documentation**: [JGAURORA_A5S_SKR_MINI_E3_V2_0_SETUP.md](JGAURORA_A5S_SKR_MINI_E3_V2_0_SETUP.md)
- **Issues**: Check the troubleshooting section in the setup guide
- **Support**: Create an issue in this repository

## 📚 Resources

- **Marlin Firmware**: [marlinfw.org](https://marlinfw.org/)
- **BigTreeTech**: [biqu.equipment](https://biqu.equipment/)
- **JGAurora**: [jg-aurora.com](https://jg-aurora.com/)
- **STM32duino**: [github.com/stm32duino](https://github.com/stm32duino)

## 🤝 Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for guidelines on contributing to this project.

## 📄 License

This project is based on Marlin Firmware, licensed under the GPL v3. See the [LICENSE](LICENSE) file for details.

---

**Built with ❤️ for the 3D printing community**
