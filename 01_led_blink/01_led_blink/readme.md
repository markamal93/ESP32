# ESP32 LED Blink Example (ESP-IDF)

This project demonstrates a simple **LED blink** example using the **ESP-IDF** framework and **FreeRTOS**.  
It toggles an LED connected to **GPIO2** on and off every 500 milliseconds.

---

## 🧠 Overview

The program initializes GPIO2 as an output pin and continuously toggles its state between HIGH and LOW inside an infinite FreeRTOS loop, creating a visible blinking effect on the LED.

---

## ⚙️ Requirements

- **ESP32 Development Board**
- **ESP-IDF Framework** (v5.0 or later recommended)
- **USB Cable** for flashing
- **VS Code** or **ESP-IDF CLI tools**

---

## 🧩 How It Works

1. **GPIO Configuration**
   - The LED pin (`GPIO_NUM_2`) is reset and configured as an output.
2. **Blink Loop**
   - The LED is turned ON (`gpio_set_level(LED_PIN, 1)`).
   - The task delays for 500 ms.
   - The LED is turned OFF (`gpio_set_level(LED_PIN, 0)`).
   - The task delays again for 500 ms.

This creates a 1 Hz blinking rate (1 second ON/OFF cycle).
    }
}
