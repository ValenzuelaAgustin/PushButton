#ifndef PUSHBUTTON_HPP
#define PUSHBUTTON_HPP
#include <Arduino.h>

#ifndef PULLDOWN
#define PULLDOWN 0
#endif
#ifndef PULLUP
#define PULLUP 1
#endif

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