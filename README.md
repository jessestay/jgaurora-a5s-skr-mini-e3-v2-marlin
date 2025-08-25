# 🚀 JGAurora A5S + SKR Mini E3 V2.0 Marlin Firmware

**Ready-to-compile Marlin 2.1.2.5 firmware for JGAurora A5S printers with BigTreeTech SKR Mini E3 V2.0 motherboards.**

## ✨ Features

- **🎯 Complete Configuration** - Ready to compile for JGAurora A5S + SKR Mini E3 V2.0
- **🖥️ Touchscreen Support** - TFTGLCD_PANEL_SPI with integrated touch functionality
- **💡 NeoPixel LED Support** - Addressable RGB LED strips on PA8 pin *(temporarily disabled for compilation)*
- **📱 SD Auto-Detection** - Built-in SD card detection (no jumper wires needed)
- **🔌 Filament Sensor** - Filament runout detection enabled
- **🔧 Z-Probe Ready** - Future-proofed for automatic bed leveling
- **📏 Correct Dimensions** - 310x310x330mm build volume configured
- **🔌 USB Support** - Full USB connectivity for easy updates
- **📚 Comprehensive Documentation** - Complete setup guide with wiring diagrams and troubleshooting

## 📖 Complete Setup Guide

**For detailed wiring instructions, troubleshooting, and step-by-step setup, see the comprehensive guide:**

**[JGAURORA_A5S_SKR_MINI_E3_V2_0_SETUP.md](JGAURORA_A5S_SKR_MINI_E3_V2_0_SETUP.md)**

This guide includes:
- **🔌 Complete wiring diagrams** with exact pin numbers and wire colors
- **📍 Step-by-step instructions** for safe installation
- **🚨 Troubleshooting guide** for common issues
- **✅ Verification checklists** to ensure proper setup
- **🎯 Quick reference tables** for easy lookup
- **⚠️ Safety warnings** about what NOT to connect

## 🏗️ Hardware Compatibility

- **Printer**: JGAurora A5S (or similar 310x310mm bed printers)
- **Motherboard**: BigTreeTech SKR Mini E3 V2.0
- **Display**: TFTGLCD_PANEL_SPI compatible touchscreens
- **Drivers**: TMC2209 stepper drivers
- **LEDs**: NeoPixel RGBW strips (WS2812B, WS2815, SK6812, etc.)

## 📥 Quick Start

### Option 1: Online Marlin Builder (Recommended)
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
| JGAurora A5S Pin | SKR Mini E3 V2.0 Pin | Function | Wire Color |
|------------------|----------------------|----------|------------|
| **Pin 1 (SCK)** | **PA5** | SPI Clock | **YELLOW** |
| **Pin 2 (TCS)** | **PA4** | Display CS | **BLUE** |
| **Pin 5 (MOSI)** | **PA7** | Data In | **ORANGE** |
| **Pin 6 (MISO)** | **PA6** | Data Out | **RED** |
| **Pin 8 (GND)** | **GND** | Ground | **BLACK** |
| **Pin 10 (VCC)** | **3.3V** | Power | **RED** |
| **Pin 30 (RST)** | **PA2** | Reset | **BROWN** |
| **Pin 33 (RS)** | **PA3** | Data/Command | **PURPLE** |

**Optional SD Card Connection:**
| JGAurora A5S Pin | SKR Mini E3 V2.0 Pin | Function | Wire Color |
|------------------|----------------------|----------|------------|
| **Pin 3 (FCS)** | **PA15** | SD Card CS | **GRAY** |

### **📍 What NOT to Connect:**
- **10-pin connector** on top of LCD panel - **DO NOT TOUCH** (internal connection)
- **Any unused pins** - Leave disconnected
- **5V power** - Display needs 3.3V only

### **📍 Touch Interface:**
Touch functionality is **integrated** with the display SPI connection - no separate wiring needed!

### NeoPixel LED Strips
| Connection | SKR Mini E3 V2.0 Pin | Function |
|------------|----------------------|----------|
| **LED Data** | **PA8** | NeoPixel data signal |
| **LED VCC** | **5V** | Power (external PSU recommended for >10 LEDs) |
| **LED GND** | **GND** | Ground |

### Filament Runout Sensor
| Connection | SKR Mini E3 V2.0 Pin | Function |
|------------|----------------------|----------|
| **Signal** | **PC15** | E0-STOP connector |
| **VCC** | **5V** | Power |
| **GND** | **GND** | Ground |

## 🎮 G-code Control

### LED Control
```gcode
M150 R255 G0 B0    ; Set LEDs to red
M150 R0 G255 B0    ; Set LEDs to green  
M150 R0 G0 B255    ; Set LEDs to blue
M150 R255 G255 B255 ; Set LEDs to white
M150 R0 G0 B0      ; Turn LEDs off
```

### Bed Leveling
```gcode
G28        ; Home all axes
G29        ; Start manual bed leveling (follow prompts)
M500       ; Save to EEPROM
M420 S1    ; Enable leveling for prints
```

## 📁 Repository Structure

```
├── Marlin/                          # Main Marlin source code
│   ├── Configuration.h              # Main configuration (READY TO USE)
│   ├── Configuration_adv.h          # Advanced configuration
│   └── src/                         # Marlin source files
├── 📖 JGAURORA_A5S_SKR_MINI_E3_V2_0_SETUP.md  # ⭐ COMPLETE SETUP GUIDE ⭐
├── platformio.ini                   # PlatformIO configuration
├── README.md                        # This file (quick overview)
└── LICENSE                          # Marlin license
```

> **📚 Primary Documentation**: The [JGAURORA_A5S_SKR_MINI_E3_V2_0_SETUP.md](JGAURORA_A5S_SKR_MINI_E3_V2_0_SETUP.md) contains the complete setup guide with detailed wiring diagrams, troubleshooting, and step-by-step instructions.

## 🔧 Configuration Details

### Key Settings
- **Motherboard**: `BOARD_BTT_SKR_MINI_E3_V2_0`
- **Build Volume**: 310x310x330mm
- **Display**: `TFTGLCD_PANEL_SPI`
- **Touch**: Integrated (no separate `TOUCH_SCREEN`)
- **LEDs**: `NEOPIXEL_LED` on PA8 (30 LEDs, RGBW)
- **Filament Sensor**: `FILAMENT_RUNOUT_SENSOR` enabled
- **SD Detection**: Built-in via PC4

### Pin Assignments
- **Display SPI**: PA4-PA7
- **NeoPixel LED**: PA8
- **Filament Sensor**: PC15
- **SD Detect**: PC4
- **Z-Probe Ready**: PC2 (shared with Z-min endstop)

## 🚨 Troubleshooting

### Common Issues
1. **Display not working** - Check SPI connections and 3.3V power
2. **Touch not responding** - Verify touch calibration
3. **LEDs not working** - Check PA8 connection and power supply
4. **Build errors** - Use online Marlin builder for best results

### NeoPixel LED Setup
**Note**: NeoPixel is temporarily disabled for compilation compatibility. To enable:
1. **Install Adafruit NeoPixel library** in Arduino IDE: `Sketch > Include Library > Manage Libraries > Search "Adafruit NeoPixel"`
2. **Re-enable in Configuration.h**: Uncomment `#define NEOPIXEL_LED`
3. **Recompile** - should work without errors

### Getting Help
- **Check wiring** - Most issues are connection-related
- **Use online builder** - Gets around local build issues
- **Community support** - Marlin forums and Discord

## 📄 License

This project is based on [Marlin Firmware](https://github.com/MarlinFirmware/Marlin) and is licensed under the [GPL v3 License](LICENSE).

## 🤝 Contributing

Found an issue or have an improvement? Please:
1. **Fork the repository**
2. **Create a feature branch**
3. **Make your changes**
4. **Submit a pull request**

## 🙏 Acknowledgments

- **Marlin Firmware Team** - For the excellent firmware base
- **BigTreeTech** - For the SKR Mini E3 V2.0 motherboard
- **JGAurora** - For the A5S printer design
- **3D Printing Community** - For testing and feedback

## 📞 Support

- **Issues**: [GitHub Issues](https://github.com/yourusername/jgaurora-a5s-skr-mini-e3-v2-firmware/issues)
- **Discussions**: [GitHub Discussions](https://github.com/yourusername/jgaurora-a5s-skr-mini-e3-v2-firmware/discussions)
- **Wiki**: [Setup Guide](JGAURORA_A5S_SKR_MINI_E3_V2_0_SETUP.md)

## 📚 Documentation

**This README provides a quick overview. For complete setup instructions, see:**

**[JGAURORA_A5S_SKR_MINI_E3_V2_0_SETUP.md](JGAURORA_A5S_SKR_MINI_E3_V2_0_SETUP.md)**

The setup guide contains:
- **🔌 Complete wiring diagrams** with exact pin numbers
- **📍 Step-by-step installation** instructions
- **🚨 Troubleshooting** for common issues
- **✅ Verification checklists** for safe operation
- **🎯 Quick reference** tables for experienced users

---

**⭐ If this firmware helps you, please star the repository or give a tip!**

**Happy 3D Printing! 🎉**
