# 🖱️ ESP32-C3 BLE Mouse Jiggler

A simple **Mouse Jiggler** project using an **ESP32-C3 SuperMini** and BLE to keep your system awake by simulating mouse movement. Supports **slow**, **fast**, and **zigzag (scribble)** modes using a single button!

---

## 🚀 Features

- Works via **BLE** – no USB cable required.
- Built-in **button toggle** for:
  - 🟢 SLOW Mode: Moves mouse every 60 seconds (wide range)
  - ⚡ FAST Mode: Moves mouse every second (small range)
  - 🌀 ZIGZAG Mode: Constant scribble-like diagonal motion
- ⛔ OFF Mode: Press again to stop jiggle
- Designed for **ESP32-C3 SuperMini** (boot button used for toggling)
- No extra hardware needed.

---

## 📦 Getting Started

### 🧰 Requirements

- [ESP32-C3 SuperMini](https://www.espressif.com/en/products/devkits/esp32-c3-devkitm-1)
- USB Type-C **data** cable
- Computer with **Bluetooth** support
- [VS Code](https://code.visualstudio.com/) + [PlatformIO](https://platformio.org/install)

---

## 🛠️ Hardware Requirements

- ESP32-C3 SuperMini board  
- USB Type-C Data Cable  
- PC/Laptop with Bluetooth  
- Optional: Breadboard/Case for enclosure

---

## 📦 Setup Instructions (PlatformIO)

### 1. 🔧 Install VS Code & PlatformIO
- Download & install [VS Code](https://code.visualstudio.com/)
- Install the [PlatformIO IDE extension](https://platformio.org/install/ide?install=vscode)

### 2. 🆕 Create New Project
1. Open PlatformIO Home (Alien icon)
2. Click **New Project**
3. Fill:
   - Name: `MouseJiggler`
   - Board: `Espressif ESP32-C3 Dev Module`
   - Framework: `Arduino`
4. Click **Finish**

### 3. 📄 Add Code
Paste the main code into `src/main.cpp`.

### 3️⃣ Add Library

The project uses the [`ESP32-BLE-Mouse`](https://github.com/T-vK/ESP32-BLE-Mouse) library.

👉 You **do not need to install it via PlatformIO**, as it's already included in the `lib/` folder in this repo.

If you are cloning this independently, just copy the contents of that GitHub repo into your project's `lib/BLEMouse` directory.

### 4️⃣ Configure `platformio.ini`

Use the following config (already optimized for USB serial):

```ini
[env:esp32-c3-devkitm-1]
platform = espressif32
board = esp32-c3-devkitm-1
framework = arduino
monitor_speed = 115200
upload_speed = 115200
build_flags =
    -D ARDUINO_USB_MODE=1 
    -D ARDUINO_USB_CDC_ON_BOOT=1
```

---

## 🎮 Button Controls (BOOT Button)

| Press Count | Mode     | Description                                |
|-------------|----------|--------------------------------------------|
| 1 Press     | 🟢 SLOW   | Moves once every 60s (large range)         |
| 2 Presses   | ⚡ FAST   | Moves every 1s (short range jitter)        |
| 3 Presses   | 🌀 ZIGZAG | Continuous diagonal scribble movement      |
| 1 Press     | 🔴 OFF    | Stops jiggling (toggles from SLOW to OFF)  |

Uses the **BOOT** button on GPIO 9 of the ESP32-C3.

---

## 💡 Notes

- Make sure you're using a proper **USB data cable** (not charge-only).
- Serial messages like `BLE Mouse started...` will show up in the Serial Monitor.
- BLE Mouse will appear as: **"Dell Wireless Mouse WM126"**
- First-time pairing may require confirmation on your OS.

---

## 📸 Demo Preview

_Wireless BLE Mouse Jiggler in action_


---

## 🛡️ License

MIT License.  
Feel free to use

---

## 🙌 Credits

- [ESP32-BLE-Mouse by T-vK](https://github.com/T-vK/ESP32-BLE-Mouse)

---

## 🔗 Related

- [ESP32 BLE Docs](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-reference/bluetooth/esp_ble.html)
- [PlatformIO for ESP32](https://docs.platformio.org/en/latest/platforms/espressif32.html)