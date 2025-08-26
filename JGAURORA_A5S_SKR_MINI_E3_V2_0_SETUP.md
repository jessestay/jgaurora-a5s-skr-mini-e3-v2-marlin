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

## 🔧 **Configuration Selection Guide**

**Software SPI Configuration (Required):**

Since the hardwired SPI pins (PA4, PA5, PA6, PA7) are not accessible on the TFT connector, we **MUST use Software SPI** with available EXP1 connector pins.

**Software SPI Pins (Available):**
- **PB9 (EXP1-6)**: SCK (Clock)
- **PB8 (EXP1-7)**: MOSI (Data In)
- **PB5 (EXP1-1)**: MISO (Data Out)
- **PA15 (EXP1-2)**: CS (Chip Select)
- **PB15 (EXP1-8)**: SD Card CS

**Required Pins**: PB9, PB8, PB5, PA15, PB15, PA2, PA3, 3.3V, GND

> **💡 Why Software SPI?**: The hardwired SPI pins (PA4-PA7) are not accessible on the TFT connector, so Software SPI is the only option.

## 🔌 COMPLETE WIRING DIAGRAM

### **📍 SKR Mini E3 V2.0 Pin Locations:**

**TFT Connector (Top-Left Area):**
- **PA2 (RST)**: Reset pin - near TFT connector
- **PA3 (DC)**: Data/Command pin - near TFT connector  
- **PA4 (CS)**: Display Chip Select - near TFT connector
- **PA5 (SCK)**: Clock signal - near TFT connector
- **PA6 (MISO)**: Data Out - near TFT connector
- **PA7 (MOSI)**: Data In - near TFT connector

**Power Pins:**
- **3.3V**: Available on TFT connector and power headers
- **GND**: Available on TFT connector and power headers

**Other Pins:**
- **PA8**: NeoPixel LED data pin (labeled "Neopixel" header)
- **PA15**: Available GPIO for SD card CS (optional)
- **PC2**: Z-STOP connector (Z-min endstop)
- **PC4**: Built-in SD card detect (no wiring needed)
- **PC15**: E0-STOP connector (filament sensor)

### **📍 Software SPI Configuration (Required - Hardwired Pins Not Accessible)**

Since the hardwired SPI pins (PA4, PA5, PA6, PA7) are not accessible on the TFT connector, we **MUST use Software SPI** with these available pins:

**Software SPI Pins (Available):**
- **PB9 (EXP1-6)**: SCK (Clock) - Available on EXP1 connector
- **PB8 (EXP1-7)**: MOSI (Data In) - Available on EXP1 connector
- **PB5 (EXP1-1)**: MISO (Data Out) - Available on EXP1 connector
- **PA15 (EXP1-2)**: CS (Chip Select) - Available on EXP1 connector

**Already Connected Pins:**
- **PA2**: RST (Reset) - Connected to TFT RX2 ✅
- **PA3**: RS/DC (Data/Command) - Connected to TFT TX2 ✅
- **3.3V**: Power - Connected to SWD area ✅
- **GND**: Ground - Connected to SWD area ✅

**To Enable Software SPI:**
1. **Use the custom pin configuration** already added to the firmware
2. **Connect to EXP1 connector** using the pin assignments above
3. **No additional firmware changes** needed - Software SPI is automatically enabled

### **📍 Software SPI Wiring Table (Alternative Configuration):**

**Display Connection (Software SPI - EXP1 Connector):**
| JGAurora A5S Display | SKR Mini E3 V2.0 Pin | Function | Wire Color | Status |
|----------------------|----------------------|----------|------------|---------|
| **Pin 1 (SCK)** | **PB9 (EXP1-6)** | SPI Clock | **YELLOW** | ✅ Available |
| **Pin 2 (TCS)** | **PA15 (EXP1-2)** | Display CS | **BLUE** | ✅ Available |
| **Pin 5 (MOSI)** | **PB8 (EXP1-7)** | Data In | **ORANGE** | ✅ Available |
| **Pin 6 (MISO)** | **PB5 (EXP1-1)** | Data Out | **PURPLE** | ✅ Available |
| **Pin 8 (GND)** | **GND** | Ground | **BLACK** | ✅ Connected |
| **Pin 10 (VCC)** | **3.3V** | Power | **RED** | ✅ Connected |
| **Pin 30 (RST)** | **PA2** | Reset | **BROWN** | ✅ Connected |
| **Pin 33 (RS)** | **PA3** | Data/Command | **PURPLE** | ✅ Connected |

**SD Card Connection (Optional - Software SPI):**
| JGAurora A5S SD | SKR Mini E3 V2.0 Pin | Function | Wire Color | Status |
|----------------|----------------------|----------|------------|---------|
| **Pin 3 (FCS)** | **PB15 (EXP1-8)** | SD Card CS | **GRAY** | ✅ Separate from Display CS |

> **✅ Software SPI Advantages:**
> - **Uses available pins** - No need to access hardwired SPI pins
> - **EXP1 connector accessible** - Easy to connect and disconnect
> - **Same functionality** - Display and touch work identically
> - **No performance loss** - Software SPI is fast enough for displays

### **📍 JGAurora A5S LCD Board Pinout:**

**34-Pin Ribbon Connector (Main Connection):**
```
Pin Layout (Looking at the connector):
┌─────────────────────────────────────────────────┐
│ 1  3  5  7  9  11 13 15 17 19 21 23 25 27 29 31 33 │
│ 2  4  6  8  10 12 14 16 18 20 22 24 26 28 30 32 34 │
└─────────────────────────────────────────────────┘

Pin 1  (SCK)     → PA5  (SPI1_SCK)     ← YELLOW wire
Pin 2  (TCS)     → PA4  (Display CS)    ← BLUE wire  
Pin 3  (FCS)     → PA15 (SD Card CS)    ← GRAY wire (OPTIONAL)
Pin 4  (TINT)    → NC   (Not Connected) ← RED wire
Pin 5  (MOSI)    → PA7  (SPI1_MOSI)    ← ORANGE wire
Pin 6  (MISO)    → PA6  (SPI1_MISO)    ← PURPLE wire
Pin 7  (NC)      → NC   (Not Connected)
Pin 8  (GND)     → GND  (Ground)        ← BLACK wire
Pin 9  (GND)     → GND  (Ground)        ← BROWN wire
Pin 10 (VCC)     → 3.3V (3.3V Power)   ← RED wire
Pin 11 (VCC)     → 3.3V (3.3V Power)   ← (Not Connected)
Pin 12 (BLEN)    → NC   (Not Connected)
Pin 13 (SDCS)    → NC   (Not Connected)
Pin 14-29 (DB17-DB1) → NC (Not Connected)
Pin 30 (RST)     → PA2  (Reset)         ← BROWN wire
Pin 31 (RD)      → NC   (Not Connected)
Pin 32 (WR)      → NC   (Not Connected)
Pin 33 (RS)      → PA3  (Data/Command)  ← PURPLE wire
Pin 34 (CS)      → NC   (Not Connected)
```

**10-Pin Connector (Top of LCD Panel):**
- **DO NOT TOUCH** - This connects to the LCD screen internally
- **Already connected** - No wiring needed
- **Leave alone** - Modifying this will damage the display

### **📍 Complete Wiring Guide:**

#### **Required Connections (Display + Power):**
| JGAurora A5S Pin | SKR Mini E3 V2.0 Pin | Function | Wire Color | Status |
|------------------|----------------------|----------|------------|---------|
| **Pin 1 (SCK)** | **PA5** | SPI Clock | **YELLOW** | ✅ Required |
| **Pin 2 (TCS)** | **PA4** | Display CS | **BLUE** | ✅ Required |
| **Pin 5 (MOSI)** | **PA7** | Data In | **ORANGE** | ✅ Required |
| **Pin 6 (MISO)** | **PA6** | Data Out | **RED** | ✅ Required |
| **Pin 8 (GND)** | **GND** | Ground | **BLACK** | ✅ Required |
| **Pin 10 (VCC)** | **3.3V** | Power | **RED** | ✅ Required |
| **Pin 30 (RST)** | **PA2** | Reset | **BROWN** | ✅ Required |
| **Pin 33 (RS)** | **PA3** | Data/Command | **PURPLE** | ✅ Required |

#### **Optional Connections:**
| JGAurora A5S Pin | SKR Mini E3 V2.0 Pin | Function | Wire Color | Status |
|------------------|----------------------|----------|------------|---------|
| **Pin 3 (FCS)** | **PA15** | SD Card CS | **GRAY** | 🔶 Optional |

#### **Unused Pins (Leave Disconnected):**
- **Pin 4 (TINT)**: Touch interrupt - not needed for TFTGLCD_PANEL_SPI
- **Pin 7 (NC)**: Not connected
- **Pin 9 (GND)**: Second ground - not needed (use Pin 8)
- **Pin 11 (VCC)**: Second VCC - not needed (use Pin 10)
- **Pin 12 (BLEN)**: Backlight enable - not needed
- **Pin 13 (SDCS)**: Secondary SD CS - not needed
- **Pin 14-29 (DB17-DB1)**: Data bus pins - not needed for SPI mode
- **Pin 31 (RD)**: Read signal - not needed for SPI mode
- **Pin 32 (WR)**: Write signal - not needed for SPI mode
- **Pin 34 (CS)**: Secondary CS - not needed

### **📍 Wire Color Guide:**

**Essential Colors (Required):**
- **YELLOW**: SCK (Clock) - Pin 1
- **BLUE**: Display CS - Pin 2  
- **ORANGE**: MOSI (Data In) - Pin 5
- **RED**: MISO (Data Out) - Pin 6
- **BLACK**: Ground - Pin 8
- **RED**: 3.3V Power - Pin 10
- **BROWN**: Reset - Pin 30
- **PURPLE**: Data/Command - Pin 33

**Optional Colors:**
- **GRAY**: SD Card CS - Pin 3 (only if you need SD functionality)

### **📍 Step-by-Step Wiring Instructions:**

#### **Step 1: Prepare the 34-Pin Ribbon**
1. **Identify the ribbon end** that connects to the SKR Mini E3 V2.0
2. **Count the pins** - ensure you're working with the correct end
3. **Check wire colors** - verify you have all required colors

#### **Step 2: Connect Power First**
1. **Pin 8 (GND)** → **GND** on SKR Mini E3 V2.0 (BLACK wire)
2. **Pin 10 (VCC)** → **3.3V** on SKR Mini E3 V2.0 (RED wire)

#### **Step 3: Connect Display SPI Pins**
1. **Pin 1 (SCK)** → **PA5** (YELLOW wire)
2. **Pin 2 (TCS)** → **PA15** (BLUE wire)
3. **Pin 5 (MOSI)** → **PB8** (ORANGE wire)
4. **Pin 6 (MISO)** → **PB5** (RED wire)
5. **Pin 30 (RST)** → **PA2** (BROWN wire)
6. **Pin 33 (RS)** → **PA3** (PURPLE wire)

#### **Step 4: Optional SD Card Connection**
1. **Pin 3 (FCS)** → **PB15** (GRAY wire) - only if you want SD functionality

#### **Step 5: Verify Connections**
1. **Check all wire colors** match the pinout above
2. **Ensure no loose connections**
3. **Verify power connections** (3.3V and GND)
4. **Double-check pin numbers** on both boards

### **📍 What NOT to Connect:**

#### **10-Pin Connector (Top of LCD Panel):**
- **DO NOT TOUCH** - This is for internal LCD connection
- **Already wired** - No external connections needed
- **Modifying this** will damage the display

#### **Unused Pins:**
- **Leave all unused pins disconnected**
- **Don't connect to 5V** - Display needs 3.3V only
- **Don't connect to random pins** - Only use the specified connections

### **📍 Touch Interface:**
| JGAurora A5S Touch | SKR Mini E3 V2.0 Pin | Function |
|-------------------|----------------------|----------|
| **Touch integrated with display** | **SPI pins** | TFTGLCD_PANEL_SPI handles touch through main SPI |

> **✅ Touch Functionality:**
> - **No separate touch wiring needed** - Touch handled through display SPI connection
> - **TFTGLCD_PANEL_SPI protocol** - Touch commands sent through main display interface
> - **Z-Probe and SD detection pins available** - No pin conflicts with touch functionality
> - **Simplified wiring** - Only display SPI connection required for full touch support
> - **Works with both configurations**: Hardware SPI (PA5/PA6/PA7) or Software SPI (PB9/PB8/PB5)

### **📍 SD Card (Optional):**

**Hardware SPI Configuration:**
| JGAurora A5S SD | SKR Mini E3 V2.0 Pin | Function |
|----------------|----------------------|----------|
| **SD MOSI** | **PA7** | Shared with display |
| **SD MISO** | **PA6** | Shared with display |
| **SD SCK** | **PA5** | Shared with display |
| **SD CS** | **PA15** | Available GPIO |

**Software SPI Configuration:**
| JGAurora A5S SD | SKR Mini E3 V2.0 Pin | Function |
|----------------|----------------------|----------|
| **SD MOSI** | **PB8** | Shared with display |
| **SD MISO** | **PB5** | Shared with display |
| **SD SCK** | **PB9** | Shared with display |
| **SD CS** | **PB15** | Available GPIO |

> **✅ SD Card Sharing:**
> - **SPI bus shared** between display and SD card
> - **Separate CS pins** - Display uses PA4, SD uses PA15
> - **No conflicts** - Firmware switches between devices
> - **Efficient design** - Saves pins while maintaining functionality

### **📍 Filament Runout Sensor:**
| JGAurora A5S Sensor | SKR Mini E3 V2.0 Pin | Function |
|---------------------|----------------------|----------|
| **Filament Sensor Signal** | **PC15** | E0-STOP connector |
| **Filament Sensor VCC** | **5V** | Power |
| **Filament Sensor GND** | **GND** | Ground |

### **📍 SD Auto-Detection (Built-in - ENABLED):**
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

### **📍 NeoPixel LED Strips (ENABLED):**
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

### **📍 Wiring Verification Checklist:**

#### **Before Powering On:**
- [ ] **All 8 required wires connected** (6 SPI + 2 power)
- [ ] **Wire colors match** the pinout guide
- [ ] **10-pin connector untouched** (top of LCD panel)
- [ ] **Unused pins disconnected**
- [ ] **3.3V power** (not 5V)
- [ ] **Connections secure** and not loose

#### **Power-Up Test:**
- [ ] **Display powers on** and shows Marlin boot screen
- [ ] **Touch responds** to finger input
- [ ] **No smoke or burning smell**
- [ ] **All LEDs on SKR board** light up normally

### **📍 Common Wiring Mistakes to Avoid:**

1. **❌ Connecting 10-pin connector** - Will damage display
2. **❌ Using 5V instead of 3.3V** - Will damage display
3. **❌ Connecting unused pins** - Can cause conflicts
4. **❌ Loose connections** - Can cause intermittent issues
5. **❌ Wrong wire colors** - Can cause confusion during troubleshooting
6. **❌ Connecting to wrong pins** - Double-check pin numbers

### **📍 Troubleshooting Wiring Issues:**

#### **Display Not Working:**
1. **Check power connections** - Verify 3.3V and GND
2. **Verify all 6 SPI pins** - SCK (Pin 1), CS (Pin 2), MOSI (Pin 5), MISO (Pin 6), RST (Pin 30), RS (Pin 33)
3. **Check wire colors** - Ensure correct pin identification
4. **Verify pin numbers** - Count carefully from pin 1

#### **Touch Not Responding:**
1. **Check MOSI/MISO connections** - Touch uses these pins (Pin 5 and Pin 6)
2. **Verify firmware settings** - TFTGLCD_PANEL_SPI enabled
3. **Check for loose connections** - Secure all wires

#### **SD Card Issues:**
1. **Verify SD CS connection** - Pin 3 (FCS) to PA15
2. **Check shared SPI pins** - MOSI (Pin 5), MISO (Pin 6), SCK (Pin 1)
3. **Ensure SD card formatted** - FAT32 format required

#### **Power Issues:**
1. **Check voltage** - Must be 3.3V, not 5V
2. **Verify ground connection** - Use main GND, not shield GND
3. **Check wire gauge** - Ensure adequate current capacity

### **📍 Quick Reference - Essential Pins Only:**

> **⚠️ IMPORTANT: Software SPI is REQUIRED on this board**
> - **Hardwired SPI pins (PA4, PA5, PA6, PA7) are NOT accessible**
> - **Software SPI uses available EXP1 connector pins**

**Software SPI Configuration (Required):**
```
Pin 1  (YELLOW)  → PB9  (SCK)   - EXP1-6
Pin 2  (BLUE)    → PA15 (CS)    - EXP1-2  
Pin 3  (GRAY)    → PB15 (SD CS) - EXP1-8
Pin 5  (ORANGE)  → PB8  (MOSI)  - EXP1-7
Pin 6  (RED)     → PB5  (MISO)  - EXP1-1
Pin 8  (BLACK)   → GND
Pin 10 (PURPLE)     → 3.3V
Pin 30 (BROWN)   → PA2  (RST)
Pin 33 (PURPLE)  → PA3  (RS)
```

**DO NOT TOUCH:**
- **10-pin connector** on top of LCD panel
- **Any other pins** not listed above

### **📍 Success Indicators:**

✅ **Display shows Marlin boot screen**
✅ **Touch responds to finger input**  
✅ **No error messages** on display
✅ **All SKR board LEDs** light normally
✅ **No smoke or burning smell**
✅ **USB connection** works for firmware updates

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

**Visual Guide:**
```
TFT Connector (5 pins):
  -----
  | 1 | RST
  | 2 | PA3 RX2 ← PA3 is HERE (Pin 2)
  | 3 | PA2 TX2
  | 4 | GND
  | 5 | 5V
  -----
```

**⚠️ IMPORTANT: TFT Connector Only Has 5 Pins!**

The TFT connector only provides:
- **PA2** (Reset)
- **PA3** (Data/Command) ← **Your target pin**
- **GND** and **5V** (Power)

**PA4, PA5, PA6, PA7 are NOT accessible here** - they're hardwired elsewhere on the board.

**This is why our configuration uses Software SPI with EXP1 connector pins instead of Hardware SPI!**

### **📍 Pin Index (Quick Lookup):**

**A-Pins (Port A):**
- **PA0**: Temperature sensor (Hotend) - Bottom area
- **PA1**: Servo connector - Right side
- **PA2**: TFT Reset - TFT Connector Pin 1
- **PA3**: TFT Data/Command - TFT Connector Pin 2 ← **YOUR TARGET**
- **PA4**: TFT Chip Select - **NOT ACCESSIBLE** (hardwired elsewhere)
- **PA5**: TFT Clock - **NOT ACCESSIBLE** (hardwired elsewhere)
- **PA6**: TFT MISO - **NOT ACCESSIBLE** (hardwired elsewhere)
- **PA7**: TFT MOSI - **NOT ACCESSIBLE** (hardwired elsewhere)
- **PA8**: NeoPixel LED - Right side
- **PA9**: Button 1 - EXP1 Connector Pin 3
- **PA10**: Button 2 - EXP1 Connector Pin 4
- **PA13**: SWD Debug - Right side (disabled)
- **PA14**: USB Connect - Right side (disabled)
- **PA15**: Button Encoder - EXP1 Connector Pin 2

**B-Pins (Port B):**
- **PB0**: Z Motor Step - Bottom area
- **PB1**: Z Motor Enable - Bottom area
- **PB2**: Y Motor Direction - Bottom area
- **PB3**: E0 Motor Step - Bottom area
- **PB4**: E0 Motor Direction - Bottom area
- **PB5**: Beeper - EXP1 Connector Pin 1
- **PB6**: I2C SCL (EEPROM) - Right side
- **PB7**: I2C SDA (EEPROM) - Right side
- **PB8**: LCD RS - EXP1 Connector Pin 7
- **PB9**: LCD D4 - EXP1 Connector Pin 6
- **PB10**: Y Motor Step - Bottom area
- **PB11**: Y Motor Enable - Bottom area
- **PB12**: X Motor Direction - Bottom area
- **PB13**: X Motor Step - Bottom area
- **PB14**: X Motor Enable - Bottom area
- **PB15**: LCD EN - EXP1 Connector Pin 8

**C-Pins (Port C):**
- **PC0**: X Limit Switch - Bottom area
- **PC1**: Y Limit Switch - Bottom area
- **PC2**: Z Limit Switch - Bottom area
- **PC3**: Bed Temperature - Bottom area
- **PC4**: SD Card Detect - Right side
- **PC5**: Z Motor Direction - Bottom area
- **PC6**: Fan 0 - Right side
- **PC7**: Fan 1 - Right side
- **PC8**: Hotend Heater - Right side
- **PC9**: Bed Heater - Right side
- **PC10**: TMC UART - Right side
- **PC11**: TMC UART - Right side
- **PC12**: Power Loss Detection - Right side
- **PC13**: Power Supply Control - Right side
- **PC14**: Z Probe - Right side
- **PC15**: Filament Runout - Right side

**D-Pins (Port D):**
- **PD2**: E0 Motor Enable - Bottom area

**Power Pins:**
- **3.3V**: Multiple locations - Right side power headers
- **5V**: Multiple locations - Right side power headers
- **24V**: Main power input - Right side
- **GND**: Multiple locations - Throughout board

**Special Pins:**
- **USB_DM**: PA11 (hardwired)
- **USB_DP**: PA12 (hardwired)
- **RESET**: Reset button (top)
- **BOOT0**: Boot button (top)
