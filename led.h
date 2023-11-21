#pragma once

#include "driver/gpio.h"

/// @brief Type of connection of LED diode. Can be connected TO_GROUND or TO_VCC
enum LedConnection {
    TO_GROUND,
    TO_VCC
};

/// @brief Class for setting up and handling LED diode
class Led 
{
    private:
        gpio_num_t m_pin = GPIO_NUM_0;
        LedConnection m_connType = TO_GROUND;

    public:
        Led(gpio_num_t pin, LedConnection connType = TO_GROUND); 
        Led();     

    public:
        void on();
        void off();
        void toggle();
        void changeState(uint8_t state);
};