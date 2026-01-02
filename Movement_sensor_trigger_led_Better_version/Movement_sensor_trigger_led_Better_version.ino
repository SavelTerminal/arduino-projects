//Creare la variabile "Stato" per il LED
//Il sensore di movimento rileva se c'è stato un movimento
//Se c'è stato, la variabile Stato del led passa su ON e si accende il LED
//Se non c'è stato, la variabile passa su COOLDOWN e attende che siano passati 5 secondi, se sono passati, il led passa su OFF
//
//
enum StatoLed {   //enum serve per creare una lista di opzioni per uno stato
  ON,
  OFF,
  COOLDOWN
};

StatoLed stato_led = OFF;   //StatoLed stato_led = OFF Associa la variabile stato led al valore enum, così da non sbagliare
unsigned long movimento_rilevato = 0;   //Determina il momento in cui è stato rilevato il movimento
int tempo_spegnimento = 5000;
int LED_PIN = 13;
int PIR_PIN = 10;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(PIR_PIN, INPUT);
}

void loop() {
  int sensore_movimento = digitalRead(PIR_PIN);
  if (sensore_movimento == HIGH){
    stato_led = ON;
    movimento_rilevato = millis();
  }

  else if (stato_led == ON && sensore_movimento == LOW){
    stato_led = COOLDOWN;
  }

  else if (stato_led == COOLDOWN){
    int led_off = millis() - movimento_rilevato;  //Sottrae il tempo attuale a quando è stato rilevato il movimento
    if (led_off >= tempo_spegnimento){
      stato_led = OFF;
    }
  }

  if (stato_led == ON){     //Da qui decido cosa fanno gli stati assegnati al led
    digitalWrite(LED_PIN, HIGH);
  }

  else if (stato_led == OFF){
    digitalWrite(LED_PIN,LOW);
  }
}
