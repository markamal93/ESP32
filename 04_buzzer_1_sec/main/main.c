#include "driver/gpio.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include ""

#define BUZZER_PIN GPIO_NUM_5   // choose your buzzer pin


void app_main(void) {

    gpio_set_direction(BUZZER_PIN , GPIO_MODE_OUTPUT);

    while (1)
    {
    gpio_set_level(BUZZER_PIN , 1);
    vTaskDelay(1000 / portTICK_PERIOD_MS);  // 1 second ON

    gpio_set_level(BUZZER_PIN , 0);
    vTaskDelay(1000 / portTICK_PERIOD_MS);  // 1 second ON


    }
    

}