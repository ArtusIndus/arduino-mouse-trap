# Arduino Mouse Trap

## Overview
This project is a simple automated mouse trap using an Arduino and a servo motor.

A phototransistor and an LED are used together as a light-based detection system. When a mouse interrupts the light reaching the sensor, the trap is triggered instantly.

The system also records how long it has been running before activation using EEPROM.

---

## Features
- Light-based detection using LED and phototransistor
- Fast servo-triggered trap mechanism
- LED used as light source for detection
- Time tracking (days, hours, minutes)
- EEPROM storage

---

## Components
- Arduino (e.g. Uno)
- Servo motor
- Phototransistor
- LED (used as light source)
- Resistors
- Jumper wires

---

## Bait (Important)

To make the trap effective, bait is required to attract the mouse.

Common options:
- Peanut butter (very effective)
- Chocolate
- Nuts or seeds
- Bread

The bait should be placed behind the sensor so the mouse has to pass through the detection area.

Make sure the mouse interrupts the light beam between the LED and phototransistor.

---

## How It Works
1. The LED continuously shines light onto the phototransistor.
2. As long as the light reaches the sensor, the system stays idle.
3. When a mouse passes between the LED and the phototransistor:
   - The light is blocked
   - The sensor value drops below a threshold
4. The Arduino detects this change and:
   - Triggers the servo (trap closes)
   - Turns off the LED
   - Calculates runtime
   - Stores time in EEPROM

---

## Detection Principle
The system works by measuring light intensity:
- High value → light reaches the phototransistor
- Low value → light is blocked (trigger condition)

Threshold in code:

```cpp
while(analogRead(sensor)>30){} // try which value is good. 30 was good for me.
```

This value may need calibration depending on your setup and environment.

---

## Data Storage
The Arduino stores:
- Days
- Hours
- Minutes

in EEPROM addresses:
- 0 → Days  
- 1 → Hours  
- 2 → Minutes  

---

## Important Notes
- EEPROM is cleared on every startup in this version.
- Sensor alignment (LED ↔ phototransistor) is critical.
- Ambient light may affect readings.
- Servo positions:
  - `90°` = open
  - `180°` = triggered

---

## Possible Improvements
- Remove EEPROM reset on startup
- Shield sensor from ambient light
- Add adjustable threshold (potentiometer)
- Add wireless notification (ESP8266 / ESP32)
- Add enclosure for stability

---

## Disclaimer
This project is for educational purposes only.  
Use responsibly and follow local regulations regarding animal handling.
