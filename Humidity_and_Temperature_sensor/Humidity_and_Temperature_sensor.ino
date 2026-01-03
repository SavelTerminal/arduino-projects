#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  dht.begin();
  lcd.begin(16, 2);
}

void loop() {
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Celsius

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor");
    return;
  }

  Serial.print("Humidity: ");
  lcd.print("Humidity: ");
  lcd.print(humidity);
  lcd.print("%");
  Serial.print(humidity);
  Serial.print(" %  |  ");

  Serial.print("Temperature: ");
  lcd.setCursor(0, 1);
  lcd.print("Temp.:");
  lcd.print(temperature);
  lcd.print(" C");
  Serial.print(temperature);
  Serial.println(" °C");
  

  delay(2000);
  lcd.clear();



}
