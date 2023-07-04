#include <LiquidCrystal.h> 
LiquidCrystal lcd(8, 9, 10, 11, 12, 13); 
int sensorPin = A0; 
int relayPin = 2; 
void setup() {
  lcd.begin(16, 2); 
  Serial.begin(9600);
   
  pinMode(sensorPin, INPUT); 
  pinMode(relayPin, OUTPUT); 
}

void loop() {
  int sensorValue = analogRead(sensorPin); 
  float voltage = sensorValue * (5.0 / 1023.0); 
  int percentage = map(sensorValue, 0, 1023, 0, 100); 

  lcd.setCursor(1, 0); 
  lcd.print("Valor:" + String(sensorValue)); 
  lcd.setCursor(1, 1); 
  lcd.print(percentage); 
  lcd.println("%"); 

  if (percentage <50) {
    lcd.print("Riego"); 
    //Serial.println("La tierra está humeda");
    //Serial.println("Valor del sensor: " + String(sensorValue)); 
    digitalWrite(relayPin, LOW);
  }
  else { 
    digitalWrite(relayPin,HIGH); 
    lcd.print("NO_Regar"); 
   // Serial.println("La tierra está seca, comienza el riego");
   //Serial.println("Valor del sensor: " + String(sensorValue));  
  }
  //Serial.print("Valor de exacto: "); 
  Serial.println(percentage); // 
  delay(500); 
}
