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
    PushButton(uint8_t pin, uint8_t mode);
    bool Read();

private:
    uint32_t last_pressed;
    uint8_t pin;
    bool is_pressed;
    bool mode;
};

#endif