#include <Servo.h>
#include <EEPROM.h>

// Pins
#define sensor A0
#define led 11
#define servopin 3

Servo servo;

// Struktur für saubere Speicherung
struct Runtime {
  unsigned long days;
  unsigned long hours;
  unsigned long minutes;
};

void setup() {
  // LED
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);

  // Servo
  servo.attach(servopin);
  servo.write(90); // OPEN

  delay(1000);

  // Warten auf Maus (Lichtstrahl unterbrochen)
  while (analogRead(sensor) > 30) {
    // warten
  }

  // Falle auslösen
  servo.write(180);

  // Laufzeit berechnen
  unsigned long millisec = millis();

  Runtime runtime;

  runtime.days = millisec / 86400000;
  millisec %= 86400000;

  runtime.hours = millisec / 3600000;
  millisec %= 3600000;

  runtime.minutes = millisec / 60000;

  // In EEPROM speichern (ab Adresse 0)
  EEPROM.put(0, runtime);

  // LED aus
  digitalWrite(led, LOW);
}

void loop() {
  // nichts
}