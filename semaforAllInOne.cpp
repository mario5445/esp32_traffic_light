#include "semaforAllInOne.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_log.h"

SemaforAllInOne::SemaforAllInOne(Led redLEDCars, Led orangeLEDCars, Led greenLEDCars, Led redLEDPeds, Led greenLEDPeds, Led waitLed, Button pedsButton)
{
    m_redLEDCars = redLEDCars;
    m_orangeLEDCars = orangeLEDCars;
    m_greenLEDCars = greenLEDCars;
    m_redLEDPeds = redLEDPeds;
    m_greenLEDPeds = greenLEDPeds;
    m_waitLed = waitLed;
    m_pedsButton = pedsButton;
}

enum class SemaforState
{
    OFF,
    GREEN_CARS,
    BTN_PUSHED_GREEN,
    ORANGE_AFTER_GREEN,
    RED_CARS,
    GREEN_PEDS,
    PEDS_TRANSIT,
    ORANGE_AFTER_RED
};

/// @brief Starts traffic light
void SemaforAllInOne::startWorking()
{
    SemaforState state = SemaforState::OFF;
    const char *TAG = "SEMAFOR";
    while(1)
    {
        switch (state)
        {
            case SemaforState::OFF:
                turnOffAll();
                state = SemaforState::GREEN_CARS;
                ESP_LOGW(TAG, "OFF");
                break;
            case SemaforState::GREEN_CARS:
                turnOffCars();
                m_redLEDPeds.on();
                m_greenLEDCars.on();
                ESP_LOGW(TAG, "Green cars, red peds");
                while(!m_pedsButton.isPushed()){
                    vTaskDelay(1);
                }
                state = SemaforState::BTN_PUSHED_GREEN;
                break;
            case SemaforState::BTN_PUSHED_GREEN:
                m_waitLed.on();
                ESP_LOGW(TAG, "wait!");
                vTaskDelay(5000 / portTICK_PERIOD_MS);
                state = SemaforState::ORANGE_AFTER_GREEN;
                break;
            case SemaforState::ORANGE_AFTER_GREEN:
                turnOffCars();
                m_orangeLEDCars.on();
                ESP_LOGW(TAG, "Orange after green");
                vTaskDelay(2000 / portTICK_PERIOD_MS);
                state = SemaforState::RED_CARS;
                break;
            case SemaforState::RED_CARS:
                turnOffCars();
                m_redLEDCars.on();
                ESP_LOGW(TAG, "Red for cars");
                vTaskDelay(1000 / portTICK_PERIOD_MS);
                state = SemaforState::GREEN_PEDS;
                break;
            case SemaforState::GREEN_PEDS:
                turnOffPeds();
                m_waitLed.off();
                m_greenLEDPeds.on();
                ESP_LOGW(TAG, "Green for peds!");
                vTaskDelay(5000 / portTICK_PERIOD_MS);
                state = SemaforState::PEDS_TRANSIT;
                break;
            case SemaforState::PEDS_TRANSIT:
                turnOffPeds();
                m_redLEDPeds.on();
                ESP_LOGW(TAG, "Peds transit");
                vTaskDelay(2000 / portTICK_PERIOD_MS);
                state = SemaforState::ORANGE_AFTER_RED;
                break;
            case SemaforState::ORANGE_AFTER_RED:
                m_orangeLEDCars.on();
                ESP_LOGW(TAG, "Orange after red Cars");
                vTaskDelay(1000 / portTICK_PERIOD_MS);
                state = SemaforState::GREEN_CARS;
                break;
        }
    }
}

void SemaforAllInOne::turnOffCars(){
    m_redLEDCars.off();
    m_orangeLEDCars.off();
    m_greenLEDCars.off();
}

void SemaforAllInOne::turnOffPeds(){
    m_redLEDPeds.off();
    m_greenLEDPeds.off();
}

void SemaforAllInOne::turnOffAll(){
    turnOffCars();
    turnOffPeds();
}