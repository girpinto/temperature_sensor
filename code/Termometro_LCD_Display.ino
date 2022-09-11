#include <DHT.h>
#include <LiquidCrystal.h>
//               RS  E  D4 D5  D6  D7
LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

#define DHTTYPE DHT11
#define DHTPIN 2

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  dht.begin();
}


void loop() {
  // Wait a few seconds between measurements.
  delay(2000);
  lcd.setCursor(0,0);
  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  //float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t)) {
    lcd.print(F("Failed reading"));
    return;
  }

  // Compute heat index in Fahrenheit (the default)
  //float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  lcd.print(F("Hum: "));
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print(F("Temp: "));
  lcd.print(t);
  lcd.print(F(" C"));
  //Serial.print(f);
  //Serial.print(F("°F  Heat index: "));
  //Serial.print(hic);
  //Serial.print(F("°C "));
  //Serial.print(hif);
  //Serial.println(F("°F"));
}
