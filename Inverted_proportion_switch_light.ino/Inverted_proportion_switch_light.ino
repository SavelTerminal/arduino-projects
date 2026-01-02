// tool che accende due lampadine in maniera direttamente inversa, inoltre nella zona centrale morta, viene acceso un terzo LED e spenti i 2 laterali.

void setup() {
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  int valore = analogRead(A0);
  int pwm = map(valore, 0, 1023, 0, 255);
  
  
  if (pwm > 100 && pwm < 175){
    analogWrite(11, LOW);
    analogWrite(10, LOW);
    digitalWrite(13, HIGH);
  }
  else{
  analogWrite(11, pwm);
  analogWrite(10, 255 - pwm);
  digitalWrite(13, LOW);
  }
}
