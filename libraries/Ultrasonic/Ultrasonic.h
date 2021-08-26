#include <Arduino.h>
#include <Servo.h>

class Ultrasonic {
    int trig;
    int echo;
public:
    Ultrasonic(int trig_pin, int echo_pin);
    int single_reading();
    int distance();
};