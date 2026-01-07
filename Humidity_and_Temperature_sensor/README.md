# Arduino DHT11 Temperature & Humidity Monitor

## Overview
This project reads temperature and humidity from a DHT11 sensor and displays the values on the Serial Monitor and on a 16x2 LCD screen.
It also evaluates humidity levels and signals the current state using three LEDs.

This version represents a stable baseline (v1.0) intended to be extended in future iterations.

## What it does
- Reads humidity (%) from a DHT11 sensor
- Reads temperature (°C) from a DHT11 sensor
- Displays values on a 16x2 LCD
- Prints values to the Serial Monitor
- Classifies humidity into logical states:
  - DRY
  - OK
  - WARNING
  - HUMID
- Signals the current humidity state using LEDs
- Uses non-blocking timing (millis())

## How it works
- The DHT11 sensor is read using the DHT library
- Sensor values are read every 1.5 seconds
- If invalid data (NaN) is received, the current loop iteration is aborted
- The LCD is refreshed every 5 seconds
- Humidity values are evaluated against fixed thresholds to determine a state
- Each state controls a specific LED output

## Hardware requirements
- Arduino Uno (or compatible)
- DHT11 temperature & humidity sensor
- 16x2 LCD (HD44780 compatible)
- Potentiometer for LCD contrast
- 3 LEDs (red, yellow, green)
- Current-limiting resistors
- Jumper wires

## Libraries
- DHT
- LiquidCrystal

## Pin configuration
DHT11
- Data pin -> Digital pin 10

LCD (4-bit mode)
- RS -> 2
- EN -> 3
- D4 -> 4
- D5 -> 5
- D6 -> 6
- D7 -> 7

LEDs
- Green LED -> Pin 13
- Yellow LED -> Pin 12
- Red LED -> Pin 11

## Output
Serial Monitor:
Humidity: XX %  |  Temperature: XX °C

LCD:
Line 1: Humidity: XX%
Line 2: Temp.: XX C

LED status
- Green: optimal humidity
- Yellow: warning range
- Red: too dry or too humid

## Notes
- The DHT11 has limited accuracy and a slow refresh rate
- Timing is handled without delay() to keep the loop responsive
- Humidity thresholds are currently hardcoded
- DRY and HUMID states share the same LED color in v1.0

## Possible improvements
- Replace DHT11 with DHT22 for higher accuracy
- Externalize humidity thresholds
- Add an automatic humidifier control
- Add remote monitoring/control (Wi-Fi or Bluetooth)
- Improve error handling with a dedicated sensor error state
- Refactor display logic into a dedicated state machine
