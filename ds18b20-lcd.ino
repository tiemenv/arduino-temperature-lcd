#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>
#include <time.h>

#define ONE_WIRE_BUS 7

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  Serial.begin(9600);
  Serial.println("Dallas Temperature demo");
  sensors.begin();
  lcd.begin(16, 2);
}

void loop() {
  sensors.requestTemperatures();
  Serial.println(sensors.getTempCByIndex(0));
  lcd.setCursor(0,0);
  lcd.print("Temp: ");
  lcd.print(sensors.getTempCByIndex(0));
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Uptime: ");
  lcd.print(millis()/1000);
  lcd.print("s");
  delay(250);

}
