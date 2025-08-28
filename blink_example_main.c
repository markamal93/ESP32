/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define CONFIG_FREERTOS_HZ 100
#define LED_PIN GPIO_NUM_2

void app_main(void){
    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN,GPIO_MODE_OUTPUT);

    while(1){
        gpio_set_level(LED_PIN,1);
        vTaskDelay(pdMS_TO_TICKS(500));
        gpio_set_level(LED_PIN , 0);
        vTaskDelay(pdMS_TO_TICKS(500));
    }
}