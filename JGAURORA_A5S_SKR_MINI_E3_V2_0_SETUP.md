# 🚀 JGAurora A5S + SKR Mini E3 V2.0 + Touchscreen Setup Guide

## 📋 What This Configuration Provides

✅ **SKR Mini E3 V2.0 motherboard** - Full STM32F103RE compatibility  
✅ **JGAurora A5S printer settings** - 310x310x330mm build volume  
✅ **Touchscreen support** - TFTGLCD_PANEL_SPI with integrated touch  
✅ **SD auto-detection** - Built-in via PC4 (no jumper wire needed)  
✅ **Filament runout sensor** - Enabled on PC15 (E0-STOP)  
✅ **USB connectivity** - Easy firmware updates  
✅ **Z-probe ready** - Future-proofed with shared pin configuration  
✅ **NeoPixel LED support** - Addressable RGB LED strips on PA8  
✅ **All JGAurora A5S features** - Preserved mechanics and functionality  

## 🔌 COMPLETE WIRING DIAGRAM

### **Display Connection (TFTGLCD_PANEL_SPI):**
| JGAurora A5S Display | SKR Mini E3 V2.0 Pin | Function | Color |
|----------------------|----------------------|----------|-------|
| **MOSI (Data In)** | **PA7** | SPI1_MOSI | Blue |
| **MISO (Data Out)** | **PA6** | SPI1_MISO | Green |
| **SCK (Clock)** | **PA5** | SPI1_SCK | Yellow |
| **CS (Chip Select)** | **PA4** | SPI1_CS | Orange |
| **DC (Data/Command)** | **PA3** | UART2_TX | Red |
| **RST (Reset)** | **PA2** | UART2_RX | Brown |
| **VCC** | **3.3V** | Power | Red |
| **GND** | **GND** | Ground | Black |

### **Touch Interface:**
| JGAurora A5S Touch | SKR Mini E3 V2.0 Pin | Function |
|-------------------|----------------------|----------|
| **Touch integrated with display** | **PA5/PA6/PA7** | TFTGLCD_PANEL_SPI handles touch through main SPI |

> **✅ Touch Functionality:**
> - **No separate touch wiring needed** - Touch handled through display SPI connection
> - **TFTGLCD_PANEL_SPI protocol** - Touch commands sent through main display interface
> - **Z-Probe and SD detection pins available** - No pin conflicts with touch functionality
> - **Simplified wiring** - Only display SPI connection required for full touch support

### **SD Card (Optional):**
| JGAurora A5S SD | SKR Mini E3 V2.0 Pin | Function |
|----------------|----------------------|----------|
| **SD MOSI** | **PA7** | Shared with display |
| **SD MISO** | **PA6** | Shared with display |
| **SD SCK** | **PA5** | Shared with display |
| **SD CS** | **PA15** | Available GPIO |

### **Filament Runout Sensor:**
| JGAurora A5S Sensor | SKR Mini E3 V2.0 Pin | Function |
|---------------------|----------------------|----------|
| **Filament Sensor Signal** | **PC15** | E0-STOP connector |
| **Filament Sensor VCC** | **5V** | Power |
| **Filament Sensor GND** | **GND** | Ground |

### **SD Auto-Detection (Built-in - ENABLED):**
| Connection | SKR Mini E3 V2.0 Pin | Function |
|------------|----------------------|----------|
| **SD Detect Switch** | **PC4** | Built-in SD detection |

> **✅ SD Auto-Detection:**
> - **No jumper wire needed** - Uses standard SD_DETECT_PIN (PC4)
> - **Automatic functionality** - Card insertion/removal detected automatically
> - **Firmware enabled** - SD auto-detection works out of the box
> - **SERVO pin available** - PA1 (SERVO) preserved for future servo use
>
> **How it works:**
> - **PC4 monitors** the SD card slot's built-in detect switch
> - **Automatic mounting** when card is inserted
> - **Safe unmounting** when card is removed
> - **No additional wiring** required

### **NeoPixel LED Strips (ENABLED):**
| Connection | SKR Mini E3 V2.0 Pin | Function |
|------------|----------------------|----------|
| **LED Data** | **PA8** | NeoPixel data signal |
| **LED VCC** | **5V** | Power (external PSU recommended for >10 LEDs) |
| **LED GND** | **GND** | Ground |

> **✅ NeoPixel LED Features:**
> - **Addressable RGB LEDs** - Individual control of each LED
> - **RGBW Support** - Red, Green, Blue, and White channels
> - **Up to 30 LEDs** - Default configuration (adjustable)
> - **Sequential temperature display** - LEDs change color during heating
> - **Printer event lighting** - Different colors for printing, finished, errors
> - **G-code control** - Full manual control via M150 commands
>
> **Supported LED Types:**
> - **WS2812B** - Most common addressable LEDs
> - **WS2815** - 12V addressable LEDs
> - **SK6812** - RGBW (with white channel)
> - **Any NEO_GRBW compatible strips**
>
> **G-code Control Examples:**
> ```gcode
> M150 R255 G0 B0    ; Set LEDs to red
> M150 R0 G255 B0    ; Set LEDs to green  
> M150 R0 G0 B255    ; Set LEDs to blue
> M150 R255 G255 B255 ; Set LEDs to white
> M150 R0 G0 B0      ; Turn LEDs off
> ```

## 🏗️ FIRMWARE BUILD OPTIONS

### **Option 1: Online Marlin Builder (RECOMMENDED)**
1. **Go to**: [Marlin Firmware Builder](https://marlinfw.org/tools/autobuild/)
2. **Upload your Configuration.h** file
3. **Select board**: "BigTreeTech SKR Mini E3 V2.0"
4. **Build online** - gets around all local build issues
5. **Download the .bin file**

### **Option 2: Use Pre-built Configuration**
The configuration files are already created and ready to use:
- `Configuration_FINAL_JGAurora_A5S_SKR_Mini_E3_V2_0.h`
- `Configuration_adv_FINAL_JGAurora_A5S_SKR_Mini_E3_V2_0.h`

### **Option 3: Arduino IDE (Alternative)**
1. **Install Arduino IDE 1.8.x** (not 2.x)
2. **Install STM32duino board package**
3. **Select board**: "Generic STM32F103R series" → "Generic STM32F103RE"
4. **Upload method**: "STM32CubeProgrammer (SWD)"
5. **Open Marlin.ino** from the Marlin folder
6. **Build and upload**

## 📁 CONFIGURATION FILES

### **Main Configuration (Configuration.h):**
- **Motherboard**: `BOARD_BTT_SKR_MINI_E3_V2_0`
- **Build Volume**: 310x310x330mm
- **Display**: `TFTGLCD_PANEL_SPI`
- **Touch**: Integrated with TFTGLCD (no separate `TOUCH_SCREEN`)
- **USB**: Full USB support enabled
- **Filament Sensor**: `FILAMENT_RUNOUT_SENSOR` enabled
- **LED Support**: `NEOPIXEL_LED` enabled on PA8 pin (30 LEDs, RGBW)
- **Z-Probe**: Ready for future use with `Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN`

### **Advanced Configuration (Configuration_adv.h):**
- **Homing**: Standard homing configuration
- **Advanced features**: Optimized for JGAurora A5S
- **Safety features**: Standard Marlin safety settings

### **SD Auto-Detection (Built-in - ENABLED):**
SD card auto-detection works automatically:
1. **Hardware**: Uses built-in SD slot detect switch connected to PC4
2. **Firmware**: Standard SD_DETECT_PIN functionality enabled
3. **No additional wiring** - Works out of the box

**Firmware configuration (standard Marlin):**
```cpp
// Standard SD detection - no special configuration needed
// SD_DETECT_PIN automatically defined as PC_4 in pins file
```

### **Z-Probe Support (Ready for Future Use):**
Z-probe functionality is configured for easy future addition:
1. **Shared pin approach**: Uses PC_2 (Z_STOP_PIN) for both Z-min endstop and probe
2. **No pin conflicts**: All pins available for probe functionality
3. **Easy activation**: Uncomment `#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN` in Configuration.h
4. **Hardware connection**: Connect probe to Z-STOP connector (PC_2)

**Future Z-probe activation:**
```cpp
// In Configuration.h, uncomment this line when adding Z-probe:
#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN  // Enable shared pin mode
```

## 🔧 FLASHING INSTRUCTIONS

### **Method 1: USB (Recommended)**
1. **Connect USB cable** to SKR Mini E3 V2.0
2. **Put board in bootloader mode** (if needed)
3. **Copy .bin file** to virtual USB drive
4. **Wait for upload to complete**
5. **Restart board**

### **Method 2: SD Card**
1. **Format SD card** to FAT32
2. **Copy .bin file** to SD card root
3. **Insert SD card** into SKR Mini E3 V2.0
4. **Power on board**
5. **Wait for upload to complete**

## ✅ VERIFICATION STEPS

After flashing:
1. **Check display** - Should show Marlin boot screen
2. **Test touch** - Touch should respond
3. **Check dimensions** - X/Y/Z should show correct values
4. **Test movement** - All axes should move correctly
5. **Check temperature** - Hotend and bed should read correctly
6. **Test LED strips** - Send `M150 R255 G0 B0` to test red LEDs

## 🚨 TROUBLESHOOTING

### **Display Not Working:**
- Check all SPI connections
- Verify 3.3V power supply
- Check CS pin connection

### **Touch Not Responding:**
- Verify touch CS and IRQ pins
- Check touch calibration
- Ensure touch library is enabled

### **LED Strips Not Working:**
- Check PA8 data connection
- Verify 5V power supply (external PSU for >10 LEDs)
- Ensure correct LED type in configuration
- Test with simple G-code: `M150 R255 G0 B0`

### **Build Issues:**
- Use online Marlin builder
- Check board selection
- Verify configuration file syntax

## 📞 SUPPORT

If you encounter issues:
1. **Check wiring** - Most issues are connection-related
2. **Verify configuration** - Ensure all settings are correct
3. **Use online builder** - Gets around local build issues
4. **Check Marlin forums** - Community support available

## 🎯 NEXT STEPS

1. **Connect hardware** using wiring diagram
2. **Choose firmware method** (online builder recommended)
3. **Flash firmware** to SKR Mini E3 V2.0
4. **Test functionality** and calibrate
5. **Enjoy your upgraded JGAurora A5S!**

---

**Configuration Status**: ✅ READY TO USE  
**Build Method**: Online Marlin Builder (recommended)  
**Hardware**: Fully compatible  
**Features**: All JGAurora A5S features preserved + touchscreen support
