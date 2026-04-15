#include <Servo.h>
#include <EEPROM.h>

// Pins
#define sensor A0
#define led 11
#define servopin 3

Servo servo;

// Structure for clean storage
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

  // Wait for mouse (light beam interrupted)
  while (analogRead(sensor) > 30) {
    // waiting
  }

  // Trigger trap
  servo.write(180);

  // Calculate runtime
  unsigned long millisec = millis();

  Runtime runtime;

  runtime.days = millisec / 86400000;
  millisec %= 86400000;

  runtime.hours = millisec / 3600000;
  millisec %= 3600000;

  runtime.minutes = millisec / 60000;

  // Save to EEPROM (starting at address 0)
  EEPROM.put(0, runtime);

  // Turn off LED
  digitalWrite(led, LOW);
}

void loop() {
  // nothing
}