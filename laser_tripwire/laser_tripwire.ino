const int TENSION = A0;
const int LED_PIN = 13;
const int SOGLIA = 800;
const int TIMER_LED = 3000;
int TIME_DIFFERENCE = 0;
unsigned long trigger_time = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int photo_res = analogRead(TENSION);
  Serial.println(photo_res);

  if (photo_res <= SOGLIA && trigger_time == 0){
    digitalWrite(LED_PIN, HIGH);
    trigger_time = millis();
  }
  TIME_DIFFERENCE = millis() - trigger_time;
  
  if (TIME_DIFFERENCE >= TIMER_LED){
    digitalWrite(LED_PIN, LOW);
    trigger_time = 0;
  }

}
