# Arduino Mouse Trap

## Overview

This project is a simple automated mouse trap using an Arduino board and a servo motor.
A phototransistor and an LED form a simple light-based detection system. 
When a mouse interrupts the light beam, the trap is triggered instantly.
The system also records how long the system runs before activation using EEPROM.

You can find a Construction manual [here](https://www.instructables.com/How-to-Build-an-Arduino-Mouse-Trap-Simple-Effectiv/.)

---

## Features
- Light barrier detection (LED + phototransistor)
- Fast servo-based trap mechanism
- Runtime tracking (days, hours, minutes)
- EEPROM storage
- Simple and low-cost components

---

## Components
- Arduino (e.g. Uno)
- Servo motor
- Phototransistor
- LED (light source)
- Resistors
- Jumper wires
- Bait (very important)

---

## Bait
To attract mice, use:
- Peanut butter (highly effective)
- Chocolate
- Nuts / seeds
- Bread

Place the bait behind the sensor so the mouse must cross the light beam.

---

## How It Works
1. The LED continuously shines on the phototransistor  
2. As long as light is detected, the system waits  
3. When a mouse interrupts the beam:
   - Light drops below the threshold
   - Arduino detects the change
   - Servo triggers the trap
   - LED turns off
   - Runtime is calculated
   - Data is stored in EEPROM

---

## Detection Principle
The system measures light intensity:
- High value: light reaches the phototransistor
- Low value: light is blocked (trigger condition)

The threshold value must be calibrated depending on the setup and ambient light.

---

## Data Storage (EEPROM)
Runtime is stored using a structured format:
- Days
- Hours
- Minutes

All values are saved starting at EEPROM address 0.

---

## Code Structure

### Trap Logic (print.ino)
Main program responsible for detection, triggering the trap, and saving runtime.

### Read EEPROM (read.ino)
Reads and prints stored runtime data via serial output.

### Reset / Open Trap (open.ino)
Moves the servo back to the open position.

---

## Important Notes
- Sensor alignment between LED and phototransistor is critical
- Ambient light can affect detection accuracy
- Servo positions:
  - 90° = open
  - 180° = triggered
- EEPROM is overwritten on each run

---

## Possible Improvements
- Prevent EEPROM reset on startup
- Shield sensor from ambient light
- Add adjustable threshold (e.g. potentiometer)
- Add wireless notification (ESP8266 / ESP32)
- Add battery operation

---

## Disclaimer
This project is for educational purposes only.  
Use responsibly and follow local regulations regarding animal handling.
