#include <Arduino.h>

struct Motors {
    void go(int left, int right);
    void stop();
};