//Crea variabili: Led acceso, timer spegnimento 
//Movimento Rilevato
//Controlla se il led era già acceso, se non lo era, procedi con l'else
//Leggi se il movimento è stato rilevato o no e segnalo su una variabile
//Se il movimento è stato rilevato in questo giro, accendi la lampadina e fai partire il timer (millis()) collegandolo alla variabile timer spegnimento
//Se il movimento non è stato rilevato e "timer spegnimento" è superiore a 5000, spegni il led


bool stato_led = LOW;
unsigned long tempo_attuale = 0;
unsigned long tempo_buzzer = 0; //Si usa unsigned long quando arrivano valori da millis e può sopportare numeri alti,
int evento_movimento = 0; //dato che int arrivato a circa 34.000 andrebbe in errore

void setup() {
  pinMode(13, OUTPUT);
  pinMode(10, INPUT);
  pinMode(3, OUTPUT);

}

void loop() {
  int sensore_movimento = digitalRead(10);
  int stato_led = digitalRead(13); // Legge valori degli input

  if (sensore_movimento == HIGH){
    digitalWrite(13, HIGH); //Accende il led se rileva un movimento
    tempo_attuale = millis(); //Segna il tempo attuale in cui è stato rilevato il movimento
  }
  if (sensore_movimento == 1 && evento_movimento == 0){
    tone(3, 600); //Per controllare Buzzer passivo (Pin, Frequenza HZ)
    tempo_buzzer = millis();
  }
  int buzzer_off = millis() - tempo_buzzer;
  if (buzzer_off >= 50){
      noTone(3); //per interrompere il buzz
  }
  int led_off = millis() - tempo_attuale;

  if (led_off >= 5000){
    digitalWrite(13, LOW);  //Spegne il led quando sono passati 5 secondi senza movimenti
  }
  evento_movimento = sensore_movimento;
}
