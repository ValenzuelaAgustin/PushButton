#ifndef PUSHBUTTON_HPP
#define PUSHBUTTON_HPP
#include <Arduino.h>

#define PULLDOWN 0
#define PULLUP 1
#define debounceTIME 150

class PushButton
{
public:
    PushButton(byte pin, byte mode);
    bool Read();

private:
    byte pin;
    bool mode;
    bool is_pressed;
    unsigned long last_pressed;
};

#endif 