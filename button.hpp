#ifndef BUTTON_HPP
#define BUTTON_HPP
#include <Arduino.h>

#define PULLDOWN 0
#define PULLUP 1
#define debounceTIME 150

class button
{
public:
    button(byte pin, byte mode);
    bool Read();

private:
    byte pin;
    byte mode;
    unsigned long last_pressed;
};

#endif