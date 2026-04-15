#include <EEPROM.h>

struct Runtime {
  unsigned long days;
  unsigned long hours;
  unsigned long minutes;
};

void setup() {
  Serial.begin(9600);

  Runtime runtime;

  // Read data from EEPROM
  EEPROM.get(0, runtime);

  Serial.println("--- STORED RUNTIME ---");
  Serial.print("Days: ");
  Serial.println(runtime.days);

  Serial.print("Hours: ");
  Serial.println(runtime.hours);

  Serial.print("Minutes: ");
  Serial.println(runtime.minutes);
}

void loop() {
  // nothing
}