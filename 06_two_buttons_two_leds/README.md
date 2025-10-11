# ⚡ ESP32 – Two Buttons, Two LEDs Example (ESP-IDF)

**Description:**  
A simple example showing how to control two LEDs using two push buttons on an **ESP32** board using the **ESP-IDF** framework.  
Each button controls one LED — press the button to turn the LED ON, release it to turn it OFF.  
This project demonstrates basic **GPIO input/output handling** in ESP-IDF.

---

## 🏷️ Project Details

- **Framework:** ESP-IDF (FreeRTOS-based)  
- **Language:** C  
- **Platform:** ESP32  
- **Difficulty Level:** Beginner  
- **Category:** GPIO / Input-Output / Embedded Systems  
- **License:** Public Domain (CC0)

**Tags:**  
`ESP32` · `ESP-IDF` · `FreeRTOS` · `Embedded C` · `GPIO` · `LED` · `Button` · `IoT Basics` · `Microcontroller`

---

## 🧠 Overview

This example illustrates the use of GPIO pins for both input and output on the ESP32.  
Two push buttons are used to control two LEDs independently, allowing hands-on understanding of digital signal reading and control in embedded systems.

---

## 📁 Pin Configuration

| Component | GPIO Pin | Direction | Description |
|------------|-----------|------------|--------------|
| LED 1      | GPIO2     | Output     | Controlled by Button 1 |
| LED 2      | GPIO4     | Output     | Controlled by Button 2 |
| Button 1   | GPIO5     | Input      | Turns LED 1 ON/OFF |
| Button 2   | GPIO18    | Input      | Turns LED 2 ON/OFF |

---

## ⚙️ Requirements

- ESP32 Development Board  
- ESP-IDF installed (v5.0 or later)  
- Two LEDs with resistors  
- Two push buttons  
- Basic jumper wires and breadboard  
- USB cable for flashing and monitoring  

---

## 🚀 How It Works

1. Initialize and configure GPIO pins:
   - LEDs → Output mode  
   - Buttons → Input mode  
2. Continuously read button states in an infinite loop.  
3. When a button reads **LOW (pressed)**, the corresponding LED turns **ON**.  
4. When it reads **HIGH (released)**, the LED turns **OFF**.  
5. The logic assumes pull-up resistors are enabled.

This demonstrates simple digital input-output control using ESP-IDF’s GPIO driver.

---
