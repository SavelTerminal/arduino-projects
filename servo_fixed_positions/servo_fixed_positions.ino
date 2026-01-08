// SERVO 3 FIXED POSITIONS - STABLE VERSION
// Pin: D7

int servoPin = 7;

int LEFT   = 440;
int CENTER = 1350;
int RIGHT  = 2300;

void setup() {
  pinMode(servoPin, OUTPUT);
}

void sendPulse(int us) {
  digitalWrite(servoPin, HIGH);
  delayMicroseconds(us);
  digitalWrite(servoPin, LOW);
}

void holdPosition(int us, int durationMs) {
  int cycles = durationMs / 20;   // ~50 Hz refresh
  for (int i = 0; i < cycles; i++) {
    sendPulse(us);
    delay(20);
  }
}

void loop() {
  holdPosition(LEFT, 2000);    // left for 2s
  holdPosition(CENTER, 2000);  // center for 2s
  holdPosition(RIGHT, 2000);   // right for 2s
}
