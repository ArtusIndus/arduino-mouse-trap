#include <Servo.h>

#define servopin 3

Servo servo;

void setup() {
  servo.attach(servopin);

  // Optional: kurze Pause für Stabilität
  delay(500);

  // Servo in OPEN-Position fahren
  servo.write(90);

  // Zeit geben, damit Servo die Position erreicht
  delay(1000);

  // Optional: Servo wieder lösen (stromsparend)
  servo.detach();
}

void loop() {
  // nichts
}