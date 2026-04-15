#include <Servo.h>

#define servopin 3

Servo servo;

void setup() {
  servo.attach(servopin);

  // Optional: short delay for stability
  delay(500);

  // Move servo to OPEN position
  servo.write(90);

  // Give time for the servo to reach the position
  delay(1000);

  // Optional: detach servo again (saves power)
  servo.detach();
}

void loop() {
  // nothing
}