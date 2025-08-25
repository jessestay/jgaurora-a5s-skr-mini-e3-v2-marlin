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

### Display Connection (TFTGLCD_PANEL_SPI)
| JGAurora A5S Display | SKR Mini E3 V2.0 Pin | Function |
|----------------------|----------------------|----------|
| **MOSI (Data In)** | **PA7** | SPI1_MOSI |
| **MISO (Data Out)** | **PA6** | SPI1_MISO |
| **SCK (Clock)** | **PA5** | SPI1_SCK |
| **CS (Chip Select)** | **PA4** | SPI1_CS |
| **DC (Data/Command)** | **PA3** | UART2_TX |
| **RST (Reset)** | **PA2** | UART2_RX |
| **VCC** | **3.3V** | Power |
| **GND** | **GND** | Ground |

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
├── JGAURORA_A5S_SKR_MINI_E3_V2_0_SETUP.md  # Complete setup guide
├── platformio.ini                   # PlatformIO configuration
├── README.md                        # This file
└── LICENSE                          # Marlin license
```

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

---

**⭐ If this firmware helps you, please star the repository!**

**Happy 3D Printing! 🎉**
