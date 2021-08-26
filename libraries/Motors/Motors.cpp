#include <Motors.h>

void Motors::stop() {
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(11, LOW);
  digitalWrite(9, LOW);
}

void Motors::go(int left, int right) {
  stop();
  if (left > 0) {
    digitalWrite(7, HIGH);
  } else if (left < 0) {
    digitalWrite(8, HIGH);
  }
  if (right > 0) {
    digitalWrite(11, HIGH);
  } else {
    digitalWrite(9, HIGH);
  }
  analogWrite(5, abs(left));
  analogWrite(6, abs(right));
}