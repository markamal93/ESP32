# ⚡ ESP32 – Two Buttons, Two LEDs Example (ESP-IDF)

This project demonstrates how to control **two LEDs** using **two push buttons** on the **ESP32** with the **ESP-IDF** framework.  
Each button independently controls one LED — when a button is pressed, its corresponding LED turns ON; when released, the LED turns OFF.

---

## 🧠 Overview

The project uses four GPIO pins:
- Two configured as **outputs** for the LEDs.
- Two configured as **inputs** for the buttons.

The program continuously reads the button states and sets each LED accordingly.  
It runs inside a FreeRTOS task loop within the ESP-IDF environment.

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

- **ESP32 Development Board**  
- **ESP-IDF** (version 5.0 or newer)  
- **Two LEDs** (with current-limiting resistors)  
- **Two Push Buttons**  
- Basic wiring tools and USB cable  

---

## 🚀 How It Works

1. Each GPIO pin is reset and configured (LEDs → output, Buttons → input).  
2. The firmware continuously reads the state of both buttons.  
3. When a button reads **LOW (0)** → the corresponding LED turns **ON**.  
4. When it reads **HIGH (1)** → the LED turns **OFF**.  
5. This logic repeats indefinitely inside a loop.

This behavior assumes the buttons are wired with **pull-up resistors** (internal or external).

---
