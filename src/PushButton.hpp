#ifndef PUSHBUTTON_HPP
#define PUSHBUTTON_HPP
#include <Arduino.h>

#ifndef PULLDOWN
#define PULLDOWN 0
#endif
#ifndef PULLUP
#define PULLUP 1
#endif

#define debounceTIME 200

class PushButton
{
public:
    /// Constructor of PushButton object.
    /// \param[in] pin Pin conected to the button.
    /// \param[in] mode Type of connection of the button (PULLDOWN, PULLUP or INPUT_PULLUP).
    PushButton(uint8_t pin, uint8_t mode);

    void begin(void(*ISR)());

    /// This method has to be inside a void(*)(void) function to be able to use it as parameter for the PushButton::begin method.
    /// If the begin method isnt called with the checkState method as parameter neither isPressed nor jusReleased methods will work as expected.
    void checkState();

    /// This method is intended to replace the digitalRead(ButtonPinNumber) and to no longer need the delay
    /// used to wait for the debounce. This method waits for the button to debounce, without using any kind
    /// of blocking function, before it returns another LOW, in case the mode was PULLUP or INPUT_PULLUP
    /// or another HIGH in case the mode was PULLDOWN.
    bool Read();

    /// \return true if the Button is being pressed.
    bool isPressed();

    /// \return true if the Button has being released and this method wasnt called since.
    bool justReleased();

private:
    uint32_t last_pressed = 0;
    uint32_t last_release = 0;
    uint8_t pin = 0;
    bool is_pressed = false;
    bool just_released = false;
    bool mode = 0;
};

#endif