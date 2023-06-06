#include <LiquidCrystal.h>
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
int sensorPin = A0;
int relayPin = 2;
void setup() {
  lcd.begin(16, 2);
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(2, OUTPUT);
}
void loop() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  int porcentaje = map(sensorValue, 0, 1023, 100, 0);
  lcd.setCursor(1, 0);
  lcd.print("Valor:" + String(sensorValue));
  lcd.setCursor(1, 1);
  lcd.print(porcentaje);
  lcd.println("%");
  if (sensorValue < 500.0) {
    digitalWrite(2, LOW);
    lcd.print(" Regar");
    Serial.println("La tierra está humeda");
    Serial.println("Valor del sensor: " + String(sensorValue));
  }
  if (sensorValue >= 500) {
    lcd.print("no_ Riego");
    Serial.println("La tierra está seca, comienza el riego");
    digitalWrite(2, HIGH);
  }
  Serial.print("Valor de voltaje: ");
  Serial.println(voltage, 2);
  Serial.print("Valor de exacto: ");
  Serial.println(porcentaje);

  delay(500);

}