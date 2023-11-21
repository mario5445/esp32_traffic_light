#include "trafficLight.h"
#include "led.h"

TrafficLight::TrafficLight(Led redLED, Led greenLED, TrafficLightMode mode, Led orangeLED)
{
    m_redLight = redLED;
    m_greenLight = greenLED;
    m_TL_mode = mode;
    m_orangeLight = orangeLED;
}

/// @brief Shows red light and turns off all other LEDS
void TrafficLight::redLight()
{
    turnOffAll();
    m_redLight.on();    
}

/// @brief If the traffic light doesn't work, this can be used
void TrafficLight::toggleOrangeLight()
{
    if(m_TL_mode == FOR_CARS){
        m_orangeLight.toggle();
    };
}

/// @brief Shows orange light but DOESN'T turn off other LEDS
void TrafficLight::orangeLightAfterRed()
{
    if(m_TL_mode == FOR_CARS) m_orangeLight.on();
}

/// @brief Shows orange light and turns off all other LEDS
void TrafficLight::orangeLightAfterGreen()
{
    turnOffAll();
    if(m_TL_mode == FOR_CARS) m_orangeLight.on();
}

/// @brief Shows green light and turns off all other LEDS
void TrafficLight::greenLight()
{
    turnOffAll();
    m_greenLight.on();
}

/// @brief Turns off all LEDS
void TrafficLight::turnOffAll()
{
    m_redLight.off();
    if(m_TL_mode == FOR_CARS) m_orangeLight.off();
    m_greenLight.off();
}
