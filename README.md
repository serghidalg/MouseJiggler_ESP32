# 🖱️ ESP32-C3 BLE Mouse Jiggler v1.1

A simple, feature-rich Mouse Jiggler using an ESP32-C3 SuperMini and BLE to keep your system awake. This version adds status LEDs, mode memory, and more intuitive controls.

## 🚀 What's New in v1.1

- 💡 **LED Status Indicator**: The onboard LED now blinks with a unique pattern for each mode, so you always know what it's doing.
- 🧠 **Mode Memory**: Remembers your last-used mode, even after being unplugged.
- ✍️ **Natural Scribble Mode**: The ZIGZAG mode now simulates a more human-like scribble.
- 🛠️ **Intuitive Controls**: The button logic has been fixed. A single click now toggles the jiggler on (SLOW mode) and off.

## ✨ Features

- Works wirelessly via BLE.
- Single-button control for all modes.
- Visual feedback via the onboard LED.
- Multiple Jiggle Modes:
  - 🟢 **SLOW Mode**: Moves mouse every 60 seconds (wide range).
  - ⚡ **FAST Mode**: Moves mouse every second (small range).
  - 🌀 **ZIGZAG Mode**: Constant, natural scribble-like motion.
- Stability enhancements including a watchdog timer and auto-reconnect logic.

## 🛠️ Hardware Requirements

- ESP32-C3 SuperMini board
- USB Type-C Data Cable
- PC/Laptop with Bluetooth
- Optional: Breadboard/Case for enclosure

## 📦 Setup Instructions (PlatformIO)

### 1. 🔧 Install VS Code & PlatformIO

- Download & install VS Code
- Install the PlatformIO IDE extension

### 2. 🆕 Create New Project

- Open PlatformIO Home (Alien icon).
- Click **New Project**.
- Fill in the details:
  - **Name**: MouseJiggler
  - **Board**: Espressif ESP32-C3 Dev Module
  - **Framework**: Arduino
- Click **Finish**.

### 3. 📄 Add Code & Libraries

- Paste the main code into `src/main.cpp`.
- This project requires the **ESP32-BLE-Mouse** library. Add `T-vK/ESP32-BLE-Mouse` to the `lib_deps` line in your `platformio.ini` file.

### 4️⃣ Configure `platformio.ini`

```ini
[env:esp32-c3-devkitm-1]
platform = espressif32
board = esp32-c3-devkitm-1
framework = arduino
monitor_speed = 115200
lib_deps =
    T-vK/ESP32-BLE-Mouse
build_flags =
    -D ARDUINO_USB_MODE=1
    -D ARDUINO_USB_CDC_ON_BOOT=1
```

## 🎮 Button Controls (BOOT Button)

The controls are now simpler and more intuitive. The LED provides feedback for each mode.

| Press Count | Action                                 | LED Indicator |
|-------------|----------------------------------------|----------------|
| 1 Press     | Toggles between OFF and SLOW mode.     | Off / Slow Blink |
| 2 Presses   | Activates FAST mode.                   | Medium Blink     |
| 3 Presses   | Activates ZIGZAG (Scribble) mode.      | Fast Blink       |

## 💡 Notes

- Make sure you're using a proper USB data cable (not charge-only).
- The BLE Mouse will appear as: `"Wireless Jiggler"`.
- First-time pairing may require confirmation on your OS.

## 🛡️ License

This project is licensed under the MIT License.

## 🙌 Credits

- **ESP32-BLE-Mouse** by **T-vK**
