#include <Ultrasonic.h>

Ultrasonic ultrasonic (A5, A4);

void setup() {
    Serial.begin(115200);
}

void loop() {
    Serial.println(ultrasonic.distance());
    delay(500);
}