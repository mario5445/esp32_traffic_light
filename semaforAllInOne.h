#pragma once

#include "led.h"
#include "button.h"

/// @brief Class for setting up and managing all-in-one traffic light
class SemaforAllInOne
{
    private:
        Led m_redLEDCars;
        Led m_orangeLEDCars;
        Led m_greenLEDCars;
        Led m_redLEDPeds;
        Led m_greenLEDPeds;
        Led m_waitLed;
        Button m_pedsButton;

    public:
        SemaforAllInOne(Led redLEDCars, Led orangeLEDCars, Led greenLEDCars, Led redLEDPeds, Led greenLEDPeds, Led waitLed, Button pedsButton);

    public:
        void startWorking();

    private:
        void turnOffCars();
        void turnOffPeds();
        void turnOffAll();

};