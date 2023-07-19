#include "button.hpp"

button::button(byte pin, byte mode)
{
    this->pin = pin;
    this->mode = mode;

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
    if (millis() - debounceSTART >= debounceTIME)
    {
        debounceSTART = millis();
        return digitalRead(pin);
    }
    switch (mode)
    {
    case PULLDOWN:
        return 0;
        break;
    default:
        return 1;
        break;
    }
}