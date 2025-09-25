# LTR390 BLE UV Sensor

A Bluetooth Low Energy (BLE) UV sensor device that connects with the [UV Light Sensor Android App](https://github.com/SlothCodeSloth/UVLightSensor) to provide UV index monitoring for safe sunscreen applications.

## 📋 Overview

This Arduino project utilizes the Adafruit LTR390 UV sensor to create a wireless BLE device that communicates UV readings to compatible Android applications. The sensor provides accurate UV measurements to enable accurate sunscreen application times.

---

## 🔧 Hardware Requirements

### Essential Components
| Component | Description | Purpose |
|-----------|-------------|---------|
| **Adafruit LTR390** | UV/Ambient Light Sensor | Measures UV index and ambient light |
| **Arduino Microcontroller** | BLE-capable microcontroller | Processes sensor data and handles BLE communication |
| **Breadboard/PCB** | Connection platform | Circuit assembly |
| **Jumper Wires** | Connections | I2C and power connections |
| **3.7V Li-Po Battery** (Optional) | Portable power | For mobile sensor deployment |

---

## 🛜 BLE Configuration

### Device Advertisement
```cpp
Device Name: "UVSensor"
Service UUID: 19B10000-E8F2-537E-4F6C-D104768A1214
Characteristic UUID: 19B10001-E8F2-537E-4F6C-D104768A1214
```


## 📚 Software Dependencies
Arduino IDE

---

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

---

## 🙏 Acknowledgments

- **Adafruit** - LTR390 sensor library and hardware design
- **Arduino Community** - ESP32 BLE libraries and examples  
- **Android Developer Community** - BLE protocol documentation
- **UV Light Sensor Android App** - Compatible mobile application

---
