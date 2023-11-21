#pragma once

#include "led.h"
#include "button.h"
#include "driver/gpio.h"

/// @brief Mode in which the traffic light is going to operate
enum TrafficLightMode
{
    FOR_CARS,
    FOR_PEDS
};

class TrafficLight 
{
    private:
        Led m_redLight = Led();
        Led m_orangeLight = Led(GPIO_NUM_0, TO_GROUND);
        Led m_greenLight;
        TrafficLightMode m_TL_mode;

    public:
        TrafficLight(Led redLED, Led greenLED, TrafficLightMode mode, Led orangeLED = Led(GPIO_NUM_0, TO_GROUND));

    public:
        void redLight();
        void toggleOrangeLight();
        void orangeLightAfterRed();
        void orangeLightAfterGreen();
        void greenLight();
        void turnOffAll();
};