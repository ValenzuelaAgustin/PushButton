#include "PushButton.hpp"

PushButton::PushButton(uint8_t pin, uint8_t mode)
{
    this->pin = pin;
    this->mode = (mode == PULLUP) || (mode == INPUT_PULLUP);
    pinMode(pin, (mode == INPUT_PULLUP) ? INPUT_PULLUP : INPUT);
}

void PushButton::begin(void(*ISR)())
{
    attachInterrupt(digitalPinToInterrupt(pin), ISR, CHANGE);
}

void PushButton::checkState()
{
    if (is_pressed && ((bool)digitalRead(pin) == mode))
    {
        is_pressed = false;
        just_pressed = false;
        just_released = true;
        last_release = millis();
    }
    if (!is_pressed && ((bool)digitalRead(pin) != mode) && (millis() - last_release >= debounceTIME) && (millis() - last_pressed >= debounceTIME))
    {
        is_pressed = true;
        just_pressed = true;
        just_released = false;
    }
}

bool PushButton::Read()
{
    is_pressed = ((bool)digitalRead(pin) != mode) && (millis() - last_pressed >= debounceTIME);
    last_pressed = millis() * is_pressed + last_pressed * !is_pressed;
    return is_pressed != mode;
}

bool PushButton::justPressed()
{
    if (!just_pressed)
        return false;
    just_pressed = false;
    return true;
}

bool PushButton::isPressed()
{
    return ((bool)digitalRead(pin) != mode) && (millis() - last_release >= debounceTIME);
}

bool PushButton::justReleased()
{
    if (!just_released)
        return false;
    just_released = false;
    return true;
}