#pragma once

#include "driver/gpio.h"

/// @brief Mode in which should button operate. PULLUP_MODE or PULLDOWN_MODE
enum ButtonMode {
    PULLUP_MODE,
    PULLDOWN_MODE
};

/// @brief Class for setting up and handling button
class Button
{
    private:
        gpio_num_t m_pin = GPIO_NUM_0;
        ButtonMode m_mode = PULLUP_MODE;

    public:
        Button(gpio_num_t pin, ButtonMode mode = PULLUP_MODE);
        Button();

    public:
        int getState();
        bool isPushed();
};