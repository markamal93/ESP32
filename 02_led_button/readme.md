# ESP32 Button-Controlled LED Example (ESP-IDF)

This project demonstrates how to **control an LED using a push button** with the **ESP-IDF** framework and **FreeRTOS**.  
It continuously reads the button input and toggles the LED state accordingly, while printing the button state to the serial monitor.

---

## 🧠 Overview

The code configures:
- **GPIO4** as a digital input (button)
- **GPIO2** as a digital output (LED)

When the button is **pressed**, the LED turns **OFF**.  
When the button is **released**, the LED turns **ON**.

The program also prints the current button state to the serial terminal every 500 milliseconds.

---

## ⚙️ Requirements

- **ESP32 Development Board**
- **ESP-IDF Framework** (v5.0 or later)
- **Push Button** connected to GPIO4 (with pull-up or pull-down resistor)
- **LED** connected to GPIO2 (or onboard LED)

---

## 🧩 How It Works

1. The LED and button GPIOs are reset and configured.
2. The program reads the button state using `gpio_get_level(button_pin)`.
3. It inverts the value and drives the LED with `gpio_set_level(led_pin, !button_val)`.
4. The button state is printed to the serial monitor.

---
