#ifndef BUTTON_HPP
#define BUTTON_HPP
#include <Arduino.h>

#define PULLDOWN 0
#define PULLUP 1

class button
{
public:
    button(byte pin, byte mode);
    bool Read();

private:
    byte pin;
    byte mode;
    unsigned long start = 0;
};

#endif