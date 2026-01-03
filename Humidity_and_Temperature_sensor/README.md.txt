# Arduino DHT11 Temperature & Humidity Monitor

## Overview
This project reads **temperature and humidity** from a DHT11 sensor and displays the values both on the **Serial Monitor** and on a **16x2 LCD screen**.

It is a simple but concrete embedded project focused on real-world data acquisition and visualization.

## What it does
- Reads humidity (%) from a DHT11 sensor
- Reads temperature (°C) from a DHT11 sensor
- Prints values to the Serial Monitor
- Displays values on a 16x2 LCD
- Handles sensor read errors gracefully

## How it works
- The DHT11 sensor is read using the `DHT` library
- Data is fetched as floating-point values
- If the sensor returns invalid data (`NaN`), the loop exits safely
- Values are refreshed every 2 seconds
- The LCD is cleared after each update cycle

## Requirements
- Arduino Uno (or compatible)
- DHT11 temperature & humidity sensor
- 16x2 LCD (HD44780 compatible)
- Potentiometer for LCD contrast
- Jumper wires
- Libraries:
  - `DHT`
  - `LiquidCrystal`

## Usage
1. Connect the DHT11 data pin to **digital pin 2**
2. Connect the LCD using 4-bit mode (pins 7–12)
3. Upload the sketch to Arduino
4. Open the Serial Monitor at **9600 baud**
5. Observe temperature and humidity values on both Serial Monitor and LCD

## Output
- Serial Monitor:
  - `Humidity: XX % | Temperature: XX °C`
- LCD:
  - Line 1: Humidity value
  - Line 2: Temperature value

## Notes
- The DHT11 has limited accuracy and slow refresh rate
- A delay of 2 seconds is required for reliable readings
- LCD is cleared after each cycle to avoid ghosting

## Possible improvements
- Replace DHT11 with DHT22 for better accuracy
- Add visual status indicators (LEDs)
- Add threshold alerts for humidity levels
- Store readings over time
- Enclose the project in a dedicated case
