#include "button.h"
#include "esp_log.h"

static const char *TAG = "BUTTON";

Button::Button(gpio_num_t pin, ButtonMode mode)
{
    m_pin = pin;
    m_mode = mode;
    gpio_reset_pin(m_pin);
    gpio_set_direction(m_pin, GPIO_MODE_INPUT);
    if(pin == GPIO_NUM_34 || pin == GPIO_NUM_35 || pin == GPIO_NUM_36 || pin == GPIO_NUM_39){
        ESP_LOGW(TAG, "This pins neither have internal pullup nor pulldown. Use them with external resistor otherwise button won't work");
    }
    else {
        if(m_mode == PULLUP_MODE)
            gpio_pullup_en(m_pin);
        else
            gpio_pulldown_en(m_pin);
    }
    
}

Button::Button()
{
    m_pin = GPIO_NUM_0;
    m_mode = PULLUP_MODE;
}

/// @brief Gets a state of the button
/// @return Nummeric state of the button. 0 or 1
int Button::getState()
{
    return gpio_get_level(m_pin);
}

/// @brief Checks if the button is pushed down
/// @return True is pushed otherwise false
bool Button::isPushed()
{
    int state = getState();
    return (m_mode == PULLUP_MODE ? !state : state);
}
