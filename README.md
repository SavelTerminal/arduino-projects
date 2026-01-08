# Servo Motor – Fixed Positions Test

## Overview
This project demonstrates basic and stable control of a hobby servo motor using raw PWM signals generated manually in Arduino code.

The goal is to understand how a servo holds a position over time, without using external libraries.

---

## What it does
- Moves the servo to three fixed positions
  - Left
  - Center
  - Right
- Each position is held stably for a fixed duration
- Prevents jitter and loss of position by repeating control pulses

---

## How it works
- The servo is controlled using PWM pulses
  - Pulse width (in microseconds) defines the position
  - Pulses are repeated approximately every 20 ms
- A helper function sends a single pulse
- Another function repeats pulses for a given duration to hold the position

---

## Requirements
- Arduino-compatible board (e.g. Arduino Uno  Nano)
- Hobby servo motor (3-wire VCC, GND, SIGNAL)
- External 5–6V power supply recommended (optional for testing)
- Common GND between Arduino and servo power

---

## Usage
1. Connect the servo
   - Red → 5V
   - BrownBlack → GND
   - YellowWhite → Digital pin D7
2. Upload the sketch
3. The servo will
   - Move to LEFT and hold
   - Move to CENTER and hold
   - Move to RIGHT and hold
   - Repeat continuously

---

## Output
- Servo reaches repeatable, stable positions
- No uncontrolled movement
- Minimal vibration when holding position

---

## Notes
- Servo pulse ranges vary between models
- Values used in this project are experimentally measured
- A single pulse is not enough to hold a position
- Continuous refresh is required

---

## Possible improvements
- Replace raw PWM with Arduino `Servo` library
- Add smooth scanning between positions
- Parameterize refresh rate
- Control position via serial input
- Port to ESP32 using hardware timers
