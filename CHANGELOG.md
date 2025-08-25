# Changelog

All notable changes to the JGAurora A5S + SKR Mini E3 V2.0 Marlin firmware will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [2.1.2.5] - 2024-08-25

### Added
- **Complete JGAurora A5S configuration** for SKR Mini E3 V2.0
- **TFTGLCD_PANEL_SPI display support** with integrated touch functionality
- **NeoPixel LED support** on PA8 pin (30 LEDs, RGBW) *(temporarily disabled for compilation compatibility)*
- **Filament runout sensor** enabled on PC15 (E0-STOP)
- **SD auto-detection** built-in via PC4 (no jumper wires needed)
- **Z-probe ready configuration** for future automatic bed leveling
- **USB connectivity** for easy firmware updates
- **Correct build volume** (310x310x330mm) for JGAurora A5S
- **Comprehensive setup guide** with wiring diagrams and troubleshooting

### Changed
- **Updated pin definitions** from PXN to PX_N format for STM32 Arduino framework compatibility
- **Modified HAL files** for STM32F103RE compatibility
- **Updated SPI definitions** for newer STM32 Arduino framework
- **Optimized configuration** for touchscreen and LED functionality
- **Resolved serial port conflicts** by using USB-only communication
- **Temporarily disabled NeoPixel** to resolve compilation issues with Adafruit library

### Fixed
- **STM32 framework compatibility** issues with pin naming
- **SPI constant definitions** for newer Arduino STM32 versions
- **F_CPU constexpr compatibility** issues
- **Display and touch conflicts** between different interface types
- **Pin assignment conflicts** for serial ports and TFT connector
- **Build system compatibility** with PlatformIO and Arduino IDE

### Technical Details
- **Motherboard**: `BOARD_BTT_SKR_MINI_E3_V2_0`
- **Display**: `TFTGLCD_PANEL_SPI` (no separate `TOUCH_SCREEN`)
- **LEDs**: `NEOPIXEL_LED` with RGBW support
- **Filament Sensor**: `FILAMENT_RUNOUT_SENSOR` enabled
- **SD Detection**: Built-in via PC4
- **Z-Probe Ready**: Shared pin configuration on PC2

## [2.1.2.5-base] - 2024-11-18

### Added
- **Base Marlin 2.1.2.5 firmware** from official release
- **SKR Mini E3 V2.0 board support** with STM32F103RE
- **Standard Marlin features** and G-code support

---

## Version History

- **2.1.2.5** - Current stable release with JGAurora A5S optimizations
- **2.1.2.5-base** - Original Marlin release (November 2024)

## Future Plans

### Planned Features
- **Automatic bed leveling** with Z-probe support
- **Advanced LED patterns** and effects
- **Enhanced touch interface** customization
- **WiFi connectivity** options
- **Advanced filament sensor** configurations

### Known Issues
- **None currently identified** - all major compatibility issues resolved

### Compatibility Notes
- **Arduino IDE 1.8.x** recommended (2.x has compatibility issues)
- **STM32duino board package** required
- **TFTGLCD_PANEL_SPI** displays only (not generic TFT)
- **SKR Mini E3 V2.0** specific optimizations

---

## Contributing

See [CONTRIBUTING.md](CONTRIBUTING.md) for details on how to contribute to this project.

## Support

- **GitHub Issues**: Report bugs and request features
- **GitHub Discussions**: Ask questions and share experiences
- **Setup Guide**: [JGAURORA_A5S_SKR_MINI_E3_V2_0_SETUP.md](JGAURORA_A5S_SKR_MINI_E3_V2_0_SETUP.md)
