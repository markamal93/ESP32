# 💡 ESP32 – Button Toggle LED with External Pull-Up (ESP-IDF)

**Description:**  
This project demonstrates how to **toggle an LED** each time a **button is pressed**, using an **external pull-up resistor** on the **ESP32** with the **ESP-IDF** framework.  
The circuit ensures stable button behavior by keeping the GPIO input HIGH when the button is not pressed and LOW when pressed.

---

## 🏷️ Project Details

- **Framework:** ESP-IDF (FreeRTOS-based)  
- **Language:** C  
- **Platform:** ESP32  
- **Difficulty:** Beginner  
- **Category:** GPIO / Input / LED Control  
- **License:** Public Domain (CC0)  

**Tags:**  
`ESP32` · `ESP-IDF` · `FreeRTOS` · `GPIO` · `LED` · `Button` · `Toggle` · `External Pull-up` · `Embedded-C` · `IoT Basics`

---

## 🧠 Overview

This example introduces **edge detection** and **external pull-up logic** for stable button input reading.  
Each button press toggles the LED state — ON, then OFF, then ON again.  
It’s ideal for learning how to interface **mechanical switches** with ESP32 safely and reliably.

---

## ⚙️ Hardware Setup

The push button is connected to **GPIO13** with an **external pull-up resistor** (typically 10kΩ).  
When the button is **not pressed**, the input reads **HIGH (1)**.  
When pressed, it connects the pin to **GND**, making the input **LOW (0)**.

---

## 📁 Pin Configuration

| Component | GPIO Pin | Direction | Description |
|------------|-----------|------------|--------------|
| LED        | GPIO2     | Output     | Turns ON/OFF when button is pressed |
| Button     | GPIO13    | Input      | External pull-up switch that toggles LED |

---

## 🔌 Circuit Description

**Connections:**

- One side of the **button** connects to **GPIO13**.  
- The other side connects to **GND**.  
- A **10kΩ resistor** connects **GPIO13** to **3.3V** (external pull-up).  
- The **LED** connects to **GPIO2** with a **220Ω resistor** in series to GND.  

This setup ensures clean digital input transitions and avoids floating pin behavior.

---

## 🚀 How It Works

1. The LED pin is configured as **output**, and the button pin as **input**.  
2. The program continuously monitors the button’s state.  
3. When the button transitions from **HIGH → LOW** (pressed), the LED toggles.  
4. A short 50 ms delay is used for basic **debouncing**.  
5. Polling continues every 10 ms in an infinite loop under FreeRTOS.

This ensures stable and reliable LED toggling with each button press.

---
