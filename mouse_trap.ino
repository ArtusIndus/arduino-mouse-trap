#include <Servo.h>
#include <EEPROM.h>

// Sensor and actuator pins
#define sensor A0
#define led 11
#define servopin 3

Servo servo;

void setup() {
  Serial.begin(9600);

  // Read stored runtime data from EEPROM
  Serial.print("days: ");
  Serial.println(EEPROM.read(0));
  Serial.print("hours: ");
  Serial.println(EEPROM.read(1));
  Serial.print("minutes: ");
  Serial.println(EEPROM.read(2));

  delay(1000);

  Serial.println("---START---");

  // Clear EEPROM memory (WARNING: erases previous data on every startup)
  for (int i = 0; i < 512; i++) {
    EEPROM.write(i, 0);
  }

  // Initialize LED as output and turn it ON
  pinMode(led, OUTPUT);
  digitalWrite(led, HIGH);

  // Initialize servo motor and set it to OPEN position
  servo.attach(servopin);
  servo.write(90);

  delay(1000);

  // Wait until the light beam is interrupted (mouse detection)
  while (analogRead(sensor) > 30) {
    // Do nothing until sensor value drops below threshold
  }

  // Trigger trap (close mechanism)
  servo.write(180);

  // Measure runtime in milliseconds
  unsigned long millisec = millis();

  // Convert runtime into days, hours, minutes
  unsigned long days = millisec / 86400000;
  millisec %= 86400000;

  unsigned long hours = millisec / 3600000;
  millisec %= 3600000;

  unsigned long minutes = millisec / 60000;

  // Store runtime values in EEPROM
  EEPROM.write(0, days);
  EEPROM.write(1, hours);
  EEPROM.write(2, minutes);

  Serial.print("---STOP---");

  // Turn off LED after triggering
  digitalWrite(led, LOW);
}

void loop() {
  // Nothing here, everything runs once in setup()
}
