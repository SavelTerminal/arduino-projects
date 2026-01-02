bool state = false;
int before_press = 1;

void setup() {
  pinMode(8, INPUT_PULLUP);
  pinMode(12, OUTPUT);
}

void loop() {
  int button = digitalRead(8);
  if (before_press == 1 && button == 0){
    state = !state;
  }

  if (state == true){
    digitalWrite(12, HIGH);
  }
  else{
    digitalWrite(12, LOW);
  }
  before_press = button;
}