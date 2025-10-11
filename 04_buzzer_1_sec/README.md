# ESP32 Buzzer Control Example (ESP-IDF)

This project demonstrates how to **control a buzzer using the ESP-IDF framework** and **FreeRTOS**.  
It toggles the buzzer ON and OFF every 1 second, creating a simple beeping pattern.

---

## 🧠 Overview

The application configures a GPIO pin as an output to drive a buzzer.  
It alternates the buzzer’s state (HIGH and LOW) with a 1-second delay between each toggle using FreeRTOS delays.  
This example showcases how to use GPIO and timing functions in ESP-IDF to generate periodic signals.

---

## ⚙️ Requirements

- **ESP32 Development Board**  
- **ESP-IDF Framework** (v5.0 or later)  
- **Active or Passive Buzzer Module**  
- **USB cable** and **serial monitor** for output observation  

---

## 🧩 How It Works

1. The buzzer GPIO pin (default **GPIO5**) is configured as an output.  
2. The program runs an infinite loop where it turns the buzzer ON for 1 second, then OFF for 1 second.  
3. Timing is managed using the FreeRTOS `vTaskDelay()` function.  

This results in a continuous beeping sound.

---
