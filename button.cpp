#include "button.hpp"

button::button(byte pin, byte mode)
{
    this->pin = pin;
    mode *= (mode == PULLDOWN || mode == PULLUP || mode == INPUT_PULLUP);
    this->mode = mode && 1;

    switch (mode)
    {
    case INPUT_PULLUP:
        pinMode(pin, INPUT_PULLUP);
        break;
    default:
        pinMode(pin, INPUT);
        break;
    }
}

bool button::Read()
{
    is_pressed = (digitalRead(pin) != mode) && (millis() - last_pressed >= debounceTIME);
    last_pressed = millis() * is_pressed + last_pressed * !is_pressed;
    return is_pressed != mode;
}