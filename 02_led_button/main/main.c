#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"


#define led_pin GPIO_NUM_2
#define button_pin  GPIO_NUM_4


void app_main(void)
{
    gpio_reset_pin(led_pin);
    gpio_reset_pin(button_pin);
    gpio_set_direction(led_pin , GPIO_MODE_OUTPUT);
    gpio_set_direction(button_pin , GPIO_MODE_INPUT);

    while (1)
    {
        int button_val = gpio_get_level(button_pin);
        gpio_set_level(led_pin , !button_val);
        printf("button state is : %d\n",button_val);
        vTaskDelay(pdMS_TO_TICKS(500));
        
    }
    

}