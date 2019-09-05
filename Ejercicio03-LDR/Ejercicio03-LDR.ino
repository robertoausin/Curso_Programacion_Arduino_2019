/*
   Ejercicio03 - Prueba LDR

*/

//Librerías pantalla LCD
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

//PINES
#define PIN_LDR A1
int maximo = 0;
int minimo = 1023;

//Objeto pantalla
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  //Inicializo puerto serie
  Serial.begin(9600);

  //Inicializo pantalla
  Serial.println(F("Inicializando pantalla..."));
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Inicializando...");
  delay(1000);
  lcd.clear();
}

void loop () {
  int sensorValue = analogRead(PIN_LDR);
  minimo = min(minimo, sensorValue);
  maximo = max(maximo, sensorValue);
  lcd.setCursor(0, 0);
  lcd.print("Valor:");
  lcd.setCursor(7, 0);
  lcd.print(sensorValue);
  lcd.setCursor(0, 1);
  lcd.print("M:");
  lcd.setCursor(3, 1);
  lcd.print(maximo);
  lcd.setCursor(8, 1);
  lcd.print("m:");
  lcd.setCursor(11, 1);
  lcd.print(minimo);
  Serial.print("Valor sensor: ");
  Serial.println(sensorValue);
  Serial.print("V max: ");
  Serial.print(maximo);
  Serial.print(" - V min: ");
  Serial.println(minimo);
  delay(500);
}
