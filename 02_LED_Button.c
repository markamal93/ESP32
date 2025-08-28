#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define BUTTON_PIN  GPIO_NUM_0
#define LED_PIN     GPIO_NUM_2

void app_main(){
    gpio_reset_pin(BUTTON_PIN);
    gpio_set_direction(BUTTON_PIN,GPIO_MODE_INPUT);

    gpio_reset_pin(LED_PIN);
    gpio_set_direction(LED_PIN,GPIO_MODE_OUTPUT);

    while(1){
        int button_state = gpio_get_level(BUTTON_PIN);
        if (button_state == 1){
            gpio_set_level(LED_PIN,1);
        }else {
            gpio_set_level(LED_PIN,0);
        }
    }
}