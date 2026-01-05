# Arduino Humidity & Temperature Monitor

## Overview
This project is a **non-blocking indoor humidity and temperature monitor** built with Arduino, a DHT11 sensor, a 16x2 LCD, and three status LEDs.

The system continuously measures environmental conditions and provides clear visual feedback using both a display and color-coded LEDs.

## What it does
- Reads humidity (%) and temperature (°C) from a DHT11 sensor
- Uses a state-based logic to classify humidity levels
- Displays live data on a 16x2 LCD
- Uses three LEDs to indicate air condition status
- Operates without `delay()` using time-based scheduling (`millis()`)

## How it works
- The DHT11 sensor is read at safe intervals to avoid invalid readings
- Humidity values are mapped to logical states (`DRY`, `WARNING`, `OK`, `HUMID`)
- LEDs are updated only when new sensor data is available
- The LCD refreshes independently at a fixed interval
- The last valid readings are preserved between updates

## Requirements
- Arduino Uno (or compatible)
- DHT11 temperature & humidity sensor
- 16x2 LCD (HD44780 compatible)
- 3 LEDs (red, yellow, green) with resistors
- Potentiometer for LCD contrast
- Jumper wires
- Libraries:
  - `DHT`
  - `LiquidCrystal`

## Usage
1. Connect the DHT11 data pin to digital pin 10
2. Connect the LCD in 4-bit mode
3. Connect LEDs to pins 11 (red), 12 (yellow), and 13 (green)
4. Upload the sketch
5. Observe real-time humidity and temperature feedback

## Output
- LCD:
  - Line 1: Humidity percentage
  - Line 2: Temperature in Celsius
- LEDs:
  - Green: Optimal humidity
  - Yellow: Warning range
  - Red: Critical dry or humid conditions

## Notes
- The DHT11 has limited precision and slow refresh rates
- Read intervals are enforced to ensure sensor stability
- The system is designed to run continuously without blocking

## Possible improvements
- Add hysteresis to avoid rapid state switching
- Replace DHT11 with DHT22 for better accuracy
- Add buzzer alerts for critical conditions
- Add data logging or wireless connectivity
