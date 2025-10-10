#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"


#define led_1   GPIO_NUM_2
#define led_2   GPIO_NUM_4

#define Button_1    GPIO_NUM_5
#define Button_2    GPIO_NUM_18


void app_main(void)
{
    gpio_reset_pin(led_1);
    gpio_reset_pin(led_2);

    gpio_reset_pin(Button_1);
    gpio_reset_pin(Button_2);

    gpio_set_direction(led_1 , GPIO_MODE_OUTPUT);
    gpio_set_direction(led_2 , GPIO_MODE_OUTPUT);

    gpio_set_direction(Button_1 , GPIO_MODE_INPUT);
    gpio_set_direction(Button_2 , GPIO_MODE_INPUT);

    while(1){

        int button_1_val = gpio_get_level(Button_1);
        int button_2_val = gpio_get_level(Button_2);

        if (button_1_val == 0){
            gpio_set_level(led_1 , 1);
        }else {
            gpio_set_level(led_1 , 0);
        }

         if (button_2_val == 0){
            gpio_set_level(led_2 , 1);
        }else {
            gpio_set_level(led_2 , 0);
        }
    }


}