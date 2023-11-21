#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"
#include "led.h"
#include "button.h"
#include "trafficLight.h"
#include "semaforAllInOne.h"

#define BUTTON_PIN GPIO_NUM_23
#define RED_LED_CARS_PIN GPIO_NUM_21
#define ORANGE_LED_CARS_PIN GPIO_NUM_19
#define GREEN_LED_CARS_PIN GPIO_NUM_18
#define RED_LED_PEDS_PIN GPIO_NUM_32
#define GREEN_LED_PEDS_PIN GPIO_NUM_33
#define WAIT_LED_PIN GPIO_NUM_22

static const char *TAG = "example";

// void redPeds(TrafficLight &lightPeds){
//     lightPeds.turnOffAll();
//     lightPeds.redLight();
//     ESP_LOGW(TAG, "Red for peds");
// }

// void greenCars(TrafficLight &lightCars, Button &btn){
//     lightCars.turnOffAll();
//     lightCars.greenLight();
//     ESP_LOGW(TAG, "Green for cars and red for peds");
//     while(!btn.isPushed()){
//         vTaskDelay(1);
//     }
// }

// void orangeAfterGreenCars(TrafficLight &lightCars){
//     lightCars.turnOffAll();
//     lightCars.orangeLight();
//     ESP_LOGW(TAG, "Orange after green");
// }

// void redCars(TrafficLight &lightCars){
//     lightCars.turnOffAll();
//     lightCars.redLight();
//     ESP_LOGW(TAG, "Red for cars");
// }

// void greenPeds(TrafficLight &lightPeds){
//     lightPeds.turnOffAll();
//     lightPeds.greenLight();
//     ESP_LOGW(TAG, "Green for peds");
// }

// void pedsTransit(TrafficLight &lightPeds){
//     lightPeds.turnOffAll();
//     lightPeds.redLight();
//     ESP_LOGW(TAG, "Peds transit");    
// }

// void orangeAfterRed(TrafficLight &lightCars){
//     lightCars.orangeLight();
//     ESP_LOGW(TAG, "Orange after red");
// }



extern "C"
{
    void app_main(void)
    {
        Led redLedCars(RED_LED_CARS_PIN);
        Led orangeLedCars(ORANGE_LED_CARS_PIN);
        Led greenLedCars(GREEN_LED_CARS_PIN);
        Led redLedPeds(RED_LED_PEDS_PIN);
        Led greenLedPeds(GREEN_LED_PEDS_PIN);
        Led waitLed(WAIT_LED_PIN);
        Button pedsButton(BUTTON_PIN, PULLUP_MODE);

        // TrafficLight carsLight(redLedCars, greenLedCars, FOR_CARS, orangeLedCars);
        // TrafficLight pedsLight(redLedPeds, greenLedPeds, FOR_PEDS);

        SemaforAllInOne semafor(redLedCars, orangeLedCars, greenLedCars, redLedPeds, greenLedPeds, waitLed, pedsButton);
        semafor.startWorking();
        while(1){
            // redPeds(pedsLight);
            // greenCars(carsLight, pedsButton);
            // waitLed.on();
            // vTaskDelay(5000 / portTICK_PERIOD_MS);
            // orangeAfterGreenCars(carsLight);
            // vTaskDelay(2000 / portTICK_PERIOD_MS);
            // redCars(carsLight);
            // vTaskDelay(1000 / portTICK_PERIOD_MS);
            // waitLed.off();
            // greenPeds(pedsLight);
            // vTaskDelay(5000 / portTICK_PERIOD_MS);
            // pedsTransit(pedsLight);
            // vTaskDelay(2000 / portTICK_PERIOD_MS);
            // orangeAfterRed(carsLight);
            // vTaskDelay(1000 / portTICK_PERIOD_MS);

            // Green for cars and red for peds
            // pedsLight.redLight();
            // carsLight.greenLight();
            // // Button checking
            // while(!pedsButton.isPushed()){
            //     vTaskDelay(1);
            // }
            // waitLed.on();
            // // Last five seconds of green for cars
            // vTaskDelay(5000 / portTICK_PERIOD_MS);
            // carsLight.orangeLightAfterGreen();
            // vTaskDelay(2000 / portTICK_PERIOD_MS);
            // carsLight.redLight();
            // // Transit cars
            // vTaskDelay(1000 / portTICK_PERIOD_MS);
            // waitLed.off();
            // pedsLight.greenLight();
            // vTaskDelay(5000 / portTICK_PERIOD_MS);
            // pedsLight.redLight();
            // vTaskDelay(2000 / portTICK_PERIOD_MS);
            // carsLight.orangeLightAfterRed();
            // vTaskDelay(1000 / portTICK_PERIOD_MS);
        }
    }   
}
