# Drive Without Hitting Things

Drive without hitting things is a program for an Arduino robot to drive around without hitting things.

## Setup

You will need an Arduino robot car with a servo-mounted ultrasonic sensor.

Attach pins 6, 11, 9, 8, 7, and 5 to the motor control board,
with pin 5 controlling left motor speed, pin 6: right motor speed,
pin 7 determining if the left motor can go forward, pin 8: left motor backward,
pin 11: right motor forward, and pin 9: right motor backward.

Put the servo on pin 3.

A5 is the trig pin for the ultrasonic sensor, and A4 the echo pin.

Upload the sketch to the Arduino, then turn it on and watch it wander around the house without hitting things.