#include <Arduino.h>

const int pinoLed = 13;


void setup() {
  // put your setup code here, to run once:
  pinMode(pinoLed, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pinoLed, HIGH);
  delay(300);
  digitalWrite(pinoLed, LOW);
  delay(600);
  digitalWrite(pinoLed, HIGH);
  delay(300);
  digitalWrite(pinoLed, LOW);
  delay(600);
  digitalWrite(pinoLed, HIGH);
  delay(300);
  digitalWrite(pinoLed, LOW);
  delay(1000);

  digitalWrite(pinoLed, HIGH);
  delay(800);
  digitalWrite(pinoLed, LOW);
  delay(600);
  digitalWrite(pinoLed, HIGH);
  delay(800);
  digitalWrite(pinoLed, LOW);
  delay(600);
  digitalWrite(pinoLed, HIGH);
  delay(800);
  digitalWrite(pinoLed, LOW);
  delay(1000);

  digitalWrite(pinoLed, HIGH);
  delay(300);
  digitalWrite(pinoLed, LOW);
  delay(600);
  digitalWrite(pinoLed, HIGH);
  delay(300);
  digitalWrite(pinoLed, LOW);
  delay(600);
  digitalWrite(pinoLed, HIGH);
  delay(300);
  digitalWrite(pinoLed, LOW);
  delay(1000);

}
