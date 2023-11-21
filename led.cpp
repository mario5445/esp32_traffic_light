#include "led.h"
#include "esp_log.h"

static const char *TAG = "LED";

Led::Led(gpio_num_t pin, LedConnection connType)
{
    m_pin = pin;
    m_connType = connType;

    if(m_pin == GPIO_NUM_34 || m_pin == GPIO_NUM_35 || m_pin == GPIO_NUM_36 || m_pin == GPIO_NUM_39){
        ESP_LOGE(TAG, "This pin doesn't support OUTPUT");
        return;
    }
    gpio_reset_pin(m_pin);
    gpio_set_direction(m_pin, GPIO_MODE_INPUT_OUTPUT);
    off();
}

Led::Led()
{
    m_pin = GPIO_NUM_0;
    m_connType = TO_GROUND;
}

/// @brief Turns on the LED diode
void Led::on()
{
    gpio_set_level(m_pin, (m_connType == TO_GROUND ? 1 : 0));
}

/// @brief Turns off the LED diode
void Led::off()
{
    gpio_set_level(m_pin, (m_connType == TO_GROUND ? 0 : 1));
}


/// @brief Toggles the state of the LED diode
void Led::toggle()
{
    bool level = (bool)gpio_get_level(m_pin);
    gpio_set_level(m_pin, !level);
}

/// @brief Changes state according to parameter
/// @param state state of led to be set to. 0 for off, 1 for on
void Led::changeState(uint8_t state)
{
    if(state == 0 || state == 1){
        state == 0 ? off() : on();
        return;
    }
    else
    {
        ESP_LOGE(TAG, "Invalid value");
    }
}
