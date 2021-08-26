#include <Ultrasonic.h>

Ultrasonic::Ultrasonic (int trig_pin, int echo_pin) {
  trig = trig_pin;
  echo = echo_pin;
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
}

int Ultrasonic::single_reading() {
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(20);
  digitalWrite(trig, LOW);
  return (int) pulseIn(echo, HIGH) / 58;
}

int Ultrasonic::distance() {
  int a = single_reading(), b = single_reading(), c = single_reading();
  if (b < c) return constrain(a, b, c);
  else return constrain(a, c, b);
}