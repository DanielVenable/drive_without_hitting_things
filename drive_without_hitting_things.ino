#include <Ultrasonic.h>
#include <Motors.h>
#include <Servo.h>

Ultrasonic ultrasonic (A5, A4);
Motors motors;
Servo servo;

struct {
  bool is_forward {true};
  bool finished_looking_left {false};
  bool finished_looking_right;
  int left;
  unsigned long start_time {0};
  unsigned long end_time;
} state;

void setup() {
  motors.go(255, 255);
  servo.attach(3);
  servo.write(100);
  randomSeed(analogRead(A0));
}

void loop() {
  if (state.is_forward) {
    if (ultrasonic.distance() < 20) {
      motors.stop();
      state.is_forward =
        state.finished_looking_left =
        state.finished_looking_right = false;
      state.end_time = millis() + 200;
      servo.write(150);
    } else if (millis() > state.end_time) {
      state.end_time = millis() + 200;
      if (state.finished_looking_left = !state.finished_looking_left) {
        servo.write(110);
      } else {
        servo.write(70);
      }
    }
  } else {
    if (millis() > state.end_time) {
      if (state.finished_looking_left) {
        if (state.finished_looking_right) {
          state.is_forward = true;
          motors.go(255, 255);
        } else {
          if (state.left > ultrasonic.distance()) motors.go(-255, 255);
          else motors.go(255, -255);
          state.finished_looking_right = true;
          state.end_time = millis() + random(100, 1000);
          servo.write(100);
        }
      } else {
        state.left = ultrasonic.distance();
        state.finished_looking_left = true;
        state.end_time = millis() + 200;
        servo.write(30);
      }
    }
  }
}