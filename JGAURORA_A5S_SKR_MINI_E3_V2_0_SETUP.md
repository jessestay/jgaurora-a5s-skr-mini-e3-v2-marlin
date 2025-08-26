# 🚀 JGAurora A5S + SKR Mini E3 V2.0 Setup Guide

> **🎯 Goal**: Upgrade your JGAurora A5S with a touchscreen and modern motherboard in under 30 minutes

---

## 📋 **What You'll Get**

✅ **Touchscreen Display** - Full color with touch controls  
✅ **Modern Motherboard** - SKR Mini E3 V2.0 (STM32F103RE)  
✅ **SD Card Support** - Auto-detect, no extra wiring  
✅ **Filament Sensor** - Built-in runout detection  
✅ **NeoPixel LEDs** - RGB lighting effects  
✅ **USB Updates** - Easy firmware flashing  
✅ **All Original Features** - Preserved mechanics  

---

## 🚨 **IMPORTANT: Read This First**

**⚠️ CRITICAL WARNING**: The TFT connector on this board only has **5 pins** (PA2, PA3, GND, 5V, 3.3V). The hardwired SPI pins (PA4, PA5, PA6, PA7) are **NOT accessible**.

**✅ SOLUTION**: We use **Software SPI** with the EXP1 connector instead. This works perfectly and is actually easier to wire!

---

## 🔧 **Quick Start (3 Steps)**

### **Step 1: Get the Firmware**
- **Option A**: Use the pre-built files in this folder
- **Option B**: Build online at [Marlin Firmware Builder](https://marlinfw.org/tools/autobuild/)

### **Step 2: Wire the Display (8 wires)**
Connect the 34-pin ribbon to these pins:
- **YELLOW** → PB9 (EXP1-6) - Clock
- **BLUE** → PA15 (EXP1-2) - Chip Select  
- **ORANGE** → PB8 (EXP1-7) - Data In
- **RED** → PB5 (EXP1-1) - Data Out
- **BROWN** → PA2 (TFT connector) - Reset
- **PURPLE** → PA3 (TFT connector) - Data/Command
- **BLACK** → GND - Ground
- **PURPLE** → 3.3V - Power

### **Step 3: Flash & Test**
- Copy firmware to USB drive or SD card
- Power on the board
- Test display and touch

---

## 📍 **Pin Location Guide**

### **🔌 EXP1 Connector (Right Side)**
```
EXP1 Connector:
┌─────────┐
│ 1  3  5 │
│ 2  4  6 │
│ 7  8    │
└─────────┘

Pin 1: PB5  (MISO - RED wire)
Pin 2: PA15 (CS   - BLUE wire)  
Pin 6: PB9  (SCK  - YELLOW wire)
Pin 7: PB8  (MOSI - ORANGE wire)
Pin 8: PB15 (SD CS - GRAY wire, optional)
```

### **🔌 TFT Connector (Top-Left)**
```
TFT Connector (5 pins):
┌─────────┐
│ 1  3  5 │
│ 2  4    │
└─────────┘

Pin 1: PA2  (Reset - BROWN wire)
Pin 2: PA3  (Data/Command - PURPLE wire)
Pin 4: GND  (Ground - BLACK wire)
Pin 5: 3.3V (Power - PURPLE wire)
```

### **🔌 Power Connections**
- **3.3V**: Available on TFT connector and power headers
- **GND**: Available on TFT connector and power headers
- **5V**: Available on power headers (for NeoPixels)

---

## 🔌 **Complete Wiring Diagram**

### **📱 Display Connection (Required - 8 wires)**

| Wire Color | JGAurora Pin | SKR Pin | Function | Location |
|------------|--------------|---------|----------|----------|
| **YELLOW** | Pin 1 | PB9 | Clock | EXP1-6 |
| **BLUE** | Pin 2 | PA15 | Chip Select | EXP1-2 |
| **ORANGE** | Pin 5 | PB8 | Data In | EXP1-7 |
| **RED** | Pin 6 | PB5 | Data Out | EXP1-1 |
| **BROWN** | Pin 30 | PA2 | Reset | TFT Connector |
| **PURPLE** | Pin 33 | PA3 | Data/Command | TFT Connector |
| **BLACK** | Pin 8 | GND | Ground | TFT Connector |
| **PURPLE** | Pin 10 | 3.3V | Power | TFT Connector |

### **💾 SD Card Connection (Optional - 1 wire)**

| Wire Color | JGAurora Pin | SKR Pin | Function | Location |
|------------|--------------|---------|----------|----------|
| **GRAY** | Pin 3 | PB15 | SD Card CS | EXP1-8 |

---

## 📋 **Step-by-Step Wiring Instructions**

### **🔧 Step 1: Prepare Your Workspace**
- [ ] **Clean, well-lit area** with good ventilation
- [ ] **Small screwdriver** for terminal blocks
- [ ] **Wire strippers** if needed
- [ ] **Multimeter** (optional but recommended)

### **⚡ Step 2: Connect Power First**
1. **Connect Pin 8 (BLACK)** → **GND** on SKR board
2. **Connect Pin 10 (PURPLE)** → **3.3V** on SKR board

**✅ Test**: Board should power up normally

### **🔌 Step 3: Connect Display SPI Pins**
1. **Pin 1 (YELLOW)** → **PB9 (EXP1-6)**
2. **Pin 2 (BLUE)** → **PA15 (EXP1-2)**
3. **Pin 5 (ORANGE)** → **PB8 (EXP1-7)**
4. **Pin 6 (RED)** → **PB5 (EXP1-1)**

**✅ Test**: Display should show power indicator

### **📱 Step 4: Connect Display Control Pins**
1. **Pin 30 (BROWN)** → **PA2 (TFT connector)**
2. **Pin 33 (PURPLE)** → **PA3 (TFT connector)**

**✅ Test**: Display should show Marlin boot screen

### **💾 Step 5: Optional SD Card (Skip if not needed)**
1. **Pin 3 (GRAY)** → **PB15 (EXP1-8)**

---

## 🚨 **What NOT to Connect**

### **❌ 10-Pin Connector (Top of LCD Panel)**
- **DO NOT TOUCH** - This is internal LCD connection
- **Already wired** - No external connections needed
- **Modifying this** will damage the display

### **❌ Unused Pins**
- **Leave all unused pins disconnected**
- **Don't connect to 5V** - Display needs 3.3V only
- **Don't connect to random pins** - Only use specified connections

---

## 🔍 **Wiring Verification Checklist**

### **Before Powering On:**
- [ ] **All 8 required wires connected** (6 SPI + 2 power)
- [ ] **Wire colors match** the pinout guide exactly
- [ ] **10-pin connector untouched** (top of LCD panel)
- [ ] **Unused pins disconnected**
- [ ] **3.3V power** (not 5V)
- [ ] **Connections secure** and not loose

### **Power-Up Test:**
- [ ] **Display powers on** and shows Marlin boot screen
- [ ] **Touch responds** to finger input
- [ ] **No smoke or burning smell**
- [ ] **All LEDs on SKR board** light up normally

---

## 🚨 **Common Mistakes to Avoid**

| ❌ **Don't Do This** | ✅ **Do This Instead** |
|----------------------|------------------------|
| Connect 10-pin connector | Leave it alone - it's internal |
| Use 5V instead of 3.3V | Use 3.3V only for display |
| Connect unused pins | Leave them disconnected |
| Loose connections | Secure all wires tightly |
| Wrong wire colors | Follow color guide exactly |
| Random pin connections | Only use specified pins |

---

## 🔧 **Firmware Setup**

### **Option 1: Use Pre-built Files (EASIEST)**
1. **Find these files** in this folder:
   - `Configuration_FINAL_JGAurora_A5S_SKR_Mini_E3_V2_0.h`
   - `Configuration_adv_FINAL_JGAurora_A5S_SKR_Mini_E3_V2_0.h`
2. **Copy them** to your Marlin folder
3. **Build firmware** using your preferred method

### **Option 2: Online Builder (RECOMMENDED)**
1. **Go to**: [Marlin Firmware Builder](https://marlinfw.org/tools/autobuild/)
2. **Upload your Configuration.h** file
3. **Select board**: "BigTreeTech SKR Mini E3 V2.0"
4. **Build online** - gets around all local build issues
5. **Download the .bin file**

### **Option 3: Arduino IDE (Advanced Users)**
1. **Install Arduino IDE 1.8.x** (not 2.x)
2. **Install STM32duino board package**
3. **Select board**: "Generic STM32F103RE"
4. **Upload method**: "STM32CubeProgrammer (SWD)"
5. **Build and upload**

---

## 📱 **Flashing Instructions**

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

---

## ✅ **Testing & Verification**

### **After Flashing:**
1. **Check display** - Should show Marlin boot screen
2. **Test touch** - Touch should respond to finger input
3. **Check dimensions** - X/Y/Z should show correct values
4. **Test movement** - All axes should move correctly
5. **Check temperature** - Hotend and bed should read correctly

### **Test NeoPixel LEDs:**
Send this G-code to test red LEDs:
```gcode
M150 R255 G0 B0
```

---

## 🚨 **Troubleshooting**

### **Display Not Working:**
1. **Check power connections** - Verify 3.3V and GND
2. **Verify all 6 SPI pins** - SCK, CS, MOSI, MISO, RST, RS
3. **Check wire colors** - Ensure correct pin identification
4. **Verify pin numbers** - Count carefully from pin 1

### **Touch Not Responding:**
1. **Check MOSI/MISO connections** - Touch uses these pins
2. **Verify firmware settings** - TFTGLCD_PANEL_SPI enabled
3. **Check for loose connections** - Secure all wires

### **SD Card Issues:**
1. **Verify SD CS connection** - Pin 3 (FCS) to PB15
2. **Check shared SPI pins** - MOSI, MISO, SCK
3. **Ensure SD card formatted** - FAT32 format required

### **Power Issues:**
1. **Check voltage** - Must be 3.3V, not 5V
2. **Verify ground connection** - Use main GND
3. **Check wire gauge** - Ensure adequate current capacity

---

## 🎯 **Success Checklist**

- [ ] **Display shows Marlin boot screen**
- [ ] **Touch responds to finger input**  
- [ ] **No error messages** on display
- [ ] **All SKR board LEDs** light normally
- [ ] **No smoke or burning smell**
- [ ] **USB connection** works for firmware updates
- [ ] **All axes move** correctly
- [ ] **Temperature sensors** read correctly

---

## 🚀 **Next Steps**

1. **Connect hardware** using wiring diagram above
2. **Choose firmware method** (online builder recommended)
3. **Flash firmware** to SKR Mini E3 V2.0
4. **Test functionality** and calibrate
5. **Enjoy your upgraded JGAurora A5S!**

---

## 📞 **Need Help?**

**Most issues are wiring-related:**
1. **Double-check all connections** - Use the verification checklist
2. **Verify wire colors** - Follow the color guide exactly
3. **Check pin numbers** - Count carefully from pin 1
4. **Use online builder** - Gets around local build issues

**Community Support:**
- [Marlin Forums](https://forums.marlinfw.org/)
- [BigTreeTech Discord](https://discord.gg/biqu3d)

---

**Configuration Status**: ✅ READY TO USE  
**Build Method**: Online Marlin Builder (recommended)  
**Hardware**: Fully compatible  
**Features**: All JGAurora A5S features preserved + touchscreen support

**🎉 You're ready to upgrade your JGAurora A5S!**
