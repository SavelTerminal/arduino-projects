#include <DHT.h>

// Digital pin used by the DHT11 sensor
#define DHTPIN 10
#define DHTTYPE DHT11

#include <LiquidCrystal.h>
// LCD pins: RS, E, D4, D5, D6, D7 (4-bit mode)
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

// DHT sensor instance
DHT dht(DHTPIN, DHTTYPE);

// Logical states derived from humidity ranges
enum Humiditystate {
  DRY,      // Critically dry air
  HUMID,    // Critically humid air
  OK,       // Optimal humidity range
  WARNING   // Outside optimal range but not critical
};

// LED pins used as visual indicators
const int pinVerde = 13;
const int pinGiallo = 12;
const int pinRosso = 11;

// Current humidity state
Humiditystate humidityState;

// LCD timing control (non-blocking)
unsigned long screen_delay;
unsigned long actual_time = 0;
int duration_delay = 5000; // LCD refresh interval (ms)

// DHT timing control (non-blocking)
unsigned long lastDhtRead = 0;
int dhtDelay = 1500;       // Minimum delay between DHT reads (ms)
unsigned long dhtTimer;

// Latest valid sensor readings
float humidity = 0;
float temperature = 0;

void setup() {
  Serial.begin(9600);      // Serial output for debugging
  dht.begin();             // Initialize DHT sensor
  lcd.begin(16, 2);        // Initialize 16x2 LCD

  // Configure LED pins
  pinMode(pinVerde, OUTPUT);
  pinMode(pinGiallo, OUTPUT);
  pinMode(pinRosso, OUTPUT);
}

void loop() {

  // Check if enough time has passed to safely read the DHT sensor
  dhtTimer = millis() - lastDhtRead;

  if (dhtTimer >= dhtDelay){
    // Read humidity and temperature
    humidity = dht.readHumidity();
    temperature = dht.readTemperature(); // Celsius
    lastDhtRead = millis();

    // Abort cycle if sensor data is invalid
    if (isnan(humidity) || isnan(temperature)) {
      Serial.println("Failed to read from DHT sensor");
      return;
    }

    // Determine humidity state based on defined ranges
    if (humidity <= 30){
      humidityState = DRY;
    }
    else if(humidity >= 31 && humidity <= 40){
      humidityState = WARNING;
    }
    else if(humidity >= 41 && humidity <= 60){
      humidityState = OK;
    }
    else if(humidity >= 61 && humidity <= 70){
      humidityState = WARNING;
    }
    else if(humidity >= 71){
      humidityState = HUMID;
    }

    // Update LEDs according to current humidity state
    if (humidityState == DRY){
      digitalWrite(pinRosso, HIGH);
      digitalWrite(pinGiallo, LOW);
      digitalWrite(pinVerde, LOW);
    }
    else if (humidityState == OK){
      digitalWrite(pinRosso, LOW);
      digitalWrite(pinGiallo, LOW);
      digitalWrite(pinVerde, HIGH);
    }
    else if (humidityState == WARNING){
      digitalWrite(pinRosso, LOW);
      digitalWrite(pinGiallo, HIGH);
      digitalWrite(pinVerde, LOW);
    }
    else if (humidityState == HUMID){
      digitalWrite(pinRosso, HIGH);
      digitalWrite(pinGiallo, LOW);
      digitalWrite(pinVerde, LOW);
    }
  }

  // Handle LCD refresh independently from sensor reads
  screen_delay = millis() - actual_time;

  if (screen_delay >= duration_delay){
    actual_time = millis();
    lcd.clear();

    // Display humidity on first row
    Serial.print("Humidity: ");
    lcd.print("Humidity: ");
    lcd.print(humidity);
    lcd.print("%");
    Serial.print(humidity);
    Serial.print(" %  |  ");

    // Display temperature on second row
    Serial.print("Temperature: ");
    lcd.setCursor(0, 1);
    lcd.print("Temp.:");
    lcd.print(temperature);
    lcd.print(" C");
    Serial.print(temperature);
    Serial.println(" °C");
  }
}
