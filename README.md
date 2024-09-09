# Heart Rate Monitoring Project with LCD Display and Apk Android

## Overview

This project uses an Arduino, Pulse Sensor, and an LCD to monitor and display heart rate (BPM). It provides real-time heart rate data on the LCD screen and uses a buzzer to alert when a pulse is detected.

## Components

- Arduino Board (e.g., Arduino Uno)
- Pulse Sensor
- 16x2 Liquid Crystal Display (LCD) with I2C
- Buzzer
- LED
- Resistors and other basic electronic components

## Libraries

- [PulseSensorPlayground](https://github.com/WorldFamousElectronics/PulseSensorPlayground) - For interfacing with the Pulse Sensor
- [LiquidCrystal_I2C](https://github.com/fdebrabander/Arduino-LiquidCrystal-I2C-library) - For controlling the LCD

## Circuit Diagram

- **Pulse Sensor**:
  - Signal pin to Analog pin A1
  - VCC to 5V
  - GND to GND
- **LCD (I2C)**:
  - SDA to A4 (on Arduino Uno)
  - SCL to A5 (on Arduino Uno)
  - VCC to 5V
  - GND to GND
- **Buzzer**:
  - Positive pin to Digital pin 4
  - Negative pin to GND
- **LED**:
  - Positive pin to Digital pin 13
  - Negative pin to GND

## Code Description

1. **Setup**:

   - Initializes serial communication, LCD, Pulse Sensor, and buzzer.
   - Displays a startup message on the LCD.

2. **Loop**:

   - Continuously reads BPM from the Pulse Sensor.
   - If a beat is detected, it activates the buzzer and displays BPM on the LCD.

3. **Functions**:
   - `buzz()`: Activates the buzzer for a short duration when a beat is detected.
   - `lcd_tampil()`: Updates the LCD with the current BPM value.

## Usage

1. Connect the components as described in the Circuit Diagram.
2. Upload the code to your Arduino.
3. Open the Serial Monitor to view BPM readings and messages.
4. Observe the heart rate data on the LCD and listen for the buzzer alerts.
