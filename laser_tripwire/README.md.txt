# Laser Tripwire (LDR + Timer)

Simple laser tripwire using a photoresistor (LDR) and a non-blocking timer.
When the laser beam is interrupted, a LED turns on for a fixed amount of time.

## What it does
- Reads light intensity from a photoresistor on analog pin A0
- Detects when the laser beam is interrupted (value below threshold)
- Turns a LED ON
- Keeps the LED ON for 3 seconds using millis()
- Turns the LED OFF automatically after the timer expires

## Components
- Arduino (Uno or compatible)
- Laser module
- Photoresistor (LDR)
- 10kΩ resistor
- LED
- Jumper wires
- Breadboard

## How it works
- The LDR and resistor form a voltage divider connected to A0
- When the laser hits the LDR, the analog value is high
- When the beam is broken, the value drops below a threshold
- The first valid trigger stores the current time (millis)
- The LED stays ON until the time difference reaches the configured duration

## Pins
- A0 -> Photoresistor signal
- 13 -> LED output

## Configuration
You can tweak these constants in the code:

const int SOGLIA = 800;
Light threshold

const int TIMER_LED = 3000;
LED ON time in milliseconds

## Notes
- Uses non-blocking timing (millis), no delay
- The trigger fires only once per event
- Designed as a base for more complex state-based logic

## Possible improvements
- Add explicit states (IDLE / ARMED)
- Add a buzzer or relay
- Add debounce / noise filtering
- Replace Arduino with ESP32 for Wi-Fi control
