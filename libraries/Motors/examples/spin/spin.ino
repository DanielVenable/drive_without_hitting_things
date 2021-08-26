#include <Motors.h>

Motors motors;

void setup() {}

void loop() {
  motors.go(255, -255);
  delay(1000);
  motors.go(-255, 255);
  delay(1000);
}